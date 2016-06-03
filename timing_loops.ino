/*
  Timing experiments on Arduino. This version tested on Genuino Uno R3
  
  Principle : 1) Measure an empty for loop, using microsecondes time function.
              2) Measure the desired instruction/block/function using the same for loop structure
			  3) Print total time of the for loop and then the time taken by
			     the included code (by subtracting the time for an empty for loop)
*/

const int monBouton = 2; // bouton en broche 2
const int monBoutonConst = 2; // bouton en broche 2
unsigned int compteur = 0; // un compteur
unsigned int etatBouton; // L'état du bouton 
unsigned long time = 0;
unsigned long longI=0;
unsigned int intI=0;
unsigned long intDureeBouclesVides=0;
unsigned const int nbBouclesInt=10000;
unsigned const long nbBouclesLong=10000;
  
void setup() {   
  pinMode(monBouton, INPUT);
  Serial.begin(9600);
} 

void fonctionVide(){};

void afficheTemps() {
 Serial.print(time);
 Serial.print(" usec totales, soit ");
 Serial.print(time/nbBouclesInt);
 Serial.println(" microsecondes par boucle");
}

void loop() {
  
  Serial.println("Boucle 'for' vide, int i globale ");
  time=micros();
  for(intI=0;intI<nbBouclesInt;intI++){
  }
  time=micros()-time;
  intDureeBouclesVides=time; // garder pour plus tard
  afficheTemps();
  Serial.println("-------------------------------------");
 
  Serial.println("Boucle 'for' vide, int i locale ");
  time=micros();
  for(int i=0;i<nbBouclesInt;i++){
  }
  time=micros()-time;
  afficheTemps();
  Serial.println("-------------------------------------");

  Serial.println("Boucle 'for' vide, long i globale ");
  time=micros();
  for(longI=0;longI<nbBouclesLong;longI++){
  }
  time=micros()-time;
  afficheTemps();
  Serial.println("-------------------------------------"); 

  Serial.println("Boucle 'for' vide, long i locale ");
  time=micros();
  for(long longI=0;longI<nbBouclesLong;longI++){
  }
  time=micros()-time;
  afficheTemps();
  Serial.println("-------------------------------------");

  Serial.println("Boucle 'for' avec appel fonction vide(), int i globale ");
  time=micros();
  for(intI=0;intI<nbBouclesInt;intI++){
    fonctionVide();
  }
  time=micros()-time;
  afficheTemps();
  Serial.println("Moins le temps du 'for' vide =");
  time=time-intDureeBouclesVides;
  afficheTemps();
  Serial.println("-------------------------------------");


  Serial.println("Exemple code detection front. int monBouton");
  time=micros();
  for(intI=0;intI<nbBouclesInt;intI++) {
    etatBouton=digitalRead(monBouton);
    if (etatBouton)
      compteur++;
  }
  time=micros()-time;
  afficheTemps();
  Serial.println("Moins le temps du 'for' vide =");
  time=time-intDureeBouclesVides;
  afficheTemps();
  Serial.println("-------------------------------------");

  Serial.println("Exemple code detection front. const int monBoutonConst");
  time=micros();
  for(intI=0;intI<nbBouclesInt;intI++) {
    etatBouton=digitalRead(monBoutonConst);
    if (etatBouton)
      compteur++;
  }
  time=micros()-time;
  afficheTemps();
  Serial.println("Moins le temps du 'for' vide =");
  time=time-intDureeBouclesVides;
  afficheTemps();
  Serial.println("-------------------------------------");

  
  Serial.println("Detection front. const int monBoutonConst ReadFast");
  time=micros();
  for(intI=0;intI<nbBouclesInt;intI++) {
    etatBouton=PIND & B00000100;
    if (etatBouton) 
      compteur++;
  }
  time=micros()-time;
  afficheTemps();
  Serial.println("Moins le temps du 'for' vide =");
  time=time-intDureeBouclesVides;
  afficheTemps();
  Serial.println("-------------------------------------");

  
  while(1);
}
