#include "./Human.h"
#include "./xassert.h"

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

int main(){
	testCopyfrom();
	testCopyTo();
}
