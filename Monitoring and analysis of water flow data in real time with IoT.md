# Monitoring and analysis of water flow data in real time with IoT
Yindra Yuliana Perez-Vargas
yindraperezvargas699@gmail.com
Joan Francisco Rojas-Varela
jofarova214@gmail.com
Kristhel Nayeli Guido-Ramos
kristhel26@gmail.com

Computer Engineering Career, Instituto Tecnol ́ogico de Costa Rica

### Abstract
This project shows how the IoT can be implemented in a basic way in daily life, in this case facilitating the visualization of the water consumption of a home by the user, since an Arduino sensor is used to control the flow of water and collect data on water consumption in a system. The information collected is stored in a database and can be accessed through a mobile application. The introductory section presents the problem of water management and the need for real-time monitoring solutions to optimize the use of resources. Next, the problem of the project is described and the solution proposal is proposed, which is based on an Arduino device and an IoT solution. In the related works section, previous projects that have used IoT solutions to monitor water consumption are discussed. The limitations and opportunities of these projects are presented to compare with the proposal presented. In the conceptual framework section, the basic concepts of the IoT solution are explained and the Arduino device used in the project is described. The database and the mobile application used to access the data are also analyzed. In the project proposal section, the implementation of the system is described and the design of the Arduino device and the water flow control circuit are presented. In addition, the structure of the database and the functionality of the mobile application are detailed.
In the section on functional tests of the prototype, the results of the tests carried out on the prototype are discussed. The collected data is presented and analyzed to assess the performance and effectiveness of the system. In the conclusion section, the results are summarized and the contributions of the project are discussed. Limitations are also identified and possible future work is proposed. We present an effective IoT solution to monitor water consumption using an Arduino device and a database. The project demonstrates an efficient and accessible way to monitor water use in real time and can help reduce water consumption, optimize resource use and raise awareness about the problem.

### Introduction
The efficient use of water is a global concern. Population growth and climate change are increasing the demand for water and putting pressure on existing water resources. To deal with this problem, real-time monitoring of water consumption is presented as a key solution to optimize resources and reduce unnecessary consumption. The Internet of Things (IoT) is a technological tool that can be used to implement real-time monitoring solutions for water consumption in homes and buildings. In a recent project, a solution based on an Arduino device and a mobile application to monitor water consumption was proposed. This solution allows you to monitor water consumption in real time and make informed decisions about its use. The objective is to present an effective and accessible solution to reduce unnecessary consumption and optimize the use of water. The implementation of this monitoring system gives users greater control over their water consumption, promoting awareness of conservation and responsible use of the resource. In addition, by detecting abnormal or excessive consumption patterns, possible leaks or problems in the distribution network can be identified, which contributes to more efficient and sustainable water management.

### Problematic
The massive consumption of water in Costa Rican homes is an issue of great importance and concern, since water is a scarce and essential resource for life. However, many households do not have a clear idea of the amount of water they consume daily and do not take measures to reduce their unnecessary consumption. In addition, increasing demand for water due to population growth, climate change, and urbanization put increasing pressure on water resources. The lack of real-time monitoring of water consumption is one of the main obstacles to efficient water management in homes. Currently, most households have water meters, but these only provide a general reading of water consumption and do not allow for real-time monitoring. This makes it difficult to identify problems and make informed decisions to reduce water consumption. In addition, the lack of awareness about the impact of excessive water consumption on the environment and on the household economy further aggravates this situation. In this context, the use of IoT technology can provide an effective and accessible solution to monitor water consumption in real time and make informed decisions about its use. Therefore, the objective of this project is to implement an IoT solution to monitor water consumption in Costa Rican homes and contribute to raising awareness about the responsible use of water.

### Related jobs
Considering the problem mentioned above, there are various technologies that can help face the challenges of water control and management in Costa Rica. These technologies vary in their complexity and functionality, adapting to different approaches and specific objectives. This project focuses on developing an interface that provides information on water consumption, simplifying meter reading. This is important, as workers sometimes make mistakes or the results are incorrect. In addition, an intelligent billing system based on the measurements provided by the interface will be implemented, which will allow a clear visualization for users and promote awareness of excessive water consumption and use. 

Over the years, various projects have been carried out that have explored the use of IoT technologies for monitoring water consumption in homes, buildings and/or cities. Below are some of the works most relevant to our research, which have addressed similar issues and used key components.

