//variaveis
long lastTime;
double Input, Output, Setpoint;
double errSum, lastErr;
double kp, ki, kd;
int amostragem = 100; // = 1s

//função para computar
void Compute(){
  long now = millis();
  int timeChange = (int)(now - lastTime); 
  if (timeChange>=amostragem){  //nova
    double error = Setpoint - Input;
    errSum += (error * timeChange);
    double dErr = (error - lastErr)/timeChange;
    
    Output = kp * error + ki * errSum + kd * dErr;
  
    lastErr = error;
    lastTime = now;
  } //nova
}
void SetPesos(double nkp, double nki, double nkd){
   kp = nkp;
   ki = nki;
   kd = nkd; 
}
void SetAmostragem(int novaAmostragem){
  if (novaAmostragem>0){
    double taxa = (double)novaAmostragem/(double)amostragem;  
    ki *= taxa;
    kd /= taxa;
    amostragem = (int)novaAmostragem;
  }
}














void setup() {
  // put your setup code here, to run once:

}

void loop() {
  // put your main code here, to run repeatedly:

}
