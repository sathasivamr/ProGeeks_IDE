<?php
	include 'db/dbconnection.php';
	//DISALLOW MULTIPLE ACCESS
	if(isset($_SESSION['progeeks_email'])){
		$row = mysqli_fetch_assoc(mysqli_query($con,'select * from psg_access where email="'.$_SESSION['progeeks_email'].'"'));
		if($row['session']!=$_SESSION['progeeks_session']){
			header('location: force.php');
		}
	}else{
		header('location: login.php');
	}

?>