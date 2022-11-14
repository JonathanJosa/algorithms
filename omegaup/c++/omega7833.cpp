#include <bits/stdc++.h>
using namespace std;

int n,t,r=0;
map<int,int> v;
int main(){
	cin.tie(0);
	ios_base::sync_with_stdio(0);
	cin>>n;
	while(n--){
		cin>>t;
		v[t]=1;
	}
	cin>>n;
	while(n--){
		cin>>t;
		if(!v[t]){
			r++;
			v[t]=1;
		}
	}
	cout<<r;
}
