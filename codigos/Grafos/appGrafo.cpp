// Jhonatan Yael Martinez Vargas A01734193
// Jonathan Josafat Vázquez Suárez A01734225

//Llamada de librerias
#include <iostream>
#include <string>
#include <vector>

using namespace std;

//Entrada segura de datos
int entrada(){
  int opc;
  bool aux = true;
  cin.exceptions(std::istream::failbit);
	do{
			try{
					cin >> opc;
					aux = true;
			}
			catch (ios_base::failure &fail){
					aux = false;
					cin.clear();
					string tmp;
					getline(cin, tmp);
			}
	}while (aux == false);
  return opc;
}

//Impresion del grafo
void imprimir(vector<vector<int>> grafo){
  int n = grafo.size();
  //Se recorre el arbol como matriz
  for(int i=0; i<n;i++){
    for(int j=0; j<n;j++){
      //Se imprime el arbol como matriz numerica
      cout<<grafo[i][j]<<" ";
    }
    cout<<endl;
  }
  //Funcion de orden cuadratico
}

//Funcion para imprimir las conexiones entre los nodos
void conexiones(vector<vector<int>> grafo){
  //el char imprime la letra
  char letra;
  int n = grafo.size(), p;
  //Recorrido del arbol
  for(int i=0; i<n;i++){
    //Se imprime la letra que define el nodo que conecta con los siguientes nodos
    p = i/26;
    if(p >= 1){
      letra = 64 + p;
        cout<< letra;
    }
    letra = 65 + i%26;
    cout<< letra <<" ";
    //Es un recorrido de matriz
    for(int j=0; j<n;j++){
      //Se compara que la matriz en esta posicion tenga valor
      if(grafo[i][j]==1){
        //Se imprime el nodo en esta posicion como letra
        cout<<"- ";
        //Se define e imprime la letra del nodo
        p = j/26;
        if(p >= 1){
            letra = 64 + p;
            cout<< letra;
        }
        letra = 65 + j%26;
        cout<< letra << " ";
      }
    }
    cout<<endl;
  }
  //Funcion de orden cuadratico
}

//Funcion de ordenamiento
void DFS(vector<vector<int>> grafo){
  //Compara el tamaño del grafo
  if(grafo.size()!=0){
    int nod [703]={0}, pos = 0, temp;
    vector<int> lista;
    char letra;
    lista.push_back(0);
    nod[0]=1;
    //Ciclo hasta que el queque este vacio
    while(lista.size() > pos){
      //Añade los valores en el queque siempre y cuendo estos tengan una conexion y no hayan sido añadidos antes
      for(int i=0;i<grafo.size();i++){
        if(grafo[lista[pos]][i]==1 && nod[i]==0){
          lista.push_back(i);
          nod[i]=1;
        }
      }
      //Se imprime la eltra del primer numero
      temp = lista[pos]/26;
      if(temp >= 1){
          letra = 64 + temp;
          cout<< letra;
      }
      letra = 65 + lista[pos]%26;
      cout<< letra << " ";
      pos++;
    }
  }
  cout<<endl;
  //Funcion de orden polinomico
}

//Funcion de ordenamento
void BFS(vector<vector<int>> grafo){
  //Compara grafo vacio
  if(grafo.size()>0){
    int nod[703]={0}, temp, reco[703]={0};
    vector<int> lista;
    char letra;
    lista.push_back(0);
    //Ciclo hasta vaciar la lista
    while(lista.size()>0){
      //Imprime el ultimo nodo siempre y cuando este no haya sido impreso antes
      if(nod[lista[lista.size()-1]]==0){
        temp = (lista[lista.size()-1])/26;
        if(temp >= 1){
            letra = 64 + temp;
            cout<< letra;
        }
        letra = 65 + (lista[lista.size()-1])%26;
        cout<< letra << " ";
        nod[(lista[lista.size()-1])]=1;
      }
      //Guarda el nodo que acaba de imprimir en temp
      temp = lista[lista.size()-1];
      //Lo borra de la lista porque ya fue impreso
      lista.pop_back();
      //Ciclo que busca sus conexiones del nodo que se acaba de imprmir
      for(int i=grafo.size()-1;i>=0;i--){
        if(grafo[temp][i]==1 && nod[i]==0){
          //Las guarda en la lista si no se han impreso
          lista.push_back(i);
        }
      }
    }
  }
  cout<<endl;
  //Funcion de orden polinomico
}

int main(){
  //Entrada y almacenamiento de datos
  //Entrada segura
  int n = entrada();
  //Almacenamiento como vector de vectores
  vector<vector<int>> grafo;
  for (int i = 0;i<n;i++){
    vector<int> enlace;
    for(int j =0; j<n;j++){
        enlace.push_back(entrada());
    }
    grafo.push_back(enlace);
  }
  //Ejecucion de funciones
  imprimir(grafo);
  cout<<endl;
  conexiones(grafo);
  cout<<endl;
  DFS(grafo);
  cout<<endl;
  BFS(grafo);
  cout<<endl;
}
