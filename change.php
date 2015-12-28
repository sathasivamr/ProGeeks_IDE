<?php
session_start();
include 'db/dbconnection.php';

if(isset($_SESSION["progeeks_uid"]) && $_SESSION["progeeks_uid"] !=NULL)
{	
	$email=$_SESSION["progeeks_uid"];
	if($_SESSION['progeeks_whois'] == 'PAR')
	{
		$query = "SELECT * FROM question where Question_Id=(select Geek_Level from geek where Geek_Email='$email') ";
		$url="geeks/".$email."/";
	}
	else
	{
		$query = "SELECT * FROM question where Question_Id=(select Geek_Level from alumni where Geek_Email='$email') ";
		$url="alumni/".$email."/";
	}
	$res = $con->query($query);
	$row=$res->fetch_assoc();
	if ($_SESSION['Progeeks_Compiler']=="c++Compiler.php") 
	{
		$file = $row['Question_Name'].".java";
		if (file_exists($url.$file))
		{

			$_SESSION['Progeeks_Compiler']="javaCompiler.php";
			$_SESSION['Progeeks_Submit']="runtestcases_java.php";
		}
		else
		{
			$_SESSION['Progeeks_Compiler']="javaCompiler.php";
			$_SESSION['Progeeks_Submit']="runtestcases_java.php";
			$res1 = $con->query($query);
			$file = $row['Question_Name'].".java";
		 	fopen($url.$file, 'w');
			 $data="import java.util.*;		
class ".$row['Question_Name']."
{
	public static void main(String... args)
	{
		//Insert Your Code			
	}
}"
;
			file_put_contents($url .$file,$data);	
		}
	}
	else
	{
		$file = $row['Question_Name'].".cpp";
		if (file_exists($url.$file))
		{
			
			$_SESSION['Progeeks_Compiler']="c++Compiler.php";
			$_SESSION['Progeeks_Submit']="runtestcases.php";
		}
		else
		{
			$_SESSION['Progeeks_Compiler']="c++Compiler.php";
			$_SESSION['Progeeks_Submit']="runtestcases.php";
			$file = $row['Question_Name'].".cpp";
		 	fopen($url.$file, 'w');
			 $data="#include<iostream> 
using namespace std;
int main()
	{
		/*Code Here*/
		return 0;
	}";
			file_put_contents($url.$file,$data);	
		}
		
	}

}
header("Location: play.php");
?>
