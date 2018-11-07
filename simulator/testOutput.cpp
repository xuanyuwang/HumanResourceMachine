#include <iostream>
#include "./OutputBox.h"

using namespace std;

void testReceive(){
	OutputBox ob;
	ob.receive(new Node(3));
	ob.receive(new Node("hi"));
	assert(ob.toString() == "3 hi \n");
}


int main(){
    testReceive();
}