We focused on a Bolivian thesis [1] that addressed the issue of water consumption in a neighborhood. In this study it was decided to use an ESP32 instead of a conventional Arduino, like the one we are using in our project. The choice of the ESP32 is due to its advantages in terms of connectivity, since it facilitates communication with the servers via WiFi and with the required application.
Although we are implementing the Blynk platform, which also allows the connection of IoT devices through a computer and the sending of data using the Blynk API, it is interesting to see how the use of the ESP32 has proven to be effective in the aforementioned thesis. However, it is important to take into account that the thesis identified a limitation associated with the use of voltage sensors to calibrate the collected data. In some cases, these sensors can generate interference that reduces the accuracy of the results obtained, which implies the need to make adjustments and consider alternatives to obtain more accurate and reliable data.

In addition, we have found guidance in the company Lain Holding [2], which is located in Costa Rica and works with various technological solutions. Among them stands out IoT SigFox [3], a meter that allows to control the flow of water consumed and perform various tasks based on this information. This meter is especially oriented to water service companies that serve thousands of customers. Although it has characteristics of an IoT device, it maintains an analog format to physically display the data.
However, like the previous proposal, this approach also has its limitations, mainly regarding the cost of the device. Due to its broad scope and complexity, its value is higher, making it less affordable to implement in average-cost homes.

We have also relied on another Ecuadorian thesis [4], which gave us guidance on monitoring water flow. However, unlike the aforementioned thesis, this research covered a much larger scale, since it was proposed to collect data from 14 cantons of the community, which in total add up to a population of 60,440 inhabitants and an extension of 112.60 km².
To carry out this large-scale project, the use of the ESP8266 WiFi module was implemented, which is responsible for integrating the sensors and devices through the network. In addition, the NRF24L01 was used, a transmitter with a considerably long range, which is crucial for the successful development of the project. This transmitter allows long-distance communication, which is of great importance given the extension of the area to be monitored.
However, it is important to mention that one of the limitations identified in this project was the high cost associated with its large-scale implementation. A considerable initial investment was required and, unfortunately, it could not be further financed in the future.

Another approach we investigated was automatic metering and smart meters, along with automatic meter reading (AMR) [5], are key tools for efficiently capturing and recording water consumption. AMR devices, whether portable or vehicle-mounted, use radio technology to collect accurate data from water meters, allowing reading without the need for physical visits. This simplifies the reading and billing process, providing more accurate data and reducing manual intervention. In short, the combination of automatic metering, smart meters, and AMR improves water management by speeding up data collection and facilitating more accurate billing.

These previous projects demonstrate the interest and feasibility of using IoT technologies, such as Arduino and G12 water flow sensors, to monitor water consumption in real time. However, each has slightly different limitations and approaches. This project seeks to address these limitations and propose a comprehensive solution that combines the aforementioned components and offers an intuitive interface for the user, while ensuring efficient storage and analysis of water consumption data.

### Conceptual framework
- G12 water flow sensor: According to [6] is a device used to measure the amount of liquid that has passed through a water pipe or hose 1. This sensor uses a paddle sensor to measure the speed of the liquid and, from that speed, the flow or volume of liquid that circulates through the tube in a certain period of time can be calculated.
    
- Arduino: Its a free and open source hardware platform used to design and build interactive electronic devices [9]. The platform allows users to create custom projects using a programmable microcontroller and a series of input/output pins used to connect various components [10] The code is written in the Arduino Integrated Development Environment (IDE) and uploaded to the board via a USB cable. Arduino is extremely popular in both the hobbyist and industry communities for creating a variety of electronic devices and projects, such as robots, home automation systems, and sensors for environmental monitoring, among others.
- LCD screen
    An LCD (Liquid Crystal Display) is a thin [13], flat screen made up of several pixels that use liquid crystal technology to display images and text. In our project it will show the information that the g12 sensor will send it and you will be able to see the liters that pass and the money that those reflect.
    
- Internet of things (IoT): Reference is made to the interconnection and communication between physical objects or devices equipped with sensors and embedded software through the use of the Internet [11]. These objects have the ability to collect and share data in real time, leading to greater efficiency and automation in industrial, commercial, and residential processes. The connection and communication of these devices through the Internet allows them to interact with each other and with other systems, thus creating an interconnected environment that facilitates the exchange of information and the making of smarter decisions.
    
- Server and App: Blynk [12] is an IoT platform that allows users to create apps for devices, control them remotely, and receive data in real time. The Java-based server can run in the cloud or on a local computer or device. The Blynk server establishes direct communication with the hardware, collecting data from the sensors and sending it to the application in real time.

