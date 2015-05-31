#!/usr/bin/php
<?php
function calc($a,$b,$op)
{
	if (is_numeric($a) && is_numeric($b))
	{
		if ($op == "-")
			print $a - $b;
		else if ($op == "+")
			print $a + $b;
		else if ($op == "*")
			print $a * $b;
		else if ($op == "/" && $a != 0 && $b != 0)
			print $a / $b;
		else if ($op == "%" && $a != 0 && $b != 0)
			print $a % $b;
		else
			echo("Syntax Error");
	}
	else
			echo('Syntax Error');
}
$a = "";
$op_f = 0;
$i = 0;
$op = "";
$str = trim($argv[1]);
while ($i < strlen($str))
{
	if ($op_f == 0 && $str[$i] <= '9' && $str[$i] >= '0')
	{
		$a = $a.$str[$i];
	}
	else if ($op_f != 0 && is_numeric($str[$i]))
	{
		$b = $b.$str[$i];
	}
	else if ($str[$i] == '-' || $str[$i] == '+' || $str[$i] == '*' || $str[$i] == '/' || $str[$i] == '%')
	{
		if ($i == 0)
			$a = $a.$str[$i];
		else if ($op_f == 0)
		{
			$op_f = 1;
			$op = $op.$str[$i];
		}
		else
			$b = $b.$str[$i];
	}
	$i++;
}
calc($a,$b,$op);
?>

