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
$ret = ft_split($argv[1]);
	foreach ($ret as $ret_tmp)
	{
		if ($i++ > 0)
			print "$ret_tmp ";
	}
	if (strlen($argv[1]) > 0)
	print "$ret[0]\n";
?>