### Project proposal
The proposal of this project focuses on the development of an IoT solution that allows monitoring water consumption in Costa Rican homes. The use of an Arduino sensor is proposed to control the flow of water and collect consumption data in a system that stores the information in a database. In addition, a mobile application will be developed to access this data and provide the user with a detailed analysis of their water consumption.
The main objective of this project is to make users aware of their water consumption and help reduce its use. With the information collected, users will be able to identify consumption patterns, detect possible leaks or waste and take measures to reduce their consumption. The mobile app will provide a user-friendly interface for users to monitor and analyze their water consumption in real time.
The proposed solution must be accessible and easy to implement in Costa Rican homes, with reasonable costs and an intuitive interface for the user. To ensure the compatibility and safety of the system, local regulations and standards must be taken into account. This solution is expected to be effective in helping to reduce water consumption in Costa Rican homes and promote sustainable management of natural resources.


- Back-End  (Server)  
The server runs on the Arduino itself and acts as a web server, that is, it listens for incoming requests from web clients and responds accordingly.

In this case, the Arduino would be connected to a USB port on a computer, and through that port, it would receive HTTP requests from the web client. The Blink server would respond to those requests and control the LED to blink at the desired frequency.

It is important to note that the arduino must be previously programmed with the necessary code to be able to run the Blink server. Also, you need to have a stable connection between the arduino and the computer via the USB port so that the server can receive requests from the client.
  
- Front-End 
 Once the user logs into the Blink app, they are presented with an intuitive and easy-to-use interface. In this interface, a real-time module is highlighted that dynamically displays the amount of water currently flowing in the home. This visual module provides the user with an instant graphical representation of water consumption, allowing him to have a clear idea of the amount of water being used in real time.

Just below the real-time display module is a detailed data table. This table displays periodic information about water consumption, including historical records and data collected by the sensor at that time. The table offers the user a more complete view of the consumption pattern over time, allowing him to identify trends, consumption peaks or significant changes in water use.

In addition, the data table can present additional relevant information, such as daily, weekly or monthly consumption statistics and averages. This allows the user to have a more accurate and detailed understanding of their water consumption over time and compare it to previous periods. These historical and comparative data can be especially useful for evaluating the effectiveness of implemented water saving measures and for making informed decisions on how to further reduce consumption.

### Functional tests of the prototype

During the development of the project, various tests were carried out following the proposed scheme. 
\begin{itemize}
\item It started by collecting information from the G12 sensor, which records water consumption data. This data is sent to the Arduino, which acts as an intermediary.

-  The Arduino is in charge of transmitting the collected data to the computer, thus establishing a connection between the two devices. Once the data is sent by the Arduino, we proceed to read it on the computer.

-  The collected data is then sent to the application server. This process ensures that the data is stored securely and is available for further analysis.

-  Finally, the data is found on the server and is presented to the user through an intuitive and friendly interface. This interface allows the user to easily access and view the data, providing a clear and understandable representation of water consumption.




Similarly, the accuracy and consistency of the data collected during the constant flow of water was analyzed. The measurements obtained were compared with the actual flow to verify the accuracy of the system and confirm its ability to provide reliable data under conditions of continuous use.



### Conclusion
- The use of IoT technologies such as Arduino and G12 water flow sensors offer a versatile and scalable solution to monitor water consumption. These devices are easily programmable and can be adapted to different configurations and specific needs of Costa Rican homes. Additionally, their low cost and market availability make them an affordable option for implementing water monitoring systems in a wide range of homes.

- The integration of a database to store the collected water consumption data provides a number of significant advantages. First, it allows for long-term data storage, making it easy to analyze historically and identify long-term patterns in water use. In addition, the database provides a centralized platform for managing and processing the data, making it easy to generate detailed reports and statistics on water consumption. These reports can be used both by individual users and by the authorities or companies responsible for water management to make informed decisions and improve efficiency in the use of water resources.

- The combination of IoT technology and an intuitive interface in a mobile application is a key factor in facilitating the access and use of water consumption information by users. An intuitive and easy-to-use interface allows users to quickly view and understand the data collected, allowing them to make informed decisions about how to reduce their water use. Additionally, a mobile app offers the convenience of accessing real-time data from anywhere at any time, enhancing the ability to monitor and control water consumption. By providing clear and understandable information, the mobile application becomes an effective tool to promote behavior change and awareness in the use of water, which in turn contributes to the conservation and sustainability of water resources.

