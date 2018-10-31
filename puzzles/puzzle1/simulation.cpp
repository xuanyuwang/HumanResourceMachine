#include <iostream>
#include <cstdlib>
#include <random>
#include "../../simulator/simulator.h"

using namespace std;

void generator(InputBox* input){
	random_device rd;
	int N = 3;
	for(int i = 0; i < N; i++){
		int number = rd() % 10;
		input->push(number);
	}
}

int main(){
	Human human;
	InputBox input;
	OutputBox output;

	generator(&input);
	string inputS = input.toString();
	while(!input.empty()){
	 	human.inbox(&input);
		human.outbox(&output);
	}
	
	string outputS = output.toString();
	assert(outputS.compare(inputS) == 0);
}
