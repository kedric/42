#!/usr/bin/php
<?php
$table = array();
if($argc == 2 && preg_match("/^(([Ll]undi)|([Mm]ardi)|([Mm]ercredi)|([jJ]eudi)|([Vv]endredi)|([Ss]amedi)|([Dd]imanche))\s[0-2]?[0-9]\s(([Jj]anvier)|([Ff][eé]vrier)|([Mm]ars)|([Aa]vril)|([Mm]ai)|([jJ]uin)|([Jj]uillet)|([Aa]o[uû]t)|([Ss]eptembre)|([Oo]ctobre)|([Nn]ovembre)|([Dd][eé]cembre))\s[0-9]{4}\s([01]?[0-9]|2[0-3]):[0-5]?[0-9]:[0-5]?[0-9]$/", $argv[1]))
{
	date_default_timezone_set('Europe/Lisbon');
	$str = str_replace(":", " ", $argv[1]);
	$patern = array ('/[Dd]imanche/','/[Ll]undi/','/[Mm]ardi/','/[Mm]ercredi/','/[jJ]eudi/','/[Vv]endredi/','/[Ss]amedi/');
	$value  = array('0' ,'1','2', '3', '4', '5', '6');
	$str = preg_replace ($patern , $value, $str);
	$n = sscanf($str, '%i %i %s %s %i %i %i', $table['day'], $table['iday'],$table['month'],$table['year'],$table['hours'],$table['min'],$table['sec']);
	if(preg_match("/[Jj]anvier/",$table['month']))
		$table['month'] = 1;
	else if(preg_match("/[Ff][eé]vrier/",$table['month']))
		$table['month'] = 2;
	else if(preg_match("/[Mm]ars/",$table['month']))
		$table['month'] = 3;
	else if(preg_match("/[Aa]vril/",$table['month']))
		$table['month'] = 4;
	else if(preg_match("/[Mm]ai/",$table['month']))
		$table['month'] = 5;
	else if(preg_match("/[jJ]uin/",$table['month']))
		$table['month'] = 6;
	else if(preg_match("/[Jj]uillet/",$table['month']))
		$table['month'] = 7;
	else if(preg_match("/[Aa]o[uû]t/",$table['month']))
		$table['month'] = 8;
	else if(preg_match("/[Ss]eptembre/",$table['month']))
		$table['month'] = 9;
	else if(preg_match("/[Oo]ctobre/",$table['month']))
		$table['month'] = 10;
	else if(preg_match("/[Nn]ovembre/",$table['month']))
		$table['month'] = 11;
	else if(preg_match("/[Dd][eé]cembre/",$table['month']))
		$table['month'] = 12;
	if ($table['day'] === jddayofweek ( cal_to_jd(CAL_GREGORIAN,$table['month'],$table['iday'],$table['year'])))
		print(mktime($table['hours'],$table['min'],$table['sec'],$table['month'],$table['iday'],$table['year'], 1));
	else
		print ("Wrong Format");
}
else
{
	echo ("Wrong Format");
}
echo ("\n");
?>
