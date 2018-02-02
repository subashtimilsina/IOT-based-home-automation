<!DOCTYPE html>
<html lang="en">
  <head>
    <meta charset="utf-8">
    <meta name="viewport" content="width=device-width, initial-scale=1, shrink-to-fit=no">
    <meta name="description" content="">
    <meta name="author" content="">
    <title>HOME AUTOMATION</title>
    <!-- Bootstrap core CSS -->
    <link href="bootstrap.min.css" rel="stylesheet">
    <!-- Custom fonts for this template -->
    <link rel="stylesheet" href="font-awesome.min.css">
    <link rel="stylesheet" href="simple-line-icons.css">
    <link href="https://fonts.googleapis.com/css?family=Lato" rel="stylesheet">
    <link href="https://fonts.googleapis.com/css?family=Catamaran:100,200,300,400,500,600,700,800,900" rel="stylesheet">
    <link href="https://fonts.googleapis.com/css?family=Muli" rel="stylesheet">
    <!-- Plugin CSS -->
    <link rel="stylesheet" href="device-mockups.min.css">
    <!-- Custom styles for this template -->
    <link href="new-age.min.css" rel="stylesheet">

<script>
	<?php
$Data1=$_GET["data1"];
$Data2=$_GET["data2"];
$Data3=$_GET["data3"];
$Data4=$_GET["data4"];
$Data5=$_GET["data5"];
$Data6=$_GET["data6"];
echo "var x=$Data1; 
var y =$Data2; var z=$Data3; var a=$Data4; var b=$Data5; var c=$Data6;";
?>
	function submit1()
	{
		if(x==1)
		{x=0;}
		else
		{x=1;}
		window.location='button.php?data1='+x+'&data2='+y+'&data3='+z+'&data4='+a+'&data5='+b+'&data6='+c+'#features';
	}
	
	function submit2()
	{
		if(y==1)
		{y=0;}
		else
		{y=1;}
		window.location='button.php?data1='+x+'&data2='+y+'&data3='+z+'&data4='+a+'&data5='+b+'&data6='+c+'#features';
	}

  function submit3()
	{
		if(z==1)
		{z=0;}
		else
		{z=1;}
    window.location='button.php?data1='+x+'&data2='+y+'&data3='+z+'&data4='+a+'&data5='+b+'&data6='+c+'#features';
	}

  function submit4()
	{
		if(a==1)
		{a=0;}
		else
		{a=1;}
		window.location='button.php?data1='+x+'&data2='+y+'&data3='+z+'&data4='+a+'&data5='+b+'&data6='+c+'#features';
	}

  function submit5()
	{
		if(b==1)
		{b=0;}
		else
		{b=1;}
		window.location='button.php?data1='+x+'&data2='+y+'&data3='+z+'&data4='+a+'&data5='+b+'&data6='+c+'#features';
	}

  function submit6()
	{
		if(c==1)
		{c=0;}
		else
		{c=1;}
		window.location='button.php?data1='+x+'&data2='+y+'&data3='+z+'&data4='+a+'&data5='+b+'&data6='+c+'#features';
	}

  
</script>

  </head>

  <body id="page-top">

    <!-- Navigation -->
    <nav class="navbar navbar-expand-lg navbar-light fixed-top" id="mainNav">
      <div class="container">
        <a class="navbar-brand js-scroll-trigger" href="#page-top">Home Automation</a>
      </div>
    </nav>

    <header class="masthead">
      <div class="container h-100">
        <div class="row h-100">
          <div class="col-lg-7 my-auto">
            <div class="header-content mx-auto">
              <h1 class="mb-5">Home Automation<br>Say hello to the future</h1>
              <a href="#download" class="btn btn-outline btn-xl js-scroll-trigger">Automate Now!</a>
            </div>
          </div>
          <div class="col-lg-5 my-auto">
            <div class="device-container">
              <div class="device-mockup iphone6_plus portrait white">
                <div class="device">
                  <div class="screen">
                    <!-- Demo image for screen mockup, you can put an image here, some HTML, an animation, video, or anything else! -->
                    <img src="" class="img-fluid" alt="">
                  </div>
                  <div class="button">
                    <!-- You can hook the "home button" to some JavaScript events or just remove it -->
                  </div>
                </div>
              </div>
            </div>
          </div>
        </div>
      </div>
    </header>

    <section class="download bg-primary text-center" id="download">
      <div class="container">
        <div class="row">
          <div class="col-md-8 mx-auto">
            <h2 class="section-heading">A new way to explore the world</h2>
          </div>
        </div>
      </div>
    </section>

    <section class="features bg-danger" id="">
      <div class="container">
        <div class="section-heading text-center">
          <h2>Wireless, efortless and magical</h2>
        </div>
      </div>
    </section>

    <section class="features" id="features">
        <div class="container">
          <div class="section-heading text-center">
            <h2>Automating.....</h2>
            <hr>
          </div>
          

		  <div class="row">
            <div class="col-lg-12 my-auto">
              <div class="container-fluid">
                <div class="row">
                  <div class="col-lg-6">
                    <div class="feature-item">
                      <button id="12" class="led" onclick = "submit1();" value = "LAMP" style = "border-radius:15px; width:300px; height: 100px; background-color:<?php
