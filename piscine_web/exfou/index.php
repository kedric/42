<!DOCTYPE HTML PUBLIC "-//W3C//DTD HTL 4.01//EN" "http://www.w3.org/TR/html4/strict.dtd">
<html>
<head>
<title></title>
<meta name="copyright" content="">
<meta name="keywords" content="">
<meta name="description" content="">
<meta name="ROBOTS" content="NOINDEX, NOFOLLOW">
<meta http-equiv="content-type" content="text/html; charset=UTF-8">
<meta http-equiv="content-type" content="application/xhtml+xml; charset=UTF-8">
<meta http-equiv="content-style-type" content="text/css">
<meta http-equiv="expires" content="0">
<link href="css/menu.css" rel="stylesheet" type="text/css">
</head>
<body>
<div id="game">
	<?php
		require_once 'Grid.class.php';
		$grid = new Grid();
		$grid->aff();
	?>
<div id="menu">
	<?php include ("menu.php"); ?>
</div>
</div>
</script>
</body>

</html>
