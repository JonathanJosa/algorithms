#include <iostream>
#include <vector>

using namespace std;

int main(){
  unsigned t0, t1;
  t0=clock();
  vector <int> v;
  int n,m, men, max, temp, st, end;
  string tipo;
  cin>> n;
  cin>> m;
  while (n--){
      cin>> temp;
      v.push_back(temp);
  }
  while(m--){
    cin>>tipo;
    cin>>st;
    cin>>end;
    if(tipo=="C"){
      men = 1000001;
      max = 0;
      for(int i = st-1;i<end;i++){
        if(v[i]<men)
          men = v[i];
        if(v[i]>max)
          max = v[i];
      }
      //cout << men <<" "<< max <<endl;
    }else{
      v[st-1]=end;
    }
  }
  t1 = clock();
  double time = (double(t1-t0)/CLOCKS_PER_SEC);
  cout << "Execution Time: " << time << endl;
}
