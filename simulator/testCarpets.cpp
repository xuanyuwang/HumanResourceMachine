#include <iostream>
#include "./Carpets.h"

using namespace std;

void testAt(){
	Carpets c;
	c.push(new Node(0));
	c.push(new Node(1));
	c.push(new Node(2));
	c.push(new Node(3));
	assert(c.at(0)->getRep().compare("3") == 0);
	assert(c.at(1)->getRep().compare("2") == 0);
	assert(c.at(2)->getRep().compare("1") == 0);
	assert(c.at(3)->getRep().compare("0") == 0);
}

void testInit(){
	Carpets c(1);
	assert(c.toString().compare("empty node \n") == 0);
}

int main(){
	testInit();
	testAt();
}
