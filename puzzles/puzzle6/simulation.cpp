#include "../../simulator/simulator.h"
#include "../../simulator/xassert.h"
#include <cstdlib>
#include <random>

using namespace std;

void generator(InputBox* ib){
    random_device rd;
	for(int i = 0; i < 8; i++){
		ib->append(new Node(rd() % 20 - 10));
	}
}

int main(){
	Human* h = new Human();
	Carpets* c = new Carpets(3);
	InputBox* ib = new InputBox();
	OutputBox* ob = new OutputBox();

	generator(ib);
	int* input = new int[8];
	for(int i = 0; i < 8; i++){
		input[i] = *(ib->at(i)->getInt());
	}
des:
	h->inbox(ib);
	h->copyto(c, 0);
	h->inbox(ib);
	h->add(c, 0);
	h->outbox(ob);
	if(!ib->empty()) goto des;

	for(int i = 0; i < 4; i++){
		int result = *(ob->at(i)->getInt());
		int add1 = input[i * 2];
		int add2 = input[i * 2 + 1];
		xassert(result == add1 + add2,
				"wrong result of pos " + std::to_string(i) + "expected " + to_string(result) + " added from " + to_string(add1)
				   + " and " + to_string(add2));
	}
}
