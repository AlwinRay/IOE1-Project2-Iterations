#define button 4

int button_state = 0;
int potentiometer = A0;
int light_sensor = A3;
int sound_sensor = A2; //added the sound sensor

int sensors[4];

void setup() {
   // start serial port at 9600 bps:
   Serial.begin(9600);
   pinMode(button, INPUT);
   pinMode(potentiometer,INPUT);
   
}
 
void loop() {
 // this example uses sensors with a different ranges
 //use the map() method to convert the range 

    //read the number from the button sensor and put the value 
    //into the first index of the Array, repeat for all indexes of the Array
    
    button_state = digitalRead(button);
    sensors[0] = button_state;
    
    int sensor_value = analogRead(potentiometer);
    int value = map(sensor_value, 0, 1023, 0, 100);
    
    sensors[1] = sensor_value;
    
    int raw_light = analogRead(light_sensor);
    int light = map(raw_light, 0, 1023, 0, 100);
    
    sensors[2] = light;

    //added sound value 
    int sound_value = analogRead(sound_sensor);
    int sounds = map(sound_value, 100, 100, 100, 100);
    
    sensors[3] = sounds;
    
    if (button_state == HIGH){
        
      }


    //I changed the value of thisSensor to < 4
    for (int thisSensor = 0; thisSensor < 4; thisSensor++) {

        int sensorValue = sensors[thisSensor];
      
      Serial.print(sensorValue);
      if (thisSensor == 3) {
         Serial.println();
      } else {
         Serial.print(",");
      }
   }
    delay(100);              
}
