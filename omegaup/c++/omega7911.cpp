#include <iostream>
using namespace std;
int a,b,c;
int main(void){
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cin>>a>>b>>c;
  if(b==c){
    cin>>c;
    if(a==c){
      cout<<"1";
      return 0;
    }
  }
  cout<<"0";
  return 0;
}
