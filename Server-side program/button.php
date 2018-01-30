<!DOCTYPE html>
<html>
<head>
<meta name="viewport" content="width=device-width, initial-scale=1">
<script type="text/javascript">
<?php
$Data1=$_GET["data1"];
$Data2=$_GET["data2"];
echo "var x=$Data1 
var y =$Data2;";
$File_data = 'file.txt';
$handle = fopen($File_data,'w') or die('Cannot open file:'.$File_data);
$data = $Data1.$Data2;
fwrite($handle,$data);
fclose($handle);
?>


	function submit1()
	{
		if(x==1)
		{x=0;}
		else
		{x=1;}
		window.location='button.php?data1='+x+'&data2='+y
		
	}
	
	function submit2()
	{
		if(y==1)
		{y=0;}
		else
		{y=1;}
		window.location='button.php?data1='+x+'&data2='+y
	}
</script>
	

</head>
<body>

<?php

$my_file1 = 'file.txt';
$handle1 = fopen($my_file1, 'r');
$data11 = fread($handle1,filesize($my_file1));	
$Data1 = (int)($data11 / 10);
$Data2 = (int)($data11 % 10);

?>

<h1><b><pre>Home Automation</pre></b></h1>
<br><br>

<button onclick = "submit1();" value = "LAMP" style = "border-radius:15px; width:300px; height: 100px; background-color:<?php
if($Data1==0)
	echo "RED";
else
	echo "GREEN";
?>;"><h1 style = "color:white">LAMP</h1></button>
<button onclick = "submit2();" value = "FAN" style = "border-radius:15px; width:300px; height: 100px; background-color: <?php
if($Data2==0)
	echo "RED";
else
	echo "GREEN";
?> ;"><h1 style = "color:white">FAN</h1></button>

<br><br>



</body>
</html> 