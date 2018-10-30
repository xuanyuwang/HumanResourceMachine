#include <cstdlib>
#include <string>
#include <iostream>
#include "Node.h"

using namespace std;

void xassert(bool b, string msg){
	if(b){// Success
		assert(1);
	}else{// Failure
		cout << msg << endl;
		assert(0);
	}
}
void xassert(bool b){
	if(b){// Success
		assert(1);
	}else{// Failure
		assert(0);
	}
}

void testInit(){
	Node n;
	xassert(n.intValue == NULL);
	xassert(n.stringValue == NULL);
}

void testInitAsInt(){
	Node n(3);
	xassert(*(n.intValue) == 3);
}

void testInitAsString(){
	Node n("hello");
	xassert((*(n.stringValue)).compare("hello") == 0);
}

void testGetRep(){
	Node a;
	Node b(3);
	Node c("hello");

	xassert(a.getRep().compare("empty node") == 0, "Not empty");
	xassert(b.getRep().compare("3") == 0);
	xassert(c.getRep().compare("hello") == 0);
}

void testSetValue(){
	Node a;
	Node* b = new Node(3);
	Node c("hi");

	a.setValue(b);
	xassert(a.getRep().compare("3") == 0, "set to int");
	a.setValue(&c);
	xassert(a.getRep().compare("hi") == 0, "set it to string");
}

int main(){
	testInit();
	testInitAsInt();
	testInitAsString();
	testGetRep();
	testSetValue();
}
