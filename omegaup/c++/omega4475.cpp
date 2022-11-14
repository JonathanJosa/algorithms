#include <bits/stdc++.h>
using namespace std;
int n,a,b,c,i;
string s="";
int main(){
  cin>>n;
  while(n--){
    cin>>a>>b>>c;
    a+=c;
    cin>>c;
    b+=c;    
    for(i=4;i>0;--i){
      cin>>c;
      if(c==a){
        cin>>c;
        if(c==b){
          s+=char(69-i);
        }
        continue;
      }
      cin>>c;
    }
  }
  cout<<s;
}
