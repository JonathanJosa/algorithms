#include<bits/stdc++.h>

using namespace std;

struct Node{
	string name;
  int grado;
  vector<struct Node*> next;
};

void leer_datos(struct Node** root){
  map <string, struct Node*> Red;
  map <string, struct Node*> Host;
  map <string, struct Node*> Puerto;
  map <string, struct Node*> Error;
  map <string, struct Node*> Fecha_Hora;

  string txt;
  string dato;
  ifstream archivo;

  archivo.open("bitacora3.txt");
  if(archivo.is_open()){
    while(!archivo.eof()){
      getline(archivo,dato);
			if(dato == " " || dato == "")
					break;

      struct Node* guia;
      guia = *root;

			string time = dato.substr(0,15);
			dato = dato.substr(16,dato.length()-16);
			string error = dato.substr(dato.find(" ")+1,dato.length()-dato.find(" "));
			dato = dato.substr(0,dato.find(" "));
			string puerto = dato.substr(dato.find(":")+1,dato.length()-dato.find(":"));
			dato = dato.substr(0,dato.find(":"));
			int corte = dato.find(".");
			string dato2 = dato.substr(corte+1,dato.length()-corte);
			corte += dato2.find(".");
			string red = dato.substr(0,corte+1);
			string host = dato.substr(corte+2,dato.length()-corte);

      //Red
      txt = red;
      // Creamos un nuevo Nodo para la Red
      if(Red.count(txt) == 0){
    		struct Node* temp = new Node();
    		temp -> name = txt;
    		temp -> grado = 0;
				Red[txt] = temp;
  		}
      Red[txt] -> grado ++;
      guia -> next.push_back(Red[txt]);
			guia = Red[txt];

      //host
      txt = host;
    	if(Host.count(txt) == 0){
    		struct Node* temp = new Node();
    		temp -> name = txt;
    		temp -> grado = 0;
				Host[txt] = temp;
  		}
			Host[txt] -> grado ++;
      guia -> next.push_back(Host[txt]);
			guia = Host[txt];


      //Puerto
      txt = puerto;
      if(Puerto.count(txt) == 0){
    		struct Node* temp = new Node();
    		temp -> name = txt;
    		temp -> grado = 0;
				Puerto[txt] = temp;
  		}
      Puerto[txt] -> grado ++;
      guia -> next.push_back(Puerto[txt]);
			guia = Puerto[txt];

      //Error
      txt = error;
      if(Error.count(txt) == 0){
    		struct Node* temp = new Node();
   		 	temp -> name = txt;
    		temp -> grado = 0;
				Error[txt] = temp;
  		}
    	Error[txt] -> grado ++;
      guia -> next.push_back(Error[txt]);
			guia = Error[txt];


      //Fecha
      txt = time;
      if(Fecha_Hora.count(txt) == 0){
    		struct Node* temp = new Node();
    		temp -> name = txt;
    		temp -> grado = 0;
				Fecha_Hora[txt] = temp;
  		}
      Fecha_Hora[txt] -> grado ++;
      guia -> next.push_back(Fecha_Hora[txt]);

    }

  }else{
    cout<< "Error al abrir el archivo" <<endl;
  }

}

void incidenciasRed(struct Node** root){
	struct Node* raiz;
	raiz = *root;
	int n = raiz -> next.size();
	vector<struct Node*> repetidos;
	int tam=0 , may=-1;


	//Buscar
	for (int i=0;i<n;i++){
		map <struct Node*,int> distintos;
		int t = (raiz -> next[i]) -> next.size();
		for(int j=0;j<t;j++){
			if(distintos.count((raiz -> next[i]) -> next[j]) == 0){
					distintos[(raiz -> next[i]) -> next[j]] = 1;
			}
		}
		tam = distintos.size();
		if(tam>may){
			repetidos.clear();
			may = tam;
			repetidos.push_back((raiz -> next[i]));
		}else if(tam==may){
			repetidos.push_back((raiz -> next[i]));
		}
	}


	//Impresion
	map <struct Node*,string> distintos;
	map <struct Node*,string>::iterator it;

	for(int j=0;j<repetidos.size();j++){
		if(distintos.count(repetidos[j]) == 0){
				distintos[repetidos[j]] = repetidos[j]->name;

		}
	}
	for(it=distintos.begin(); it!=distintos.end(); ++it){
		cout<<it->second<<endl;
	}

}


void superIp(struct Node** root){
	struct Node* raiz;
	raiz = *root;
	int n = raiz->next.size();
	string ip;
	map <string,int> distintas;

	stack<string> elStack;
	for(int i=0; i<n;i++){
		ip = raiz->next[raiz->next.size()-1]->name;
		ip += ".";
		ip += ((raiz->next[raiz->next.size()-1])->next[raiz->next[raiz->next.size()-1]->next.size()-1]->name);
		raiz->next[raiz->next.size()-1]->next.pop_back();
		raiz->next.pop_back();
		elStack.push(ip);
	}

	for(int i=0;i<n;i++){
		ip = elStack.top();
		elStack.pop();
		if(distintas.count(ip)==0){
			distintas[ip]=0;
		}
		distintas[ip]++;
	}


	vector<string> repetidos;
	int may=-1, tam=0;
	for(map <string,int>::iterator it=distintas.begin();it!=distintas.end();++it){
		tam = it->second;
		if(tam>may){
			repetidos.clear();
			may = tam;
			repetidos.push_back(it->first);
		}else if(tam==may){
			repetidos.push_back(it->first);
		}
	}

	map <string,int> distintos2;
	for(int j=0;j<repetidos.size();j++){
		if(distintos2.count(repetidos[j]) == 0){
				distintos2[repetidos[j]] = 1;
		}
	}
	for(map <string,int>::iterator it2=distintos2.begin(); it2!=distintos2.end(); ++it2){
		cout<<it2->first<<endl;
	}
}


int  main(){
	struct Node* Root = new Node();
	leer_datos(&Root);
	incidenciasRed(&Root);
	cout<<endl;
	superIp(&Root);
}
