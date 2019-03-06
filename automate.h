#pragma once

#include <string>
#include <stack>
#include <iostream>
#include "etat.h"
#include "symbole.h"
#include "lexer.h"

using namespace std;

class Etat;

class Automate{
  public:
    Automate(Lexer *l) : lexer(l) {};
    virtual ~Automate() {};
    void decalage(Symbole * s, Etat * e);
    void reduction(int n, Symbole * s);
    Symbole * depilerSymbole();
    void empilerSymbole(Symbole * s);
    void analyser();
  protected:
    Lexer * lexer;
    stack<Etat*> pileEtats;
    stack<Symbole*> pileSymboles;
};
