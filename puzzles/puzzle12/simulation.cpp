#include "../../simulator/simulator.h"
#include <random>

using namespace std;

void generator(InputBox* ib){
	random_device rd;
	for(int i = 0; i < 4; i++){
		ib->append(new Node(rd() % 20 - 10));
	}
}

int main(){
	Human* h = new Human();
	InputBox* ib = new InputBox();
	OutputBox* ob = new OutputBox();
	Carpets* c = new Carpets(3);

	generator(ib);
	int* input = new int[4];
	for(int i = 0; i < 4; i++){
		input[i] = *((*ib)[i]->getInt());
	}

	//**************************
	do{
		h->inbox(ib);

		// double up
		h->copyto(c, 0);
		h->add(c, 0);//2x

		// double up
		h->copyto(c, 0);
		h->add(c, 0);//4x
		// double up
		h->copyto(c, 0);
		h->add(c, 0);//8x

		// double up
		h->copyto(c, 0);
		h->add(c, 0);//16x
		h->add(c, 0);//24x
		h->add(c, 0);//32x
		h->add(c, 0);//40x

		h->outbox(ob);
	}while(!ib->empty());

	for(int i = 0; i < 4; i++){
		int in = input[i];
		int out = *((*ob)[i]->getInt());
		assert(out == in * 40);
	}
}
