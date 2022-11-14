//Act 5.1 - Implementación de un prototipo de tabla hash simple
//Jonathan Josafat Vázquez Suárez A01734225
//Jhonatan Yael Martinez A01734193
#include <iostream>
#include <string>

using namespace std;

//Declaracion de clase para manejo de datos
class dispersion{
private:
  //Estrcutura que guarda los datos del auto
  struct Auto{
    string placa;
    string marca;
    string modelo;
    int year;
    int valor;
    int tipo=0;
  };

  //Declaracion de la tabla hash
  struct Auto tabla[98];

public:
  //Funcion para insertar un valor en la tabla hash
  void ins(){
    string plac, marc, mod;
    char marc1[50], mod1[50];
    int anio, suma=0, suma2=0;
    char valor;
    //Booleano para detectar si esta duplicado este dato
    bool duplicado=false;
    cin>>plac;
    cin>>marc;
    cin>>mod;
    cin>>anio;
    //Revision de no duplicados
    for(int i=0;i<97;i++){
      if(tabla[i].placa==plac){
        cout<<"imposible insertar, placa duplicada"<<endl<<endl;
        duplicado=true;
      }
    }
    //Calculo de la suma de sus char en la placa
    for(int i=0;i<plac.length();i++){
      suma += plac[i];
    }
    //Aplicacion del modulo 97
    suma2 = suma%97;
    //Insertar en la tabla hash solo si no es duplicado
    while(suma2 < 97 && duplicado==false){
      //Si en la posicion que se inserta esta vacio, entonces el dato es agregado
      if(tabla[suma2].tipo == 0 || tabla[suma2].tipo == -1){
        tabla[suma2].placa = plac;
        tabla[suma2].marca = marc;
        tabla[suma2].modelo = mod;
        tabla[suma2].year = anio;
        tabla[suma2].tipo = 1;
        tabla[suma2].valor = suma%97;
        break;
      }
      //Si no esta vacio se busca un espacio en la siguiente posicion
      suma2 += 1;
    }
    //Si al terminar el while el dato no fue insertado entonces se imprime un mensaje
    if(suma2>=97){
      cout<<"tabla llena, imposible insertar"<<endl<<endl;
    }
    //Funcion de orden n
  }

  //Funcion para borrar un registro
  void del(){
    string matricula;
    int valor=0;
    cin>>matricula;
    //Se hace la suma de los char de la placa buscada
    for(int i=0;i<matricula.length();i++){
      valor += matricula[i];
    }
    //Se aplica el modulo 97
    valor = valor%97;
    //Se busac la placa que se quiere borrar en un recorrido igual al de insertar
    while(valor<97){
      if(tabla[valor].placa==matricula){
        tabla[valor].tipo = -1;
        tabla[valor].placa = "";
        tabla[valor].marca = "";
        tabla[valor].modelo = "";
        tabla[valor].year = 0;
        tabla[valor].valor = -1;
        break;
      }
      valor++;
    }
    if(valor>=97){
      cout<<"dato no encontrado"<<endl<<endl;
    }
    //Funcion de orden n
  }

  //Funcion para imprimir toda la tabla hash
  void print(){
    //Se recorre la tabla y se accede a cada parte de la estructura
    for(int i=0; i<97; i++){
      if(tabla[i].tipo==1)
        cout<<i<<" "<<tabla[i].placa<<" "<<tabla[i].marca<<" "<<tabla[i].modelo<<" "<<tabla[i].year<<endl;
      else
        cout<<i<<endl;
    }
    //Funcion de orden constante
  }

  //Funcion de busqueda de datos
  void search(){
    string busqueda;
    bool existe = false;
    int busq=0;
    //Se recibe la placa a buscar
    cin>>busqueda;
    //Se calcula el valor con modulo 97 de la placa
    for(int i=0;i<busqueda.length();i++){
      busq += busqueda[i];
    }
    int i = busq%97;
    //se recorre el arreglo buscando la placa desde la posicion
    while(i<97){
      if(tabla[i].placa==busqueda){
        existe = true;
        cout<<tabla[i].placa<<" "<<tabla[i].marca<<" "<<tabla[i].modelo<<" "<<tabla[i].year<<endl;
      }
      i++;
    }
    if(existe==false)
      cout<<"dato no encontrado"<<endl;
    //Funcion de orden lineal
  }
};

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

int main(){
  //Se inicializa la clase
  dispersion hash;
  bool flag = true;
  //Ciclo delimitado por booleano
  while(flag == true){
    //switch con 0 para romper ciclo o default para romper ciclo
    switch(entrada()){
      case 1: hash.ins(); break;
      case 2: hash.del(); break;
      case 3: hash.print(); cout<<endl; break;
      case 4: hash.search(); cout<<endl; break;
      case 0: flag = false; break;
      default: flag = false; break;
    }
  }
}
