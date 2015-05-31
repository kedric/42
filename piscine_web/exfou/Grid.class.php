<?php
require_once 'Gettourl.class.php';
Class	Grid {
	private $_grid;

	public function __construct() {
		$file = file_get_contents("map.txt");
		$this->_grid = explode("\n", $file);
	}

	public function	aff() {
		if (isset($_GET) && array_key_exists('waiting', $_GET) &&  $_GET['waiting'] == "1")
		{
			$_GET['waiting'] = 0;
			$url = Gettourl::transform($_GET);
			$_GET['waiting'] = 1;
		}
		echo "<div align=\"left\" valign=\"center\" >";
		echo "<h2 style='text-align:center;'>PARTIE DE JEU</h2>";
		echo "<table  id=\"grid\" border=\"1px\">\n";
		for ($i = 0; $i < 100; $i++) {
			echo "<tr>";
			for ($j = 0; $j < 150; $j++) {
				if ($this->_grid[$i][$j] == '.')
					$color  = "white";
				if ($this->_grid[$i][$j] == 'O')
					$color  = "black";
				if ($this->_grid[$i][$j] == 'X')
					$color  = "red";
				if ($this->_grid[$i][$j] == 'Y')
					$color  = "blue";
				if ($this->_grid[$i][$j] == 'P')
					$color  = "yellow";
				echo "<td bgcolor=\"".$color."\" height=0.6px width=1.3px border=\"1px\" >";
				if (array_key_exists('waiting', $_GET) &&  $_GET['waiting'] == "1")
					echo '<a href=index.php?'.$url.'&pose_i='.$i.'&pose_j='.$j.' style="text-decoration:none; color:'.$color.';line-height: 3px;margin:0;">';
					echo '<p style="text-decoration:none;color:'.$color.';line-height: 5px;margin:0;">.</p>';
					echo '</a>';
				echo "</td>";
			}
			echo "</tr>\n";
		}
		echo "</table>";
		echo "</div>";
	}
}
?>
