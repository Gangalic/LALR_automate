#include "symbole.h"
#include <iostream>

void Symbole::Affiche() {
  cout<<endl;
  cout<<Etiquettes[ident];
}

void Entier::Affiche() {
   Symbole::Affiche();
   cout<<"("<<valeur<<")";
}
