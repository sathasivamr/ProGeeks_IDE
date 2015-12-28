<?php
	define("def_user","root");
	define("def_pass","PlsOpen");
	define("def_host", "localhost");
	define("def_db", "psgtechs_geeks");
	
	$con = mysqli_connect(def_host,def_user,def_pass,def_db);
	
	setlocale(LC_MONETARY, 'en_IN');
	date_default_timezone_set('Asia/kolkata');
// Check connection
if (mysqli_connect_errno())
  {
  echo "Failed to connect to MySQL: " . mysqli_connect_error();
  }


?>
