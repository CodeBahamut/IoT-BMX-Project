# Daily documentation

## Week 1 (25-04-2022 - 01-05-2022)

### Day 1 (Monday)

Today we did a brainstorming session. We discussed about the sensors we would buy or make. We also had quite a lengthy discussion with Bas about it. We came up with solutions for the DIY sensors.  
We started working the design of the webpage and the collaboration contract.  
We also planned the sprints.  

### Day 2 (Tuesday)

Today, we worked on making a webdesign, to iterate on and give the client an idea of what we want the website to look like. More info on this can be found [here](Web%20Application/Website-Design.md).  
Secondly, we researched the MyLaps device manual, to check how we can use this device with our product.  
Lastly, we made sure the gitlab pages were setup correctly and documented everything we have done so far.  
We made the following pages:  

- [Sensors](Physical%20device/sensors.md)  
- [Web application](Web%20Application/Web-Application.md)  
- [Web design](Web%20Application/Website-Design.md)

### Day 3 (Wednesday)

Today we prepared the presentation for our meeting with Aukje.
We did a retrospective of what we have done so far, and made sure the documentation was up to date. We've also made the first version of the design. this consists of the splash screen, homepage and profile page

## Week 2 (9-5-2022 - 15-5-2022)

### Day 1 (Monday)

Today we prepared the performance reviews for our meeting with Bas in the afternoon. We talked about our project and the way we fill in our forms. For the backend, we laid the foundation for our models, repositories and controllers. We also searched for tutorials on making relations between our models.

