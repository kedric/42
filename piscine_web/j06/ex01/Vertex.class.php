<?php
	class Vertex
	{
		private $_x = 0;
		private $_y = 0;
		private $_z = 0;
		private $_w = 0.0;
		private $_color = 0;

		static $verbose = FALSE;
		function __construct( array $kwargs){
			if (array_key_exists('x', $kwargs))
				$this->_x = $kwargs['x'];
			if (array_key_exists('y', $kwargs))
				$this->_y = $kwargs['y'];
			if (array_key_exists('z', $kwargs))
				$this->_z = $kwargs['z'];
			$this->_w = (array_key_exists('w', $kwargs)) ? $kwargs['w'] : 1.0;
			$this->_color = (array_key_exists('color', $kwargs)) ? $kwargs['color'] : new color(array ('rgb' => (255 << 16) + (255 << 8) + 255));
			if (Vertex::$verbose == True)
					echo "Vertex( x: ".number_format($this->_x, 2).", y: ".number_format($this->_y, 2).", z:".number_format($this->_z,2).", w:".number_format($this->_w,2).", ".$this->_color." ) constructed\n";
		}
		function getX() {return $this->_x;}
		function getY() {return $this->_y;}
		function getZ() {return $this->_z;}
		function getW() {return $this->_w;}
		function getColor() {return $this->_color;}
		function setX($a) {$this->_x = $a;}
		function setY($a) {$this->_y = $a;}
		function setZ($a) {$this->_z = $a;}
		function setW($a) {$this->_w = $a;}
		function setColor($a) {$this->_color = $a;}
		function __toString()
		{
			if (Vertex::$verbose == TRUE)
				$strc = ", ".$this->_color;
			return ("Vertex( x: ".number_format($this->_x,2).", y: ".number_format($this->_y,2).", z:".number_format($this->_z,2).", w:".number_format($this->_w,2).$strc." )" );
		}
		static function doc()
		{
			print (file_get_contents("Vertex.doc.txt"));
		}
		function __destruct() {
			if (Vertex::$verbose == True)
					echo "Vertex( x: ".number_format($this->_x, 2).", y: ".number_format($this->_y, 2).", z:".number_format($this->_z,2).", w:".number_format($this->_w,2).", ".$this->_color." ) destructed\n";
		}
	}
?>
