#!/usr/bin/php
<?php
function ft_split($str)
{
	$exp = explode(" ", $str);
	$retour = array();
	$i = 0;
	foreach ($exp as $exp_tmp)
	{
		if ($exp_tmp != "")
			$retour[$i++] = $exp_tmp;
	}
	return ($retour);
}
$i = 0;
$j = 0;
$ar = array();
	foreach ($argv  as $tmp)
	{
		if ($i++ > 0)
		{
			$entry = ft_split($tmp);
			foreach ($entry as $tmp2)
			{
				$ar[$j++] = $tmp2;
			}
		}
	}
	sort($ar);
	foreach ($ar as $print)
	{
		print "$print\n";
	}
?>
