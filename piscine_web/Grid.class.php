<?php
Class	Grid {
	private $_grid;

	public function __construct() {
		$file = file_get_contents("map.txt");
		$this->_grid = explode("\n", $file);
	}

	public function	aff() {
		echo "<div align=\"center\" valign=\"center\" >";
		echo "<h2>PARTIE DE JEU</h2>";
		echo "<table border=\"1px\">\n";
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
				echo "<td bgcolor=\"".$color."\" height=0.6px width=1.3px border=\"1px\" ></td>";
			}
			echo "</tr>\n";
		}
		echo "</table>";
		echo "</div>";
	}
}
?>
