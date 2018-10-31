#include <iostream>
#include "./InputBox.h"

using namespace std;

void testInput(){
	InputBox ib;
	ib.push(new Node(4));
	assert(ib.provide()->getRep().compare("4") == 0);
}


int main(){
	testInput();
}
