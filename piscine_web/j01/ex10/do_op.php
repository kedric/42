#!/usr/bin/php
<?php
$a = trim($argv[1]);
$b = trim($argv[3]);
if ($argc == 4 && is_numeric($a) && is_numeric($b))
{
	$op = trim($argv[2]);
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
		print("Incorrect Parameters");
}
else
		print("Incorrect Parameters");
	print "\n";
?>
