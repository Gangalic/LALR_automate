#pragma once

#include "symbole.h"
#include "automate.h"

class Automate;

class Etat {
  public:
    Etat(string s) : name(s){};
    //void print() const;
    virtual bool transition(Automate & automate, Symbole * s) = 0;
  protected:
    string name;
};

class Etat0 : public Etat{
  public:
    Etat0(string s) : Etat(s){}
    bool transition(Automate & automate, Symbole * s);
};

class Etat1 : public Etat{
  public:
    Etat1(string s) : Etat(s){}
    bool transition(Automate & automate, Symbole * s);
};

class Etat2 : public Etat{
  public:
    Etat2(string s) : Etat(s){}
    bool transition(Automate & automate, Symbole * s);
};

class Etat3: public Etat{
  public:
    Etat3(string s) : Etat(s){}
    bool transition(Automate & automate, Symbole * s);
};

class Etat4: public Etat{
  public:
    Etat4(string s) : Etat(s){}
    bool transition(Automate & automate, Symbole * s);
};

class Etat5: public Etat{
  public:
    Etat5(string s) : Etat(s){}
    bool transition(Automate & automate, Symbole * s);
};

class Etat6: public Etat{
  public:
    Etat6(string s) : Etat(s){}
    bool transition(Automate & automate, Symbole * s);
};

class Etat7: public Etat{
  public:
    Etat7(string s) : Etat(s){}
    bool transition(Automate & automate, Symbole * s);
};

class Etat8: public Etat{
  public:
    Etat8(string s) : Etat(s){}
    bool transition(Automate & automate, Symbole * s);
};

class Etat9: public Etat{
  public:
    Etat9(string s) : Etat(s){}
    bool transition(Automate & automate, Symbole * s);
};
