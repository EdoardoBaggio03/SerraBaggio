
#define encoderCLK 4 
#define encoderDT 2  
#define encoderSW 3  
int encoderCount = 0; 
int actCLKState;      
int prevCLKState;  

void setup() {
    pinMode(encoderCLK, INPUT);
    pinMode(encoderDT, INPUT);   
    // Setto la resistenza di pull-up - E' equivalente a:
    // pinMode(encoderSW, INPUT);   
    // digitalWrite(encoderSW, HIGH); 
    pinMode(encoderSW, INPUT_PULLUP);
    Serial.begin(9600);
    prevCLKState = digitalRead(encoderCLK);
}

void loop() {
actCLKState = digitalRead(encoderCLK);
    if (!digitalRead(encoderSW) && encoderCount!=0)
    {
        encoderCount = 0;
        Serial.println(encoderCount);
    }
   
    if (actCLKState != prevCLKState)
    {

        encoderCount += (actCLKState == digitalRead(encoderDT) ? 1 : -1);
        Serial.println(encoderCount);
        prevCLKState = actCLKState;
}
}
