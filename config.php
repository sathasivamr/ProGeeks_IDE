<?php

	include 'db/dbconnection.php';
	define("def_user","psgtechs_progeeks");
	define("def_pass","");
	define("def_host", "localhost");
	define("def_db", "psgtechs_progeeks");
	
	$conc = mysqli_connect(def_host,def_user,def_pass,def_db);
	
	setlocale(LC_MONETARY, 'en_IN');
	date_default_timezone_set('Asia/kolkata');
	
?>