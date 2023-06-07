# Mini Manuals

## Installation guide for Spring Boot:

1. Go to https://start.spring.io
2. Select which what type of project (maven or gradle) and in which code-language (java, kotlin or groovy) the package will include and what version of spring boot you want to include.
3. Select what type of package (jar or war) you want it to be exported to and which version of the code language.
4. Select dependencies if possible to be included in the package
5. Press generate

### Setup Spring Boot in Intellij Idea:

1. Now that you have a package make sure to make a folder called **backend** inside your project folder and drop your package inside this folder
2. Right click pom.xml file and scroll down till you find the "add as maven project" option and press add.
3. At this point you should have no errors inside your backend folder, run backendApplication.java and see if it compiles
4. If it compiles you should have a


### Connect your oege database to the spring boot backend:

1. Edit the application.properties file
2. Copypaste the code below into the application.properties file

```xml
spring.jpa.hibernate.ddl-auto=update
spring.datasource.url=<JDBC_connection_string>
spring.datasource.username=<username>
spring.datasource.password=<password>
spring.datasource.driver-class-name =com.mysql.cj.jdbc.Driver

server.port=<can be everything, for example: 8080. This will return localhost:8080>

spring.jpa.properties.hibernate.globally_quoted_identifiers=true
spring.jpa.properties.hibernate.dialect=org.hibernate.dialect.MySQL5InnoDBDialect

```

### Deployment:

While deploying sounds hard, in actuality it isn't. Here is how we can deploy the webpage using heroku.

We also assume that you are using an angular front-end and a spring boot backend

We used [this guide](https://gitlab.fdmci.hva.nl/se-ewa/deployment-workshop/-/blob/master/README.md), however down below will be a quick summary of this guide.

1. Create an account at [heroku](https://signup.heroku.com/login)
2. Create 2 new apps (1 for the backend and 1 for the front-end), make sure to give your domain a useful name/
3.

### Common issues:

You will find the most common errors/issues we found developing the backend/front-end in this section.

#### front end:

 sometimes if you change from the main branch to the tmp branch, which has the front end on it, you can't launch the web page successfully due to the fact that you get the following error:
 
##### Error in starting up the website
 ```

 zaka@MacBook-Pro-van-Zakaria iot-bmx-team1-nl % npm start
npm ERR! code ENOENT
npm ERR! syscall open
npm ERR! path /Users/zaka/package.json
npm ERR! errno -2
npm ERR! enoent ENOENT: no such file or directory, open '/Users/zaka/package.json'
npm ERR! enoent This is related to npm not being able to find a file.
npm ERR! enoent 

npm ERR! A complete log of this run can be found in:
npm ERR!     /Users/zaka/.npm/_logs/2022-07-04T13_23_37_601Z-debug.log
zaka@MacBook-Pro-van-Zakaria iot-bmx-team1-nl % 



```


##### How to fix the starting up in Angular:

1. In terminal type cd bmx-app to be in the correct folder.
2. Download the package.json again by typing npm install in the terminal.
2. after downloading, type npm start in the terminal to start the web application.

#### Backend:

##### Cors policy error:

If you get this in your console, this means that you got a Cors policy error.
![img.png](img.png)

Which basically indicates that the request your trying to make does not uphold Cors security standards.

##### How to fix Cors policy error in Spring boot:

1. Create a class called WebMvcConfig
2. Paste the following code in your WebMvcConfig

```java
@Configuration
public class WebMvcConfig implements WebMvcConfigurer {
    @Override
    public void addCorsMappings(CorsRegistry corsRegistry){
        corsRegistry.addMapping("/**")
                .allowedMethods("GET","POST","PUT","DELETE")
                .allowedOriginPatterns("*")
                .allowedHeaders("*")
                .allowCredentials(true);
    }
}

```

3. Restart your backend, now you shouldn't be getting a cors policy error

##### Infinite recursion

When working on your backend and testing the different paths inside your controllers you might come across a stackoverflow error
when requesting an object which is related to another object.

This is caused by infinite recursion when jackson (which is part of Jpa) tries to serialize both sides of this relationship.
To solve this issue there are 2 primary ways of doing this:

1. Adding an @JsonIgnore in the parent of the relationship

```java
Parent.class
...
@OneToMany(mappedBy = "athlete", cascade = CascadeType.ALL, fetch = FetchType.LAZY)
@JsonIgnore
private List<TrackTimeRecord> trackTimeRecords;
```

```java
Child.class
```

2. Adding @JsonManagedReference in the parent and @JsonBackReference in the child class

```java
Parent.class
...
@OneToMany(mappedBy = "athlete", cascade = CascadeType.ALL, fetch = FetchType.LAZY)
@JsonManagedReference(value = "trackTimeRecords")
private List<TrackTimeRecord> trackTimeRecords;
```

```java
Child.class
...
@ManyToOne(targetEntity = Athlete.class, fetch = FetchType.EAGER)
@JoinColumn(name = "athlete_id")
@JsonBackReference(value = "trackTimeRecords")
private Athlete athlete;

```

##### How to make a post request with parent and child

While there are many ways to do this, I chose the easiest solution.
Which was passing the id of the athlete (in this case the foreign key) in the route.
Then using this foreign key I find the athlete related to the foreign key and then call the setter used to get tracktimerecords with their athletes

The primary reason why I did it this way is because you can't save a child without saving its entire parent in Spring Boot.

```java
Childcontroller.class
...
@PostMapping("/measurement/{athleteId}")
   public ResponseEntity<TrackTimeRecord> createTrackTimeRecord(@RequestBody TrackTimeRecord trackTimeRecord, @PathVariable int athleteId){
    
        trackTimeRecord.setAthlete(athleteRepository.findById(athleteId));
        trackTimeRecordRepository.save(trackTimeRecord);


        URI location = ServletUriComponentsBuilder
                .fromCurrentRequest()
                .path("/{id}")
                .buildAndExpand(trackTimeRecord.getId()).toUri();

        return ResponseEntity.created(location).body(trackTimeRecord);
   }
```


## Manual for POST EN GET request for the Wemos

### Tutorial we used to learn how POST and GET request works with a wemos

[ESP8266 NodeMCU HTTP GET and HTTP POST with Arduino IDE](https://randomnerdtutorials.com/esp8266-nodemcu-http-get-post-arduino/)

![](ESP8266-NodeMCU-HTTP-GET-HTTP-POST-with-Arduino-IDE-JSON-URL-Encoded-Text.jpeg)

## Installing the library's

### Download these libraries



[Arduin json library](https://github.com/arduino-libraries/Arduino_JSON)


### Installing libraries

| ![Installing the librarys](Arduino library installing.png) |
|:----------------------------------------------------------:|
|                 Going to manage libraries                  |


| ![Screenshot Json library](Screenshot 2022-06-20 at 13.37.41.png) |
|:-----------------------------------------------------------------:|
|                          Library screen                           |

Install al these libraries:

- DHT.h
- DNSServer.h
- ESP8266WebServer.h
- ESP8266HTTPClient.h
- ArduinoJson.h
- NTPClient.h
- WiFiClient.h
- "WiFiUdp.h"

If you have installed al the libraries you can run this code:

[HTTP GET and POST code](https://raw.githubusercontent.com/RuiSantosdotme/Random-Nerd-Tutorials/master/Projects/ESP8266/HTTP/ESP8266_HTTP_GET_Update.ino)












