int monBouton = 2; // bouton en broche 2
const int monBoutonConst = 2; // bouton en broche 2
int compteur = 0; // un compteur
int etatBouton; // L'état du bouton 
long time = 0;
int longI=0;
int intI=0;
long intDureeBouclesVides=0;
const int nbBouclesInt=10000;
const long nbBouclesLong=10000;
  
void setup() {   // le bouton en entrée   
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
