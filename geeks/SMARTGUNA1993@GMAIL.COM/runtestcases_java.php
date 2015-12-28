<?php
session_start();
include '../../db/dbconnection.php';
$query = "SELECT * FROM geek where Geek_Email='".$_SESSION['progeeks_uid']."' ";
	$res1= $con->query($query);
	$row1 = $res1->fetch_assoc();
$query = "SELECT * FROM question where Question_Id=".$row1['Geek_Level'];
$res = $con->query($query);
$row = $res->fetch_assoc();
$data=$_POST["txt1"];
$data=trim($data);
if($data=='')
{
}	
else{
$endtype = ".java";
$fname = $row['Question_Name'].$endtype;
file_put_contents($fname,$data);
$error=shell_exec("javac ".$fname." 2>&1");
if($error==''){
	echo "<pre><h4>TestCase Status</h4>";
	$infile = "../../temp/".$row['Question_Name']."/testinput1.txt";
	
	$outfile =  "originaloutput.txt";
	$myoutfile = "../../temp/".$row['Question_Name']."/testoutput1.txt";
	$in1="";
	$in2="";
	echo(shell_exec("timeout --signal=SIGKILL 1 java ".$row['Question_Name']."< ".$infile." >".$outfile));
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
		{
}
	else
	unlink($outfile);
	echo "</pre>";
}
else{
	$sp = "geeks/".$_SESSION['progeeks_uid'];
	$result=split($sp,$error);
	$size=sizeof($result);
	for($i=0;$i<$size;$i++)
	{
		
	}
	
	
}
}
?>
<?php
if(isset($_POST['txt1'])){	
	$query = "SELECT * FROM geek where Geek_Email='".$_SESSION['progeeks_uid']."' ";
	$res1 = $con->query($query);
	$row1 = $res1->fetch_assoc();
	$query = "SELECT * FROM question where Question_Id=".$row1['Geek_Level']." ";
	$res = $con->query($query);
	$row = $res->fetch_assoc();
	$data=$_POST['txt1'];
	$data=trim($data);	
	if($data=='')
		echo "Enter Somthing";
	else{
		$endtype = ".java";
		$fname = $row['Question_Name'].$endtype;
		file_put_contents($fname,$data);
		$outfile = "originaloutput.txt";
		$num = 1;
		$input = 'Question_I'.$num;
		$output = 'Question_O'.$num;
		$count=0;
		echo "<pre>";
		while( $num <=10 &&$row[$input] != NULL && $row[$output] != NULL){
			

			$error=shell_exec("javac ".$fname."2>&1");
			$outfile =  "originaloutput.txt";
			$infile = "../../temp/".$row['Question_Name']."/".$row[$input];
			$myoutfile = "../../temp/".$row['Question_Name']."/".$row[$output];			
			echo(shell_exec("timeout --signal=SIGKILL 1s java ".$row['Question_Name']."< ".$infile." >".$outfile." 2>&1"));
			$old=file_get_contents($outfile);
			$n=file_get_contents($myoutfile);
			$lines1 = explode("\n", $old);
			$in1="";
			$in2="";
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
			if($in1==$in2){
				$img ='<img src="img/right.png" width="20px" height="20px">';
				echo "<h4><font color=black>Test Case #".$num." ".$img."</font></h4>";
				$count++;
			}
			else{
				$img ='<img src="img/wrong.png" width="20px" height="20px">';
				echo "<h4><font color=black>Test Case #".$num." ".$img."</font></h4>";				
			}
					
			$num++;
			$input = 'Question_I'.$num;
			$output = 'Question_O'.$num;
			if($count>$row1['Geek_Testcase'])
			{
			$query="update geek set Geek_Testcase=".$count.",Geek_Time='".date('Y-m-d H:i:s',time())."' where Geek_Email='".$_SESSION['progeeks_uid']."'";
			$res1 = $con->query($query);
			}
			unlink($outfile);
			
		}
		echo "</pre>";
		if($count == 10){
			$query = "SELECT Geek_Level FROM geek where Geek_Email='".$_SESSION['progeeks_uid']."' and Geek_Level='".$row['Question_Id']."'";
			$res1 = $con->query($query);
			if($row1 = $res1->fetch_assoc())
			{
				
				$query="update geek set Geek_Level=Geek_Level+1,Geek_Testcase=0,Geek_Time='".date('Y-m-d H:i:s',time())."' where Geek_Email='".$_SESSION['progeeks_uid']."'";
					$res1 = $con->query($query);
					$query = "SELECT Question_Name,Question_Compiler FROM question where question_Id=".$row['Question_Id']."+ 1";
					$res1 = $con->query($query);
					if(mysqli_num_rows($res1) >= 1){
					$row1 = mysqli_fetch_assoc($res1);
					$file =$row1['Question_Name'].'.cpp';
					$fileplace = $file;
					fopen($fileplace,'w');
					$data="#include<iostream> 
using namespace std;
int main()
{
	/*Code Here*/
	return 0;
}";				
					file_put_contents($fileplace,$data);
					$_SESSION['Progeeks_Compiler']="c++Compiler.php";
					$_SESSION['Progeeks_Submit']="runtestcases.php";
					}else{
					    echo "Nothing";
					}				
					
			}
			
		}
	}	
}
else{
	echo "Fail";
}
?>