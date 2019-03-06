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
	}
	return false;
}

bool Etat3::transition(Automate & automate, Symbole * s){
	switch(*s){
			case PLUS:
			case MULT:
			case CLOSEPAR:
			case FIN:{
				Entier * entier = (Entier*) automate.depile_symbole();
				int valeur = entier -> getValeur();
				Expr * expr = new Expr(valeur);
				delete entier;
				automate.reduction(1, expr);
				break;
			}

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
		case FIN:
			Expr * expr1 = (Expr*) automate.depile_symbole();
			delete automate.depile_symbole();
			Expr * expr2 = (Expr*) automate.depile_symbole();
			int valeur = expr1 -> getValeur() + expr2 -> getValeur();
			Expr * expr = new Expr(valeur);
			delete expr1;
			delete expr2;
			automate.reduction(3, expr);
			break;
	}
		return false;
}

bool Etat8::transition(Automate & automate, Symbole * s){
	switch(*s){
		case MULT:
		case PLUS:
		case CLOSEPAR:
		case FIN:
			Expr * expr1 = (Expr*) automate.depile_symbole();
			delete automate.depile_symbole();
			Expr * expr2 = (Expr*) automate.depile_symbole();
			int valeur = expr1 -> getValeur() * expr2 -> getValeur();
			Expr * expr = new Expr(valeur);
			delete expr1;
			delete expr2;
			automate.reduction(3, expr);
			break;
	}
		return false;
}

bool Etat9::transition(Automate & automate, Symbole * s){
	switch(*s){
		case MULT:
		case PLUS:
		case CLOSEPAR:
		case FIN:
			delete automate.depile_symbole();
			Expr * expr = (Expr*) automate.depile_symbole();
			delete automate.depile_symbole();
			automate.reduction(3, expr);
			break;
	}
		return false;
}
