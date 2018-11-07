#include <cstdlib>
#include <string>
#include <iostream>
#include "Node.h"
#include "xassert.h"

using namespace std;


void testInit(){
	Node n;
	assert(n.getInt() == nullptr);
	assert(n.getString() == nullptr);
}

void testInitAsInt(){
	Node n(3);
	assert(*(n.getInt()) == 3);
}

void testInitAsString(){
	string s = "hello";
	Node n(s);
	assert((*(n.getString())) == "hello");
}

void testToString(){
	Node a;
	Node b(3);
	Node c("hello");

	assert(a.toString() == "empty node");
	assert(b.toString() == "3");
	assert(c.toString() == "hello");
}

void testAdd(){
	Node* a = new Node(3);
	Node* b = new Node(4);
	a->add(b);
	assert(a->toString() == "7");
	assert(b->toString() == "4");
}

void testSetValue(){
	Node a(1);
	Node* b = new Node(3);
	Node c("hi");

	a.setValue(b);
	assert(a.toString() == "3");
	assert(b->toString() == "3");
	a.destroy();
	assert(b->toString() == "3");

	a.setValue(&c);
	assert(a.toString() == "hi");
	assert(c.toString() == "hi");
	a.destroy();
	assert(c.toString() == "hi");
}

int main(){
	testInit();
	testInitAsInt();
	testInitAsString();
	testToString();
	testSetValue();
	testAdd();
}
