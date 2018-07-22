/*
 * Esp8266.cpp
 *
 * Created: 2/1/2018 3:51:40 PM
 * Author : Subash Timilsina
 */ 

#ifndef F_CPU 
#define F_CPU 16000000UL
#endif

#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/delay.h>
#include <stdio.h>
#include "string.h"
#include "uart.h"

#define  DEBUG_BOOL				true
#define  BUFFER_SIZE_RESPONSE	30

#ifndef F_CPU
#define F_CPU 16000000UL
#endif

#define clockCyclesPerMicrosecond() ( F_CPU / 1000000L )
#define clockCyclesToMicroseconds (a) ( ((a) * 1000L) / (F_CPU / 1000L) )
#define MICROSECONDS_PER_TIMER2_OVERFLOW (clockCyclesToMicroseconds(64 * 256))
#define MILLIS_INC (MICROSECONDS_PER_TIMER2_OVERFLOW / 1000)
#define FRACT_INC ((MICROSECONDS_PER_TIMER2_OVERFLOW % 1000) >> 3)
#define FRACT_MAX (1000 >> 3)


		
unsigned long _timeout = 1000;		//1 second time out
unsigned long _startMillis;

char response[100];


volatile unsigned long timer2_millis = 0;
volatile unsigned long timer2_fract = 0;


unsigned long millis()
{
	unsigned long m;
	uint8_t oldSREG = SREG;
	cli();
	m = timer2_millis;
	SREG = oldSREG;
	
	return m;
}


void initialise_timeperiod()
{
	TCCR2B |= (1<<CS22);
	TIMSK2 |= (1<<TOIE2);
	TCNT2 = 0;
}

struct MultiTarget {
	const char *str;
	size_t len;
	size_t index;
};

int timedRead()
{
	int c;
	_startMillis = millis();
	do {
		c = uart0_getc();
		if (c >= 0) return c;
	} while(millis() - _startMillis < _timeout);
	return -1;     
}

int findMulti( struct MultiTarget *targets, int tCount) {
	for (struct MultiTarget *t = targets; t < targets+tCount; ++t) {
		if (t->len <= 0)
		return t - targets;
	}

	while (1) {
		int c = timedRead();
		if (c < 0)
		return -1;

		for (struct MultiTarget *t = targets; t < targets+tCount; ++t) {
			if (c == t->str[t->index]) {
				if (++t->index == t->len)
				return t - targets;
				else
				continue;
			}

			if (t->index == 0)
			continue;

			int origIndex = t->index;
			do {
				--t->index;
				if (c != t->str[t->index])
				continue;

				if (t->index == 0) {
					t->index++;
					break;
				}
				int diff = origIndex - t->index;
				size_t i;
				for (i = 0; i < t->index; ++i) {
					if (t->str[i] != t->str[i + diff])
					break;
				}
				if (i == t->index) {
					t->index++;
					break;
				}
			} while (t->index);
		}
	}
	return -1;
}


bool findUntil(char *target, size_t targetLen)
{
		MultiTarget t[1] = {{target, targetLen, 0}};
		return findMulti(t, 1) == 0 ? true : false;
}

bool  find(char *target)
{
	return findUntil(target, strlen(target));
}

char *sendData(const char* command, const uint16_t timeout, bool debug)
{
	memset(response,'\0',100);
	uart0_puts(command);
    long unsigned time = millis();
	while( (time+timeout) > millis())
	{
		while(uart0_available())
		{
			char c[2];
			c[1] = uart0_getc();
			c[2] = '\0';
			strcat(response,c);
		}
	}
	if(debug)
	{
		uart0_puts(response);         //to check whether the esp is sending data or not
	}
	return response;
}

void initialize_esp8266()
{
	//set pb3,pb4 and pb5 as output
	  DDRB |= 0X38;
	  sendData("AT+RST\r\n",2000,DEBUG_BOOL);
	  sendData("AT+CWJAP=\"Subash's Wifi\",\"Bastain123\"\r\n",7000,DEBUG_BOOL);
	  sendData("AT+CWMODE=3\r\n",2000,DEBUG_BOOL);
	  sendData("AT+CIFSR\r\n",2000,DEBUG_BOOL);
	  sendData("AT+CIPMUX=1\r\n",2000,DEBUG_BOOL);
	  sendData("AT+CIPSERVER=1,80\r\n",2000,DEBUG_BOOL);
}


int main()
{
	initialise_timeperiod();
	uart0_init(UART_BAUD_SELECT(9600,F_CPU));
	sei();
	initialize_esp8266();
	while(1)
	{
		  if(uart0_available())
		  {
			  if(find("+IPD,"))
			  {
				  _delay_ms(1000);
				  int connectionId = uart0_getc()-48;
				  find("pin=");
				  int pinNumber = (uart0_getc() - 48)*10;
				  pinNumber += (uart0_getc()-48);
				  
				  if(pinNumber == 13)
					PORTB = 0X20;
				 else if(pinNumber == 12)
					PORTB = 0X10;
				    
				  char closeCommand[30];
				  sprintf(closeCommand,"AT+CIPCLOSE=%d\r\n",connectionId);
				  sendData(closeCommand,1000,DEBUG_BOOL);
			  }
		  }
	}
	return 0;
}

ISR(TIMER2_OVF_vect) {
	timer2_millis += 1;
	timer2_fract += 3;
	if (timer2_fract >= 125) {
		timer2_fract -= 125;
		timer2_millis += 1;
	}
}