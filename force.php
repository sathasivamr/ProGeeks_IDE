<?php
    session_start();
    include 'db/dbconnection.php';   
    if($_SESSION['progeeks_status']){
    	if(isset($_GET['yes'])){
    		
   		 //DISALLOW MULTIPLE ACCESS
	        $_SESSION['progeeks_session'] = rand(1111,9999);
	        mysqli_query($con,'update psg_access set session="'. $_SESSION['progeeks_session'].'" where email="'.$_SESSION['progeeks_email'].'"');
	      
	        	
	       header("location: play.php");
    	}
    	

    }else{
        header("location:login.php");
    }
?>
<!doctype html>
<html class="no-js" lang="">
<head>        
    <title>Botwarz | Login 2015</title>       
</head>
<body>

    <ul>
    <li>This account has been already logged In.</li>
    <li>By trying to break in, You will Slaughter 'em</li>                                
    </ul>
    <center>
        <input type="button" value="I ACCEPT" onclick="window.location='force.php?yes=1';" />
        <input type="button" value="I DECLINE" onclick="window.location='//psglogin.in';" />
    </center>
  
</body>
</html>