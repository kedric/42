#!/usr/bin/php
<?php
if ($argc == 2)
{
	$chaine = $argv[1];
	$chaine = trim($chaine);
	$chaine = str_replace("\t", " ", $chaine);
	$chaine = eregi_replace("[ ]+", " ", $chaine);
	$chaine = trim($chaine);
	print "$chaine\n";
}
?>
