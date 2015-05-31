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
	sort($retour);
	return ($retour);
}
?>
