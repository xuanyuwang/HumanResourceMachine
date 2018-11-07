#include <iostream>
#include <cstdlib>
#include "../../simulator/simulator.h"

using namespace std;

void generator(InputBox* input){
    input->append(new Node("A"));
    input->append(new Node("U"));
    input->append(new Node("T"));
    input->append(new Node("O"));
	input->append(new Node("E"));
	input->append(new Node("X"));
	input->append(new Node("E"));
    input->append(new Node("C"));
}

int main(){
	Human human;
	InputBox ib;
	OutputBox ob;

	generator(&ib);
	string input = ib.toString();

	//**********************
	do{
		human.inbox(&ib);
		human.outbox(&ob);
	}while (!ib.empty());
	//**********************

	string output = ob.toString();
	assert(output == input);
}
