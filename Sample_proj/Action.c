Action()
{

	lr_start_transaction("Sample_proj_01_LaunchURL");
	
	web_reg_find("Fail=NotFound",
		"Search=Headers",
		"Text=HTTP/1.1 200 OK",
		LAST);
	web_reg_find("Text=WebTours",
	             LAST);

	web_url("WebTours",
	        "URL=http://{pDomain}/WebTours/",
	        "TargetFrame=",
	        "Resource=0",
	        "RecContentType=text/html",
	        "Referer=",
	        "Snapshot=t1.inf",
	        "Mode=HTML",
	        LAST);
	
	lr_end_transaction("Sample_proj_01_LaunchURL", LR_AUTO);

	/* SignUp */

	lr_think_time(5);
	
	lr_start_transaction("Sample_proj_02_SignUp");

	web_url("sign up now",
	        "URL=http://{pDomain}/cgi-bin/login.pl?username=&password=&getInfo=true",
	        "TargetFrame=body",
	        "Resource=0",
	        "RecContentType=text/html",
	        "Referer=http://{pDomain}/WebTours/home.html",
	        "Snapshot=t2.inf",
	        "Mode=HTML",
	        LAST);
	
	lr_end_transaction("Sample_proj_02_SignUp", LR_AUTO);

	/* EnterDetails */

	lr_think_time(5);
	
	lr_start_transaction("Sample_proj_03_EnterDetails");

	web_url("Sites.xml",
	        "URL=http://clienteng.mhe.mhc:83/Sites.xml",
	        "TargetFrame=",
	        "Resource=0",
	        "RecContentType=text/xml",
	        "Referer=",
	        "Snapshot=t3.inf",
	        "Mode=HTML",
	        LAST);

	/* ClickContinue */

	lr_think_time(16);

	web_submit_data("login.pl",
	                "Action=http://{pDomain}/cgi-bin/login.pl",
	                "Method=POST",
	                "TargetFrame=",
	                "RecContentType=text/html",
	                "Referer=http://{pDomain}/cgi-bin/login.pl?username=&password=&getInfo=true",
	                "Snapshot=t4.inf",
	                "Mode=HTML",
	                ITEMDATA,
	                "Name=username", "Value={pUsername}", ENDITEM,
	                "Name=password", "Value={pPassword}", ENDITEM,
	                "Name=passwordConfirm", "Value={pPassword}", ENDITEM,
	                "Name=firstName", "Value={pUsername}", ENDITEM,
	                "Name=lastName", "Value={pLastname}", ENDITEM,
	                "Name=address1", "Value={pStreetName}", ENDITEM,
	                "Name=address2", "Value={pCity}", ENDITEM,
	                "Name=register.x", "Value=10", ENDITEM,
	                "Name=register.y", "Value=6", ENDITEM,
	                LAST);
	
	lr_end_transaction("Sample_proj_03_EnterDetails", LR_AUTO);


	/* ClickOnContinueAgain */

	lr_think_time(18);

	web_url("button_next.gif",
	        "URL=http://{pDomain}/cgi-bin/welcome.pl?page=menus",
	        "TargetFrame=body",
	        "Resource=0",
	        "RecContentType=text/html",
	        "Referer=http://{pDomain}/cgi-bin/login.pl",
	        "Snapshot=t5.inf",
	        "Mode=HTML",
	        LAST);

	/* ClickOnFlights */

	lr_think_time(12);

	web_url("Search Flights Button",
	        "URL=http://{pDomain}/cgi-bin/welcome.pl?page=search",
	        "TargetFrame=body",
	        "Resource=0",
	        "RecContentType=text/html",
	        "Referer=http://{pDomain}/cgi-bin/nav.pl?page=menu&in=home",
	        "Snapshot=t6.inf",
	        "Mode=HTML",
	        LAST);

	/* ClosePopupWindow */

	/* EnterFlightDetails */

	/* ClickContinueForFlightDetails */

	lr_think_time(66);

	web_submit_data("reservations.pl",
	                "Action=http://{pDomain}/cgi-bin/reservations.pl",
	                "Method=POST",
	                "TargetFrame=",
	                "RecContentType=text/html",
	                "Referer=http://{pDomain}/cgi-bin/reservations.pl?page=welcome",
	                "Snapshot=t7.inf",
	                "Mode=HTML",
	                ITEMDATA,
	                "Name=advanceDiscount", "Value=0", ENDITEM,
	                "Name=depart", "Value=San Francisco", ENDITEM,
	                "Name=departDate", "Value=12/06/2018", ENDITEM,
	                "Name=arrive", "Value=Zurich", ENDITEM,
	                "Name=returnDate", "Value=12/07/2018", ENDITEM,
	                "Name=numPassengers", "Value=2", ENDITEM,
	                "Name=roundtrip", "Value=on", ENDITEM,
	                "Name=seatPref", "Value=Aisle", ENDITEM,
	                "Name=seatType", "Value=Coach", ENDITEM,
	                "Name=.cgifields", "Value=roundtrip", ENDITEM,
	                "Name=.cgifields", "Value=seatType", ENDITEM,
	                "Name=.cgifields", "Value=seatPref", ENDITEM,
	                "Name=findFlights.x", "Value=69", ENDITEM,
	                "Name=findFlights.y", "Value=6", ENDITEM,
	                LAST);

	/* ClickOnContinueForFlightTimings */

	lr_think_time(79);

	web_submit_data("reservations.pl_2",
	                "Action=http://{pDomain}/cgi-bin/reservations.pl",
	                "Method=POST",
	                "TargetFrame=",
	                "RecContentType=text/html",
	                "Referer=http://{pDomain}/cgi-bin/reservations.pl",
	                "Snapshot=t8.inf",
	                "Mode=HTML",
	                ITEMDATA,
	                "Name=outboundFlight", "Value=690;376;12/06/2018", ENDITEM,
	                "Name=returnFlight", "Value=960;376;12/07/2018", ENDITEM,
	                "Name=numPassengers", "Value=2", ENDITEM,
	                "Name=advanceDiscount", "Value=0", ENDITEM,
	                "Name=seatType", "Value=Coach", ENDITEM,
	                "Name=seatPref", "Value=Aisle", ENDITEM,
	                "Name=reserveFlights.x", "Value=59", ENDITEM,
	                "Name=reserveFlights.y", "Value=9", ENDITEM,
	                LAST);

	/* ClickOnContinueForPaymentDetails */

	lr_think_time(22);

	web_submit_data("reservations.pl_3",
	                "Action=http://{pDomain}/cgi-bin/reservations.pl",
	                "Method=POST",
	                "TargetFrame=",
	                "RecContentType=text/html",
	                "Referer=http://{pDomain}/cgi-bin/reservations.pl",
	                "Snapshot=t9.inf",
	                "Mode=HTML",
	                ITEMDATA,
	                "Name=firstName", "Value={pUsername}", ENDITEM,
	                "Name=lastName", "Value={pLastname}", ENDITEM,
	                "Name=address1", "Value={pStreetName}", ENDITEM,
	                "Name=address2", "Value={pCity}", ENDITEM,
	                "Name=pass1", "Value={pUsername} {pLastname}", ENDITEM,
	                "Name=pass2", "Value=", ENDITEM,
	                "Name=creditCard", "Value=", ENDITEM,
	                "Name=expDate", "Value=", ENDITEM,
	                "Name=oldCCOption", "Value=", ENDITEM,
	                "Name=numPassengers", "Value=2", ENDITEM,
	                "Name=seatType", "Value=Coach", ENDITEM,
	                "Name=seatPref", "Value=Aisle", ENDITEM,
	                "Name=outboundFlight", "Value=690;376;12/06/2018", ENDITEM,
	                "Name=advanceDiscount", "Value=0", ENDITEM,
	                "Name=returnFlight", "Value=960;376;12/07/2018", ENDITEM,
	                "Name=JSFormSubmit", "Value=off", ENDITEM,
	                "Name=.cgifields", "Value=saveCC", ENDITEM,
	                "Name=buyFlights.x", "Value=47", ENDITEM,
	                "Name=buyFlights.y", "Value=12", ENDITEM,
	                LAST);

	/* ClickOnHome */

	lr_think_time(15);

	web_url("button_next.gif_2",
	        "URL=http://{pDomain}/cgi-bin/welcome.pl?page=menus",
	        "TargetFrame=body",
	        "Resource=0",
	        "RecContentType=text/html",
	        "Referer=http://{pDomain}/cgi-bin/nav.pl?page=menu&in=flights",
	        "Snapshot=t10.inf",
	        "Mode=HTML",
	        LAST);

	/* ClickOnItinerary */

	lr_think_time(18);

	web_url("Itinerary Button",
	        "URL=http://{pDomain}/cgi-bin/welcome.pl?page=itinerary",
	        "TargetFrame=body",
	        "Resource=0",
	        "RecContentType=text/html",
	        "Referer=http://{pDomain}/cgi-bin/nav.pl?page=menu&in=home",
	        "Snapshot=t11.inf",
	        "Mode=HTML",
	        LAST);

	/* ClickOnCancelChecked */

	lr_think_time(25);

	web_submit_data("itinerary.pl",
	                "Action=http://{pDomain}/cgi-bin/itinerary.pl",
	                "Method=POST",
	                "TargetFrame=",
	                "RecContentType=text/html",
	                "Referer=http://{pDomain}/cgi-bin/itinerary.pl",
	                "Snapshot=t12.inf",
	                "Mode=HTML",
	                ITEMDATA,
	                "Name=1", "Value=on", ENDITEM,
	                "Name=flightID", "Value=25569-1507808-MG", ENDITEM,
	                "Name=.cgifields", "Value=1", ENDITEM,
	                "Name=removeFlights.x", "Value=52", ENDITEM,
	                "Name=removeFlights.y", "Value=11", ENDITEM,
	                LAST);

	/* ClickOnSignOff */

	lr_think_time(5);

	web_url("SignOff Button",
	        "URL=http://{pDomain}/cgi-bin/welcome.pl?signOff=1",
	        "TargetFrame=body",
	        "Resource=0",
	        "RecContentType=text/html",
	        "Referer=http://{pDomain}/cgi-bin/nav.pl?page=menu&in=itinerary",
	        "Snapshot=t13.inf",
	        "Mode=HTML",
	        LAST);

	/* CloseTheWindow */

	return 0;
}