#include <bits/stdc++.h>
using namespace std;
vector<pair<int,string>> v;
int t,n,m,t2;
int main(){
  cin.tie(0);
	ios_base::sync_with_stdio(0);
  cin>>t;
  t2 = t;
  while(t--){
    cin>>n>>m;
    v.push_back( make_pair( pow(n,m), to_string(n)+" "+to_string(m)+"\n") );
  }
  sort(v.begin(), v.end());
  for(int i=0;i<t2;i++){
    cout<< v[i].second;
  }

}
