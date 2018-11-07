#include <iostream>
#include <cstdlib>
#include "./Box.h"
#include "./xassert.h"

using namespace std;

void testInit(){
	Box* b = new Box(3);
	assert((*b)[0]->toString() == EMPTY_NODE);
	assert((*b)[1]->toString() == EMPTY_NODE);
	assert((*b)[2]->toString() == EMPTY_NODE);
	assert((*b)[0] != (*b)[1]);
	assert((*b)[0] != (*b)[2]);
	assert((*b)[1] != (*b)[2]);
}

void testEmpty(){
    Box* a = new Box();
    assert(a->empty());

    Box* b = new Box(2);
    assert(b->empty() == false);
}

void testAppend(){
	Node a(3);
	Node b("hi");
	Box* box = new Box();
	box->append(a);
	box->append(b);
	assert(*((*box)[0]->getInt()) == 3);
	assert(*((*box)[1]->getString()) == "hi");
}

void testFirst(){
	Box* b = new Box();
	b->append(new Node("hi"));
	assert((*b).first()->toString() == "hi");
}

void testRemoveFirst(){
	Box* b = new Box();
	b->append(new Node("hi"));
	b->append(new Node(3));
	assert((*b).first()->toString() == "hi");

	b->removeFirst();
	assert((*b).first()->toString() == "3");
}

void testToString(){
	Box* b = new Box();
	b->append(new Node("hi"));
	b->append(new Node(3));
	assert(b->toString() == "hi 3 \n");
	assert((*b)[0]->toString() == "hi");
	assert((*b)[1]->toString() == "3");
}

int main(){
    testInit();
	testEmpty();
	testAppend();
	testFirst();
	testRemoveFirst();
	testToString();
}
