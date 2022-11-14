#include <bits/stdc++.h>

using namespace std;

//Los nombres Oc provienen de cada octeto de la IP
struct IP{
  int oc1;
  int oc2;
  int oc3;
  int oc4;
  int puerto;
};

struct Node{
  string data;
  int tiempo;
  string error;

  struct Node* next;
  struct Node* back;

  struct IP direccion;
};

struct IP crea_IP(string ip){
  struct IP temp;
  temp.oc1 = stoi(ip.substr(0,ip.find(".")));
  ip = ip.substr(ip.find(".")+1,ip.length());
  temp.oc2 = stoi(ip.substr(0,ip.find(".")));
  ip = ip.substr(ip.find(".")+1,ip.length());
  temp.oc3 = stoi(ip.substr(0,ip.find(".")));
  ip = ip.substr(ip.find(".")+1,ip.length());
  temp.oc4 = stoi(ip.substr(0,ip.find(":")));
  ip = ip.substr(ip.find(":")+1,ip.length());
  temp.puerto = stoi(ip);
  return temp;
}

int mes_to_seg(string m){
  string meses_dias[2][12] = {{"Jan","Feb","Mar","Apr","May","Jun","Jul","Aug","Sep","Oct","Nov","Dec"},{"31","28","31","30","31","30","31","31","30","31","30","31"}};
  int s = 0;
  for(int i = 0; i < 12; i++){
    if(m == meses_dias[0][i]){
      return  s*3600*24;
    }
    s += stoi(meses_dias[1][i]);
  }
  return s*3600*24;
}

void Insertar(string dato,struct Node** h){
  int mes;
  int dia;
  int hora;
  int min;
  int seg;

  mes = mes_to_seg(dato.substr(0,3));
  dia = stoi(dato.substr(4,2));
  hora = stoi( dato.substr(7,2) );
  min = stoi( dato.substr(10,2) );
  seg = stoi( dato.substr(13,2) );
  int time = seg + (min*60) + (hora*3600) + (dia*3600*24) + mes;

  struct IP dir2;
  string temp = dato.substr(16,dato.length());
  string error = temp.substr(temp.find(" "),temp.length());
  string dir = dato.substr(16,temp.find(" "));
  dir2 = crea_IP(dir);

  struct Node* nodito = new Node;
  nodito -> data = dato;
  nodito -> tiempo = time;
  nodito -> direccion = dir2;
  nodito -> error = error;

  struct Node *tmp2;
  bool flag = false;
  tmp2 = *h;
  if(*h == NULL){
    nodito -> back = NULL;
    nodito -> next = NULL;
    *h = nodito;
  }else{
    while(tmp2->next != NULL && flag == false){

      if(tmp2->direccion.oc1 < nodito->direccion.oc1){
         flag = false;
       }else{
         if(tmp2->direccion.oc1 == nodito->direccion.oc1){
           if(tmp2->direccion.oc2 < nodito->direccion.oc2){
              flag = false;
            }else{
              if(tmp2->direccion.oc2 == nodito->direccion.oc2){
                if(tmp2->direccion.oc3 < nodito->direccion.oc3){
                   flag = false;
                 }else{
                   if(tmp2->direccion.oc3 == nodito->direccion.oc3){
                     if(tmp2->direccion.oc4 < nodito->direccion.oc4){
                        flag = false;
                      }else{
                        if(tmp2->direccion.oc4 == nodito->direccion.oc4){
                          if(tmp2->direccion.puerto < nodito->direccion.puerto){
                             flag = false;
                           }else{
                             if(tmp2->direccion.puerto == nodito->direccion.puerto){
                               if(tmp2->tiempo < nodito->tiempo){
                                  flag = false;
                                }else{
                                  if(tmp2->tiempo == nodito->tiempo){
                                    if(((tmp2->error).compare(nodito->error))<0){
                                      flag = false;
                                    }else{
                                      flag = true;
                                    }
                                  }else{
                                    flag = true;
                                  }
                                }
                             }else{flag = true;}
                           }
                        }else{flag = true;}
                      }
                   }else{flag = true;}
                 }
              }else{flag = true;}
            }
         }else{flag = true;}
       }

      if(flag == false){tmp2 = tmp2 -> next;}
    }


    bool flag2 = true;
    if(tmp2->direccion.oc1 < nodito->direccion.oc1){
       flag2 = false;
     }else{
       if(tmp2->direccion.oc1 == nodito->direccion.oc1){
         if(tmp2->direccion.oc2 < nodito->direccion.oc2){
            flag2 = false;
          }else{
            if(tmp2->direccion.oc2 == nodito->direccion.oc2){
              if(tmp2->direccion.oc3 < nodito->direccion.oc3){
                 flag2 = false;
               }else{
                 if(tmp2->direccion.oc3 == nodito->direccion.oc3){
                   if(tmp2->direccion.oc4 < nodito->direccion.oc4){
                      flag2 = false;
                    }else{
                      if(tmp2->direccion.oc4 == nodito->direccion.oc4){
                        if(tmp2->direccion.puerto < nodito->direccion.puerto){
                           flag2 = false;
                         }else{
                           if(tmp2->direccion.puerto == nodito->direccion.puerto){
                             if(tmp2->tiempo < nodito->tiempo){
                                flag2 = false;
                              }else{
                                if(tmp2->tiempo == nodito->tiempo){
                                  if(((tmp2->error).compare(nodito->error))<0){
                                    flag2 = false;
                                  }else{
                                    flag2 = true;
                                  }
                                }else{
                                  flag2 = true;
                                }
                              }
                           }else{flag2 = true;}
                         }
                      }else{flag2 = true;}
                    }
                 }else{flag2 = true;}
               }
            }else{flag2 = true;}
          }
       }else{flag2 = true;}
     }

    if(flag2 == false){
      tmp2 -> next = nodito;
      nodito -> back = tmp2;
      nodito -> next = NULL;
    }else{
      if(tmp2->back == NULL){
        (*h)->back = nodito;
        nodito ->back = NULL;
        nodito -> next = (*h);
        (*h) = nodito;
      }else{
        struct Node *tmp;
        tmp = tmp2->back;
        tmp->next = nodito;
        tmp2->back = nodito;
        nodito -> next = tmp2;
        nodito -> back = tmp;
      }
    }
  }
}

