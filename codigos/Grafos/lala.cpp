// Actividad Integradora 5.2 (Hash) TC1031
// Jonathan Josafat Vázquez Suárez 	A01734225
// Jhonatan Yael Martinez Vargas 		A01734193
// Claudia Paola García Nocetti 		A01424238

#include<bits/stdc++.h>
using namespace std;

//Clase superHash, se encarga de leer los datos y crear la tabla hash que almacena los datos de la bitacora2.txt

class superHash{

private:

//Estructura Node que guarda un string name, que es el puerto de la ip, un int suma, que es la suma de los números del puerto, un int grado y un map elmap.

struct Node{
	string name;
  int valor;
  int grado;
  map<string, int> elmap;
};

//Estructura Hash que almacena un int tipo, que indica si la casilla esta ocupada o no, int key que almacena la posición en la que se va a guardar el dato en la tabla hash, el string ip, int accesos, que indica el numero de accesos relacionados a la ip y un vector conexiones que guarda las ip's conectadas.

struct Hash{
  int tipo = 0;
  int key;
  string ip;
  int accesos;

  vector<string> conexiones;
};


struct Hash Tablita[32749]; //Se crea la tabla con los espacios necesarios
int espacios = 32749;

public:
// Función que lee los datos de un archivo bitacora2.txt
// Ademas cada linea leida es separadas en strings diferentes las cuales seran
// los valores de cada nodo.
// Complejidad O(N)
void leer_datos(){
  map <string, struct Node*> Red;

  string txt;
  string dato;
  ifstream archivo;

  // Se abre el archivo y se comienza la lectura de datos
  archivo.open("bitacora4.txt");
  if(archivo.is_open()){
    while(!archivo.eof()){
      getline(archivo,dato);
			if(dato == " " || dato == "")
					break;

      // Segmentamos la linea leida en varios strings
			dato = dato.substr(16,dato.length()-16);

			dato = dato.substr(0,dato.find(" "));

			dato = dato.substr(0,dato.find(":"));

			int corte = dato.find(".");
			string dato2 = dato.substr(corte+1,dato.length()-corte);
			corte += dato2.find(".");

			string red = dato.substr(0,corte+1);
			string host = dato.substr(corte+2,dato.length()-corte);

      //Se separa el puerto para poder sacar la key.
      //Para sacar la key se multiplica el primera parte del puerto por 1000 y a eso se le suma la segunda parte del puerto y posteriormente se calcula el modulo de 32749.

      int red1 = stoi(red.substr(0, red.find(".")));
      int red2 = stoi(red.substr(red.find(".")+1,red.size()-red.find(".")));
      int suma = (red1*1000) + red2;
      suma %= 32749;


      //Se almacenan los datos en un struct Node.
      //Red
      if(Red.count(red) == 0){
        struct Node* temp = new Node();
        Red[red] = temp;
  		}
      Red[red]->name = red;
      Red[red] -> grado ++;
      Red[red] -> valor = suma;
      //host
      if(Red[red] -> elmap.count(host) == 0){
        Red[red] -> elmap[host] = 1;
      }

    }

    //Insertar valores en el Tabla Hash
     map <string, struct Node*>::iterator i;
     for(i=Red.begin();i!=Red.end();i++){
        int j = (i->second)->valor;
        while(j < 32749){
          if(Tablita[j].tipo == 0 || Tablita[j].tipo==-1){
            Tablita[j].ip = i->first;
            Tablita[j].key = (i->second)->valor;
            Tablita[j].tipo = 1;
            Tablita[j].accesos = (i->second)->grado;
            map<string, int>::iterator pikis;
            int cont=0;
            for(pikis=(i->second->elmap).begin();pikis!=((i->second)->elmap).end();pikis++){
              (Tablita[j].conexiones).push_back( (i->first + "." + pikis->first) );
              cont++;
            }
						espacios -= 1;
            break;
          }
          j++;
        }
				if(espacios <= 0){
					cout<<"Tabla llena, imposible meter más datos"<<endl;
					break;
				}

     }
  }else{
    cout<< "Error al abrir el archivo" <<endl;
  }
}

  //Función Buscar
  // Complejidad O(N)
  void buscar(string red){

    int red1 = stoi(red.substr(0, red.find(".")));
    int red2 = stoi(red.substr(red.find(".")+1,red.size()-red.find(".")));
    int suma = (red1*1000) + red2;
    suma %= 32749;
    int i = suma;

    while(i < 32749){

      if(Tablita[i].ip == red){

        cout<<Tablita[i].ip<<endl;
        cout<<Tablita[i].accesos<<endl;
        cout<<Tablita[i].conexiones.size()<<endl;

        for(int j=0;j<Tablita[i].conexiones.size();j++){
          cout<<Tablita[i].conexiones[j]<<endl;
        }

        break;

      }

      i++;
    }
		cout<<endl;
  }

};


int main() {

  superHash bitacoraPro;

  bitacoraPro.leer_datos();

  int n;
  string dominio;

  cin >> n;

  while(n--){

    cin >> dominio;

    bitacoraPro.buscar(dominio);

  }

}
