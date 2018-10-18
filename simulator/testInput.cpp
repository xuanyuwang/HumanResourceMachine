#include <iostream>
#include "simulator.h"

using namespace std;

void testInput(){
	InputBox ib;
	ib.push(new Node(4));
	assert(ib.provide().getRep().compare("4") == 0);
}

void testOutput(){
	OutputBox ob;
	ob.receive(new Node(3));
	assert(ob.top().getRep().compare("3") == 0);
}

int main(){
	testInput();
	testOutput();
}
