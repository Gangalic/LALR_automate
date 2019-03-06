#include "etat.h"

bool Etat0::transition(Automate & automate, Symbole * s){
  switch (*s) {
    case INT:
      automate.decalage(s, new Etat3("3"));
      break;
    case OPENPAR:
      automate.decalage(s, new Etat2("2"));
      break;
    case EXPR:
      automate.decalage(s, new Etat1("1"));
      break;
  }
  return false;
}

bool Etat1::transition(Automate & automate, Symbole * s){
  switch (*s) {
    case PLUS:
      automate.decalage(s, new Etat4("4"));
      break;
    case MULT:
      automate.decalage(s, new Etat5("5"));
      break;
    case FIN:
      return true;
  }
  return false;
}
