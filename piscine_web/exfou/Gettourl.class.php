<?php
	class Gettourl
	{
		static function transform(array $get)
		{
			$i = 0;
			$str = "";
			foreach ($get as $key => $value) {
				if ($i != 0);
				{
					$str = $str."&";
					$i = 1;
				}
				$str = $str.$key."=".$value;
			}
			return ($str);
		}
	}
?>