if($Data1==0)
	echo "RED";
else
	echo "GREEN";
?>;"><h1 style = "color:white">FAN</h1></button>
                    </div>
                  </div>
                  <div class="col-lg-6">
                    <div class="feature-item">
<button id="13" class="led" onclick = "submit2();" value = "FAN" style = "border-radius:15px; width:300px; height: 100px; background-color: <?php
if($Data2==0)
	echo "RED";
else
	echo "GREEN";
?> ;"><h1 style = "color:white">LAMP</h1></button>
                    </div>
                  </div>
                </div>
                <div class="row">
                  <div class="col-lg-6">
                    <div class="feature-item">
                    <button id="14" class="led" onclick = "submit3();" value = "TV" style = "border-radius:15px; width:300px; height: 100px; background-color:<?php
                    if($Data3==0)
                      echo "RED";
                    else
                      echo "GREEN";
                    ?>;"><h1 style = "color:white">TV</h1></button>
                                        </div>
                  </div>
                  <div class="col-lg-6">
                    <div class="feature-item">
                    <button id="15" class="led" onclick = "submit4();" value = "MOTOR" style = "border-radius:15px; width:300px; height: 100px; background-color:<?php
                    if($Data4==0)
                      echo "RED";
                    else
                      echo "GREEN";
                    ?>;"><h1 style = "color:white">MOTOR</h1></button>
                                        </div>
                  </div>
                  <div class="col-lg-6">
                        <div class="feature-item">
                        <button id="16" class="led" onclick = "submit5();" value = "CHARGING_PORT" style = "border-radius:15px; width:300px; height: 100px; background-color:<?php
                        if($Data5==0)
                          echo "RED";
                        else
                          echo "GREEN";
                        ?>;"><h1 style = "color:white">CHARGING PORT</h1></button>
                                                </div>
                      </div>
                      <div class="col-lg-6">
                            <div class="feature-item">
                            <button id="17" class="led" onclick = "submit6();" value = "SOUND_SYSTEM" style = "border-radius:15px; width:300px; height: 100px; background-color:<?php
                            if($Data6==0)
                              echo "RED";
                            else
                              echo "GREEN";
                            ?>;"><h1 style = "color:white">SOUND SYSTEM</h1></button>
                                                        </div>
                          </div>
                </div>
              </div>
            </div>
          </div>
        </div>
      </section>
    <section class="contact bg-primary" id="contact">
      <div class="container">
        <h2>Contact us!! at 9846778497</h2>
      </div>
    </section>

    <footer>
      <div class="container">
        <p>&copy; Home Automation. All Rights Reserved.</p>
        <ul class="list-inline">
          <li class="list-inline-item">
            <a href="#">Privacy</a>
          </li>
          <li class="list-inline-item">
            <a href="#">Terms</a>
          </li>
          <li class="list-inline-item">
            <a href="#">FAQ</a>
          </li>
        </ul>
      </div>
    </footer>

    <!-- Bootstrap core JavaScript -->
    <script src="jquery.min.js"></script>
    <script src="bootstrap.bundle.min.js"></script>

    <!-- Plugin JavaScript -->
    <script src="jquery.easing.min.js"></script>

    <!-- Custom scripts for this template -->
    <script src="new-age.min.js"></script>
	<script type="text/javascript">
$(document).ready(function(){
  $(".led").click(function(){
    var p = $(this).attr('id');                                                               
    $.get("http://192.168.137.154:80/", {pin:p}); 
  });
});
</script>

  </body>

</html>
