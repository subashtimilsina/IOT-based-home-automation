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
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "uart.h"

volatile int count;
char response[100];
char c;

void start_timer()
{
	TCCR0A |= (1<<WGM01);
	TCCR0B |= (1<<CS00)|(1<<CS02);
	TIMSK0 |= (1<<OCIE0A);
	OCR0A = 156;		//1 centi seconds 	
	TCNT0 = 0;
}

void stop_timer()
{
	TCCR0A=0;
	TCCR0B =0;
	TIMSK0 &= ~(1<<OCIE0A);
	count = 0;
}

const char* sendData(char *command,const int timeout) //timeout in centi seconds
{
	memset(response,'\0',100);
	uart0_puts(command);
	start_timer();
	while(timeout >= count)
	{
		while(uart0_available())
		{
			c = uart0_getc();
			strcat(response,&c);
		}
	}
	stop_timer();
	return response;
}


void initialise()
{
	uart0_init(UART_BAUD_SELECT(115200,F_CPU));
	sei();
	DDRB |= 0X38; //set pb3 pb4 and pb5 as a output pin
	count = 0;
	sendData("AT+RST\r\n",200);
	sendData("AT+CWJAP=\"Subash's Wifi\",\"bastain123\"\r\n",700);
	sendData("AT+CWMODE=3\r\n",200);
	sendData("AT+CIFSR\r\n",200);
	sendData("AT+CIPMUX=1\r\n",200);
	sendData("AT+CIPSERVER=1,80\r\n",200);
}


bool find(char *substring)
{
	uint8_t i;
	uint8_t length = strlen(substring);
	memset(response,'\0',100);
	bool search = false;
	while(uart0_available())
	{
		c = uart0_getc();
		strcat(response,&c);
	}
	if (response[0] != '\0')
	{
		for(i=0;i<strlen(response);i++)
		{
			for(uint8_t j=0;j<length;j++)
			{
				if (substring[j] == response[i])
					continue;
				else 
					break;		
				search = true;
			}
		}
	}
	return search;
}

int main()
{
	initialise();	
	while(1)
	{
		if (find("+IPD"))
		{
			_delay_ms(1000);
			int connectionId = uart0_getc()-48;
			find("pin=");
			int pinnumber = (uart0_getc()-48)*10;
			pinnumber += (uart0_getc()-48);
			if (pinnumber == 13)
				PORTB = 0X20;
			else if(pinnumber == 12)
				PORTB = 0X10;
			char closecommand[30];
			sprintf(closecommand,"AT+CIPCLOSE=%d\r\n",connectionId);
			sendData(closecommand,100);	
		}		
	}

}

ISR(TIMER0_COMPA_vect)
{
	count++;
}