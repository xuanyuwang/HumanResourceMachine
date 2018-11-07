#include <iostream>
#include "./InputBox.h"

using namespace std;

void testProvide(){
	InputBox ib;
	ib.append(new Node(4));
	assert(ib.provide()->toString() == "4");
}


int main(){
    testProvide();
}
