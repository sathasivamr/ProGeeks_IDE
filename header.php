

<nav class="navbar navbar-default" style="background:#4183D7">
  <div class="container-fluid">
    <div class="navbar-header" style="margin-top: -7px;">
      <button type="button" class="navbar-toggle collapsed" data-toggle="collapse" data-target="#bs-example-navbar-collapse-1">
        <span class="sr-only">Toggle navigation</span>
        <span class="icon-bar"></span>
        <span class="icon-bar"></span>
        <span class="icon-bar"></span>
      </button>
      <div class="navbar-brand"><b style="color:#000"><img src="img/logo.png" width="40px" height="40px"></link>PROGEEKS</b></div>
    </div>

    <div class="collapse navbar-collapse" id="bs-example-navbar-collapse-1">

      <ul class="nav navbar-nav navbar-right">
         <li class="active"><a >Level - <?php echo $row4['Question_Id'];?> <span class="sr-only">(current)</span></a></li>
          <li class="dropdown">
              <a href="#" class="dropdown-toggle" data-toggle="dropdown" role="button" aria-expanded="false"><?php if(isset($_SESSION["progeeks_uid"])){ $Name = split("@",$_SESSION['progeeks_uid']);echo $Name[0];} else echo "Email_id_Not_assigned"; ?><span class="caret"></span></a>
              <ul class="dropdown-menu" role="menu">
		   <li><a href="play.php">Play</a></li>
                  <li><a href="leaderboard.php">Leader Board</a></li>
		    <li><a href="instructions.php">Instructions</a></li>                  
                  <li class="divider"></li>
                  <li><a href="logout.php">Sign Out</a></li>
              </ul>
          </li>
      </ul>
    </div>
  </div>
</nav>