### Future works

- Monitoring system optimization: The possibility of improving the accuracy and efficiency of the monitoring system can be explored through periodic calibration of the G12 water flow sensors and implementation of more advanced data processing algorithms. This will ensure the most accurate detection and the highest reliability in the data collected.
    
-  Integration with other IoT devices: Considering the increasing adoption of smart devices in homes, integration of the water monitoring system with other IoT devices such as smart energy indicators and automated irrigation systems can be explored. This will allow a more comprehensive and efficient management of household resources.

-  Advanced data analytics: Future research may further analyze the collected data, using more advanced data analytics techniques such as machine learning and predictive analytics. This will make it possible to identify more complex patterns and trends in water consumption, as well as provide more personalized recommendations to users to optimize their consumption.

-  Community Expansion: One possible future direction is to expand the implementation of the monitoring system to the community level, rather than just being limited to the residential setting. This will allow for a broader analysis of water consumption in a community and will facilitate the implementation of large-scale water conservation and management strategies.

-  Integration with water management systems: It would be interesting to explore the integration of the monitoring system with existing water management systems in Costa Rica. This would allow a two-way data exchange, which would facilitate the early detection of leaks or problems in the supply network and would improve efficiency in the management of water resources.

### References

[1] 330ohms. ¿Qu ́e es una Protoboard? 2016. url: https://blog.330ohms.com/2016/03/02/protoboards/.
[2] Oracle — Cloud Applications and Cloud Platform. ¿Qu ́e es el Internet de las cosas (IoT)? 2020. url: https:
//www.oracle.com/mx/internet-of-things/what-is-iot/.
[3] Arduino.cl. ¿Qu ́e es Arduino? 2010. url: https://arduino.cl/que-es-arduino/.
[4] Azure IoT Central. “Uso del puente de dispositivos de IoT Central para conectar otras nubes de IoT a IoT
Central”. In: (June 2023). url: https://learn.microsoft.com/es-es/azure/iot-central/core/howto-
build-iotc-device-bridge.
[5] Blynk Community. examples-¿blynk. 2020. url: https://community.blynk.cc/t/almacenar- variable/
46126.
[6] Arduino Docs — Arduino Documentation. Liquid Crystal Displays (LCD) with Arduino — Arduino Docu-
mentation. 2023. url: https://docs.arduino.cc/learn/electronics/lcd-displays.
[7] LAIN HOLDINGS”. “Sigfox IOT No.1 Costa Rica Soluciones Internet Of Things”. In: 2009. url: https:
//lainholding.com/sigfox- iot- costa- rica- internet- of- things/#:~:text=Soluciones’ 20IOT’
20de’20extremo’20a’20extremo’20Sigfox’2.
[8] Aula21 — Formaci ́on para la Industria. Arduino: Gu ́ıa completa para principiantes y expertos — Aprende ya.
2012. url: https://www.cursosaula21.com/arduino-todo-lo-que-necesitas-saber/.
[9] Sgmls.com. G12 water flow sensor. url: https://es.sgmls.com/new-water-flow-switch-g1-2-copper-
hall-effect-liquid-water-flow-sensor-switch-flowmeter-meter-1-30l-min.html.
[10] M. Suresh, U. Muthukumar, and J. Chandapillai. “A novel smart water-meter based on IoT and smartphone
app for city distribution management”. In: 2017 IEEE Region 10 Symposium (TENSYMP). July 2017, pp. 1–
5. doi: 10.1109/TENCONSpring.2017.8070088.
[11] Mundo teleco. ¿Como usar el protoboard? 2014. url: https://mundotelecomunicaciones1.blogspot.com/
2014/10/como-usar-el-protoboard.html/.
[12] J. J. C. Maraza Vigabriel. “Prototipo de medidor de agua IoT para el control y monitoreo del consumo de
agua potable en hogares de la ciudad de la paz”. In: 2021, p. 163. url: https://repositorio.umsa.bo/
xmlui/bitstream/handle/123456789/28899/T-3879.pdf?sequence=1&isAllowed=y.
[13] D. V. Carrera Villacr ́es. “Sistema automatizado de control y monitoreo del funcionamiento de la planta de
agua potable regional Arenillas Huaquillas basado en internet de las cosas (IoT)”. In: Oct. 2021, p. 76. url:
http://repositorio.espe.edu.ec/bitstream/21000/28914/1/T-ESPE-052112.pdf.
