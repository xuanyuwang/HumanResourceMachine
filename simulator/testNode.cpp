#include <cstdlib>
#include <string>
#include <iostream>
#include "./simulator.h"

using namespace std;
void testIntNode(){
	int i = 3;
	Node *n = new Node(i);
	assert(!n->getRep().compare(std::to_string(i)));
}
void testStringNode(){
	string s = "Test";
	Node *n = new Node(s);
	assert(!s.compare(n->getRep()));
}
 void testEmptyNode(){
	 Node* n = new Node();
	assert(!(n->getRep().compare("empty node")));
 }

int main(){
	testIntNode();
	testStringNode();
	testEmptyNode();
}
