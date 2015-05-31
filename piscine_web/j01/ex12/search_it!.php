#!/usr/bin/php
<?php
	if ($argc < 3)
		return (0);
	$to_find = trim($argv[1]);
	$i = 2;
	while ($i < $argc)
	{
		$ateste = explode(":", $str);
		if(trim($ateste[0]) == trim($to_find))
		{
			print "$ateste[1]\n";
			return (0);
		}
		$i++;
	}

?>
