#include <iostream>
#include <string>
#include <vector>
using namespace std;
struct ma{
  int max;
  int min;
};
vector <struct ma> v;
vector <int> r;
int n,n2,t,ma,mi,i,j,k,compa;
string a;
int main(void){
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cin>>n>>n2;
  for(j = 0;j<n;j++){
    mi = 1000001;
    ma = 0;
    if((n-j)>=10){
      for(i=0;i<10;i++){
        cin>>t;
        r.push_back(t);
        if(mi>t)
          mi=t;
        if(ma<t)
          ma=t;
      }
      struct ma temp;
      temp.max=ma;
      temp.min=mi;
      v.push_back(temp);
      j+=9;
      continue;
    }
    for(i=0;i<(n-j);i++){
      cin>>t;
      r.push_back(t);
      if(mi>t)
        mi=t;
      if(ma<t)
        ma=t;
    }
    struct ma temp;
    temp.max=ma;
    temp.min=mi;
    v.push_back(temp);
    break;
  }
  while(n2--){
    cin>>a>>mi>>ma;
    mi--;
    ma--;
    if(a=="C"){
      compa = 0;
      i = 1000001; //minimo
      j = 0; //max
      while(mi%10!=0 && mi<=ma){
        if(i>r[mi])
          i=r[mi];
          compa++;
        if(j<r[mi])
          j = r[mi];
          compa++;
        mi++;
      }
      while(ma%10!=0 && ma>=mi){
        if(i>r[ma])
          i=r[ma];
          compa++;
        if(j<r[ma])
          j = r[ma];
          compa++;
        ma--;
      }
      if(i>r[ma])
        i=r[ma];
        compa++;
      if(j<r[ma])
        j = r[ma];
        compa++;
      if(ma==mi){
        cout<<i<<" "<<j<<"\n";
        continue;
      }
      mi/=10;
      ma/=10;
      for(k=mi;k<ma;k++){
        if(v[k].max>j)
          j = v[k].max;
          compa++;
        if(v[k].min<i)
          i = v[k].min;
          compa++;
      }
      cout<<i<<" "<<j<<"\n";
      continue;
    }
    r[mi]=++ma;
    t = mi/10;
    i = 1000000; //minimo
    j = 0; //max
    mi--;
    mi -= mi%10;
    for(k=0;k<10;k++){
      if(mi+k>=n)
        break;
      if(i>r[mi+k])
        i=r[mi+k];
      if(j<r[mi+k])
        j = r[mi+k];
    }
    v[t].max=j;
    v[t].min=i;
  }
}
