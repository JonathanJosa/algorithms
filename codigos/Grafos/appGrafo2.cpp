#include <iostream>
#include <string>
#include <cstring>
#include <vector>
#include <map>

using namespace std;

void imprimir(int nodo[703][703], int size){
  for(int i=0; i<=size;i++){
    cout<<"Nodo "<<i<<" | ";
    for(int j=0; j<=size;j++){
      if(nodo[i][j]==1){
        cout<<" -";
      }
    }
    cout<<endl;
  }
}

bool isTree(int nodo[703][703], int size){
  if(size>=1){
    cout<<"F";
  }
}

int main(){
  int n,m, nodo[703][703] = {0}, numero, pos1 = 0, pos2=0, nN = 0;
  char letra2[3];
  string letra;
  bool flag;
  cin>>m;
  cin>>n;
  for(int i=0;i<n;i++){
    cin>>letra;
    strcpy(letra2,letra.c_str());
    if(strlen(letra2)>1){
      pos1 = (((letra2[0] - 64)*26)) +  letra2[1]-65;
    }else{
      pos1 = letra[0]-65;
    }


    cin>>letra;
    strcpy(letra2,letra.c_str());
    if(strlen(letra2)>1){
      pos2 = (((letra2[0] - 64)*26)) +  letra2[1]-65;
    }else{
      pos2 = letra[0]-65;
    }


    if(pos1 > nN)nN = pos1;
    if(pos2 > nN)nN = pos2;
    nodo[pos1][pos2] = 1;
  }
  cout<< boolalpha << isTree(nodo, nN) <<endl;
  imprimir(nodo, nN);
}
