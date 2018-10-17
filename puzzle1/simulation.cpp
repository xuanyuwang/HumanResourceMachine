#include <iostream>
#include <cstdlib>
#include <random>
#include "../simulator/simulator.h"

using namespace std;

void generator(Input* input){
	random_device rd;
	int N = 3;
	for(int i = 0; i < N; i++){
		int number = rd() % 10;
		input->set(number);
	}
}

int main(){
	Human human;
	Input input;
	Output output;

	generator(&input);
	input.display();
	while(!input.isEmpty()){
	 	human.inbox(&input);
		human.outbox(&output);
	}
	output.display();
}
