#include <iostream>
#include <vector>
using namespace std;


//Funcion para entrada correcta de los datos
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

//Creacion de la clase priority_queue
class priority_queue{
  //Como elemntos privados se tiene el vector de la lista
  private:
    vector<int> lista;

//Paraa accesos publicos estan las funciones utilizadas
  public:
    //Funcion recursiva que dada una piosicion verifica a padres mayores e hijos menores
    void revisar(int pos){
      //Comparacion del tamaño de lista  mayor o igual a la posicion del proximo hijo derecho
      if( lista.size() >= ((pos+1)*2) ){
        //Comparar si el valor es mayor que su hijo derecho
        if(lista[pos]<lista[((pos+1)*2)]){
          //Intercambio de valores si no lo es
          int tmp = lista[pos];
          lista[pos] = lista[(2*(pos+1))];
          lista[(2*(pos+1))] = tmp;
          //Revisar esta nueva posicion para comprobar que son mayores a sus hijos y menores a sus padres
          revisar((2*(pos+1)));
          revisar(pos);
        }
      }
      //Comparacion del tamaño de lista  mayor o igual a la posicion del proximo hijo izquierdo
      if( lista.size() >= ((pos+1)*2)-1 ){
        //Comparacion de los valores, si no se cumple se intercambia y tambien se revisa esa posicion
        if(lista[pos]<lista[((pos+1)*2)-1]){
          //Cambio de valores
          int tmp = lista[pos];
          lista[pos] = lista[((2*(pos+1))-1)];
          lista[(2*(pos+1))-1] = tmp;
          //Revisar esta posicion recursivamente
          revisar((2*(pos+1))-1);
          revisar(pos);
        }
      }
    if(pos > 0){
        //Siempre y cuando la pos a revisar deseada sea mayor a 0 tendra un padre
        //Se identifica la posicion de su padre
        int tmp2 = ((pos+1)/2)-1 ;
        //Compara valores con su padre
        if(lista[tmp2] < lista[pos]){
          //Si es mayor que su padre se intercambian
          int tmp = lista[pos];
          lista[pos] = lista[tmp2];
          lista[tmp2] = tmp;
          //Revisar que ambas estan correctas
          revisar(tmp2);
          revisar(pos);
        }
      }
      //Funcion de orden lineal
    }

    //Añadir un nuevo valor
    void push(int valor){
      //Se coloca hasta el final
      lista.push_back(valor);
      //Se revisa que sus padres sean mayores a este
      revisar(lista.size()-1);
      //Funcion de orden constante
    }

    //el valor mas alto
    int pop(){
      //Siempre y cuando la lista tenga uno o mas valores
      if(lista.size()>0){
        //Se intercambian las valores de las posiciones posiciones entre el primer y ultimo valor
        int tmp = lista[0];
        lista[0] = lista[lista.size()-1];
        //Elimina el ultimo valor de la lista
        lista.pop_back();
        //Revisar el orden de todos los valores desde l posicio 0
        if(lista.size()>1) revisar(0);
        //retorna el valor mas alto
        return tmp;
      }
      //Retornar -1 si la lista esta vacia
      return -1;
      //Funcion de orden constante
    }

    //imprimir todos los valores de la lista
    void print(){
      ///Ciclo que recorre la lista
      for(int i=0; i<lista.size();i++){
        //Imprimir con un espacio final
        cout<<lista[i]<<" ";
      }
      //Imrpimir enter al terminar
      cout<<endl;
      //Funcion de orden lineal
    }

    //Funcion que retorna el valor mas alto
    int top(){
      //Retorna el primer valor del heap
      return lista[0];
      //Funcion de orden constante
    }

    //Funcion que detecta si esta vacio
    bool empty(){
      //Siempre y cuando exista mas de un valor retorna un false
      if(lista.size()>0){
        return false;
      }
      //Retorna true por defecto si no entra en el if
      return true;
      //Funcion de orden constante
    }

    //Funcion que retorna el tmaño del heap
    int size(){
      //Retorna el tamaño del vector
      return lista.size();
      //Funcion de orden constante
    }
};



int main(){
  //Decalaracion del objeto de la clase
  priority_queue heap;
  int opcion, tmp;
  bool flag = true;
  //Inicio del ciclo hasta detectar un 0 o error al ingresar un numero
  while(flag == true){
    opcion = entrada();
    //Seleccion de cada caso
    switch (opcion){
      //Se ingresa un valor en el head
      case 1: heap.push(entrada()); break;
      //Se rompe el ultimo valor en el head
      case 2: tmp = heap.pop();
      //Si esto retorna un -1 se imprime un enter
      if(tmp == -1) cout<<endl;
      //Si no se imprime el valor
      else cout<<tmp<<endl;
      break;
      //Imprimir todos los valores
      case 3: heap.print(); break;
      //Imprimir el valor maximo
      case 4: cout<< heap.top() << endl; break;
      //Revisar si esta vacia, retorna un bool y "boolalpha" imprime lo que se reciba directamente
      case 5: cout<< boolalpha << heap.empty() << endl; break;
      //Se imprime el tamaño del heap
      case 6: cout<< heap.size() << endl; break;
      //Si ingresa 0 o algo erroneo esto sale
      case 0: flag = false; break;
      default: flag = false; break;
    }
  }
  //Funcion de orden lineal
}
