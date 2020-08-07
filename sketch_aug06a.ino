int sheet[]={
//At Doom's Gate - DOOM - E1M1 (Best at : Speed 0.65 / Octavia 0)
12,12,22,12,12,112,12,12,110,12,12,18,12,12,19,110,
12,12,22,12,12,112,12,12,110,12,12,18,0,0,0,0

//11,0,0,1,11,0,1,11,1
};

float sheetSpeed = 0.65; // default => 1
int octavia = 1; //default => 0
int bootOctavia;
int note;
String noteString;
String noteHeightString;
int noteHeight;
int lastNote;
int x;

//comp
const int ledPin = 13;
const int buzPin = 8;


void setup(){
  Serial.println("Setup");
  pinMode(ledPin,OUTPUT);
  digitalWrite(ledPin, HIGH);
  bootOctavia = octavia;
  octavia = 1;
  //Nintendo - Gameboy startup
  play(312,50);
  delay(50);
  play(45,500);
    delay(2000);
  //SEGA - Game boot
  play(38,1000);
  delay(1000);
  play(35,1000);
  delay(1000);
  
  octavia = bootOctavia;
}

void loop(){
  
  for(x=0;x<(sizeof(sheet) / sizeof(sheet[0])); x++){
    note = sheet[x];
    digitalWrite(ledPin, LOW);
    
    //.charAt(n)  substring()
    
    if(note == 0){
      play(lastNote,250*sheetSpeed);
      delay(200*sheetSpeed);
    }else if(note == 1){
      delay(200*sheetSpeed);
    }else{
      delay(50*sheetSpeed);
      play(note,200*sheetSpeed);
      lastNote = note;
      delay(150*sheetSpeed);
  }
  Serial.println(note);
}
}

int play(int note, int l){
  //y note pendant l millisecondes à la hauteur h
  noteString = String(note);
    
    noteHeightString=String(noteString.charAt(0));
    noteString = noteString.substring(1);
    Serial.println(noteString);
    Serial.println(noteHeightString);
    note = noteString.toInt();
    noteHeight = noteHeightString.toInt()+octavia;
    Serial.println(note);
    Serial.println(noteHeight);
    
  switch(note){
    case 1: tone(buzPin,32.70*pow(2,noteHeight),l);
    break;
    
    case 2: tone(buzPin,34.65*pow(2,noteHeight),l);
    break;
    
    case 3: tone(buzPin,36.71*pow(2,noteHeight),l);
    break;
    
    case 4: tone(buzPin,38.89*pow(2,noteHeight),l);
    break;
    
    case 5: tone(buzPin,41.20*pow(2,noteHeight),l);
    break;
    
    case 6: tone(buzPin,43.65*pow(2,noteHeight),l);
    break;
    
    case 7: tone(buzPin,46.25*pow(2,noteHeight),l);
    break;
    
    case 8: tone(buzPin,49.00*pow(2,noteHeight),l);
    break;
    
    case 9: tone(buzPin,51.91*pow(2,noteHeight),l);
    break;
    
    case 10: tone(buzPin,55.00*pow(2,noteHeight),l);
    break;
    
    case 11: tone(buzPin,58.27*pow(2,noteHeight),l);
    break;
    
    case 12: tone(buzPin,61.74*pow(2,noteHeight),l);
    break;
  
  }
  
  
      digitalWrite(ledPin, HIGH);
}

