#include <iostream>
#include "./simulator.h"

using namespace std;

void testAt(){
	Carpets c;
	c.push(new Node(0));
	c.push(new Node(1));
	c.push(new Node(2));
	c.push(new Node(3));
	assert(c.at(2).getRep().compare("empty node") == 0);
}

int main(){
	testAt();
}
