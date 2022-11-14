#include <bits/stdc++.h>
using namespace std;

int n, a, t, b;
int arr[200000];
int main(){
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cin>>n;
  while(n--){
    cin>>t;
    arr[t]++;
  }
  for (int i=i;i<=100000;i++){
    arr[i]+=arr[i-1];
  }
  cin>>a>>b;
  cout<<arr[b]-(a>0 ? arr[a-1] : 0);
}
