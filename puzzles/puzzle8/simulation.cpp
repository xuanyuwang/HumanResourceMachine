#include "../../simulator/simulator.h"
#include <random>

using namespace std;

void generator(InputBox* ib){
    random_device rd;
	for(int i = 0; i < 8; i++){
		ib->append(new Node(rd() % 20 - 10));
	}
}

int main(){
	Human*h = new Human();
	InputBox* ib = new InputBox();
	OutputBox* ob = new OutputBox();
	Carpets* c = new Carpets(3);

	generator(ib);
	int* input = new int[8];
	for(int i = 0; i < 8; i++){
		input[i] = *(ib->at(i)->getInt());
	}
	
	//**************************
	do{
		h->inbox(ib);
		h->copyto(c, 0);
		h->add(c, 0);
		h->add(c, 0);
		h->outbox(ob);
	}while(!ib->empty());

	for(int i = 0; i < 8; i++){
		int result = *(ob->at(i)->getInt());
		int src = input[i];
		xassert( result == src * 3, "Pos " + to_string(i) + " : expected " + to_string(result) + " == 3 * " + to_string(src) + "\n");
	}
}
