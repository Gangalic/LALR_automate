#include "automate.h"

void Automate::decalage(Symbole * s, Etat * e){
  pileSymboles.push(s);
  pileEtats.push(e);
  if(s->isTerminal()){
    lexer->Avancer();
  }
}

void Automate::reduction(int n, Symbole * s){
  for (int i=0; i<n; i++){
    delete pileEtats.top();
    pileEtats.pop();
  }
  pileEtats.top()->transition(*this,s);
}

Symbole * Automate::depilerSymbole(){
  Symbole * temp = pileSymboles.top();
  pileSymboles.pop();
  return temp;
}

void Automate::empilerSymbole(Symbole * s){
  pileSymboles.push(s);
}

void Automate::analyser(){
  pileEtats.push(new Etat0("0"));
  bool temp = pileEtats.top()->transition(*this, lexer->Consulter());
  while(!temp){
    temp = pileEtats.top()->transition(*this, lexer->Consulter());
  }
  pileSymboles.top()->Affiche();
  cout<<endl;
}
