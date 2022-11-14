#include <iostream>

using namespace std;

int f,b,a;
float r;
int main(){
  cin.tie(NULL);
  ios_base::sync_with_stdio(false);
  cin>>f;
  while(f--){
    cin>>b>>a;
    r = (b+a)*0.3;
    if(b<=r){
      cout<<"BARCO\n";
      continue;
    }
    if(a<=r){
      cout<<"BATEADA MASIVA\n";
      continue;
    }
    cout<<"BATEADA MODERADA\n";
    continue;

  }
  return 0;
}
