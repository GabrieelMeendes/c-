#include <fstream>
#include <string>
#include <queue>
#include <iostream>
#include <cstring>
#include <map>
#include <vector>

using namespace std;


vector<string> explode(string separador, string frase) {
  int prox = separador.size();
  vector<string> ret;
  string word = "";
  string::size_type ini, fim;
  ini = fim = 0;
   while (true) {
    fim = frase.find(separador, ini); 
     if (fim == string::npos) {
       word = frase.substr(ini, frase.size() - ini);
     if(word.size() > 0){
       ret.push_back(word);
     }
     break;
     }  
      word = frase.substr(ini, fim - ini);
       if(word.size() > 0){
        ret.push_back(word);
       }
        ini = fim + prox; 
   }
  return ret;
 }
 
 

int main(){

ifstream input;
input.open("Resultado.txt");


vector <string> linha;  
string Resultado; 
map <int , string> MYmap;

while(getline(input, Resultado)){
  linha = explode("->" , Resultado);
  for(int i = 0 ; i < linha.size(); i++){
    MYmap[i]= linha[i];
   // cout << MYmap[i] << endl;
}
cout << MYmap[1];
}}