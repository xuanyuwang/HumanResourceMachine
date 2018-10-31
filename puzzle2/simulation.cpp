#include <iostream>
#include <cstdlib>
#include "../simulator/simulator.h"

using namespace std;

void generator(InputBox* input){
	input->push(new Node("C"));
	input->push(new Node("E"));
	input->push(new Node("X"));
	input->push(new Node("E"));
	input->push(new Node("O"));
	input->push(new Node("T"));
	input->push(new Node("U"));
	input->push(new Node("A"));
}

int main(){
	Human human;
	InputBox ib;
	OutputBox ob;

	generator(&ib);
	ib.display();
	string input = ib.toString();
des:
	human.inbox(&ib);
	human.outbox(&ob);
	if(!ib.empty()) goto des;
	ob.display();
	ob.reverse();
	string output = ob.toString();
	assert(output.compare(input) == 0);
}
