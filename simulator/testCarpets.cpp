#include <iostream>
#include "./simulator.h"

using namespace std;

void testAt(){
	Carpets c;
	c.push(new Node(0));
	c.push(new Node(1));
	c.push(new Node(2));
	c.push(new Node(3));
	c.display();
	assert(c.at(0)->getRep().compare("3") == 0);
	assert(c.at(1)->getRep().compare("2") == 0);
	assert(c.at(2)->getRep().compare("1") == 0);
	assert(c.at(3)->getRep().compare("0") == 0);
}

int main(){
	testAt();
}
