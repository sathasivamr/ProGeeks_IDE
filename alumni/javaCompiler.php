<?php
session_start();
include '../../db/dbconnection.php';
$query = "SELECT Geek_Level FROM alumni where Geek_Email='".$_SESSION['progeeks_uid']."' ";
	$res1= $con->query($query);
	$row1 = $res1->fetch_assoc();
$query = "SELECT * FROM question where Question_Id=".$row1['Geek_Level'];
$res = $con->query($query);
$row = $res->fetch_assoc();
$data=$_POST["code"];
$data=trim($data);
if($data=='')
	echo "Enter Somthing";
else{
$endtype = ".java";
$fname = $row['Question_Name'].$endtype;
file_put_contents($fname,$data);
$error=shell_exec("javac ".$fname." 2>&1");
if($error==''){
	echo "<pre>";
	$infile = "../../temp/".$row['Question_Name']."/testinput1.txt";
	$outfile =  "originaloutput.txt";
	$myoutfile = "../../temp/".$row['Question_Name']."/testoutput1.txt";
	$in1="";
	$in2="";
	echo(shell_exec("timeout --signal=SIGKILL 2 java " .$row['Question_Name']."< ".$infile." >".$outfile));
	$old=file_get_contents($outfile);
	$n=file_get_contents($myoutfile);
	$lines1 = explode("\n", $old);
	foreach($lines1 as $line1){
	$line1 = trim($line1);
	$in1=$in1.$line1;
	}
	$lines2 = explode("\n", $n);
	foreach($lines2 as $line2)
	{
	$line2 = trim($line2);
	$in2=$in2.$line2;
	}
	$old=rtrim($old);
	$n=rtrim($n);
	if($in1==$in2)
		echo "<h4><font color=green>Success , you pass this test case</font></h4><pre><strong>Expected Output:</strong><br>".$n."</pre><pre><strong>Your Output:</strong><br/>".$old."</pre>";
	else
		echo "<h4><font color=red>Nice try, but you did not pass this test case</font></h4><pre><strong>Expected Output:</strong><br>".$n."</pre><pre><strong>Your Output:</strong><br/>".$old."</pre>";
	unlink($outfile);
	echo "</pre>";	
}
else{
	echo "<h4><font color=red>Compilation Error<br/></font></h4><pre>";
	$sp = "\^";
	$result=split($sp,$error);
	$size=sizeof($result);
	for($i=0;$i<$size;$i++)
	{
		echo "<p>".$result[$i]."</p>";
	}
	
	echo "</pre>";
	
}
}
?>