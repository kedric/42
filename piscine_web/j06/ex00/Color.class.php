<?php
	class color
	{
		public $red = 0;
		public $green = 0;
		public $blue = 0;

		static $verbose = FALSE;
		function __construct( array $kwargs){
			$kwargs = (array_key_exists('rgb', $kwargs)) ? array ('red' => $kwargs['rgb'] >> 16 & 0xFF, 'green' => $kwargs['rgb'] >> 8 & 0xFF, 'blue' => $kwargs['rgb'] & 0xFF): $kwargs;
			$this->red = (array_key_exists('red', $kwargs)) ? (int)$kwargs['red'] : 0;
			$this->red = ($this->red > 0) ? $this->red : 0;
			$this->red = ($this->red < 255) ? $this->red : 255;
			$this->green = (array_key_exists('green', $kwargs)) ? (int)$kwargs['green'] : 0;
			$this->green = ($this->green > 0) ? $this->green : 0;
			$this->green = ($this->green < 255) ? $this->green : 255;
			$this->blue = (array_key_exists('blue', $kwargs)) ? (int)$kwargs['blue'] : 0;
			$this->blue = ($this->blue > 0) ? $this->blue : 0;
			$this->blue = ($this->blue < 255) ? $this->blue : 255;
			if (color::$verbose == TRUE)
			print ("Color( red: ".color::print_c($this->red).", green: ".color::print_c($this->green).", blue: ".color::print_c($this->blue)." ) constructed.\n");
			return;
		}
		static function print_c($c)
		{
			if (strlen($c) == 3)
				return $c;
			else if (strlen($c) == 2)
				return " $c";
			else
				return "  $c";
		}
		function add($c)
		{
			$nr = ($this->red + $c > 255) ? 255 : $this->red + $c->red;
			$nr = ($this->red + $c < 0) ? 0 : $this->red + $c->red;
			$ng = ($this->green + $c > 255) ? 255 : $this->green + $c->green;
			$ng = ($this->green + $c < 0) ? 0 : $this->green + $c->green;
			$nb = ($this->blue + $c > 255) ? 255 : $this->blue + $c->blue;
			$nb = ($this->blue + $c < 0) ? 0 : $this->blue + $c->blue;
			return (new Color(array('red'=>$nr,'green' => $ng, 'blue' => $nb)));
		}
		function sub($c)
		{
			$nr = ($this->red - $c < 0) ? 0 : $this->red - $c->red;
			$nr = ($this->red - $c > 255) ? 255 : $this->red - $c->red;
			$ng = ($this->green - $c < 0) ? 0 : $this->green - $c->green;
			$ng = ($this->green - $c > 255) ? 255 : $this->green - $c->green;
			$nb = ($this->blue - $c < 0) ? 0 : $this->blue - $c->blue;
			$nb = ($this->blue - $c > 255) ? 255 : $this->blue - $c->blue;
			return (new Color(array('red'=>$nr,'green' => $ng, 'blue' => $nb)));
		}
		function mult($c)
		{
			if ($c > 0)
			{
				$nc = (($this->red << 16) + ($this->green << 8) + $this->blue ) * $c;
				$nr = ($nc >> 16 & 0xFF > 255) ? 255 : $nc >> 16;
				$ng = ($nc >> 8 & 0xFF > 255) ? 255 : $nc >> 8 & 0xFF;
				$nb = ($nc & 0xFF > 255) ? 255 : $nc & 0xFF;
				return (new Color(array('red'=>$nr,'green' => $ng, 'blue' => $nb)));
			}
			else
				return (new Color(array('red'=> 0,'green' => 0, 'blue' => 0)));
		}
		function __toString() {
			return("Color( red: ".color::print_c($this->red).", green: ".color::print_c($this->green).", blue: ".color::print_c($this->blue)." )");
		}
		function __destruct() {
			if (color::$verbose == TRUE)
			print ("Color( red: ".color::print_c($this->red).", green: ".color::print_c($this->green).", blue: ".color::print_c($this->blue)." ) destructed.\n");
			return;
		}
		static function doc(){
			print (file_get_contents("Color.doc.txt"));
		}
	}
?>
