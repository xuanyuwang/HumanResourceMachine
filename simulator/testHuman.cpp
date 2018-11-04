#include "./Human.h"
#include "./xassert.h"
#include "./InputBox.h"
#include "./OutputBox.h"

using namespace std;

void testCopyfrom(){
	Carpets c;
	c.push(new Node("c"));
	c.push(new Node(1));

	Human h;
	h.copyfrom(&c, 0);
	assert(h.getInHand()->getRep().compare("1") == 0);
	h.copyfrom(&c, 1);
	assert(h.getInHand()->getRep().compare("c") == 0);
}

void testCopyTo(){
	Carpets c;
	c.push(new Node(3));
	Human h;

	h.grab(new Node(1));
	h.copyto(&c, 0);

	assert(c.at(0)->getRep().compare("1") == 0);
}

void testInbox(){
	InputBox ib;
	ib.push(new Node(2));
	ib.push(new Node(3));

	Human h;

	h.inbox(&ib);
	assert(h.getInHand()->getRep().compare("3") == 0);
}

void testOutputBox(){
	OutputBox ob;
	Human h;
	h.grab(new Node(3));
	ob.receive(h.getInHand());
	h.grab(new Node(2));
	ob.receive(h.getInHand());
	assert(ob.toString().compare("3 2 \n") == 0);
}

void testGetInhand(){
	Human h;
	h.grab(new Node(4));

	assert(h.getInHand()->getRep().compare("4") == 0);
}

void testAdd(){
	Human* h = new Human();
	h->grab(new Node(4));
	Carpets* c = new Carpets(1);
	c->at(0)->setValue(new Node(5));
	h->add(c, 0);
	assert(h->getInHand()->getRep().compare("9") == 0);
}

int main(){
	testCopyfrom();
	testCopyTo();
	testInbox();
	testOutputBox();
	testAdd();
}
