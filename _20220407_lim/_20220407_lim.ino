int echo = 3;     //IO 핀번호
int trig = 2;       //IO 핀번호
unsigned long duration;
float distance;
void setup() {
  //Initialize serial and wait for port to open:
   Serial.begin(9600);                //   시리얼 셋팅
    pinMode(echo, INPUT);       //   초음파 input  설정
    pinMode(trig, OUTPUT);      //  초음파 out  설정
    while (!Serial) {
   }
  
   // prints title with ending line break
   Serial.println("------- Start -------" );
}
void loop() {
  int i;
  duration = 0;
    
  digitalWrite(trig, HIGH);   // trigpin  에 High       를 출력
  delay(10);
  digitalWrite(trig, LOW);  // // trigpin  에 Low    를 출력
  
    duration = pulseIn(echo, HIGH);
 
  // Calcurate distance
  distance = ((float)(340*duration)/10000) / 2;
  Serial.print(distance);
  Serial.println("cm");
  if(distance < 15) {
    Serial.println("Warning");
  }
  delay(10); 
}
