<?php
function ft_is_sort($tab)
{
	$tab_s = $tab;
	$i = 0;
	sort($tab_s);
	foreach ($tab as $tmp)
	{
		if ($tmp != $tab_s[$i++])
			return (0);
	}
	return (1);
}
?>
