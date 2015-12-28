
<?php
include 'db/dbconnection.php';
session_start();
$_SESSION['ses_auth']=1;
if(isset($_SESSION['ses_auth'])){
	$_SESSION['progeeks_whois'] = "ALU";
	$_SESSION['progeeks_email'] = $_POST['email'];
	$_SESSION['progeeks_phone'] = "9655010440";
	$_SESSION["progeeks_uid"] = $_POST['email'];
	if($_SESSION['progeeks_whois'] == 'PAR'){
		$_SESSION['progeeks_code'] = $_SESSION['ses_cCode'];
		$_SESSION['progeeks_college_name'] = $_SESSION['ses_college_name'];
		$_SESSION['progeeks_department_name'] = $_SESSION['ses_dept_name'];
	}else{
		$_SESSION['progeeks_alumni_rollno'] =$_POST['email'];
    	$_SESSION['progeeks_alumni_name'] =  "Progeeks_team";
	}

	$_SESSION['progeeks_session'] = rand(1111,9999);
	if(mysqli_num_rows(mysqli_query($con,'select * from psg_access where email="'.$_SESSION['progeeks_email'].'"'))==1)
	    mysqli_query($con,'update psg_access set session="'. $_SESSION['progeeks_session'].'" where email="'.$_SESSION['progeeks_email'].'"');
	else
	    mysqli_query($con,'insert into psg_access values("'.$_SESSION['progeeks_email'].'","'. $_SESSION['progeeks_session'].'")');


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

	if($_SESSION['progeeks_whois'] == 'PAR')
	{
	  $query = "SELECT * FROM question where Question_Id=1 ";
	}
	else
	{
	   $query = "SELECT * FROM question where Question_Id=1 ";
	}	
	$res4 = $con->query($query);
	if ($row4= $res4->fetch_assoc()) 
	{
		
	}
	else
	{
		header("Location: 404.php");
	}
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
		
		$file = $row4['Question_Name'].'.cpp';
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
		$file = $row4['Question_Name'].'.cpp';
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
}
else
{
	header("LOCATION: //accounts.psglogin.in/index.php?r=progeeks");
}
?>
