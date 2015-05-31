<?php
Class	Spaceship {
	private $_name;
	private $_width;
	private $_height;
	private $_PC;
	private $_PP;
	private $_speed;
	private $_manoeuvre;
	private $_shield;
	private $_weapon;
	private $_active;
	private	$_coord = array('x' => 0, 'y' => 0);

	public function	getName() {
		return $this->_name;
	}
	public function	getWidth() {
		return $this->_width;
	}
	public function	getHeight() {
		return $this->_height;
	}
	public function	getPC() {
		return $this->_PC;
	}
	public function	getPP() {
		return $this->_PP;
	}
	public function	getSpeed() {
		return $this->_speed;
	}
	public function	getManoeuvre() {
		return $this->_manoeuvre;
	}
	public function	getShield() {
		return $this->_shield;
	}
	public function	getWeapon() {
		return $this->_weapon;
	}
	public function	getActive() {
		return $this->_Active;
	}

	public function	setName($name) {
		$this->_name = $name;
	}
	public function	setWidth($width) {
		$this->_width = $width;
	}
	public function	setHeight($height) {
		$this->_height = $height;
	}
	public function	setPC($PC) {
		$this->_PC = $PC;
	}
	public function	setPP($PP) {
		$this->_PP = $PP;
	}
	public function	setSpeed($speed) {
		$this->_speed = $speed;
	}
	public function	setManoeuvre($manoeuvre) {
		$this->_manoeuvre = $manoeuvre;
	}
	public function	setShield($shield) {
		$this->_shield = $shield;
	}
	public function	setWeapon($weapon) {
		$this->_weapon = $weapon;
	}
	public function	setActive($value) {
		$this->_active = $value;
	}
}
?>
