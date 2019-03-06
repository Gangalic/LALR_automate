#pragma once

#include <string>
using namespace std;

enum Identificateurs { OPENPAR, CLOSEPAR, PLUS, MULT, INT, FIN, ERREUR, EXPR };

const string Etiquettes[] = { "OPENPAR", "CLOSEPAR", "PLUS", "MULT", "INT", "FIN", "ERREUR", "EXPR" };

class Symbole {
  public:
    Symbole(int i, bool t) : ident(i), terminal(t) {  }
    virtual ~Symbole() { }
    operator int() const { return ident; }
    bool isTerminal() {return terminal;};
    virtual void Affiche();
  protected:
    int ident;
    bool terminal;
};

class Entier : public Symbole {
  public:
    Entier(int v) : Symbole(INT,true), valeur(v) { }
    ~Entier() { }
    virtual void Affiche();
    int getValeur();
  protected:
    int valeur;
};

class Expr : public Symbole {
  public:
    Expr(int v) : Symbole(EXPR,false), valeur(v) { }
    virtual ~Expr() {};
    int getValeur();
    virtual void Affiche();
  protected:
    int valeur;
};
