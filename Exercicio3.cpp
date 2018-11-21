#include <iostream>     // std::cerr
#include <fstream>      // std::ifstream

using namespace std;

string arq;
ifstream is;

int main () {  
  
  arq = "texto.txt";  
    is.open(arq);
    
    if (is) {
         cerr << "Arquivo "<< arq << " existe.";
    }
   
   else { 
        cout << "Arquivo " << arq << " nao existe.";
    }

 is.close(); 

}