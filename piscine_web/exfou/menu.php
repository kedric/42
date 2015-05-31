<?php
$player = 1;
print_r($_POST);
$battleship = array("test" , "test1");
echo "turn of player:".$player."<br/>";
if (!array_key_exists('turn', $_GET))
{
	foreach ($battleship as $value) {
	echo '<a href="index.php?batlleship='.$value.'&turn=2"><button class="bmenu" name="submit" id="'.$value.'" type="submit" value="auth">'.$value.'</button></a><br />';
	}
}
?>

