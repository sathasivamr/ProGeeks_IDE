
<?php
session_start();
include 'db/dbconnection.php';
if(isset($_SESSION["progeeks_uid"]) && $_SESSION["progeeks_uid"] !=NULL)
{	
    $email = $_SESSION["progeeks_uid"];
    if($_SESSION['progeeks_whois'] == 'PAR')
    {
      $query = "select * from geek  where Geek_Code NOT LIKE 'A%' order by Geek_Level desc ,Geek_Testcase desc,Geek_Time";
      $f1="College Name";
      $f2="Department Name";
    }
    else
    {
      $query = "select * from alumni where Geek_Rollno NOT LIKE '13%' order by Geek_Level desc ,Geek_Testcase desc,Geek_Time ";
      $f1="Email";
      $f2="Level";
    }
    $res = $con->query($query);
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
  <style>
  </style>
</head>
<body >
    <?php include('header.php');?>
     <div class="myrow">
	<div class="col-lg-12">            
            <div class="bs-component">
		<h3>LeaderBoard</h3>	    
              <table class="table table-striped table-hover ">
                <thead>
                  <tr class="warning" style="">
                    <th>#</th>
                    <th><?php echo $f1; ?></th>
                    <th><?php echo $f2; ?></th>
                    <th>Level</th>
                  </tr>		
                </thead>
		
		<?php
		$count=1;$str="";$total =1;
		while ($row = $res->fetch_assoc()) 
		{
		    if($_SESSION['progeeks_whois'] == 'PAR')
		    {
			$d1=$row['Geek_College'];
			$d2=$row['Geek_Department'];
		    }
		    else
		    {
			$d1=$row['Geek_Email'];
			$d2=$row['Geek_Level'];
		    }
		    if($count<=10){
		      if($count==1){
			echo "<tr><td><img src = img/1st.png width=20px height=20px></td><td>";
			$count++;
		      }
		      else if($count == 2){
			echo "<tr><td><img src = img/2nd.png width=20px height=20px></td><td>";
			$count++;
		      }
		      else
			echo "<tr><td>".$count++."</td><td>";
			if($d1 != "")
			echo $d1."</td><td>".$d2."</td><td>".$row['Geek_Testcase']."</td></tr>";    
		    }
		    if($row['Geek_Email'] == $_SESSION['progeeks_uid']){
 			  $str ="<tr><td bgcolor=#B8B8E6>".$total."</td><td bgcolor=#B8B8E6>".$d1."</td><td bgcolor=#B8B8E6>".$d2."</td><td bgcolor=#B8B8E6>".$row['Geek_Testcase']."</td></tr>"; 
		    }
		    $total++;
		}		
		?>	
              </table > 
	      <h3>Your Rank</h3>
	      <table class="table table-striped table-hover ">
		<thead>
                  <tr>
                    <th></th>
                    <th></th>
                    <th></th>
                    <th></th>
                  </tr>		
                </thead>
	      <?php
		    echo $str;
	      ?>
	      </table>
          </div>
      </div>
	<script src="//ajax.googleapis.com/ajax/libs/jquery/1.11.2/jquery.min.js"></script>
        <script>window.jQuery || document.write('<script src="js/vendor/jquery-1.11.2.min.js"><\/script>')</script>
        <script src="js/vendor/bootstrap.min.js"></script>
        <script src="js/plugins.js"></script>
        <script src="js/modernizr.js"></script>
</body>
</html>