void busqueda(string inicio, string final, struct Node* h){
    struct Node *tmp = h;
    vector<string> salida;
    bool limite = false, cont = true;

    struct IP start;
    start = crea_IP(inicio);

    struct IP end;
    end = crea_IP(final);

    ofstream outfile("sortedData.txt");
    while(tmp != NULL && cont == true){
      if(limite == false){
        if(tmp->direccion.oc1 < start.oc1){
           limite = false;
         }else{
           if(tmp->direccion.oc1 == start.oc1){
             if(tmp->direccion.oc2 < start.oc2){
                limite = false;
              }else{
                if(tmp->direccion.oc2 == start.oc2){
                  if(tmp->direccion.oc3 < start.oc3){
                     limite = false;
                   }else{
                     if(tmp->direccion.oc3 == start.oc3){
                       if(tmp->direccion.oc4 < start.oc4){
                          limite = false;
                        }else{
                          if(tmp->direccion.oc4 == start.oc4){
                            limite = true;
                          }else{
                            limite = true;
                          }
                        }
                     }else{
                       limite = true;
                     }
                   }
                }else{
                  limite = true;
                }
              }
           }else{
             limite = true;
           }
         }
      }

      if(limite == true){
        if(tmp->direccion.oc1 < end.oc1){
           limite = true;
         }else{
           if(tmp->direccion.oc1 == end.oc1){
             if(tmp->direccion.oc2 < end.oc2){
                limite = true;
              }else{
                if(tmp->direccion.oc2 == end.oc2){
                  if(tmp->direccion.oc3 < end.oc3){
                     limite = true;
                   }else{
                     if(tmp->direccion.oc3 == end.oc3){
                       if(tmp->direccion.oc4 < end.oc4){
                          limite = true;
                        }else{
                          if(tmp->direccion.oc4 == end.oc4){
                            limite = true;
                          }else{
                            limite = false;
                            cont = false;
                          }
                        }
                     }else{
                       limite = false;
                       cont = false;
                     }
                   }
                }else{
                  limite = false;
                  cont = false;
                }
              }
           }else{
             limite = false;
             cont = false;
           }
         }
      }

      if(limite == true && cont == true){
        salida.push_back(tmp->data);
        outfile<<tmp->data<<endl;
      }
      tmp = tmp -> next;
    }
  for(int i=salida.size();i>0;i--){
    cout<<salida[i-1]<<endl;
  }
}


void leer_datos(struct Node** h){
  string data;
  ifstream archivo;
  archivo.open("bitacora-11.txt");
  if(archivo.is_open()){
    while(!archivo.eof()){
      getline(archivo,data);
      Insertar(data,&(*h));
    }
  }else{
    cout<< "Error al abrir el archivo" <<endl;
  }
}

int main(){
  struct Node* head = NULL;
  leer_datos(&head);
  string inicio, fin;
  cin>>inicio;
  cin>>fin;
  busqueda(inicio, fin, head);
}
