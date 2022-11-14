#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main(){
	int N, num;
	cin >> N;
	vector <int> secuencia = {1,1};
	for(int i = 2; i <= N; i++){
		num = secuencia[i - 1] + secuencia[i - 2];
		secuencia.push_back(num);
		if(num > N){
			break;
		}
	}
	bool dentro = false;
	for(int i = 0; i < secuencia.size(); i++){
		if(secuencia[i] == N){
			dentro = true;
			break;
		}
	}
	bool fibonacci = dentro ? true : false;

	bool primo = (N == 1) ? false : true;

	for(int i = 2; i < N; i++){
		if((N % i) == 0){
			primo = false;
		}
	}
	if(fibonacci && primo){
		printf("asombroso\n");
	} else if(fibonacci && !primo){
		printf("fibonacci\n");
	} else{
		printf("ordinario\n");
	}
	return 0;
}
