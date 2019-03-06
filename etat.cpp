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
    default:
      cout<<"Erreur juste apres:"<<endl;
      return true;
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
    default:
      cout<<"Erreur juste apres:"<<endl;
      return true;
      break;
  }
  return false;
}

bool Etat2::transition(Automate & automate, Symbole * s){
	switch(*s){
		case INT:
			automate.decalage(s, new Etat3("3"));
			break;
		case OPENPAR:
			automate.decalage(s, new Etat2("2"));
			break;
		case EXPR:
			automate.decalage(s, new Etat6("6"));
			break;
    default:
      cout<<"Erreur juste apres:"<<endl;
      return true;
      break;
	}
	return false;
}

bool Etat3::transition(Automate & automate, Symbole * s){
	switch(*s){
			case PLUS:
			case MULT:
			case CLOSEPAR:
			case FIN:{
				Entier * entier = (Entier*) automate.depilerSymbole();
				int valeur = entier -> getValeur();
				Expr * expr = new Expr(valeur);
				delete entier;
				automate.reduction(1, expr);
				break;
			}
      default:
        cout<<"Erreur juste apres:"<<endl;
        return true;
        break;
	}
	return false;
}

bool Etat4::transition(Automate & automate, Symbole * s){
	switch(*s){
		case INT:
			automate.decalage(s, new Etat3("3"));
			break;
		case OPENPAR:
			automate.decalage(s, new Etat2("2"));
			break;
		case EXPR:
			automate.decalage(s, new Etat7("7"));
			break;
    default:
      cout<<"Erreur juste apres:"<<endl;
      return true;
      break;
	}
	return false;
}

bool Etat5::transition(Automate & automate, Symbole * s){
	switch(*s){
		case INT:
			automate.decalage(s, new Etat3("3"));
			break;
		case OPENPAR:
			automate.decalage(s, new Etat2("2"));
			break;
		case EXPR:
			automate.decalage(s, new Etat8("8"));
			break;
    default:
      cout<<"Erreur juste apres:"<<endl;
      return true;
      break;
	}
	return false;
}

bool Etat6::transition(Automate & automate, Symbole * s){
	switch(*s){
		case PLUS:
			automate.decalage(s, new Etat4("4"));
			break;
		case MULT:
			automate.decalage(s, new Etat5("5"));
			break;
		case CLOSEPAR:
			automate.decalage(s, new Etat9("9"));
			break;
    default:
      cout<<"Erreur juste apres:"<<endl;
      return true;
      break;
	}
	return false;
}

bool Etat7::transition(Automate & automate, Symbole * s){
	switch(*s){
		case MULT:
			automate.decalage(s, new Etat5("5"));
			break;
		case PLUS:
		case CLOSEPAR:
		case FIN:{
			Expr * expr1 = (Expr*) automate.depilerSymbole();
			delete automate.depilerSymbole();
			Expr * expr2 = (Expr*) automate.depilerSymbole();
			int valeur = expr1 -> getValeur() + expr2 -> getValeur();
			Expr * expr = new Expr(valeur);
			delete expr1;
			delete expr2;
			automate.reduction(3, expr);
			break;
    }
    default:
      cout<<"Erreur juste apres:"<<endl;
      return true;
      break;
	}
	return false;
}

bool Etat8::transition(Automate & automate, Symbole * s){
	switch(*s){
		case MULT:
		case PLUS:
		case CLOSEPAR:
		case FIN:{
			Expr * expr1 = (Expr*) automate.depilerSymbole();
			delete automate.depilerSymbole();
			Expr * expr2 = (Expr*) automate.depilerSymbole();
			int valeur = expr1 -> getValeur() * expr2 -> getValeur();
			Expr * expr = new Expr(valeur);
			delete expr1;
			delete expr2;
			automate.reduction(3, expr);
			break;
    }
    default:
      cout<<"Erreur juste apres:"<<endl;
      return true;
      break;

	}
	return false;
}

bool Etat9::transition(Automate & automate, Symbole * s){
	switch(*s){
		case MULT:
		case PLUS:
		case CLOSEPAR:
		case FIN:{
			delete automate.depilerSymbole();
			Expr * expr = (Expr*) automate.depilerSymbole();
			delete automate.depilerSymbole();
			automate.reduction(3, expr);
			break;
    }
    default:
      cout<<"Erreur juste apres:"<<endl;
      return true;
      break;
	}
	return false;
}
