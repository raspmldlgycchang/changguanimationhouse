int R=5;
int Y=6;
int G=13;
int SW=7;
int buz=3;
#define DO 261
#define RE 293
#define MI 329
#define FA 349
#define SOL 392
#define LA 440
#define SI 493
#define DOS 523
int music[] = {DOS,0,DOS,0,LA,0,LA,0,SOL,0,SOL,0,LA,0,SOL,0,DOS,0,DOS,0,LA,0,LA,0,SOL,0,SOL,0,LA,0,SOL,0,DOS,DOS,DOS,SI,SI,SI,LA,LA,SOL,SOL,SOL,MI,MI,MI,MI,SOL,0,SOL,0,SOL,0,LA,LA,0,LA,LA,0,LA,LA,LA,0,LA,LA,LA,0,SI,SI,0,SI,SI,SI,0,LA,LA,0,SI,SI,SI,0,DOS,DOS,DOS,DOS,DOS,DOS,0,0,0,0,0,0,0};
int sound[]={LA,LA,LA,0,0,SOL,SOL,SOL,0,0,LA,LA,LA,0,0,SOL,SOL,SOL,0,0};
void setup() {
  // put your setup code here, to run once:
  pinMode(R,OUTPUT);
  pinMode(Y,OUTPUT);
  pinMode(G,OUTPUT);
  pinMode(SW, INPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  int readValue=digitalRead(SW);
  if(readValue==HIGH){
    for(int i=0;i<(sizeof(sound)/sizeof(int));i++){
      tone(buz,sound[i], 1050);
      delay(130);
    }
    digitalWrite(R, HIGH);
    digitalWrite(Y, LOW);
    digitalWrite(G, LOW);
    delay(250);
    digitalWrite(R, LOW);
    digitalWrite(Y, HIGH);
    digitalWrite(G, LOW);
    delay(250);
    digitalWrite(R, LOW);
    digitalWrite(Y, LOW);
    digitalWrite(G, HIGH);
    delay(250);
    delay(10000);
    for(int i=0;i<(sizeof(music)/sizeof(int));i++){
      tone(buz,music[i], 1050);
      delay(130);
    }
  }
}
