<?php
	class NightsWatch
	{
		function recruit($a)
		{
			if ($a instanceof IFighter)
				$a->fight();
		}
		function fight()
		{
			return TRUE;
		}
	}
?>
