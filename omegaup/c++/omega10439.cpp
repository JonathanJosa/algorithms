#include <iostream>
using namespace std;
int n,m,c=0;
bool b=false;
int main(void){
  cin.tie(0);
	ios_base::sync_with_stdio(0);
  cin>>n>>m;
  while(n<=m){
    if(b){
      c++;
      n+=4;
      continue;
    }
    if(n%4==0){
      b=true;
      n+=4;
      c++;
      continue;
    }
    n++;
  }
  cout<<c;
}