[Backend tutorial link](https://www.baeldung.com/hibernate-one-to-many)

| ![img.png](img.png) |
| :-----------------: |
| Backend foundation  |

### Day 2 (Tuesday)

Today we made the documentation look better, added some orange accents and some TeamNL logos.
A proper homepage was written.

| ![Homepage_mkdocs.png](Homepage_mkdocs.png) |
| :-----------------------------------------: |
|         Homepage for documentation          |

Then got a temperature and humidity sensor.
We were able to wire it properly and get the first data.

| ![Humidity_and_Temp_sensor.jpg](Humidity_and_Temp_sensor.jpg) |
| :-----------------------------------------------------------: |
|             DHT22 Humidity and Temperature sensor             |

```cpp
#include "DHTesp.h"
DHTesp dht;
 
void setup() {
    Serial.begin(115200);
    dht.setup(D2, DHTesp::DHT22);
}
 
void loop() {
    float h = dht.getHumidity();
    float t = dht.getTemperature();
 
    Serial.print("humidity: ");
    Serial.println(h);
    Serial.print("temp: ");
    Serial.println(t);
 
    delay(2000);
}
```

This is the first prototype of the web application.

| ![front_end_1st_prototype.png](front_end_1st_prototype.png) |
| :---------------------------------------------------------: |
|           First prototype of the web application            |

The base of the back end is done.
All of the current models now have their required variables and methods.
Controllers and repositories also have their required methods.
The backend is now connected to a remote database.
Routes were checked.

### Day 3 (Wednesday)

We connected the wemos to the internet and we made sure it can perform get requests when we want it to. You can find the code example here below:  

```cpp
void setup_wifi() {
  // Connect WiFi
  Serial.print("Connecting to ");
  Serial.println(ssid);
  WiFi.hostname("Name");
  WiFi.begin(ssid, password);
 
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print("-");
    Serial.flush();
  }
  Serial.println("");
  Serial.println("WiFi connected");
 
  // Print the IP address
  Serial.print("IP address: ");
  Serial.println(WiFi.localIP());
}



int httpGETRequest(const char* serverName, JsonObject& json) {
  WiFiClient client;
  HTTPClient http;
  http.useHTTP10(true);
  http.begin(client, serverName);
  int errcode = http.GET();
  if (errcode) {
    String err = http.errorToString(errcode);
    Serial.print("error get request for url: ");
    Serial.println(serverName);
    return -1;
  } else {
    // Parse response
    DynamicJsonDocument doc(2048);
    deserializeJson(doc, http.getStream());
    json = doc["data"];
    // Disconnect
    http.end();
  }

}

```

Also, the website now has a loading screen, and it has a page where the player table can be shown, which is hardcoded for now, but will be connected with the backend tomorrow.  
The loading screen looks like this:  

| ![loading screen](loadingpage.png) |
| :--------------------------------: |
|       Current loading screen       |

The table page looks as follows:

| ![main page](mainpage.png) |
| :------------------------: |
|     Current main page      |

The code for the table page looks as follows:  

```html
<app-header></app-header>
<app-navbar></app-navbar>
<body>
    <h1>Players</h1>
    <table>
        <tr>
            <th>ID</th>
            <th>Name</th>
            <th>Windspeed (km/h)</th>
            <th>Winddirection</th>
            <th>Time</th>
        </tr>
        <tr>
            <td>#0001</td>
            <td>Jan Stokpaard</td>
            <td>25.8</td>
            <td>NNO</td>
            <td>1:03.209</td>
        </tr>
        <tr>
            <td>#0314</td>
            <td>Cor Leon</td>
            <td>46.4</td>
            <td>SE</td>
            <td>59.101</td>
        </tr>
    </table>
</body>
<app-footer></app-footer>
```  

The header, navbar and footer are also loaded onto the page. The header and footer are still empty, but the navbar does contain something, which is the orange bar on the top of the page. The code for it looks like this:

```html
<ul>
  <ol>BMX environment</ol>
  <img class="navbar-img" src="../../../assets/images/cloud.png">
  <ol>Windspeed: 55 km/h</ol>
  <li><a class="active" href="default.asp">Home</a></li>
</ul>
```  

The styling for the navbar looks as follows:  

```css
ul {
    list-style-type: none;
    margin: 0;
    padding: 0;
    overflow: hidden;
    background-color: #ffa600;
  }
  
  li {
    float: right;
  }

  .navbar-img{
    width: 3%;
    float: left;
    padding: 6px 8px;
  }
  
  li a {
    display: block;
    color: white;
    text-align: center;
    padding: 14px 16px;
    text-decoration: none;
  }

  .active {
    background-color: #ff0000;
  }
  
  /* Change the link color to #c58000 (deep orange) on hover */
  li a:hover {
    background-color: #c58000;
  }

  ol {
    float: left;
    color: white;
    text-align: center;
    padding: 14px 16px;
    font-family: Arial, Helvetica, sans-serif;
  }

  ol a{
    display: block;
    text-decoration: none;
  }
```

### Day 4 (Tuesday)

Today, we made progress on the connection between the back-end and the front-end of the website. Now the front-end can receive data from the back-end regarding the data of the players, but it can't get data from the timings set by these players yet. The front-end code regarding this looks like this:  

```html
//Work in progress
      <tr *ngFor="let athlete of athletes; let i= index">
        <th>{{athlete.id}}</th>
        <th>{{athlete.firstName}} {{athlete.surname}}</th>
        <th>{{athlete.trackTimeRecords}}</th>
        <th></th>
        <th></th>
      </tr>
```

## Week 3 (16-5-2022 - 22-5-2022)

### Day 1 (Monday)

Today we got the post request function done on the wemos.
  
```cpp
  void httpPOSTRequest(const char* serverName, char[] httpRequestData){
  WiFiClient client;
  HTTPClient http;
  http.useHTTP10(true);
  http.begin(client, serverName);
    // Specify content-type header
  http.addHeader("Content-Type", "application/x-www-form-urlencoded");
  // Data to send with HTTP POST
  http.addHeader("Content-Type", "application/json");
  int httpResponseCode = http.POST(httpRequestData);
  //int httpResponseCode = http.POST("{\"api_key\":\"tPmAT5Ab3j7F9\",\"sensor\":\"BME280\",\"value1\":\"24.25\",\"value2\":\"49.54\",\"value3\":\"1005.14\"}");
  
  Serial.print("HTTP Response code: ");
  Serial.println(httpResponseCode);
  http.end();
}
```

After tha, we fixed a problem on the webpage due to which we couldn't get the weather data to display properly.
It would only appear as Object object and not access the actual data.
We also worked on styling and added the fonts that our client sent us.

we have made small adjustments to the splash screen so that it is ready.

CSS change:

```css
  color: rgba(0, 0, 0, 0.3);
  font-size: 5em;
}
  .logo{

.logo{
    background-image: url("src/woordbeeld_TeamNL_Wit_RGB.png");

  }
  width: 10%;
  height: 10%;
}


.loading-text:before {
```

HTML change:

```html
<div class="app-splash-content">

    <div class="logo"></div>

    <img src="woordbeeld_TeamNL_Wit_RGB.png" alt="logo" width="750" >
    
    <div data-text="Loading ..." class="loading-text">Loading ...
    </div>
  </div>
```

### Day 2 (Tuesday)

The weather station arrived today, so we decided to go test it out and make sure it is working.  

| ![weather station Buidling](weather-station-building-2.jpg) |
| :---------------------------------------------------------: |
|                Building the weather station                 |

| ![weather station Buidling](weahter-station-building.jpg) |
| :-------------------------------------------------------: |
|               Building the weather station                |

| ![weather station Buidling done](weather-station-building-done.jpg) |
| :-----------------------------------------------------------------: |
|                    Building weather station done                    |

Once we had it assembled we cut the wires and tried to make it work with the Wemos device.

| ![Trying the wires of the windspeed sensor](trywires.jpg) |
| :-------------------------------------------------------: |
|         Trying the wires of the windspeed sensor          |

<iframe width="420" height="315"
src="https://www.youtube.com/embed/rhg-blru4b8">
</iframe>  

We also figured out how the pinout from the rj11 connector works.

| ![RJ11 pinout weahter station wind direction and speed meter](Weather_station_connector_rj11.jpg) |
| :-----------------------------------------------------------------------------------------------: |
|                    RJ11 pinout weahter station wind direction and speed meter                     |

We also talked to our client, discussing the current progress. She was pretty positive about it, and we now have a great idea of how to progress during the next sprint.

We styled the homepage today. We've added an orange background to the header. The teamnl logo has also been added to the homescreen. We looked up how to center css images.

### Day 3 (Wednesday)

Today, we started by doing the sprint retrospective. Discussing what went well and what didn't go as well during this sprint. After that we decided to continue working where we left off yesterday, trying to figure out how to read the values from the windspeed sensor.

With this tutorial we made the anemometer working with a Arduino Uno.

[Arduino measure wind speed tutorial](https://www.aeq-web.com/arduino-anemometer-wind-sensor/?lang=en)

This is the schematic to connect the anemometer to an Arduino Uno

| ![Windspeed meter connection arduino](Anemometer_connection_arduino.png) |
| :----------------------------------------------------------------------: |
|                   Schematic anemometer to arduino Uno                    |

We have made the windspeed sensor work!

| ![Windspeed meter complete](IMG_20220518_121711.jpg) |
| :--------------------------------------------------: |
|               Windspeed meter testing                |

| ![Windspeed meter working](IMG_20220518_121700.jpg) |
| :-------------------------------------------------: |
|      Windspeed meter working with the terminal      |

| ![Windspeed meter connetion](IMG_20220518_121705.jpg) |
| :---------------------------------------------------: |
|              Windspeed meter connection               |

The code we are using to control the windspeed meter

```cpp
const int RecordTime = 3; //Define Measuring Time (Seconds)
const int SensorPin = 3;  //Define Interrupt Pin (2 or 3 @ Arduino Uno)

int InterruptCounter;
float WindSpeed;

void setup()
{
  Serial.begin(9600);
}

void loop() {
  meassure();
  Serial.print("Wind Speed: ");
  Serial.print(WindSpeed);       //Speed in km/h
  Serial.print(" km/h - ");
  Serial.print(WindSpeed / 3.6); //Speed in m/s
  Serial.println(" m/s");
}

void meassure() {
  InterruptCounter = 0;
  attachInterrupt(digitalPinToInterrupt(SensorPin), countup, RISING);
  delay(1000 * RecordTime);
  detachInterrupt(digitalPinToInterrupt(SensorPin));
  WindSpeed = (float)InterruptCounter / (float)RecordTime * 2.4;
}

void countup() {
  InterruptCounter++;
}
```

Finally we also got the wind direction sensor to work.
The code used is the following:

```cpp

void loop() {
  // read the input on analog pin 0:
  int sensorValue = analogRead(A0);
  float voltage = sensorValue*5/1023.0; // multiply the value by the voltage(5 volts) and divide it by the range of values (1023)
  int direction = map(sensorValue, 0, 1023, 0, 360); // we watch all the values possible with an angle 
  Serial.print("Direction : ");
  Serial.println(direction);
  delay(300); 
}

```

This is how the sensor is wired, we're using a 10k resistor and 5V power:

| ![Wind vane wiring](wind_vane_wiring.png) |
| :---------------------------------------: |
|         Wind vane wiring diagram          |

Lastly, we tried to get all the sensors connected and working at the same time. We went outside to test this. Luckily everything was working properly.

## Week 4 (23-5-2022 - 29-5-2022)

### Day 1 (Monday)

Today, we started with applying the feedback we got during the meeting with the client. She was not very happy about our current design for the webpages. So we went back to the drawing board to redesign the personal page, as it was too bland, needed to look cleaner and be more vibrant. So we added a background grayscaled of the orange background delivered to us by our client:  

| ![Personal page redesign](personalpage_design.png) |
| :------------------------------------------------: |
|               Personal page redesign               |

we looked up how to create tables using html.

- [Tutorial 1](https://developer.mozilla.org/en-US/docs/Learn/CSS/Building_blocks/Styling_tables)
- [Tutorial 2](https://dev.to/dcodeyt/creating-beautiful-html-tables-with-css-428l)

### Day 2 (Tuesday)

Today, we worked on the design of the personal page again, as it was still to bland, so we made a final version for the design of the personal page:  

| ![Personal page final redesign](personalpage_design_final.png) |
| :------------------------------------------------------------: |
|                  Personal page final redesign                  |

We also tested the 2nd windspeed and winddirection sensors to make sure those also work, which they do. We are now trying to figure out how to make them work with the Wemos as we need an internet connection, which is pretty unstable with the wifi module for the arduino.  

After that we also worked on the other documentation files, for example:  

- [Web application](Web%20application/Web-Application.md)
- [Web design](Web%20application/Website-Design.md)

### Day 3 (Wednesday)

Today, we tried to wire the sensors to the Wemos. We are getting an error.

```cmd
 ets Jan  8 2013,rst cause:2, boot mode:(3,6)

load 0x4010f000, len 3460, room 16 
tail 4
chksum 0xcc
load 0x3fff20b8, len 40, room 4 
tail 4
chksum 0xc9
csum 0xc9
v00042c50
~ld
ISR not in IRAM!

User exception (panic/abort/assert)

Abort called

>>>stack>>>

ctx: cont
sp: 3ffffe90 end: 3fffffc0 offset: 0000
3ffffe90:  feefeffe feefeffe feefeffe 3ffef46c  
3ffffea0:  000000fe 00000000 00000000 00000000  
3ffffeb0:  00000000 00000000 00000000 00ff0000  
3ffffec0:  5ffffe00 5ffffe00 0001c200 3ffee67c  
3ffffed0:  00000000 00000001 0000000d 4020278a  
3ffffee0:  40100419 00000001 3ffee614 4020279c  
3ffffef0:  00000000 00000001 0000000d 40202cd9  
3fffff00:  00000000 feefeffe feefeffe feefeffe  
3fffff10:  3fffdad0 00000000 3ffee614 40202d78  
3fffff20:  3fffdad0 00000000 3ffee614 4020108f  
3fffff30:  feefeffe feefeffe feefeffe feefeffe  
3fffff40:  feefeffe feefeffe feefeffe feefeffe  
3fffff50:  feefeffe feefeffe feefeffe feefeffe  
3fffff60:  feefeffe feefeffe feefeffe feefeffe  
3fffff70:  feefeffe feefeffe feefeffe feefeffe  
3fffff80:  feefeffe feefeffe feefeffe feefeffe  
3fffff90:  feefeffe feefeffe feefeffe feefeffe  
3fffffa0:  feefeffe 00000000 3ffee668 402020a0  
3fffffb0:  feefeffe feefeffe 3ffe85d8 40100cd5  
<<<stack<<<
```

We will try to fix it as soon as possible, but no success for now. So we will try again during the next workday.

Today we looked at a suitable background for the homepage, this because it is currently white and makes for a less professional look. Here are some examples we found:

 | ![Example background for homepage](Backgroundexample1.png) |
 | :--------------------------------------------------------: |
 |              Example background for homepage               |

 | ![Example background for homepage 2](backgroundexample2.png) |
 | :----------------------------------------------------------: |
 |              Example background for homepage 2               |

## Week 5 (30-5-2022 - 5-6-2022)

### Day 1 (Monday)

Today we worked on the different reports and updated old ones to fit within what Bas expected.
We also wrote user stories on our issue board in gitlab, you can find a link to that [here](https://gitlab.fdmci.hva.nl/IoT/2021-2022-feb-jun/group-project/teamnl-bmx-windspeed-logging/iot-bmx-team-nl/-/boards/5331).
We had meetings with Bas in the afternoon about our current progress as a group and individually, due to this we didn't really have as much time to work on the device as we wanted to.

### Day 2 (Tuesday)

We're still trying to fix the error we had on wednesday.
We tried to redo the wiring but it doesn't seem to be the problem. So we tried googling the error, but sadly that hasn't help either.  
We also researched what the possibilities are to make the device weatherproof, as the device needs to function outside, also at times of bad weather. This documentation can be found [here](Physical%20device/weatherproofing.md).

### Day 3 (Wednesday)

Today we continued to try make the sensors work with the Wemos. We tried swapping the wemos for a different one, we replaced the cables, redid the wiring, tried the other set of sensors, tried an alternative to the wiring we had but still no luck.  

We're starting to consider using an arduino to receive the data and send it to the wemos which would then communicate with the internet. That solution would be less elegant and require some work. But it would get us unstuck.  

At the end of the day nearly everything worked except for the windsspeed sensor. We used these tutorials today to try and fix the sensors:  

- [ESP8266 Weather Station - with Wind and Rain Sensors](https://tysonpower.de/blog/esp8266-weather-station)
- [Arduino Measure Wind Speed](https://www.aeq-web.com/arduino-anemometer-wind-sensor/?lang=en)
- [ESP8266 Combined timer and pin interrupts to measure wind speed sensors](https://www.youtube.com/watch?v=FnTtv6ozW90)
- [ESP_Anenometer_SH1106_OLED_03.ino](https://www.youtube.com/redirect?event=video_description&redir_token=QUFFLUhqbVJJQmxwRWxOcmd2b3BqRUZRZ1ZfSVZkZFFOUXxBQ3Jtc0tuM0d4LW9FaUNQeE9xdWExMEY4bUVFTGJZLUxMVU1zUlh0bWZqRmlXcUFHZk1ub2dtTlFOQTRWWXhDcEhEZ2trQ3k1OVVFZkNQVmRkU0tYME94M2xzQlo2SFdKVHNiRmpER1lpQ2tZenlfN0ptejhIaw&q=https%3A%2F%2Fgithub.com%2FG6EJD%2FESP_Interrupt_Examples&v=FnTtv6ozW90)

Today we watched a basic video about angular to understand the basics. This is the video that we watched:

- [angular basics](https://www.youtube.com/watch?v=k5E2AVpwsko&t=5881s)

### Day 5 (Friday)

Today we started with deploying our webpage to our "own" domain.
We followed [this guide](https://gitlab.fdmci.hva.nl/se-ewa/deployment-workshop/-/blob/master/README.md)
to deploy our website using heroku, which we did successfully. A link to the website can be found [here](https://bmx-nl-app-staging.herokuapp.com).

At this point, the only way to deploy something to our staging environment is by manually making a commit using heroku git. Which is really annoying, as it would take way longer to test and make us spend a lot of time waiting for it. This is why we also started working on automating this part using a pipeline, that way we don't have to wait that long to test the website.

### Day 6 (Saturday)

Today, we started working on automating the committing through Heroku. We do this using the git pipeline on a different branch than the one we run the pages on. That way we can effectively have 2 pipelines running simultaneously without having problems of the pipelines intervening with eachother. We did this using [this tutorial](https://gitlab.fdmci.hva.nl/se-ewa/deployment-workshop/-/blob/master/doc/general/gitlab-cicd/README.md). We personalised it to our usecase, and we got this result:  

```yml
stages:
  - deploy

deploy_be:
    stage: deploy
    image: node:latest
    tags:
        - hva
    only:
        refs:
            - heroku-deployment
        changes:
          - "bmx-app-backend/**/*"  
    script:
        - git remote rm heroku-be-app || true
        - git remote add heroku-be-app https://heroku:$HEROKU_API_KEY@git.heroku.com/bmx-nl-app-be-staging.git || true
        - git subtree split --prefix bmx-app-backend -b splitting-staging-be
        - git push --force heroku-be-app splitting-staging-be:master
        - git branch -D splitting-staging-be

deploy_fe:    
    stage: deploy
    image: node:latest
    tags:
        - hva
    only:
        refs:
            - heroku-deployment
        changes:
          - "bmx-app/**/*"  
    script:
        - git remote rm heroku-fe-app || true
        - git remote add heroku-fe-app https://heroku:$HEROKU_API_KEY@git.heroku.com/bmx-nl-app-staging.git || true
        - git subtree split --prefix bmx-app -b splitting-staging-fe
        - git push --force heroku-fe-app splitting-staging-fe:master
        - git branch -D splitting-staging-fe
```

However, this did not fully fix it already. As we got errors with Heroku, saying that our account had reached its concurrend build limit. Due to this we had to reset our Heroku website, to remove some of the concurrend builds. After we had done this, the front-end fixed itself and is now automatically working, however the back-end, is not yet working. We will continue to work on this next week.  

The profile page has been set up. The time service has also been set up.  
the code for the profile page is as follows:

```html
<body>

<app-navbar></app-navbar>

<img src="assets/images/TeamNL_Logo_Olympisch_RGB_WitKader.jpg" class="center">

<table id="customers">
  <tr>
    <th>Time</th>
    <th>Date</th>
    <th>Temperature (C)</th>
    <th>Wind</th>
    <th>Winddirection</th>

  </tr>
  <tr *ngFor="let time of time; let i= index">
    <th>{{time.id}}</th>
    <th>{{time.recordedValue}}</th>
    <th>{{time.recordedTime}}</th>
    <th>{{time.trackTimeRecords[0].windSpeed}}</th>
    <th>{{time.trackTimeRecords[0].recordedValue}}</th>
    <th>{{time.trackTimeRecords[0].recordedTime}}</th>
  </tr>
</table>
</body>
```

```css

.center {
  display: block;
  margin-left: auto;
  margin-right: auto;
  width: 7%;
}
```

```ts
@@ -1,4 +1,6 @@
import { Component, OnInit } from '@angular/core';
import {TrackTimeRecord} from "../../models/tracktimerecord";
import {Athlete} from "../../models/athlete";

@Component({
  selector: 'app-profile',
@@ -7,7 +9,15 @@ import { Component, OnInit } from '@angular/core';
})
export class ProfileComponent implements OnInit {

  constructor(

    private trackTimeService : TrackTimeRecord
  ) { }


  get time(): TrackTimeRecord[] {
    return this.trackTimeService.findAll();
  }

  ngOnInit(): void {
  }
```

## Week 6 (6-6-2022 - 12-6-2022)

### Day 1 (Tuesday)

Today, the soldering on one of the wires on the weatherstation broke. We ended up resoldering every wire on that set.
Then We looked up some ways to go around the internet/wemos problem. We could be able to use a simple python script to read the data from the terminal and perform the post request.
We'll try to put that in practice tomorrow.

### Day 2 (Wednesday)

Finally, we managed to get all the sensors work on the wemos. The goal for this afternoon is to connect the wemos to the back-end of the webapplication, so the data can actually be used. Error handling remains to be done on the back-end.
Here you can see the code where we are reading all the data:
[Wemos reading weather data code](https://gitlab.fdmci.hva.nl/IoT/2021-2022-feb-jun/group-project/teamnl-bmx-windspeed-logging/iot-bmx-team-nl/-/blob/main/Arduino-main/Weahter_station_data___dht22/Weahter_station_data___dht22.ino)

Here is the wire scheme for reading the sensors:

|         ![Wemos reading weather data code](Fritzing%20wemos.png)          |
| :-----------------------------------------------------------------------: |
| Connecting schema weather station + DHT22 temperature and humidity sensor |  

The time service method required for the profile page has been completed. The code for the time service is as follows:

```ts
export class TimeService {

  private tracktimerecord : TrackTimeRecord[] = []

  constructor(private httpClient: HttpClient) {

    this.restGetTrackTime().subscribe(
      responseData => this.tracktimerecord = responseData,
      error => ErrorHandler.apply(error) )
  }

  //Work in progress
  restGetTrackTime(): Observable<TrackTimeRecord[]>{
    return this.httpClient.get<TrackTimeRecord[]>(`http://localhost:808/TrackTimeRecord`)
      .pipe(
        map(responseData => {
          const trackArray: TrackTimeRecord[] = [];
          for(const key in responseData){
            responseData[key].recordedTime;
            trackArray.push(responseData[key])
          }
          console.log("initial list", trackArray)
          return trackArray
        })
      );
  }
}
```

Minor improvements have been made to the profile page so that the correct Findall method is called to retrieve all data. It looks like this:

```ts
@@ -2,6 +2,7 @@ import {ErrorHandler, Injectable} from '@angular/core';
import {HttpClient} from "@angular/common/http";
import {TrackTimeRecord} from "../models/tracktimerecord";
import {map, Observable} from "rxjs";
import {Athlete} from "../models/athlete";

@Injectable({
  providedIn: 'root'
@@ -33,6 +34,9 @@ export class TimeService {
        })
      );
  }
  findAll(): TrackTimeRecord[]{
    return this.tracktimerecord;
  }
}
```

```ts
@@ -1,6 +1,7 @@
import { Component, OnInit } from '@angular/core';
import {TrackTimeRecord} from "../../models/tracktimerecord";
import {Athlete} from "../../models/athlete";
import {TimeService} from "../../services/time.service";

@Component({
  selector: 'app-profile',
@@ -10,8 +11,7 @@ import {Athlete} from "../../models/athlete";
export class ProfileComponent implements OnInit {

  constructor(

    private trackTimeService : TrackTimeRecord
    private trackTimeService : TimeService
  ) { }
```

### Day 3 (Thursday)

Today, we had a meeting with the client, discussing our recent progress. Luckily, the client was very happy with our progress and we arranged that we as a team are gonna go to the location of our client next week to test our product! Next to that, we also worked on a design for the 3d print for our product. This now looks as follows:  

| ![Top part of the design](topPartCasing.png) |
| :------------------------------------------: |
|            Top part of the design            |

| ![main part of the design](middlePartCasing.png) |
| :----------------------------------------------: |
|             Main part of the design              |

The roof is slanted because the water will then just fall off on its own, creating less time for the water to get into the device.

## Week 7 (13-6-2022 - 19-6-2022)

### Day 1 (Monday)

We did the first attempt at 3D printing the casing, which sadly failed. This is the result:

| ![3D print of the casing](casing3Dprintfail.png) |
| :----------------------------------------------: |
|          3D print of the casing failed           |

We also resoldered the wires coming out of the sensors, and made them a bit stronger hoping that we won't need to do that ever again.

A problem was fixed in the wemos code where we accidently copied some code twice.  
Lastly, we also fixed the design for the top part of the 3d print, making the fill bigger. This way, there won't be a gap in there once we print it again.

### Day 2 (Tuesday)

Today we did the sprint review and retrospective meeting. We discussed our progress and the problems we encountered. We also discussed the next steps we are going to take. Because of this.yhe issue board was also updated with new tasks for the next sprint.  

| ![meeting picture](20220614_112032.jpg) |
| :-------------------------------------: |
|             Meeting Picture             |

We also got a second try at the piece we tried to print yesterday. This time it worked!
The rest of the casing takes too long to print so we'll need to find an alternative as we can only print at Miguel if it can be printed within the workday he is here, which is too short for our print sadly.  
Next to that, we worked on a testing plan to follow on location on thursdays during the testing. This can be found [here](Testing-plan.md).

### Day 3 (Wednesday)

Today, we worked hard to try and fix the problem with receiving data from the MyLaps system, we got our back-end fully live and functional. However, we sadly did not see any data coming in from our client. Next to that, we also got problems again with the Wemos, we couldn't update its software, as we got a weird error. However, after just waiting a while and trying it again, we removed the wire on the 5V pin and everything was working again, with this we could succesfully send data to the back-end, which was not in the correct formatting, so we changed that to make it fully work. Finally we also worked on the final part of our casing. We went to the makerslab to get it printed there, as it is a really long print, thus we cannot do it at our usual location. However, the 3d printers at the makerslab were all occupied. So we decided to use the [UPrinter](https://support.stratasys.com/en/printers/fdm-legacy/uprint), which is way different than regular 3d printing, but still works fine for us. But due to it taking so long we could not get the 3d print yet, so we will retrieve it tomorrow.

Today the styling has been finalized for the profile page:

```css
@@ -5,3 +5,38 @@
  width: 7%;

}

#customers {
  font-family: Arial, Helvetica, sans-serif;
  border-collapse: collapse;
  width: 100%;
}

#customers td, #customers th {
  border: 1px solid #ddd;
  padding: 8px;
}

#customers tr:nth-child(even){background-color: #f2f2f2;}

#customers tr:hover {background-color: #ddd;}

#customers th {
  padding-top: 12px;
  padding-bottom: 12px;
  text-align: left;
  background-color: orangered;
  color: white;
}

body{

  height: 100vh;
  background-color: #e5e5f7;
  opacity: 0.6;
  background-image:  repeating-radial-gradient( circle at 0 0, transparent 0, #e5e5f7 10px ), repeating-linear-gradient( #f4872e55, #f4872e );
  margin: 0;
}
```

### Day 4 (Thursday)

Today we finally got the 201 HTTP response from the back-end. The problem was that we were accessing the back-end through HTTPS, removing the S solved the issue.
We also worked on the documentation, as some of the documentation was still not finished, so we finished the following pages:  

- [Testing plan](Testing-plan.md)
- [Weatherproofing](Physical%20device/weatherproofing.md)  

Next to that we also had another meeting with our client. We were planning to go to the location of our client, but due to connection issues between their software and our software we decided to delay that. Because of this we had an extra meeting to plan ahead and think of solutions for the problem. We came to the conclusion of using teamviewer to remotely use their computer, that way we can fix the issue while not needing to go all the way there, as we need to make sure the data they receive will also be send to our database. We plan to do this tomorrow, so hopefully we can fix it then. If we fix it we will go to their location next tuesday.

### Day 5 (Friday)

Today we tried to solve the issue with the mylaps system permanently. We tried sloving the issue by using teamviewer on their computer, this way we get access to the mylaps system so that we can try to configure the mysql JDBC string. However this didnt work as we recieved the following error: mysql error code 08s01. After testing multiple solution we eventually came to the conclusion that it couldn't be solved due to outside factors that were out of our reach, more on why it didn't work can be found [here](https://iot.dev.hihva.nl/2021-2022-feb-jun/group-project/teamnl-bmx-windspeed-logging/iot-bmx-team-nl/Web%20application/Deploy-Website/#sql-error-0-sqlstate-08s01-communications-link-failure). We did find a solution with Finn, the person who gave us access to the computer with mylaps installed. We decided to use a CSV file that the transponders generate and insert them manually into the database. This way we got the real data, however not automated as intented.

## Week 8 (20-6-2022 - 24-6-2022)

### Day 1 (Monday)

Today, we decided to take a step back and look at the current situation and what we plan to do, now that another meeting at the clients location to test our device is cancelled and we do not have enough time to arrange another meeting there. We talked with Bas about the situation. We came to the conclusion that we should design different possible solutions and then pick one to replace the data being received from the client's system. We are gonna work on this tomorrow.  
Next to that, we worked a lot on documentation, making mini-manuals.  
We also made a diagram of the software part of the product:
![Software diagram](application_diagram.png)
Lastly, we also started importing the CSV file from Mylaps into our database as we can't get the data directly, as the program is running locally to avoid any tempering on the times.
This means adding new columns and finding a smart way to add all the data without having to do it by hand.

Today we decided that for the webpage we would make the homepage only the id, name and a button to see all the details of the player only on the profile page. Also, an attempt was made to repair the router as it currently loads all components instead of just the selected component.

### Day 2 (Tuesday)

We received the main part of the casing for the device today from the 3d printer. It took such a long time due to the supports needing to be removed through a special method. It needed to sit in a special bath with citric acid, which automatically removed the supports. However, this takes a long time, which is why we only got it now.  

| ![Main casing of the device](main-casing.png) |
| :-------------------------------------------: |
|           Main casing of the device           |

As we are mostly meeting online today due to personal reasons, we will set up the device into the casing and make sure everything still works tomorrow.  

We also worked more on properly documenting everything, as we want to make sure all of the documentation is great when the project is finished. These are some of the pages we have been working on today:  

- [Website design](Web%20Application/Website-Design.md)
- [Mini manuals](Mini-manuals.md)

Next to that, we read through this entire document to find missing information or grammar and spelling mistakes, we fixed all of those.

### Day 3 (Wednesday)

Today, was a great day! We fixed the back-end completely, meaning we can go test the device. We planned to go to the clients location for testing next monday. Next to that, we did a lot more documentation. First we reordered how the documents are shown on the documentation website, as the navbar was completely full with tabs, so we put some tabs together. Due to this there now is a ["Physical device"](https://iot.dev.hihva.nl/2021-2022-feb-jun/group-project/teamnl-bmx-windspeed-logging/iot-bmx-team-nl/Physical%20device/embedded_device/) tab, this holds the embedded device, sensors and weatherproofing documents. Next to that, we also started worked on a to fully document what we will be delivering to the client next week. This way everything will be compact and easy to find. You can find this documentation [here](https://iot.dev.hihva.nl/2021-2022-feb-jun/group-project/teamnl-bmx-windspeed-logging/iot-bmx-team-nl/Final_Delivery/).  
We also made sure the casing of the device fits, as the top part didn't fit first due to the edges on the main part being too big and the usb cable didn't fit through the designated hole. So we used a vile to slim the edges down and make the hole for the usb bigger. Now everything fits in there.  

| ![Full casing of the device](casingfull.png) |
| :------------------------------------------: |
|          Full casing of the device           |

Today we managed to get the button to navigate to the profile page with the help of a method. The method is as follows:

```html
@@ -12,7 +12,7 @@
  <tr *ngFor="let athlete of athletes; let i= index">
    <th> {{athlete.id}}</th>
    <th>{{athlete.firstName}} {{athlete.surname}}</th>
    <button (click)="goToPage('profile')" class="btn btn-outline-primary">Profile</button>
  </tr>
```

```ts
@@ -2,6 +2,7 @@ import { Component, OnInit } from '@angular/core';
import { SplashScreenStateService } from "../../services/splash-screen.service";
import { AthleteService } from "../../services/athlete.service";
import { Athlete } from "../../models/athlete";
import {Router} from "@angular/router";

@Component({
  selector: 'app-homepage',
@@ -12,9 +13,11 @@ export class HomepageComponent implements OnInit {

  constructor(
    private splashScreenStateService: SplashScreenStateService,
    private athleteService: AthleteService
    private athleteService: AthleteService,
    private router: Router
  ) {
  }
    get athletes(): Athlete[] {
      // let trackTimeRecords = this.athleteService.findAll().map(obj => ({humidity: obj.trackTimeRecords.humidity}));
@@ -27,5 +30,11 @@ export class HomepageComponent implements OnInit {
        this.splashScreenStateService.stop();
      }, 5000);
    }

  goToPage(pageName: string) : void {
    this.router.navigate([`${pageName}`])
  }
}
```

### Day 4 (Thursday)

Today, we continued working on the documentation, as that needs to be great when the project is finished. We mostly worked on the [Final delivery document](Final_Delivery.md). Next to that, we also had a meeting with our client. We talked about the current situation and decided that we would definitely meet her at her location this monday, to test our product and so they know how our product works.

## Week 9 (27-6-2022 - 1-7-2022)

### Day 1 (Monday)

We went to the location of our client today to test our product. Firstly, we had a meeting with our client to discuss our current progress and how the product exactly works. Next to that, we also talked about further possible development for the product. After that, we went to the bmx track by bike, to test our product there. We hung the product up next to the start of the track, calibrated the direction of the winddirection sensor and then tested if we got results.

| ![testing the sensors on the track](sensors_on_track.png) |
| :-------------------------------------------------------: |
|             testing the sensors on the track              |

| ![grouppicture on the track](grouppicture_on_track.png) |
| :-----------------------------------------------------: |
|                grouppicture on the track                |

We in the end we got great results and now know what is left to do during the last week. As we now completely understand what data is coming through and how we need to read that and combine it with the data the sensors collect.

### Day 2 (Tuesday)

We started the day by reflecting on the last sprint through the retrospective, we did a lot this sprint, a lot went well but there was some stuff which did not go so well. We wanted to figure out how we were gonna prevent these issues next time. Next to that we also started putting the wemos device into the casing, to make sure the device cannot break and is protected from the weather. Lastly, we also had a meeting with Bas on how our project is going and reflecting on the project as a whole, we are happy with the result we predict that we will be able to present this friday.

### Day 3 (Wednesday)

Today, we started to continue the documentation. We improved the following documents:

- [Homepage](index.md)
- [Final delivery](Final_Delivery.md)
- [Web application](Web%20application/Web-Application.md)

We also made a video for our homepage and for the final event as an introduction to our project. Next to that, we made sure the 2nd pair of sensors also works so we can use them on friday during the event.

<video width="500" controls muted> <source src="../BMX_TEAMNL.mp4" type="video/mp4"> </video>

### Day 4 (Thursday)

Today is the last day before the end of the project, so we set out finalizing everything and making sure everything works fine. We mostly worked on documentation, the [Final delivery](Final_Delivery.md) is now fully finished. Next to that, we tweaked some other pages here and there to make them look better, for example:  

- [Web application](Web%20application/Web-Application.md)
- [Mini manuals](Mini-manuals.md)
- [Testing plan](Testing-plan.md)  

Next to that, we also had a meeting with our client, discussing the complete product. We reflected on our work, what went well and what could've gone better and how.We all agreed we had some parts where we could've done something different, but this is all discussing afterwards. overall we could all agree we did well.

### Day 5 (Friday)

Today was the day of the final event. All other project of all other minors were also present showing their work of the past semester. We set up our project so people could try it out. We set up two monitors each with a device connected to them, with this we could let people blow into the windspeed sensor and they could check how fast they were blowing, hoping to set the record. This turned out to be pretty successful and a lot of people came to test it out!  

| ![setting up the project](settingup_event.png) |
| :-----------------------------------------------------: |
|                setting up the project                |  

| ![people checking out our stand!](stand_in_action.png) |
| :-----------------------------------------------------: |
|                people checking out our stand!                |
