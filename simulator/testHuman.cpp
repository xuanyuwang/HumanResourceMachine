#include "./Human.h"
#include "./InputBox.h"
#include "./OutputBox.h"

using namespace std;

void testCopyfrom(){
	Carpets c;
	c.append(new Node("c"));
	c.append(new Node(1));

	Human h;
	h.copyfrom(&c, 0);
	assert(h.getInHand()->toString() == "c");
	assert(c[0]->toString() == "c");
	h.copyfrom(&c, 1);
	assert(h.getInHand()->toString() == "1");
	assert(c[1]->toString() == "1");
}

void testCopyTo(){
	Carpets c(3);
	c[0]->setValue(new Node(3));
	c[1]->setValue(new Node(2));

	Human h;
	InputBox ib;
	ib.append(new Node("hi"));

	h.inbox(&ib);
	h.copyto(&c, 0);

	assert(c[0]->toString() == "hi");
	assert(c[1]->toString() == "2");
}

void testInbox(){
	InputBox ib;
	ib.append(new Node(2));
	ib.append(new Node("hi"));

	Human h;

	h.inbox(&ib);
	assert(h.getInHand()->toString() == "2");

	assert(ib.first()->toString() == "hi");

	h.inbox(&ib);
	assert(h.getInHand()->toString() == "hi");
}

void testOutputBox(){
	InputBox ib;
	ib.append(new Node(2));
	ib.append(new Node("hi"));

	OutputBox ob;
	Human h;
	h.inbox(&ib);
	ob.receive(h.getInHand());
	h.inbox(&ib);
	ob.receive(h.getInHand());
	assert(ob.toString().compare("2 hi \n") == 0);
}

void testAdd(){
    InputBox ib;
    ib.append(new Node(3));

	auto * h = new Human();
	h->inbox(&ib);
	Carpets c;
	c.append(new Node(5));

	h->add(&c, 0);
	assert(h->getInHand()->toString() == "8");
	assert((c)[0]->toString() == "5");
}

int main(){
	testInbox();
	testOutputBox();
	testCopyfrom();
	testCopyTo();
	testAdd();
}
