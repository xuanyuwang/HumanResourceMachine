#include <iostream>
#include <cstdlib>
#include "./Box.h"
#include "./xassert.h"

using namespace std;

void testInit(){
	Box b;
	xassert(b.getLength() == 0);
}

void testEmpty(){
	Box *b1 = new Box();
	xassert(b1->empty() == true);

	Box *b2 = new Box();
	Node n(3);
	b2->push(n);
	xassert(b2->empty() == false);
}

void testPush(){
	Box b1;
	Node a(3);
	Node c("ok");
	b1.push(a);
	b1.push(new Node(4));
	b1.push(c);
	xassert(b1.toString().compare("ok 4 3 \n") == 0);
}

void testPop(){
	Box b;
	b.push(new Node(3));
	b.push(new Node(4));
	b.push(new Node("ok"));
	b.pop();
	b.pop();
	assert(b.toString().compare("3 \n") == 0);
}

void testTop(){
	Box b;
	b.push(new Node(3));
	b.push(new Node(4));
	b.push(new Node("ok"));
	assert(b.top()->getRep().compare("ok") == 0);
	b.pop();
	assert(b.top()->getRep().compare("4") == 0);
	b.pop();
	assert(b.top()->getRep().compare("3") == 0);
}

void testReverse(){
	Box b;
	b.push(new Node(3));
	b.push(new Node(4));
	b.push(new Node("ok"));
	b.reverse();
	assert(b.toString().compare("3 4 ok \n") == 0);
}

int main(){
	testEmpty();
	testPush();
	testPop();
	testTop();
	testReverse();
}
