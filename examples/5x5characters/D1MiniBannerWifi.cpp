/*
 * Copyright (c) 2015, Majenko Technologies
 * All rights reserved.
 * 
 * Redistribution and use in source and binary forms, with or without modification,
 * are permitted provided that the following conditions are met:
 * 
 * * Redistributions of source code must retain the above copyright notice, this
 *   list of conditions and the following disclaimer.
 * 
 * * Redistributions in binary form must reproduce the above copyright notice, this
 *   list of conditions and the following disclaimer in the documentation and/or
 *   other materials provided with the distribution.
 * 
 * * Neither the name of Majenko Technologies nor the names of its
 *   contributors may be used to endorse or promote products derived from
 *   this software without specific prior written permission.
 * 
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND
 * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
 * WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
 * DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE FOR
 * ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
 * (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
 * LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON
 * ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
 * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
 * SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */

/* Create a WiFi access point and provide a web server on it. */

#include <ESP8266WiFi.h>
#include <WiFiClient.h> 
#include <ESP8266WebServer.h>

#include <WEMOS_Matrix_LED.h>

MLED mled(5); //set intensity=5

/* Set these to your desired credentials. */
const char *ssid = "ESPBANNER";
const char *password = NULL;

ESP8266WebServer server(80);

#define BANNER_FORM \
		"<form action='/banner'>"\
		"Text: <input type='text' name='txt'><br>"\
		"<input type='submit' value='Submit'>"\
		"</form>"

void sendBannerForm() {
	server.sendContent(BANNER_FORM);
}

/* Just a little test message.  Go to http://192.168.4.1 in a web browser
 * connected to this access point to see it.
 */
void handleRoot() {
	server.send(200, "text/html",
			"<h1>You are connected</h1>" BANNER_FORM);
}

#define OUT(title,msg) Serial.print(title);Serial.println(msg);
#define OUT_(title,msg) Serial.print(title);Serial.print(msg);Serial.print(' ');

String banner=String("Welcome");
uint8_t bannerCounter=0;

void handleBanner() {
	OUT("Args count=",server.args());
	for(int i=0;i<server.args();i++) {
		OUT_("Arg ",server.argName(i)); OUT("=",server.arg(i));
	}
	OUT("Setting Banner to ",server.arg("txt").c_str());
	mled.clear();
	bannerCounter=0;
	banner=server.arg("txt");
	server.send(200, "text/html","<p>Text set</p>" BANNER_FORM);
}

void softAPCallBack(const WiFiEventSoftAPModeStationConnected& evt) {
	Serial.print("AP Sta connected MAC=");
	for(int i=0;i<6;i++) {
		if(i>0) Serial.print(':');
		Serial.print(evt.mac[i]);
	}
	Serial.print(" aid=");
	Serial.println(evt.aid);
}

void setup() {
	mled.clear(); mled.display();

	delay(1000);
	mled.dot(0, 0); mled.display();
	Serial.begin(115200);
	Serial.println();
	Serial.print("Configuring access point... ssid=");
	Serial.print(ssid);
	Serial.print(" pwd=");
	Serial.println(password);
	mled.dot(1, 0); mled.display();
	/* You can remove the password parameter if you want the AP to be open. */
	WiFi.softAP(ssid,password);
	mled.dot(2, 0); mled.display();
	//WiFi.onEvent(phgEvtCallBack, WIFI_EVENT_ANY);
	WiFi.onSoftAPModeStationConnected(softAPCallBack);
	mled.dot(3, 0); mled.display();

	IPAddress myIP = WiFi.softAPIP();
	Serial.print("AP IP address: ");
	Serial.println(myIP);
	mled.dot(4, 0); mled.display();
	server.on("/", handleRoot);
	mled.dot(5, 0); mled.display();
	server.on("/banner", handleBanner);
	mled.dot(6, 0); mled.display();
	server.begin();
	Serial.println("HTTP server started");
	mled.dot(7, 0); mled.display();
}

#define CHAR_DELAY 150
unsigned long lastMillis=0;

void loop() {
	server.handleClient();

	unsigned long curMillis=millis();
	if(curMillis-lastMillis>CHAR_DELAY) {
		mled.clear();
		mled.banner(banner.c_str(),banner.length(),bannerCounter);
		mled.display();
		bannerCounter++;
		lastMillis=curMillis;
	}
}
