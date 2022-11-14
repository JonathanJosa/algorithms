//Programación de algoritmos dinamica y avara

#include <iostream>
#include <bits/stdc++.h>
#include <algorithm>
#include <map>
#include <vector>

using namespace std;

map<int, pair<int, map<int, int>>> memoria;

void dinamica(map<int, int> monedas, int cambio){
  set<pair<int, map<int, int>>> recursos;
  pair<int, map<int, int>> temp;
  if(cambio == 0){
    memoria[0] = {0, monedas};
    return;
  }
  for(auto &v: monedas){
    if(cambio - v.first < 0) continue;

    if(memoria.count(cambio - v.first) <= 0) dinamica(monedas, cambio - v.first);

    temp = memoria[cambio - v.first];
    temp.first += 1;
    (temp.second)[v.first] += 1;
    recursos.insert({temp});
  }
  memoria[cambio] = *(recursos.begin());
}


map<int, int> programacionAvara(map<int, int> monedas, int cambio){
  for(auto it=monedas.rbegin(); it!= monedas.rend(); ++it){
    it->second = cambio/(it->first);
    cambio = cambio%(it->first);
  }
  return monedas;
}


map<int, int> programacionAvara2(map<int, int> monedas, int valor){

  if(monedas.size() <= 0 || valor <= 0) return monedas;

  int coin = (--monedas.end())->first;
  map<int, int> copia (monedas.begin(), --(monedas.end()));

  map<int, int> a = (programacionAvara(copia, valor%coin));
  a.insert({coin, (valor/coin)});
  return a;

}

void imprimir(map<int, int> monedas){

  for(auto it=monedas.rbegin(); it!= monedas.rend(); ++it){
    cout<<it->first<<":"<<it->second<<"\n";
  }
  cout<<"\n";

}

int main(){
  map<int, int> monedas;
  int N, entrada, P, Q;

  cin>>N;
  while(N--){
    cin>>entrada;
    monedas.insert({entrada, 0});
  }

  cin>>P>>Q;

  dinamica(monedas, Q-P);
  imprimir(memoria[Q-P].second);

  imprimir(programacionAvara(monedas, Q-P));
}
