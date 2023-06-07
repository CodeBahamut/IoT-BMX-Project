# Final delivery

This document will contain everything we will deliver to the client at the end of the project. That means there will be info here about the hardware and software of the device and any other important information.

## Software

The software is split into a couple of parts, the front-end and the back-end. The front-end is the part which the user can see, the webpages and the looks of it. The back-end are the parts the user cannot see. This includes a database, security and a lot of functionality.

### Front-end

The front-end consists of a few pages; the loading screen, the main page and the personal page. The loading screen is just a screentransition in which the website has time to load all the correct data. It looks like this:  

| ![Loading screen](Loadingpage_Final.png) |
| :-------------------------------------------: |
|          Loading screen           |  

The main page is the page shown after the loading screen. This screen shows the most recent data collected by the database. This looks as follows:  

| ![homepage](homepage.png) |
| :-------------------------------------------: |
|          Home screen           |  

The personal page is a page which can be navigated to through the main page. Every run is connected to a driver, clicking on these drivers will take them to their own page, showing the data connected to them through their runs. This looks as follows:  

| ![profilepage](Profilepagev2.jpg) |
| :-------------------------------------------: |
|          Profilepage           |  

### Back-end

The back-end was made in spring-boot which is a framework used to make enterprise level back-end applications.

We use MVC(model view controller) to structure our back-end. In the models reside the entities that are going to be generated using JPA
when you start the back-end in your IDE. In the views reside how the data is going to be sent and retrieved. Lastly in the controllers resides most of the logic that is going to be used to process http requests.

Below you can see the general architecture of the entire product, but for now we focus on the application layer where our backend-resides:
![img_1.png](img_1.png)

## Physical device

The physical device also consists of multiple parts, which can be explained individually. The 3d print, which is the casing of the device and makes sure the electronics are protected. The wiring, which is how the wires are connected from the sensors to the wemos. Lastly, there is the code on the wemos, this code makes sure the wemos uses the data from the sensors correctly and sends it to the designated location.

### Casing

The casing is designed to be weatherproof, due to this, a couple of measurements have been taken in designing the casing. This is how the casing looks:  

| ![Full casing for the device](casingfull.png) |
| :-------------------------------------------: |
|          Full casing for the device           |  

The roof is slanted, so the water that can rain on top of it automatically falls off and has a low chance of actually getting into the device. The device has these 'legs' to let the wires go to the wemos savely without encountering water. Lastly, there is the hole in the middle of the device. This is to connect the wemos to a power supply with a usb wire, which sits in the middle of the device.

### Sensors

We are using multiple sensors on our device to read data on multiple things regarding the weather. We have a humidity sensor, a temperature sensor, a windspeed sensor and a winddirection sensor.  
For the humidity and the temperature, we are using a [combined sensor module](https://elektronicavoorjou.nl/product/dht22-temp-vocht-sensor/?utm_campaign=organic_shopping&utm_content=&utm_source=google&utm_medium=organic&utm_term=&gclid=Cj0KCQjwntCVBhDdARIsAMEwACkGb2X-jlnPqTqaltdO49JmOLQFREfF94tp1S9dRzX6pyGRSkC0wYUaAm8hEALw_wcB). It looks like this in real life:  

| ![Temperature and humidity sensors](Humidity_and_Temp_sensor.jpg) |
| :-------------------------------------------: |
|                    Temperature and humidity sensors |  

We are also using a combined sensor module for the windspeed and winddirection sensors, you can buy these [here](https://www.robotshop.com/nl/nl/sparkfun-weermeterset.html). These look as follows in real life:  

| ![Windspeed and winddirection sensors](weather-station-building-done.jpg) |
| :-------------------------------------------: |
|                    Windspeed and winddirection sensors |  

### Wiring

The sensors are connecting to the Wemos in the following way:

|         ![Wemos reading weather data code](Fritzing%20wemos.png)          |
| :-----------------------------------------------------------------------: |
| Connecting schema weather station + DHT22 temperature and humidity sensor |

Here is the refernce for the wiring from the weatherstation cable:

| ![RJ11 pinout weahter station wind direction and speed meter](Weather_station_connector_rj11.jpg) |
| :-----------------------------------------------------------------------------------------------: |
|                    RJ11 pinout weahter station wind direction and speed meter                     |

### Wemos configuration

You will find these lines of codes in the Weather_station_data file and you just need to change the values to connect to the right wifi.

```cpp
const char* ssid = "AFBLIJVEN"; <- change this to your ssid
const char* password = "Kaas012!!"; <- change this to your wifi password
```

If you want to know more on how to change the wifi, visit [this page](Physical%20device/embedded_device.md)

For more information regarding wemos configuration visit [this page](https://iot.dev.hihva.nl/2021-2022-feb-jun/group-project/teamnl-bmx-windspeed-logging/iot-bmx-team-nl/Physical%20device/embedded_device/).

## Bill of materials

The following materials are needed to recreate our product:

- [Combination of windspeed and winddirection sensors (and rainspeed sensors)](https://www.robotshop.com/nl/nl/sparkfun-weermeterset.html)
- [Humidity and temperature sensor](https://elektronicavoorjou.nl/product/dht22-temp-vocht-sensor/?utm_campaign=organic_shopping&utm_content=&utm_source=google&utm_medium=organic&utm_term=&gclid=Cj0KCQjwntCVBhDdARIsAMEwACkGb2X-jlnPqTqaltdO49JmOLQFREfF94tp1S9dRzX6pyGRSkC0wYUaAm8hEALw_wcB)
- [Wemos d1 mini pro v2.0](https://www.reichelt.nl/nl/nl/d1-mini-esp8266-v2-0-d1-mini-p253978.html?PROVID=2809&gclid=Cj0KCQjw8O-VBhCpARIsACMvVLN1xLTCpVC0Wklr6kpkGidXt02jjd6Pnowqp3iYpxYQitq4FHLvUFoaAnEnEALw_wcB)
- A soldering kit, [this one](https://nl.rs-online.com/web/p/soldering-stations/4310367?cm_mmc=NL-PLA-DS3A-_-google-_-CSS_NL_NL_Power_Tools_%26_Soldering_%26_Welding_Whoop-_-(NL:Whoop!)+Soldering+Stations-_-4310367&matchtype=&aud-826607888587:pla-322411145756&gclid=Cj0KCQjw8O-VBhCpARIsACMvVLNdPkYiuYJw4LzC_cj1FHub7cORzBCIlOWYXGI6zRtSYCJBDYCcZjwaAk_GEALw_wcB&gclsrc=aw.ds) for example.
- A 3d printer, like [this one](https://www.bol.com/nl/nl/p/creality-3d-ender-3-pro-3d-printer/9200000104863827/?Referrer=ADVNLGOO002013-G-123000383400-S-1077204641435-9200000104863827&gclid=Cj0KCQjw8O-VBhCpARIsACMvVLN37_tz3NV-8HA5qnp7RjS0cgxXUmUQr1LgNN4y3NS6Rq-QCqG1Wg4aAuebEALw_wcB)
