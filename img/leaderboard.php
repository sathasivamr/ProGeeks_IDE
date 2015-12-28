<?php
include '../db/dbconnection.php';
	
   
      $query = "select * from geek  where Geek_Code NOT LIKE 'A%' order by Geek_Level desc ,Geek_Testcase desc,Geek_Time";
      $d1="College Name";
      $d2="Department Name";
$res = $con->query($query);  
    
     $query1 = "select * from alumni where Geek_Rollno NOT LIKE '13%' order by Geek_Level desc ,Geek_Testcase desc,Geek_Time ";
      $f1="Rollno";
      $f2="Name";
$res2 = $con->query($query1);   
    
   


?>
<!DOCTYPE html>
<html>
<head>  
  <meta charset="utf-8">
  <meta http-equiv="X-UA-Compatible" content="IE=edge,chrome=1">
  <title>PROGEEKS</title>
  <meta name="description" content="">
  <meta name="viewport" content="width=device-width, initial-scale=1">
  <link rel="stylesheet" href="../css/bootstrap.min.css">         
  <link rel="stylesheet" href="../css/main.css">
  <link rel="icon" type="img/png" href="../img/logo.png"></link>
  <style>
  </style>
</head>
<body >
     <div class="myrow" style="overflow:scroll;">
	<div class="col-lg-12">            
            <div class="bs-component">	    
	       <h3> Participate Status</h3>
              <table class="table table-striped table-hover ">
                <thead>
                  <tr class="warning" style="">
                    <th>#</th>
                    <th><?php echo $d1; ?></th>
                    <th><?php echo $d2; ?></th>
                    <th>Level</th>
			<th>Testcases</th>
			<th>Time</th>
                  </tr>
		
                </thead>
		
		<?php
		$count=1;$str="";$total =1;
		while ($row = $res->fetch_assoc()) 
		{
		    
			$d1=$row['Geek_College'];
			$d2=$row['Geek_Department'];
		   
		   
		      if($count==1){
			echo "<tr><td><img src = 1st.png width=20px height=20px></td><td>";
			$count++;
		      }
		      else if($count == 2){
			echo "<tr><td><img src = 2nd.png width=20px height=20px></td><td>";
			$count++;
		      }
		      else
			echo "<tr><td>".$count++."</td><td>";
			echo $d1."</td><td>".$d2."</td><td>".$row['Geek_Level']."</td><td>".$row['Geek_Testcase']."</td><td>".$row['Geek_Time']."</td></tr>";    
		    
		    
 			  $str ="<tr><td bgcolor=#B8B8E6>".$total."</td><td bgcolor=#B8B8E6>".$d1."</td><td bgcolor=#B8B8E6>".$d2."</td><td bgcolor=#B8B8E6>".$row['Geek_Level']."</td></tr>"; 
		    
		    $total++;
		}		
		?>	
              </table > 
	      

	    <h3> Alumni Status</h3>
	    <table class="table table-striped table-hover ">
                <thead>
                  <tr class="warning" style="">
                    <th>#</th>
                    <th><?php echo $f1; ?></th>
                    <th><?php echo $f2; ?></th>
                    <th>Level</th>
			<th>Testcases</th>
			<th>Time</th>
                  </tr>
		
                </thead>
		
		<?php
		$count=1;$str="";$total =1;
		while ($row4 = $res2->fetch_assoc()) 
		{
		   
		    
			$d1=$row4['Geek_Rollno'];
			$d2=$row4['Geek_Name'];
		   
		    
		      if($count==1){
			echo "<tr><td><img src = 1st.png width=20px height=20px></td><td>";
			$count++;
		      }
		      else if($count == 2){
			echo "<tr><td><img src = 2nd.png width=20px height=20px></td><td>";
			$count++;
		      }
		      else
			echo "<tr><td>".$count++."</td><td>";
			echo $d1."</td><td>".$d2."</td><td>".$row4['Geek_Level']."</td><td>".$row4['Geek_Testcase']."</td><td>".$row4['Geek_Time']."</td></tr>";    
		   
		    
 			  $str ="<tr><td bgcolor=#B8B8E6>".$total."</td><td bgcolor=#B8B8E6>".$d1."</td><td bgcolor=#B8B8E6>".$d2."</td><td bgcolor=#B8B8E6>".$row4['Geek_Level']."</td></tr>"; 
		    
		    $total++;
		}		
		?>	
              </table > 
          </div>
      </div>
	<script src="//ajax.googleapis.com/ajax/libs/jquery/1.11.2/jquery.min.js"></script>
        <script>window.jQuery || document.write('<script src="../js/vendor/jquery-1.11.2.min.js"><\/script>')</script>
        <script src="../js/vendor/bootstrap.min.js"></script>
        <script src="../js/plugins.js"></script>
        <script src="../js/modernizr.js"></script>
</body>
</html>