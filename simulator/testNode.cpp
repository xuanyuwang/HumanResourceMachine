#include <cstdlib>
#include <string>
#include <iostream>
#include "Node.h"
#include "xassert.h"

using namespace std;


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

void testAdd(){
	Node* a = new Node(3);
	Node* b = new Node(4);
	a->add(b);
	assert(a->getRep().compare("7") == 0);
}

void testSetValue(){
	Node a(1);
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
	//testAdd();
}
