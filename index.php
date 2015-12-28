
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

    .home_bg{
      background:url(img/bg/bg.png)no-repeat center;
      width:100%;
      height:100%;
    }

    .btn{
      text-decoration: none;
      color: #4183D7 ;
      background: #fff;
      padding: 6px 20px;
      margin-top: 350px;
      display: inline-block;
      font-size: 140%;
      transition: 0.4s all;
    }

    .btn:hover{
        text-decoration: none;
         padding: 6px 40px;
    }

  </style>
</head>
<body class="home_bg">
 <!--div class="well bs-component">
    <!--fieldset style="font-size:20pt;">
      PROGEEKS       
    </fieldset> 
   </div-->  
   <div style="background:url(img/bg/text_logo.png)no-repeat; margin-top:3%; background-size:200px; width:180px; height:100px"></div>
   <center>
	     <div  style="background:url(img/bg/logo.png) no-repeat center; background-size:250px; margin-top:5%; width:100%; height:250px"/>
		 <form action="login.php" method="post">
       <input type="submit" value="LOGIN" class="btn">
	<input type="email" class="form-control" id="inputEmail" name="email" placeholder="Email" required="">
    </form>
	</center>   
</body>
</html>