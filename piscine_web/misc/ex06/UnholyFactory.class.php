<?php
class UnholyFactory{

	private $cacth = 0;
	public $possibility = 0;
	public function __construct($v='')
	{
		$this->possibility = array('foot soldier' => 1, 'archer' => 1, 'assassin' => 1);
	}
	function absorb($a){
		foreach ($this->possibility as $k => $v) {
			if ($k == $a->name)
			{
				if ($this->possibility[$k] == 1)
				{
					echo "(Factory absorbed a fighter of type ".$a->name.")". PHP_EOL;
					$this->cacht[$k] = $a;
					$this->possibility[$k] = 0;
					return ;
				}
				else{
					echo "(Factory already absorbed a fighter of type ".$a->name.")". PHP_EOL;
					return ;
				}
			}
		}
			echo "(Factory can't absorb this, it's not a fighter)".PHP_EOL;
	}
	function fabricate($key){
		if (array_key_exists($key, $this->possibility)){
			echo "(Factory fabricates a fighter of type ".$key.")".PHP_EOL;
			return (clone $this->cacht[$key]);
		}
		else
			echo "(Factory hasn't absorbed any fighter of type ".$key.")".PHP_EOL;
	}
}
?>
