#!/usr/bin/php
<?php
while (1)
{
	print "Entrez un nombre: ";
	$retour = fgets(STDIN);
	if(!feof(STDIN))
	{
		$retour_tmp = explode("\n", $retour)[0];
		if (is_numeric($retour_tmp))
		{
			if ($retour_tmp % 2 == 0)
				print "Le chiffre $retour_tmp est Pair\n";
			else
				print "Le chiffre $retour_tmp est Impair\n";
		}
		else
		print "'$retour_tmp' n'est pas un chiffre\n";
}
	else
		break;
}
?>
