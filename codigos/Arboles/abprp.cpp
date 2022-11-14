// Claudia Poala Garcia Nocetti A01424238
// Jhonatan Yael Martinez Vargas A01734193
// Jonathan Josafat Vázquez Suárez A01734225

#include<bits/stdc++.h>
using namespace std;

int cont=5;
//Declaracion de subestrcutura para control de IP
struct IP {
  //Cada octal de la IP
  int oct1;
  int oct2;
  int oct3;
  int oct4;
  //Puerto
  int puerto;
};

//Declaracion de estructura para la organizacion de los datos
struct Acceso{
  //Pair de <string del mes, equivalencia numerica>
  pair <string,int> mes;
  int dia;
  int hora;
  int min;
  int seg;
  //Sub estructura IP
  struct IP ip;
  //Mensaje de error
  string error;

};

//Declaracion de la estrcutura de cada nodo del arbol
struct Node{
  //Datos
  struct Acceso ac;
  //Hijos
  struct Node* left;
  struct Node* right;
};

//Funcion que retorna un pair<string del mes, equivalencia numerica del mes>
pair<string, int> mes_int(string m){
  //  Creamos una matriz que relaciona meses y su cantidad de dias
  string meses[12] = {"Jan","Feb","Mar","Apr","May","Jun","Jul","Aug","Sep","Oct","Nov","Dec"};
  int meses_int[12] = {1,2,3,4,5,6,7,8,9,10,11,12};

  int i;
  pair <string,int> mes;

  //Recorrer array de meses
  for(i = 0; i < 12; i++){
    if(m == meses[i]){
      //Al encontrar un valor equivalente en string de meses declarar el valor de mes
      mes = make_pair(meses[i],meses_int[i]);
      //Romper ciclo al encontrarlo
      break;
    }
  }
  return mes;
  //Complejidad: constante
};

//Funcion para encontrar el lugar donde guardar el nuevo nodo
bool compara(struct Acceso n_ac, struct Acceso a_ac){
  //False representa insertar al lado izquuiero
  //True representa insertar al lado derecho
  bool temp = false;
  //Comparar los atributos de n_ac vs a_ac
  //Si estos atributos son diferentes se define cual es el mayor y se retorna un valor
  //Si son iguales se compara con el siguiente valor
  if(n_ac.ip.oct1 > a_ac.ip.oct1){

    temp = true;

  }else if(n_ac.ip.oct1 < a_ac.ip.oct1){

    temp = false;

  }else if(n_ac.ip.oct1 == a_ac.ip.oct1){

    if(n_ac.ip.oct2 > a_ac.ip.oct2){

      temp = true;

    }else if(n_ac.ip.oct2 < a_ac.ip.oct2){

      temp = false;

    }else if(n_ac.ip.oct2 == a_ac.ip.oct2){

      if(n_ac.ip.oct3 > a_ac.ip.oct3){

        temp = true;

      }else if(n_ac.ip.oct3 < a_ac.ip.oct3){

        temp = false;

      }else if(n_ac.ip.oct3 == a_ac.ip.oct3){

        if(n_ac.ip.oct4 > a_ac.ip.oct4){

          temp = true;

        }else if(n_ac.ip.oct4 < a_ac.ip.oct4){

          temp = false;

        }else if(n_ac.ip.oct4 == a_ac.ip.oct4){

          if(n_ac.ip.puerto > a_ac.ip.puerto){

            temp = true;

          }else if(n_ac.ip.puerto < a_ac.ip.puerto){

            temp = false;

          }else if(n_ac.ip.puerto == a_ac.ip.puerto){

            if(n_ac.mes.second > a_ac.mes.second){

              temp = true;

            }else if(n_ac.mes.second < a_ac.mes.second){

              temp = false;

            }else if(n_ac.mes.second == a_ac.mes.second){

              if(n_ac.dia > a_ac.dia){

                temp = true;

              }else if(n_ac.dia < a_ac.dia){

                temp = false;

              }else if(n_ac.dia == a_ac.dia){

                if(n_ac.hora > a_ac.hora){

                  temp = true;

                }else if(n_ac.hora < a_ac.hora){

                temp = false;

                }else if(n_ac.hora == a_ac.hora){

                  if(n_ac.min > a_ac.min){

                    temp = true;

                  }else if(n_ac.min < a_ac.min){

                    temp = false;

                  }else if(n_ac.min == a_ac.min){

                    if(n_ac.seg > a_ac.seg){

                      temp = true;

                    }else if(n_ac.seg < a_ac.seg){

                      temp = false;

                    }

                  }

                }

              }

            }

          }

        }

      }

    }

  }
  //Una vez definido se retorna el bool
  return temp;
  //Funcion de orden constante
}

