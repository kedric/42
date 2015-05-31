<?php
abstract class Fighter {
	public $name;
	abstract function fight($target);
	public function __construct($a)
	{
		$this->name = $a;
	}
}
?>
