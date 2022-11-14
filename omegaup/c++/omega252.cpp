#include <bits/stdc++.h>
using namespace std;
int n1, n2;
int rev(queue<int> h){
  queue<int> h2;
  n1 = h.front();
  h.pop();
  h2.push(n1);
  if(h.empty())
    return 1;
  while(!h.empty()){
    n2 = h.front();
    h.pop();
    if(n2>n1){
      h2.push(n2);
    }
    n1 = n2;
  }
  if(n1>h2.front())
    h2.pop();
  return 1 + rev(h2);
}

int main(){
  cin.tie(NULL);
  ios_base::sync_with_stdio(false);
  queue<int> h;
  cin>>n2>>n1;
  h.push(n1);
  while(cin>>n2){
    if(n2>n1)
      h.push(n2);
    n1 = n2;
  }
  if(n1>h.front())
    h.pop();
  cout<<rev(h);
}
