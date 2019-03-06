#include <iostream>
#include "lexer.h"
#include "automate.h"


int main(void) {
   string chaine;

   cout<<"Inserez votre chaine:"<<endl;
   cin>>chaine;

   Lexer l(chaine);
   Automate automate(&l);
   automate.analyser();

   return 0;
}
