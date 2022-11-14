#include <iostream>
#include <string>

using namespace std;

int main() {
  string a;
  char buf[10];
  fgets(buf, 10, stdin);
  a = buf;
  cout<<a;
}
