<?php

include 'db/dbconnection.php';
?>
<?php


session_start();
$_SESSION['ses_auth']=1;
	 	if(isset($_SESSION['ses_auth'])){

		 	$_SESSION['progeeks_whois'] = "ALU";
	 		$_SESSION['progeeks_email'] = "fdgfdg";
	 		$_SESSION['progeeks_phone'] = "9655";

	 		if($_SESSION['progeeks_whois'] == 'PAR'){
		 		$_SESSION['progeeks_code'] ="1223";
		 		$_SESSION['progeeks_college_name'] = "aasd college";
		 		$_SESSION['progeeks_department_name'] = "MCA";
	 		}else{
		 		$_SESSION['progeeks_alumni_rollno'] = "13mx16";
	            $_SESSION['progeeks_alumni_name'] =  "gow1";
	        }
	        }


$_SESSION["progeeks_uid"] = $_SESSION['progeeks_email'];
if(isset($_SESSION["progeeks_uid"]) && $_SESSION["progeeks_uid"] !=NULL)
{	
	$email=$_SESSION["progeeks_uid"];
	$query = "SELECT Geek_Email FROM geek where Geek_Email='$email' ";
	$res = $con->query($query);

	if ($row = $res->fetch_assoc()) 
	{
		header("Location: play.php");
		$_SESSION['Progeeks_Compiler']="c++Compiler.php";
		$_SESSION['Progeeks_Submit']="runtestcases.php";
	}
	else
	{
	  if($_SESSION['progeeks_whois']=='PAR')
	  {
		$code=$_SESSION['progeeks_code'];
		$college=$_SESSION['progeeks_college_name'];
		$department=$_SESSION['progeeks_department_name'];
		$phone=$_SESSION['progeeks_phone'];
		mysqli_query($con,"INSERT INTO geek (Geek_Email,Geek_College,Geek_Department,Geek_Phone,Geek_Code) VALUES ('$email','$college','$department','$phone','$code')");
		$dir1 = 'geeks/'.$email;
		$_SESSION['Progeeks_Compiler']="c++Compiler.php";
		$_SESSION['Progeeks_Submit']="runtestcases.php";
		if (!is_dir($dir1)){ mkdir($dir1, 0777);
		$file = 'factorial.cpp';
		 fopen("geeks/".$email."/" .$file, 'w');
		 $data="#include<iostream> 
using namespace std;
int main()
{
	/*Code Here*/
	return 0;
}";
		 file_put_contents("geeks/".$email."/" .$file,$data);

		$file = 'c++Compiler.php';
		 fopen("geeks/".$email."/" .$file, 'w');
		$data = file_get_contents("geeks/c++Compiler.php");
		file_put_contents("geeks/".$email."/" .$file,$data);
		
		$file = 'runtestcases.php';
		 fopen("geeks/".$email."/" .$file, 'w');
		$data = file_get_contents("geeks/runtestcases.php");
		file_put_contents("geeks/".$email."/" .$file,$data);

		$file = 'javaCompiler.php';
		 fopen("geeks/".$email."/" .$file, 'w');
		$data = file_get_contents("geeks/javaCompiler.php");
		file_put_contents("geeks/".$email."/" .$file,$data);
		
		$file = 'runtestcases_java.php';
		fopen("geeks/".$email."/" .$file, 'w');
		$data = file_get_contents("geeks/runtestcases_java.php");
		file_put_contents("geeks/".$email."/" .$file,$data);

		
		 } 
		
	      }
	else
	  {
		$rollno=$_SESSION['progeeks_alumni_rollno'];
		$name= $_SESSION['progeeks_alumni_name'];
		$phone=$_SESSION['progeeks_phone'];
		mysqli_query($con,"INSERT INTO alumni (Geek_Rollno,Geek_Email,Geek_Name,Geek_Phone) VALUES ('$rollno','$email','$name','$phone')");
		$dir1 = 'alumni/'.$email;
		$_SESSION['Progeeks_Compiler']="c++Compiler.php";
		$_SESSION['Progeeks_Submit']="runtestcases.php";
		if (!is_dir($dir1)){ mkdir($dir1, 0777);
		$file = 'factorial.cpp';
		 fopen("alumni/".$email."/" .$file, 'w');
		 $data="#include<iostream> 
using namespace std;
int main()
{
	/*Code Here*/
	return 0;
}";
		 file_put_contents("alumni/".$email."/" .$file,$data);

		$file = 'c++Compiler.php';
		 fopen("alumni/".$email."/" .$file, 'w');
		$data = file_get_contents("alumni/c++Compiler.php");
		file_put_contents("alumni/".$email."/" .$file,$data);
		
		$file = 'runtestcases.php';
		 fopen("alumni/".$email."/" .$file, 'w');
		$data = file_get_contents("alumni/runtestcases.php");
		file_put_contents("alumni/".$email."/" .$file,$data);

		$file = 'javaCompiler.php';
		 fopen("alumni/".$email."/" .$file, 'w');
		$data = file_get_contents("alumni/javaCompiler.php");
		file_put_contents("alumni/".$email."/" .$file,$data);
		
		$file = 'runtestcases_java.php';
		fopen("alumni/".$email."/" .$file, 'w');
		$data = file_get_contents("alumni/runtestcases_java.php");
		file_put_contents("alumni/".$email."/" .$file,$data);

		
		 } 
		
	      }
		
	header("Location: play.php");
	}
}
else
{
	header("Location: //accounts.psglogin.in/");
}


?>
