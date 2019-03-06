#include "symbole.h"
#include <iostream>

void Symbole::Affiche() {
  cout<<Etiquettes[ident];
}

void Entier::Affiche() {
   Symbole::Affiche();
   cout<<"("<<valeur<<")";
}

void Expr::Affiche() {
  //Symbole::Affiche();
  //cout<<"("<<valeur<<")";
  // sortie plus joli pour tester interactivement
  cout<<"Votre resultat est: "<<valeur;
}

int Entier::getValeur(){
  return valeur;
}

int Expr::getValeur(){
  return valeur;
}