//Funcion para insertar un nuevo nodo
void Insertar(struct Acceso a, struct Node** r){
  //Se declara el nuevo nodo ademas de el nodo padre recibido
  struct Node* actual_node = *r;
  struct Node* n_node = new Node;
  //Si el nodo padre esta vacio se inserta directamente
  if(*r == NULL){

    n_node -> ac = a;
    n_node -> left = NULL;
    n_node -> right = NULL;

    *r = n_node;

  }else{
    //Si el nodo padre ya tiene datos se compara cual es la posible posicion del nodo
    bool c = compara(a, actual_node -> ac);
    //Esta funcion retorna si el valor deberia ir a la izquiera o derecha
    //True representa derecha
    //False representa derecha

    //Si debe ir a la derecha
    if(c == true){
      //Se ejecuta recursivamente hasta encontrar el nodo vacio donde sse puede colocar
      Insertar(a,&actual_node -> right);

    }else{

      Insertar(a,&actual_node -> left);

    }
  }
  //Funcion de orden n
}


//Funcion de impresion de los 5 valores mas altos, es recursiva
//Funcion de recorrido de arbol inorden convexa
void inordenConvexa(struct Node* r){
  //Compara que el contador no sea menor o igual 0
  //Esto evita que se imprima mas de 5 veces
  //Tambien compara que el nodo no este vacio
  if(r == NULL || cont <= 0)
    return;
  inordenConvexa(r -> right);
  if(cont<=0)
      return;
  cout << r -> ac.mes.first << " ";
  cout << r -> ac.dia << " ";
  cout << r -> ac.hora << ":";
  cout << r -> ac.min << ":";
  cout << r -> ac.seg << " ";
  cout << r -> ac.ip.oct1 << ".";
  cout << r -> ac.ip.oct2 << ".";
  cout << r -> ac.ip.oct3 << ".";
  cout << r -> ac.ip.oct4 << ":";
  cout << r -> ac.ip.puerto << " ";
  cout << r -> ac.error << "\n";
  cont --;
  //Resta 1 al contador por imprimirse
  //Se compara el contador para solo imprimir a los 5 maximos
  if(cont<=0)
      return;
  inordenConvexa(r -> left);
  //Funcion recursiva de orden n
}

//Funcion para leer los datos del archivo
void leer_datos(struct Node** r){

  struct Acceso data;
  string dato, dato2;
  ifstream archivo;

  //Abrimos el archivo .txt
  archivo.open("bitacora.txt");

  if(archivo.is_open()){
      //Mientras tenga lineas por leer se ejecuta
      while(!archivo.eof()){

        //  Almacenamos e insertamos los datos en el arbol binario
        getline(archivo,dato);
        //Se guardan los datos de la linea a leer
        //Se hace un substring de la cadena para valores con tamaños constantes
        data.mes = mes_int(dato.substr(0,3));
        data.dia = stoi(dato.substr(4,2));
        data.hora = stoi(dato.substr(7,2));
        data.min = stoi(dato.substr(10,2));
        data.seg = stoi(dato.substr(13,2));

        //Se hace un corte de todos los octetos de la IP
        //La IP comienza en la posicion 16
        int l = 16;
        //Se asigna en dir el corte desde 16 hasta el final del string
        string dir = dato.substr(l,dato.find("\n"));
        //Ahora la IP comienza en 0, por la string guardada en dir
        l = 0;
        //Se asigna el primer conteto de la IP cortando la string hasta el primer punto
        data.ip.oct1 = stoi(dir.substr(l,dir.find(".")));
        l += dir.find(".") + 1;
        //Se corta la string desde el 1 lugar despues del punto hasta el final
        dir = dir.substr(l,dir.find("\n"));
        l = 0;
        //Se realiza el mismo procedimiento de cortar hasta el punto
        //Se hace lo mismo en cada octeto de la IP
        data.ip.oct2 = stoi(dir.substr(l,dir.find(".")));
        l += dir.find(".") + 1;

        dir = dir.substr(l,dir.find("\n"));

        l = 0;

        data.ip.oct3 = stoi(dir.substr(l,dir.find(".")));
        l += dir.find(".") + 1;

        dir = dir.substr(l,dir.find("\n"));

        l = 0;

        data.ip.oct4 = stoi(dir.substr(l,dir.find(":")));
        l += dir.find(":") + 1;

        dir = dir.substr(l,dir.find("\n"));

         l = 0;

        data.ip.puerto = stoi(dir.substr(l,dir.find(" ")));
        l += dir.find(" ") + 1;

        dir = dir.substr(l,dir.find("\n"));

        //Se guarda el error que es la string restante despues de la IP
        data.error = dir;
        //Se insertan estos datos usando esta funcion
        Insertar(data, r);

      }

  }else{
    //Si no se abre el archivo
    cout<< "Error al abrir el archivo" <<endl;

  }
  //Funcion de orden lineal
}

int main(){
  //Declaracion del nodo padre
  struct Node* Root = NULL;
  //Leer datos y guardarlos en el nodo
  leer_datos(&Root);
  //Imrpimir solo los 5 mayores
  inordenConvexa(Root);
}
