
<?php
session_start();
include 'db/dbconnection.php';
if(isset($_SESSION["progeeks_uid"]) && $_SESSION["progeeks_uid"] !=NULL)
{	
	$email=$_SESSION["progeeks_uid"];
	if($_SESSION['progeeks_whois'] == 'PAR'){
	$query = "SELECT Geek_Email FROM geek where Geek_Email='$email' ";
	}
	else
	{
	  $query = "SELECT Geek_Email FROM alumni where Geek_Email='$email' ";
	}
	$res = $con->query($query);

	if ($row = $res->fetch_assoc()) 
	{
		if($_SESSION['progeeks_whois'] == 'PAR')
		{
		  $query = "SELECT Geek_level FROM geek where Geek_Email='$email' ";
		}
		else
		{
		  $query = "SELECT Geek_level FROM alumni where Geek_Email='$email' ";
		}
		$res = $con->query($query);
		$row1=$res->fetch_assoc();
		$qid=$row1['Geek_level'];
		$query = "SELECT * FROM question where Question_Id='$qid' ";
		$res = $con->query($query);
		$row2=$res->fetch_assoc();
	}
	else
	{
		
		header("Location: index.php");
	}
}
else
{
	header("Location: //accounts.psglogin.in/");
}
?>
<?php
if(isset($_SESSION["progeeks_uid"]) && $_SESSION["progeeks_uid"] !=NULL)
{
	if($_SESSION['progeeks_whois'] == 'PAR')
	{
	  $query = "SELECT * FROM question where Question_Id=(select Geek_Level from geek where Geek_Email='$email') ";
	}
	else
	{
	   $query = "SELECT * FROM question where Question_Id=(select Geek_Level from alumni where Geek_Email='$email') ";
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
<html class="no-js" lang=""> <!--<![endif]-->
    <head>
        <meta charset="utf-8">
        <meta http-equiv="X-UA-Compatible" content="IE=edge,chrome=1">
        <title>PROGEEKS</title>
        <meta name="description" content="">
        <meta name="viewport" content="width=device-width, initial-scale=1">
        <link rel="stylesheet" href="lib/codemirror.css">
        <link rel="stylesheet" href="addon/hint/show-hint.css">
        <link rel="stylesheet" href="css/bootstrap.min.css">         
        <link rel="stylesheet" href="css/main.css">
	<link rel="icon" type="img/png" href="img/logo.png"></link>

        <!--[if lt IE 9]>
            <script src="js/vendor/html5-3.6-respond-1.4.2.min.js"></script>
        <![endif]-->
	<style>
        .cldate{
        	display: inline-block;
			margin-bottom: 0px;
			font-weight: normal;
			text-align: center;
			vertical-align: middle;			
			background-image: none;
			background:transparent;
			border: 1px solid transparent;
			white-space: nowrap;
			padding: 8px 12px;
			font-size: 14px;
			line-height: 1.42857;
			border-radius: 4px;
			-moz-user-select: none;
			color: #F61209;
        }
        </style>
    </head>
    <body >
        <?php include('header.php');?>

          <div class="myrow">

          <div class="mycol-1">
            <div class="wrapper">
              <div id="question" class="question">
                  <div class="page-header" style="margin-top:0;">
                      <h3 style="margin-top:0;"><?php echo strtoupper ($row4['Question_Name']);?></h3>
                  </div>
                  <div class="statement">
                     <h4><b>Problem Statement</b></h4>
                      <div class="content"><?php echo $row4['Question_Problem'];?>
                      </div>
                  </div>
                  <div class="constraint">
                      <h4><b>Constraint</b></h4>
                      <div class="content">
                        <?php echo $row4['Question_Range'];?>

                      </div>
                  </div>
                  <div class="input-format">
                      <h4><b>Input Format</b></h4>
                      <div class="content">
			<?php echo $row4['Question_Inputformat'];?>
                      </div>
                  </div>
                  <div class="output-format">
                       <h4><b>Output Format</b></h4>
                      <div class="content">
			<?php echo $row4['Question_Outputformat'];?>
                      </div>
                  </div>
                  <div class="sampleinput">
                       <h4><b>Sample Input</b></h4>
                      <div class="content">
			<?php echo $row4['Question_Input'];?>
                      </div>
                  </div>
                  <div class="sampleoutput">
                       <h4><b>Sample Output</b></h4>
                      <div class="content">
                       <?php echo $row4['Question_Output'];?>
                      </div>
                  </div>
                  <div class="explanation">
                       <h4><b>Explanation</b></h4>
                      <div class="content">
                        <?php echo $row4['Question_Explanation'];?>
                      </div>
                  </div>
              </div>


          </div>
          </div>
          <div class="mycol-1 noscroll">
              <div class="title" style="margin:10px 0;">

                      
                      <div class="btn-group ">
                      <button type="button" class="btn btn-danger dropdown-toggle" data-toggle="dropdown" aria-haspopup="true" aria-expanded="false">
                        <?php 
				$comp1="";
				
				if($_SESSION['Progeeks_Compiler']=="c++Compiler.php")
				{
				    $comp1= " C++  ";
				    $comp2=" Java  ";
				 }
				  else
				  {
				    $comp1= " Java  ";
				    $comp2=" C++  ";
				  }?> 
			<?php echo $comp1;?><span class="caret"></span>
                      </button>
                      <ul class="dropdown-menu">
                        <li><a href="change.php"><?php echo $comp2;?></a></li>
                      </ul>
			
                    </div>
                 <div style="float:right">
			<button class="btn btn-info" type="button"  id="run" data-toggle="modal" data-target="#myModal">RUN</button>                     
                     <input class="btn btn-success" type="button" value="SUBMIT" id="submitvalue" data-toggle="modal" data-target="#myModal"/>    
                 </div>
                <?php if($_SESSION['progeeks_whois'] == 'PAR')
		      {
			    $addr='geeks/'.$_SESSION['progeeks_uid'].'/'.$_SESSION['Progeeks_Compiler'];
		      }
		      else
		      {
			    $addr='alumni/'.$_SESSION['progeeks_uid'].'/'.$_SESSION['Progeeks_Compiler'];
		      }
  ?>
	      
              </div>
              <form action="<?php echo $addr; ?>" method="post" id="form" >		
                <textarea  id="code" name="code" onChange="input()" >
<?php 
if($_SESSION['progeeks_whois'] == 'PAR')
{
  $addr1="geeks/".$email."/".$row4['Question_Name'];
}
else
{
   $addr1="alumni/".$email."/".$row4['Question_Name'];
}
if($_SESSION['Progeeks_Compiler']=="c++Compiler.php")
{


echo file_get_contents($addr1.'.cpp');
}
else
{
echo file_get_contents($addr1.'.java');
}
 ?>
		</textarea>
              </form>
          </div>
			    <div class="modal fade" id="myModal" role="dialog" data-backdrop="false">
	    <div class="modal-dialog" style="z-index:9999;">
	    
	      <!-- Modal content-->
	     <div class="modal-content">
		<div class="modal-header">
		  <button type="button" class="close" data-dismiss="modal" onclick="window.location.reload();">&times;</button>
		  <h4 class="modal-title">Result</h4>
		</div>
		<div class="modal-body">
		  <div id="result" ><center><img src="img/loader.gif"width="320" height="240"/></center></div>
		  <div id="resulttestcases" ><center><img src="img/loader.gif"width="320" height="240"/></center></div>
		</div>
	<!--	<div class="modal-footer">
		  <button type="button" class="btn btn-default" data-dismiss="modal">Close</button>
		</div> -->
	      </div>
	      
	    </div>
	  </div> 
		

          </div>
	


        <script src="//ajax.googleapis.com/ajax/libs/jquery/1.11.2/jquery.min.js"></script>
        <script>window.jQuery || document.write('<script src="js/vendor/jquery-1.11.2.min.js"><\/script>')</script>
        <script src="js/vendor/bootstrap.min.js"></script>
        <script src="js/plugins.js"></script>
        <script src="js/modernizr.js"></script>        
        <script src="lib/codemirror.js"></script>
        <script src="addon/hint/show-hint.js"></script>
        <script src="addon/hint/javascript-hint.js"></script>
        <script src="mode/javascript/javascript.js"></script>
        <script src="addon/selection/active-line.js"></script>
        <script src="addon/edit/matchbrackets.js"></script>
        <script src="js/main.js"></script>
        <script>
        var editor = CodeMirror.fromTextArea(document.getElementById("code"), {
        lineNumbers: true,
        extraKeys: {"Ctrl-Space": "autocomplete"},
        mode: {name: "javascript", globalVars: true},   
        styleActiveLine: true,
        matchBrackets: true,
        onBlur:function()
        {
          editor.save();
        }
        });

        var input = document.getElementById("select");
        function selectTheme() 
        {
          var theme = input.options[input.selectedIndex].textContent;
          editor.setOption("theme", theme);
          location.hash = "#" + theme;
        }

        var choice = (location.hash && location.hash.slice(1)) || (document.location.search && decodeURIComponent(document.location.search.slice(1)));
        if (choice) 
        {
          input.value = choice;
          editor.setOption("theme", choice);
        }

        CodeMirror.on(window, "hashchange", function() {
          var theme = location.hash.slice(1);
          if (theme) 
          { 
            input.value = theme; selectTheme();
          }
        });
      </script>


</body>

	

<script type="text/javascript">
function reload(){
    window.location.reload();
}	
$(function()
{	
	
	function showCode(){
		var textCode = editor.getCode();
		
	}
	$("#run").click(function()
	{	
		editor.save();		
		var text1 = document.getElementById('code').value;		
			$.ajax({
			<?php  
			if($_SESSION['progeeks_whois'] == 'PAR')
			{
				$url="geeks/".$_SESSION['progeeks_uid']."/".$_SESSION['Progeeks_Compiler'];
			}
			else
			 {
				$url="alumni/".$_SESSION['progeeks_uid']."/".$_SESSION['Progeeks_Compiler'];
			 }?>
				type:"post",
				url:'<?php echo $url; ?>',
				data:{code:text1},
				success:function(response){				
				$("#result").html(response);
				}
			});
		$('#resulttestcases').hide();
		$('#result').show();	
	});
	$('#submitvalue').click(function()
	{		
		editor.save();
		var text1 = document.getElementById('code').value;
		$.ajax(
		{
			<?php  
			if($_SESSION['progeeks_whois'] == 'PAR')
			{
				$url1="geeks/".$_SESSION['progeeks_uid']."/".$_SESSION['Progeeks_Submit'];
			}
			else
			 {
				$url1="alumni/".$_SESSION['progeeks_uid']."/".$_SESSION['Progeeks_Submit'];
			 }?>
			type:"post",
			url: '<?php echo $url1;?>',
			data: {txt1:text1},
			success:function(result)
			{		
				$('#resulttestcases').html(result);
				
						
			}
		});		
		$('#result').hide();
		$('#resulttestcases').show();
		
	});
	
});
</script>

</html>
