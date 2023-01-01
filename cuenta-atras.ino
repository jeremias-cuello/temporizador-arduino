
int numeros[10][7] = {
// a|b|c|d|e|f|g
  {1,1,1,1,1,1,0}, // 0
  {1,1,0,0,0,0,0}, // 1
  {1,0,1,1,0,1,1}, // 2
  {1,1,1,0,0,1,1}, // 3
  {1,1,0,0,1,0,1}, // 4
  {0,1,1,0,1,1,1}, // 5
  {0,1,1,1,1,1,1}, // 6
  {1,1,0,0,0,1,0}, // 7
  {1,1,1,1,1,1,1}, // 8
  {1,1,0,0,1,1,1} // 9
};

/**
 * puerto -> segmento
 * 2 -> a
 * 3 -> b
 * 4 -> c
 * 5 -> d
 * 6 -> e
 * 7 -> f
 * 8 -> g
*/

const int pin_ini = 2;

void prenderNumero(int numero[]){
  for(int i = pin_ini; i < pin_ini + 7; i++){
    digitalWrite(i, numero[i-2]);
  }
}

void setup()
{
  for(int i = pin_ini; i < pin_ini+7; i++){
    pinMode(i, OUTPUT);
  }
}

bool seguir = true;

void loop()
{
  for (int i = 9; i >= 0 && seguir; i--) {
    prenderNumero(numeros[i]);
    delay(1 * 1000);
  } seguir = false;

  parpadear();
}

void parpadear(){
  for(int i = pin_ini; i < pin_ini + 7; i++){
    digitalWrite(i, LOW);
  } delay(500);

  for(int i = pin_ini; i < pin_ini + 7; i++){
    digitalWrite(i, HIGH);
  } delay(500);
}
