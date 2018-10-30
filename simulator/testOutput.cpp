#include <iostream>
#include "./OutputBox.h"
#include "./xassert.h"

using namespace std;

void testOutput(){
	OutputBox ob;
	ob.receive(new Node(3));
	xassert(ob.toString().compare("3 \n") == 0);
}


int main(){
	testOutput();
}

