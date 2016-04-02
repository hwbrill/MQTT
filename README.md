# CLI as a MQTT|Particle Client
<a href="https://www.npmjs.com/package/mqtt#command-line-tools" target=_blank>NPM MQTT.js</a> #command-line-tools
To work with the Particle RGBcolor example using the CLI and NPM's MQTT.js:

Replace 'hello' to 'RGB/Color' as the Topic, or whatever is defined in your source code.
Replace 'from MQTT.js' with 'RED','GREEN','BLUE' to change the color.


Referenced: hirotakaster/MQTT
MQTT for Photon, Spark Core
<a href="http://mqtt.org/" target=_blank>MQTT</a> publish/subscribe library for Photon, Spark Core version 0.3.7.

Source Code
This lightweight library source code are only 2 files. firmware -> MQTT.cpp, MQTT.h.

Application can use QOS0,1,2 and retain flag when send a publish message.

Example
Some sample sketches for Spark Core and Photon included(firmware/examples/).
 - mqtttest.ino	: simple pub/sub sample. 
 - mqttqostest.ino : QoS1, QoS2 publish and callback sample.

Arduino compatible
This library is Arduino compatible. Arduino version is <a href="https://github.com/hirotakaster/MQTT/tree/arduino">here</a>. 
