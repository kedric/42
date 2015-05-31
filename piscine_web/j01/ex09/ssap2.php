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
function mysort($tab)
{
	$i = 0;
	$ret = array();

	foreach ($tab as $tmp)
	{
		if ($tmp[0] >= 'a' && $tmp[0] <= 'z' || $tmp[0] >= 'A' && $tmp[0] <= 'Z')
			$ret[$i++] = $tmp;
	}
	foreach ($tab as $tmp)
	{
		if ($tmp[0] >= '0' && $tmp[0] <= '9' || $tmp[0] == '-' && is_numeric($tmp))
			$ret[$i++] = $tmp;
	}
	foreach ($tab as $tmp)
	{
			if (is_numeric($tmp) != 1)
			{
				if (($tmp[0] < 'a' || $tmp[0] >'z') && ($tmp[0] < 'A' || $tmp[0] > 'Z'))
					$ret[$i++] = $tmp;
			}
	}
	return ($ret);
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
	sort($ar, SORT_FLAG_CASE | SORT_STRING);
	$ar = mysort($ar);
	foreach ($ar as $print)
	{
		print "$print\n";
	}
?>
