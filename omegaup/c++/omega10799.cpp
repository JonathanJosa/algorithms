#include <iostream>
using namespace std;
char a[3];
int d=0;
int main(){
  cin.tie(0);
  ios_base::sync_with_stdio(0);
  cin>>a[0]>>a[1];
  while(cin>>a[2]){
    if(a[0]==a[2] && a[0]!=a[1]) d+=1;
    a[0]=a[1];
    a[1]=a[2];
  }
  cout<<d;
}
