#include "MQTT/MQTT.h"

void callback(char* topic, byte* payload, unsigned int length);

String myID = System.deviceID();

int led0 = D7;
int In1 = D1;

/**
 * if want to use IP address,
 * byte server[] = { XXX,XXX,XXX,XXX };
 * MQTT client(server, 1883, callback);
 * want to use domain name,
 * MQTT client("www.sample.com", 1883, callback);
 **/
MQTT client("test.mosquitto.org", 1883, callback);

// recieve message
void callback(char* topic, byte* payload, unsigned int length) {
    char p[length + 1];
    memcpy(p, payload, length);
    p[length] = NULL;
    String message(p);
    
    if (message.equals("RGBON"))
        RGB.control(true);
        
    if (message.equals("RGBOFF"))
        RGB.control(false);
        
    digitalWrite(led0, HIGH);

    if (message.equals("RED"))    
        RGB.color(255, 0, 0);
    else if (message.equals("GREEN"))    
        RGB.color(0, 255, 0);
    else if (message.equals("BLUE"))    
        RGB.color(0, 0, 255);
    else    
        RGB.color(255, 255, 255);
        
    delay(5000);
    digitalWrite(led0, LOW);
}


void setup() {
    
    pinMode(led0, OUTPUT);
    pinMode(In1, INPUT_PULLDOWN);
    
    // connect to the server
    client.connect("connect");

    // publish/subscribe
    if (client.isConnected()) {
        RGB.color(0, 255, 0);
        client.publish(myID + "/RGB/Color","Control Online!");
        client.subscribe(myID + "/RGB/Color");
    } else {
        RGB.color(255, 0, 0);
    }
}

void loop() {
    if (digitalRead(In1)) {
        RGB.color(255, 0, 0);
        delay(3000);
        RGB.control(false);
        client.publish(myID + "/RGB/Color","Control Reset!");
    }    
    if (client.isConnected())
        client.loop();
        
        
}
