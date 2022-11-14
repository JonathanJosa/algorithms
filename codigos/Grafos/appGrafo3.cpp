#include <iostream>
#include <string>
#include <cstring>
#include <vector>

using namespace std;

vector<vector<int>> loadGraph(){
  int n, m, pos1, pos2;
  vector<vector<int>> nodos;
  char letra2[3];
  string letra;
  cin>>m;
  cin>>n;
  for(int i = 0; i<n;i++){
    cin>>letra;
    strcpy(letra2,letra.c_str());
    if(strlen(letra2)>1){
      pos1 = (((letra2[0] - 64)*26)) +  letra[1]-65;
    }else{
      pos1 = letra[0]-65;
    }

    cin>>letra;
    strcpy(letra2,letra.c_str());
    if(strlen(letra2)>1){
      pos2 = (((letra2[0] - 64)*26)) +  letra[1]-65;
    }else{
      pos2 = letra[0]-65;
    }

    if(nodos.size()>0){
      bool fin = false;
      for(int j=0;j<nodos.size();j++){
        if(nodos[j][0]==pos1){
          nodos[j].push_back(pos2);
          fin = true;
          break;
        }
      }
      if(fin == false){
        vector<int> interior;
        nodos.push_back(interior);
        nodos[nodos.size()-1].push_back(pos1);
        nodos[nodos.size()-1].push_back(pos2);
      }
    }else{
      vector<int> interior;
      nodos.push_back(interior);
      nodos[0].push_back(pos1);
      nodos[0].push_back(pos2);
    }
  }
  return nodos;
}

bool isTree(vector<vector<int>> nodo){
  int size = nodo.size();
  int conex[size]={0};
  for(int i=0;i<nodo.size();i++){
    for(int j=1;j<nodo[i].size();j++){
      if(nodo[i][j]<size-1){
        conex[nodo[i][j]]++;
      }
    }
  }

  bool verdad = false;
  while(verdad == false){
    for(int i=0;i<size-1;i++){
      if(conex[i]==0){
        for(int j=1;j<nodo[i].size();j++){
          if(nodo[i][j]<size-1){
            conex[nodo[i][j]]-=1;
          }
        }
        conex[i] = -1;
        verdad = true;
        break;
      }
    }
    if(verdad == true){
      verdad = false;
    }else if(verdad == false){
      for(int i=0;i<size-1;i++){
        if(conex[i]>0){
          return false;
        }
      }
      return true;
    }
  }
}

int main(){
  vector<vector<int>> nodos;
  nodos = loadGraph();
  cout<< boolalpha << isTree(nodos) <<endl;
}
