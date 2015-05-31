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

$entry = ft_split($argv[1]);
$i = 0;
	if (strlen($argv[1]) > 0)
	{
		foreach ($entry as $tmp)
		{
			if ($i++ > 0)
				echo " ";
			echo "$tmp";
		}
		if (strlen(tmp))
		echo "\n";
	}
?>
