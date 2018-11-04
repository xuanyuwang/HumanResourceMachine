#include "../../simulator/simulator.h"

using namespace std;

void generator(InputBox* ib){
	for(int i = 0; i < 8; i++){
		ib->push(new Node(i));
	}
}

int main(){
	Human* h = new Human();
	InputBox* ib = new InputBox();
	OutputBox* ob = new OutputBox();
	Carpets* c = new Carpets(3);

	generator(ib);
	string input = ib->toString();

	//**************************
des:
	h->inbox(ib);
	h->copyto(c, 0);
	h->inbox(ib);
	h->outbox(ob);
	h->copyfrom(c, 0);
	h->outbox(ob);
	if(!ib->empty()) goto des;

	ob->display();
	string output = ob->toString();
	assert(output.compare("6 7 4 5 2 3 0 1 \n") == 0);
}
