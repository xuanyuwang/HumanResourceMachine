#include "../../simulator/simulator.h"
#include <random>

#define N_INPUT 10

using namespace std;

void generator(InputBox* ib){
	random_device rd;
	for(int i = 0; i < N_INPUT; i++){
		ib->append(new Node(rd() % 20 - 10));
	}
}

int main(){
	Human* h = new Human();
	InputBox* ib = new InputBox();
	OutputBox* ob = new OutputBox();
	Carpets* c = new Carpets(9);

	generator(ib);
	int* input = new int[N_INPUT];
	for(int i = 0; i < N_INPUT; i++){
		input[i] = *((*ib)[i]->getInt());
	}

	do{
		do{
			h->inbox(ib);
		}while(!ib->empty() && h->getInHand()->toString() == "0");
		h->outbox(ob);
	}while(!ib->empty());

	
}
