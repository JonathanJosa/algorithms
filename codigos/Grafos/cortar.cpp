#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main(){
string dato = "May 27 22:54:04 074.067.154.064:58754 Failed password for illegal user guest";
string time = dato.substr(0,15);
dato = dato.substr(16,dato.length()-16);
string error = dato.substr(dato.find(" ")+1,dato.length()-dato.find(" "));
dato = dato.substr(0,dato.find(" "));
string puerto = dato.substr(dato.find(":")+1,dato.length()-dato.find(":"));
dato = dato.substr(0,dato.find(":"));
int corte = dato.find(".");
string dato2 = dato.substr(corte+1,dato.length()-corte);
corte += dato2.find(".");
string red = dato.substr(0,corte+1);
string host = dato.substr(corte+2,dato.length()-corte);

cout<<time<<"pikis"<<endl;
cout<<error<<"pikis"<<endl;
cout<<puerto<<"pikis"<<endl;
cout<<red<<"pikis"<<endl;
cout<<host<<"pikis"<<endl;
}
