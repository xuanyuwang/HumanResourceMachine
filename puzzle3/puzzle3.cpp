#include <iostream>
#include "../simulator/simulator.h"

using namespace std;

void generator(InputBox* input, Carpets* carpets){
	input->push(new Node(-99));
	input->push(new Node(-99));
	input->push(new Node(-99));
	carpets->push(new Node("E"));
	carpets->push(new Node("B"));
	carpets->push(new Node("G"));
	carpets->push(new Node("X"));
	carpets->push(new Node("J"));
	carpets->push(new Node("U"));
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

	ob->display();
}
