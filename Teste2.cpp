#include <fstream>
#include <string>
#include <queue>
#include <iostream>
#include <cstring>
#include <map>
#include <json.h>
using namespace std;
 
vector<string> getLinesFromFile(string filePath) {
    vector<string> result;
    fstream fileToRead(filePath.c_str(), fstream::in);
    std::string line; 
    while (std::getline(fileToRead, line)){
        result.push_back(line);
    }
    fileToRead.close();
    return result;
}
 
Json::Value getUserInfo(string line) {
    int delimiter = 0;
    int d=0;
    int cont = 0;
 
    Json::Value result; 
    do {
        d = line.find(":", delimiter);
        string value = line.substr(delimiter, d-delimiter);
        delimiter = d+1;
        if (cont == 0){
            result["userName"] = value;
            cont++;
        }
        else if(cont == 3) {
            result["groupId"] = value;
            cont++;
        } else
            cont++;
    } while (delimiter != 0 );
    return result;
} 
 
Json::Value getUserInfos(vector<string> lines) {
    Json::Value result;
    for (int i = 0; i < lines.size(); i++){
        Json::Value user = getUserInfo(lines[i]);
        result.append(user);
    }
    return result;
}
 
map<string,string> getGroups(vector<string> lines){
    int delimiter = 0;
    int d=0;
    string groupName;
    string groupId;
    string line;
    map<string,string> result;
    for (int i =0; i < lines.size(); i++){
        line = lines[i]; // suricata:x:1019:
        d = line.find(":", delimiter); // d = primeiro :
        groupName = line.substr(delimiter, d-delimiter); // valor de 0 até D = suricata
        delimiter = line.find(":", d+1); // delimiter = segundo :
        d = line.find(":", delimiter+1); //d = terceiro :
        groupId = line.substr(delimiter+1, d-delimiter-1); // valor entre o seugndo e terceiro :
        result[groupId] = groupName;
        delimiter = d = 0; 
        groupName = groupId = "";
    }
    return result;
}
 
Json::Value formatJson (Json::Value users, map<string, string> groups) {
    Json::Value result;
        for (int i =0 ; i < users.size(); i++){
            users[i]["groupName"] =  groups[users[i]["groupId"].asString()];
            result.append(users[i]);
        }
    return result;
}
 
void writeToFile(string filePath, Json::Value jsonObj) {
    Json::StyledWriter jsonWriter;
 
    fstream fileToWrite;
    fileToWrite.open(filePath.c_str(), std::fstream::in | std::fstream::out);
    fileToWrite << jsonWriter.write(jsonObj) << endl;
    fileToWrite.close();
}
 
int main() 
{ 
    vector<string> lnhasArquivo = getLinesFromFile("/etc/passwd");
    //vector<string> linesEtcGroup = getLinesFromFile("/etc/group");
 
    Json::Value users = getUserInfos(linesEtcPwd);
 
    map<string, string> groups = getGroups(linesEtcGroup);
 
    Json::Value jsonData = formatJson(users, groups);
 
    writeToFile("/home/resultado.txt", jsonData);
 
    vector<string> resultadoTxt = getLinesFromFile("/home/resultado.txt");
 
    for (int i = 0; i < resultadoTxt.size(); i++){
        cout << resultadoTxt[i] << endl;
    }
        
}

using namespace std;


// pega linha dos arquivos 

vector<string> result;
    ifstream input;
    input.open(arquivoLeitura);

    vector<string> linha; 

    while (getline(arquivoLeitura, linha)){
        result.push_back(linha);
    }
    arquivoLeitura.close();
    return 0;

    // pega usuarios 
    int encontraInicio = 0;
    int fim=0;
    int cont = 0;

          Json::Value result;  

    do {
        fim = line.find(":", encontraInicio);
        string value = line.substr(encontraInicio, d-delimiter);
        encontraInicio = fim + 1;
        if (cont == 0){
            result["userName"] = value;
            cont++;
        }
        else if(cont == 3) {
            result["groupId"] = value;
            cont++;
        } else
            cont++;
    } while (encontraInicio != 0 );
    return result;
} 
    
    // adiciona o usuario
    Json::Value result;
    for (int i = 0; i < lines.size(); i++){
        Json::Value user = getUserInfo(lines[i]);
        result.append(user);
    }
    return result;
}

//Pega Grupo
  int encontraInicio = 0;
    int fim=0;
    string groupName;
    string groupId;
    string linhas;
    map<string,string> result;
    for (int i =0; i < linhas.size(); i++){
        linhas = linhas[i]; // suricata:x:1019:

        //encontra o nome do grupo
        fim = line.find(":", encontraInicio); // d = primeiro :
        groupName = line.substr(encontraInicio, fim-encontraInicio); // valor de 0 até fim = suricata
        encontraInicio = line.find(":", fim+1); // delimiter = segundo :
        fim = line.find(":", encontraInicio+1); //d = terceiro :
        groupId = line.substr(encontraInicio+1, fim-encontraInicio-1); // valor entre o seugndo e terceiro :
        result[groupId] = groupName;
        encontraInicio = fim = 0; 
        groupName = groupId = "";
    }
    return result;
}
// Formata o Json
  for (int i =0 ; i < users.size(); i++){
            users[i]["groupName"] =  groups[users[i]["groupId"].asString()];
            result.append(users[i]);
        }
            return result;
}
 

 // le o arquivo  
 
 Json::StyledWriter jsonWriter;
 
    ifstream lendoArquivo;
    lendoArquivo.open(arquivo);
    lendoArquivo << jsonWriter.write(jsonObj) << endl;
    lendoArquivo.close();





    void MyClass::myMethod(Json::Value& jsonValue_ref)
{
    for (int i = 0; i <= m_stringList.size(); i++)
    {
        if (m_boolMarkerList[i])
        {
            jsonValue_ref.append(stringList[i]);
        }
    }
}


void MyClass::myOuterMethod()
{
    Json::Value jsonRoot;
    Json::Value jsonValue;

    myMethod(jsonValue);

    jsonRoot["somevalue"] = jsonValue;
    Json::StyledWriter writer;
    std::string out_string = writer.write(jsonRoot);
}