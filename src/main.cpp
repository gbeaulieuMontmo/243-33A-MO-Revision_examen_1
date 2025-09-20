/**************************************************************/
// Date de création du programme: 15 septembre 2025
// Date de la dernière modification: 15 septembre 2025
// Nom du programmeur principal: Guillaume Beaulieu
//
// But du programme: solution des exercices de révision du cours 5
//
// Pour obtenir cet exemple de code, voir le dépôt GitHub suivant :
// https://github.com/gbeaulieuMontmo/243-33A-MO-Revision_examen_1.git
/**************************************************************/

#include <Arduino.h>
#include <bits_manip.h>
#include <math.h> //Pour la fonction puissance v2

#define DEL PL4 //Définition de la broche DEL 

//Exercice 3 du cours 5 (révision)
//Écrire une fonction qui saute 10 lignes dans le moniteur série
void Saute_10_Lignes()
{
  for(int i = 0; i < 10; i++)
  {
    Serial.println();
  }
}

//Exercice 4 du cours 5 (révision)
//Écrire une fonction qui prend en paramètre un entier et qui saute ce nombre 
//de lignes dans le moniteur série
void Sautes_Lignes(int iNbre_saut)
{
  if(iNbre_saut < 1) iNbre_saut = 1;
  if(iNbre_saut > 23) iNbre_saut = 23;

  //Ici on pourrait utiliser la fonction constrain de la librairie Arduino
  //à la place des deux lignes if ci-dessus
  //iNbre_saut = constrain(iNbre_saut, 1, 23); 
  
  for(int i = 0; i < iNbre_saut; i++) Serial.println();
}

//Exercice 5 du cours 5 (révision)
//Écrire une fonction qui calcule la puissance d’un nombre
//La fonction prend en paramètre un nombre et la puissance
//La fonction retourne le résultat du calcul
//Exemple : puissance(2,3) = 8 (2x2x2)
//***** solution sans la librairie math.h *****/
double puissance(int iNombre1, int iNombre2)
{
  int i;
  double dPuiss;
  dPuiss = iNombre1;
  for(i = 1; i < iNombre2; i++)
  {
    dPuiss *= iNombre1;
  }
  return dPuiss;
}

// Exercice 5 du cours 5 (révision) v2
//Écrire une fonction qui calcule la puissance d’un nombre
//La fonction prend en paramètre un nombre et la puissance
//La fonction retourne le résultat du calcul
//Exemple : puissance(2,3) = 8 (2x2x2)
//***** solution avec la librairie math.h *****/
double puissance_v2(double dNombre1, double dNombre2)
{
  return pow(dNombre1, dNombre2);
}

//Exercice 6 du cours 5 (révision)
//Fonction qui reçoit un chiffre. Si celui-ci est pair, la DEL  
//allume si le chiffre est impair la DEL clignote 4 fois.
void clignote_DEL(int iChiffre)
{
  if(iChiffre % 2 == 0) //Le chiffre est pair
  {
    PORTL |= (1 << DEL); //Allumer la DEL sans la librairie
    //PORTL = setBit(PORTL, DEL); //Allumer la DEL avec la librairie
  }
  else //Le chiffre est impair
  {
    for(int i = 0; i < 4; i++)
    {
      PORTL |= (1 << DEL); //Allumer la DEL sans la librairie
      //PORTL = setBit(PORTL, DEL); //Allumer la DEL avec la librairie
      delay(500);
      PORTL &= ~(1 << DEL); //Éteindre la DEL sans la librairie
      //PORTL = clearBit(PORTL, DEL); //Éteindre la DEL avec la librairie
      delay(500);
    }
  }
}

//Fonction de test pour Saute_10_Lignes
void test_Saute_10_Lignes()
{
  Serial.println("Avant");
  Saute_10_Lignes();
  Serial.println("Après");
} 

//Fonction de test pour Sautes_Lignes
void test_Sautes_Lignes()
{
  Serial.println("Avant");
  Sautes_Lignes(5);
  Serial.println("Après");
}

//Fonction de test pour la fonction puissance
void test_Puissance()
{
  int iBase, iExpo;
  double dResultat;
  iBase = 2;
  iExpo = 3;
  dResultat = puissance(iBase, iExpo);
  Serial.print("La puissance de ");
  Serial.print(iBase);
  Serial.print(" à la ");
  Serial.print(iExpo);
  Serial.print(" est égale à : ");
  Serial.println(dResultat);
}

//Fonction de test pour la fonction puissance_v2
void test_Puissance_v2()
{
  double dBase, dExpo;
  double dResultat;
  dBase = 2.5;
  dExpo = 3.0;
  dResultat = puissance_v2(dBase, dExpo);
  Serial.print("La puissance de ");
  Serial.print(dBase);
  Serial.print(" à la ");
  Serial.print(dExpo);
  Serial.print(" est égale à : ");
  Serial.println(dResultat);
}

//Fonction de test pour clignote_DEL
void test_clignote_DEL()
{
  int iChiffre;
  iChiffre = 3; //Impair
  clignote_DEL(iChiffre);
  delay(2000);
  iChiffre = 4; //Pair
  clignote_DEL(iChiffre);
}

void setup() {
  Serial.begin(9600);
  DDRL |= (1 << DEL); //Définir la broche de la DEL comme une sortie
  
  PORTL &= ~(1 << DEL); //éteindre la DEL sans la librairie
  //PORTL = clearBit(PORTL, DEL); //Éteindre la DEL avec la librairie
}

void loop() {
  test_Saute_10_Lignes();
  delay(2000);
  test_Sautes_Lignes();
  delay(2000);
  test_Puissance();
  delay(2000);
  test_Puissance_v2();
  delay(2000);
  test_clignote_DEL();
  while(1); //Arrêter le programme ici
}
