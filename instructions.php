
<?php session_start();
include 'db/dbconnection.php';
if(isset($_SESSION["progeeks_uid"]) && $_SESSION["progeeks_uid"] !=NULL)
{
 $email = $_SESSION["progeeks_uid"];
 	if($_SESSION['progeeks_whois'] == 'PAR')
    {
      $query = "SELECT * FROM question where Question_Id=(select Geek_Level from geek where Geek_Email='$email')";
    }
    else
    {
      $query = "SELECT * FROM question where Question_Id=(select Geek_Level from alumni where Geek_Email='$email ')";
     
    }
    $res4 = $con->query($query);
    if ($row4= $res4->fetch_assoc()) 
    {
		
    }
    else
    {
      header("Location: 404.php");
    }
}
else
{
	header("Location: //accounts.psglogin.in/");
}
?>
<!DOCTYPE html>
<html>
<head>  
  <meta charset="utf-8">
  <meta http-equiv="X-UA-Compatible" content="IE=edge,chrome=1">
  <title>PROGEEKS</title>
  <meta name="description" content="">
  <meta name="viewport" content="width=device-width, initial-scale=1">
  <link rel="stylesheet" href="css/bootstrap.min.css">         
  <link rel="stylesheet" href="css/main.css">
  <link rel="icon" type="img/png" href="img/logo.png"></link>
  <style type="text/css">
    .info{
      margin:0 0 0 40px;
      font-size:18px;
      ul.square {list-style-type: square;}
      line-height:50%;
    }
    h4{
      color:#4183D7;
      margin-top:20px;
      font-size: 23px;
    }
  </style>
</head>
<body >
    <?php include('header.php');?>     
 
      <div class="col-lg-12">            
        <div class="bs-component">
	<div class="info">
  	<h4>INSTRUCTIONS</h4>
  	<p>
              <ul>
                <li>The Event consists of several challenges.</li>
                  <li>Participants can use either Java or C++ programming language.</ll>
                  <li>No time constraint.</li>
                  <li>Any attempt to gain illegal access will result in elimination of the participant.</li>
                  <li>Participants will be disqualified in case of deviations from any of the rules.</li>                    
              </ul>
            </p>
	
 		<h4>CONTACT</h4>
          <ul>
            <li>GOWTHAM S</li>
            <li>+91 96550 10440</li>
		<li>gowthamjayam93[at]gmail[dot]com</li>
          </ul>
	</div>       
            
        </div>
      </div>
   
	<script src="//ajax.googleapis.com/ajax/libs/jquery/1.11.2/jquery.min.js"></script>
        <script>window.jQuery || document.write('<script src="js/vendor/jquery-1.11.2.min.js"><\/script>')</script>
        <script src="js/vendor/bootstrap.min.js"></script>
        <script src="js/plugins.js"></script>
        <script src="js/modernizr.js"></script>
</body>
</html>


