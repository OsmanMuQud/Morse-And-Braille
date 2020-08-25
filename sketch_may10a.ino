//by Osman Mustafa Quddusi
//This program can convert your message into Braille or Morse Depending on what functions you call 
//this uses single led to give out the message.
void setup() {
  //view in serial port
  //Serial.begin(9600);
  pinMode(13, OUTPUT);
}
String Mess= "put message here";
void loop() {

 Morse(MorseConv(Mess));
 
}
int dot=1000;

void Morse(String MorseM)
{
  int MorsePause[]={dot,3*dot,2*dot,4*dot};
  for (int i = 0; i < MorseM.length(); i++)
  {
    int value=(int)(MorseM.charAt(i)-'0');
    //view in serial port
    //Serial.println(value);
    digitalWrite(13,value<=1?HIGH:LOW);
    delay(MorsePause[value]);
    digitalWrite(13,LOW);
    delay(dot);
  }
}

void Braille()
{
   String Brail=BrailleConv(Mess);
  for (int i = 0; i < Brail.length(); i++)
  {
    if(Brail.charAt(i)=='1')
    {digitalWrite(13, HIGH);
    delay(500);
    digitalWrite(13,LOW);}
    else
    {digitalWrite(13,LOW);
    delay(500);
    digitalWrite(13,HIGH);
    }
    delay(50);
  }
  delay(8000);
}
String BrailleConv(String s)
{
  String Braille="";
        String DIR="100000110000100100100110100010110100110110110010010100010110101000111000101100101110101010111100111110111010011100011110101001111001010111101101101111101011";    
        s.toLowerCase();
        for(int i=0;i<s.length();i++)
        {
            char ch=s.charAt(i);              
            if((ch)==" ")
            {
                Braille+="000000";
                continue;
            }
            
            int p=(ch -'a')*6;
            Braille+=DIR.substring(p,p+6);
        }
        return Braille;
}
String MorseConv(String s)
{
  String mor="";
  String Morse[]={"01","1000","1010","100","0","0010","110","0000","00","0111","101","0100","11","10","111","0110","1101","010","000","1","001","0001","011","1001","1011","1100"};
  for(int i=0;i<s.length();i++)
        {
            char ch=s.charAt(i);  

            if((ch)==" ")
            {
                mor+="3";
                continue;
            }
            
            int p=(ch -'a');
            mor+=Morse[p]+"2";
        }
  return mor;
}
