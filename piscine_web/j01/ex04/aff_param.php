#!/usr/bin/php
<?php
 $i = 0;
 	foreach ($argv as $tmp)
	{
		if ($i++ > 0)
			echo "$tmp\n";
	}
?>
