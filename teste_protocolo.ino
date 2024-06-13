String comando;
char ler;
int i=0, porta=0, valor=0, aux=2;
void setup()
{
  Serial.begin(9600); 
  pinMode(13, OUTPUT);
  pinMode(12, OUTPUT);
  pinMode(9, OUTPUT);
  pinMode(8, OUTPUT);
  pinMode(7, OUTPUT);
  pinMode(4, OUTPUT);
}

void loop()
{
  while (Serial.available()){
    ler = Serial.read();
    comando += ler;
    if((aux==2) || (ler == ';')){
      
      if (comando.substring(0,1) == "C") aux=1;
      if (comando.substring(0,1) == "A") aux=0;
      
      if(aux == 1){
        
        if(comando.substring(1,2) == "0") porta=13;
        if(comando.substring(1,2) == "1") porta=12;
        if(comando.substring(1,2) == "2") porta=8;
        if(comando.substring(1,2) == "3") porta=7;
        if(comando.substring(1,2) == "4") porta=4;
      		}
      if(aux == 0){
        if(comando.substring(1,2) == "0") porta=11;
        if(comando.substring(1,2) == "1") porta=10;
        if(comando.substring(1,2) == "2") porta=9;
        if(comando.substring(1,2) == "3") porta=6;
        if(comando.substring(1,2) == "4") porta=5;
      }

      if(aux == 1){
        valor = (comando.substring(2,3)).toInt();
      }
      if(aux == 0){
        valor= ((comando.substring(2,4)).toInt())*255/99;
      }
      if(aux==1)digitalWrite(porta, valor);
      if(aux==0)analogWrite(porta, valor);
    }
    if(comando != "") Serial.println(comando);		//Verifica a leitura do comando
    
  }
    if(aux == 1){
        if(comando.substring(3,4)== ";") comando = "";
      }
  if(aux == 0){
        if(comando.substring(4,5)== ";") comando = "";
      }
}