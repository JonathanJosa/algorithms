#include<bits/stdc++.h>
using namespace std;

class superHash{

private:
struct Node{
	string name;
  int valor;
  int grado;
  map<string, int> elmap;
};

struct Hash{
  int tipo = 0;
  int key;
  string ip;
  int accesos;
  vector<string> conexiones;
};

struct Hash Tablita[32749];

public:
void leer_datos(){
  map <string, struct Node*> Red;
  string txt;
  string dato;
  ifstream archivo;
  archivo.open("bitacora.txt");
  if(archivo.is_open()){
    while(!archivo.eof()){
      getline(archivo,dato);
			if(dato == " " || dato == "")
					break;
			dato = dato.substr(16,dato.length()-16);
			dato = dato.substr(0,dato.find(" "));
			dato = dato.substr(0,dato.find(":"));
			corte += dato2.find(".");
			string red = dato.substr(0,corte+1);
			string host = dato.substr(corte+2,dato.length()-corte);
      int red1 = stoi(red.substr(0, red.find(".")));
      int red2 = stoi(red.substr(red.find(".")+1,red.size()-red.find(".")));
      int suma = (red1*1000) + red2;
      suma %= 32749;
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
            break;
          }
          j++;
        }
     }
  }else{
    cout<< "Error al abrir el archivo" <<endl;
  }
}

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
  }

};

int main(){
  superHash bitacoraPro;
  bitacoraPro.leer_datos();
  int n;
  string dominio;
  cin >> n;
  while(n--){
    cin >> dominio;
    bitacoraPro.buscar(dominio);
  }
  cout << "Estoy vivo XD\n";
}
