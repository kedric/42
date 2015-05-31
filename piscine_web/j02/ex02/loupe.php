#!/usr/bin/php
<?php
$right = is_readable("./".$argv[1]);
if ($right == FALSE)
	return (NULL);
if ($argc == 2 && file_exists("./".$argv[1]) !== FALSE)
{
	$buff = file_get_contents("./".$argv[1]);
	$tab = $tab_a = array();
	preg_match_all("/<a[[:ascii:]]*>[[:ascii:]]*<\/a>/Ui",$buff, $tab);
	$i = 0;
	foreach ($tab[0] as $buff_tmp)
	{
		preg_match_all("/>([[:ascii:]]*)</Ui",$buff_tmp, $tab_a);
		$i = 0;
		foreach ($tab_a[1] as $buff_tmp2)
		{
			$tmp = $tab_a[0][$i];
			$tmp_up = strtoupper($buff_tmp2);
			$tmp = str_replace($buff_tmp2, $tmp_up,$tmp);
			$buff = str_replace($tab_a[0][$i], $tmp ,$buff);
			$i++;
		}
		preg_match_all("/[[:ascii:]]*title=\"([[:ascii:]]*)\"/Ui",$buff, $tab_a);

			$i = 0;
		foreach ($tab_a[1] as $buff_tmp3)
		{
			$tmp = $tab_a[0][$i];
			$tmp_up = strtoupper($buff_tmp3);
			$tmp = str_replace($buff_tmp3, $tmp_up,$tmp);
			$buff = str_replace($tab_a[0][$i], $tmp ,$buff);
			$i++;
		}
	}
}
print("$buff")
?>
