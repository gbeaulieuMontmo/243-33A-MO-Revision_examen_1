#include <Arduino.h>

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
  for(int i = 0; i < iNbre_saut; i++) Serial.println();
}

//Exercice 5 du cours 5 (révision)
//Écrire une fonction qui calcule la puissance d’un nombre
//La fonction prend en paramètre un nombre et la puissance
//La fonction retourne le résultat du calcul
//Exemple : puissance(2,3) = 8 (2x2x2)
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

//Exercice 5 du cours 5 (révision)
//Écrire une fonction qui calcule la puissance d’un nombre
//La fonction prend en paramètre un nombre et la puissance
//La fonction retourne le résultat du calcul
//Exemple : puissance(2,3) = 8 (2x2x2)
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

void setup() {
  Serial.begin(9600);

}

void loop() {
  test_Saute_10_Lignes();
  delay(2000);
  test_Sautes_Lignes();
  delay(5000);
}
