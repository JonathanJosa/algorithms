#include <iostream>
#include <cstdlib>
#include <time.h>
#include <queue>
#include <stack>
#include <set>

using namespace std;

//Value of N > Nodes
//Value of P > Probability of connection
const int   N = 12;
const float P = 0.35;

/*
  Probabilidad de grafo conexo con probabilidad de conexion de vertices
  #Nodos      #Prob_arst      #Prob_No_Conexo
   800         0.5             0/50
   800         0.1             10/50
   800         0.05            12/50
   800         0.01            10/25
   800         0.005           50/50

   80          0.5             0/40
   80          0.1             1/40
   80          0.05            10/15
   80          0.01            40/40

   8           0.5             0/30
   8           0.35            12/30
   8           0.2             27/30
   8           0.1             50/50
*/

/*
  ¿Cómo sería diferente este problema si se pide un grafo dirigido?
    Un grafo dirigido aumentaría la propabilidad de que sea NO CONEXO,
    puesto que las conexiones no serían unidireccionales,
    los recorridos bfs/dfs tendrían valores muy diferentes
    aunque la implementación podria ser la misma,
    cambiando los valores espejo en la matriz por su propia probabilidad.
*/

//Save of graphs
int levels = 0;

//Get random number between 0-1 (inclusive)
float randomm(){
  return static_cast <float> (rand()) / static_cast <float> (RAND_MAX);
}

//Random probability of conections
//Loop over the half of Matriz^-1
void linkNodes(bool (*table)[N]){
  for(int i=0; i<N; i++){
    cout<<i<<" : ";
    for(int j=0; j<i; j++)
      if(P >= randomm()){
        table[j][i] = table[i][j] = true;
        cout<<j<<" ";
      }
    cout<<"\n";
  }
  cout<<"\n";
}

//1.Goes through the nodes that havent been visited
//2.Adds it to the stack if not visited
//3.While stack is not empty, keep looping
//4.Extract the back value and goes through it, also, delete from visited
//The conections is added to the back
//It prints the last node who join on the stack
void breadthSearch(bool (*table)[N]){
  set<int> reviewed, reviewed_copy; for(int i=0; i<N; i++) reviewed.insert(i);
  stack<int> line; int temp, value;
  for(int i=0; i<N; i++){
    if(reviewed.find(i) != reviewed.end()){
      cout<<"#"<<i<<" : ";
      line.push(i);
      while(!line.empty()) {
        temp = line.top(); line.pop();
        if(reviewed.find(temp) != reviewed.end()){
          cout<<temp<<" "; reviewed.erase(temp);
          reviewed_copy = reviewed;
          while(!reviewed_copy.empty()){
            value = *(--reviewed_copy.end()); reviewed_copy.erase(value);
            if(table[temp][value]) line.push(value);
          }
        }
      }
      cout << "\n\n";
    }
  }
}

//1.Goes through the nodes that havent been visited
//2.Adds it to the queue if not visited
//3.While queue is not empty, keep looping
//4.Extract the front value and goes through it
//5.The conection is added to the back and delete the value from the queue
//It prints node as it join on the queue
void deepSearch(bool (*table)[N]){
  set<int> reviewed, reviewed_copy; for(int i=0; i<N; i++) reviewed.insert(i);
  queue<int> line; int temp;
  for(int i=0; i<N; i++)
    if(reviewed.find(i) != reviewed.end()){
      cout<<"#"<<i<<" : ";
      line.push(i); reviewed.erase(i);
      while(!line.empty()){
        temp = line.front(); line.pop(); cout<<temp<<" ";
        reviewed_copy = reviewed;
        for(auto value: reviewed_copy)
          if(table[temp][value]){
            line.push(value); reviewed.erase(value);
          }
      }
      //checks every level of the matrix(graph)
      cout<<"\n\n"; levels++;
    }
}

int main(){
  //Set the random seed as the local time
  srand(time(0));
  //Default matrix as false with size of N*N
  bool tableNodes[N][N]{};

  cout<<"Nodes\n";
  linkNodes(tableNodes);

  cout<<"Deep Search\n";
  deepSearch(tableNodes);

  cout<<"Breadth Search\n";
  breadthSearch(tableNodes);

  cout<<"Graph levels: "<<levels<<"\nConexo -> "<<std::boolalpha<<(levels > 1)<<"\n\n";
  cout<<"Count of Nodes: "<<N<<"\nProbability of connection: "<<P<<endl;
}
