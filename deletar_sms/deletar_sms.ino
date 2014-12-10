#include <GSM_Shield.h>
int error;
GSM gsm;


void setup(){
  Serial.begin(9600);
  Serial.println("system startup"); 
  gsm.TurnOn(9600);          //module power on
  gsm.InitParam(PARAM_SET_1);//configure the module  
  gsm.Echo(0);               //enable AT echo 

}
void loop(){
  char pos_sms_rx = 12;//posicao do sms pra apagar
  error=gsm.DeleteSMS(pos_sms_rx);
  if (error==1){

    Serial.println("SMS deleted");
  }      
  else {
    Serial.println("SMS not deleted");
  }
}

