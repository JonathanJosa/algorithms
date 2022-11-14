//Jonathan Josafat Vázquez Suárez
//A01734225
#include<bits/stdc++.h>
using namespace std;

struct Nodo{
  int data;
  struct Nodo* izq;
  struct Nodo* der;
};

struct Nodo* findMin(Nodo* padre)
{
	while(padre->izq != NULL){
    padre = padre->izq;
  }
	return padre;
};

void insertar(struct Nodo **p, int data){
  struct Nodo *control;
  control = *p;
  struct Nodo *tmp = new Nodo;
  tmp -> data = data;
  tmp -> izq = NULL;
  tmp -> der = NULL;
  if(control != NULL){
    while(control != NULL){
      if(control->data > data){
        if(control->izq == NULL){
          control->izq = tmp;
          break;
        }
        control = control->izq;
      }else if(control->data < data){
        if(control->der == NULL){
          control->der = tmp;
          break;
        }
        control = control->der;
      }else{
        break;
      }
    }
  }else{
    *p = tmp;
  }
}

void transversal(struct Nodo **p, int tipo){
  struct Nodo *control;
  control = *p;
  if(tipo == 1 && control != NULL){
    cout<< control->data << " ";
    transversal(&(control->izq), tipo);
    transversal(&(control->der), tipo);
  }
  if(tipo == 2 && control != NULL){
    transversal(&(control->izq), tipo);
    cout<< control->data << " ";
    transversal(&(control->der), tipo);
  }
  if(tipo == 3 && control != NULL){
    transversal(&(control->izq), tipo);
    transversal(&(control->der), tipo);
    cout<< control->data << " ";
  }
  if(tipo == 4 && control != NULL){
    cout<<"Trabajando...";
  }
}

int height(struct Nodo **p, int v){
  struct Nodo *control;
  control = *p;
  int v1 = 0,v2 = 0;
  if(control != NULL){
    v1 = height(&(control->der), v+1);
    v2 = height(&(control->izq), v+1);
    if(v1 != 0 || v2 != 0){
      if(v1 >= v2)
        return v1;
      else
        return v2;
    }else{
        return v;
    }
  }
  return v;
}

void whatlevelamI(struct Nodo **p, int data){
  int cont = 0;
  struct Nodo *control;
  control = *p;
  bool flag = false;
  while(control != NULL){
    if(control->data == data){
        flag = true;
        break;
    }else{
      cont += 1;
    }
    if(control->data > data){
      if(control->izq == NULL){
        break;
      }
      control = control->izq;
    }else if(control->data <= data){
      if(control->der == NULL){
        break;
      }
      control = control->der;
    }else{
      break;
    }
  }
  if(flag == false){
    cout << -1;
  }else{
    cout << cont;
  }
}

void ancestors(struct Nodo **p, int data){
  vector<int> v;
  struct Nodo *control;
  control = *p;
  bool flag = false;
  while(control != NULL){
    if(control->data == data){
        flag = true;
        break;
    }else{
      v.push_back(control->data);
    }
    if(control->data > data){
      if(control->izq == NULL){
        break;
      }
      control = control->izq;
    }else if(control->data <= data){
      if(control->der == NULL){
        break;
      }
      control = control->der;
    }else{
      break;
    }
  }
  if(v.size()==0 && flag == false){
    if(control == NULL)
      cout<< endl;
    else
      cout << -1;
  }else{
    for(int i=0;i<v.size();i++){
      cout<< v[i] << " ";
    }
  }
}

struct Nodo* eliminar(struct Nodo *padre, int data){
  if (padre == NULL)
    return padre;
  else if (data < padre->data)
    padre->izq = eliminar(padre->izq, data);
  else if (data > padre->data)
    padre->der = eliminar(padre->der, data);
  else {
      if (padre->izq == NULL && padre->der == NULL ) {
        delete padre;
        padre = NULL;
        return padre;
      }
      else if(padre->izq == NULL){
        struct Nodo *temp = padre;
        padre = padre->der;
        delete temp;
      }
      else if(padre->der == NULL ){
        struct Nodo *temp = padre;
        padre = padre->izq;
        delete temp;
      }
      else {
        struct Nodo *temp = findMin(padre->der);
        padre->data = temp->data;
        padre->der = eliminar(padre->der,temp->data);
      }
  }
  return padre;
}

int main(){
  struct Nodo *padre = NULL;
  int n1,n2;
  cin>>n1;
  for (int i=0;i<n1;i++){
    cin>>n2;
    insertar(&padre,n2);
  }
  cin>>n1;
  for (int i=0;i<n1;i++){
    cin>>n2;
    struct Node *tmpR = NULL;
    eliminar(padre, n2);
  }
  transversal(&padre, 1);
  cout << endl;
  transversal(&padre, 2);
  cout << endl;
  transversal(&padre, 3);
  cout << endl;
  transversal(&padre, 4);
  cout << endl;
  cout << height(&padre,-1);
  cout << endl;
  cin>>n1;
  for (int i=0;i<n1;i++){
    cin>>n2;
    ancestors(&padre,n2);
    cout << endl;
  }
  cin>>n1;
  for (int i=0;i<n1;i++){
    cin>>n2;
    whatlevelamI(&padre,n2);
    cout << endl;
  }
  return 0;
}
