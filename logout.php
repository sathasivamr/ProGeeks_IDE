<?php
	session_start();
	$_SESSION["progeeks_uid"] =NULL;
	session_destroy();	
	header("Location: index.php");
?>