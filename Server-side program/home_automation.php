<!DOCTYPE html>
<html>
<head>
<meta name="viewport" content="width=device-width, initial-scale=1">

</head>
<body>
<?php

$my_file1 = 'file.txt';
$handle1 = fopen($my_file1, 'r');
$data11 = fread($handle1,filesize($my_file1));	
$Data1 = (int)($data11 / 10);
$Data2 = (int)($data11 % 10);
header("Location: /Switch/button.php?data1=$Data1&data2=$Data2");

?>




</body>
</html> 