#!/usr/bin/php
<?php
function ft_split($str, $c)
{
	$exp = explode($c, $str);
	$retour = array();
	$i = 0;
	foreach ($exp as $exp_tmp)
	{
		if ($exp_tmp != "")
			$retour[$i++] = $exp_tmp;
	}
	return ($retour);
}

if ($argc == 2)
{
	$tab = array();
	$buff = file_get_contents($argv[1]);
	preg_match_all("/<img[[:ascii:]]*src=\"([[:ascii:]]*)\"/Ui",$buff, $tab);
	print_r($tab);
	foreach ($tab[1] as $tmp)
	{
		$tmp = preg_replace("^z/\/\//", "/",$tmp);
		if (!preg_match("/http:\/\//", $tmp))
			$tmp = $argv[1].$tmp;
		$file = file_get_contents($tmp);
		$name = ft_split($tmp, "/");
		print_r($name);
		$name_url = $name[1];
		$name_f = $name[count($name) - 1];
		mkdir($name_url);
		file_put_contents($name_url."/".$name_f, $file);
	}
}
?>
