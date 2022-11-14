#include <iostream>

using namespace std;

int main(){
  int pl=0, pr=0, gl=0, gr=0;
  char a;
  bool saque = true;
  while(cin>>a){
    if(a==81){
      if(gr>=2){
        cout<<gl<<" - 2 (winner)"<<endl;
      }else if(gl>=2){
        cout<<"2 (winner) - "<<gr<<endl;
      }else{
        if(saque==true){
          cout<<gl<<" ("<<pl<<"*) - "<<gr<<" ("<<pr<<")"<<endl;
        }else{
          cout<<gl<<" ("<<pl<<") - "<<gr<<" ("<<pr<<"*)"<<endl;
        }
      }
    }else if(a==83){
      if(saque==true){
        pl++;
      }else{
        pr++;
      }
    }else if(a==82){
      if(saque==true){
        pr++;
        saque=false;
      }else{
        pl++;
        saque=true;
      }
    }else{
      break;
    }
    if(((pr-pl)>=2 && (pr>=5))  || pr >= 10 ){
      pl=0;
      pr=0;
      gr++;
    }else if(((pl-pr)>=2 && (pl>=5)) || pl >= 10){
      pl=0;
      pr=0;
      gl++;
    }
  }
}
