#include <iostream>
#include "../../simulator/simulator.h"

using namespace std;

void generator(InputBox* input, Carpets* carpets){
	input->append(new Node(-99));
	input->append(new Node(-99));
	input->append(new Node(-99));
	carpets->append(new Node("U"));
	carpets->append(new Node("J"));
	carpets->append(new Node("X"));
	carpets->append(new Node("G"));
	carpets->append(new Node("B"));
	carpets->append(new Node("E"));
}

int main(){
	Human* human = new Human();
	InputBox* ib = new InputBox();
	OutputBox* ob = new OutputBox();
	Carpets* carpets = new Carpets(); 
	
	generator(ib, carpets);

	human->copyfrom(carpets, 4);
	human->outbox(ob);
	human->copyfrom(carpets, 0);
	human->outbox(ob);
	human->copyfrom(carpets, 3);
	human->outbox(ob);

	assert(ob->toString().compare("B U G \n") == 0);
}
