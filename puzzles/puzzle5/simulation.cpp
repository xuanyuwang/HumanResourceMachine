#include "../../simulator/simulator.h"
#include <cstdlib>

using namespace std;

void generator(InputBox* ib){
	srand(10);
	for(int i = 0; i < 8; i++){
		ib->push(new Node(rand() % 20 - 10));
	}
}

int main(){
	Human* h;
	Carpets* c = new Carpets(3);
	InputBox* ib = new InputBox();
	OutputBox* ob = new OutputBox();

	generator(ib);
	string input = ib->toString();
	cout << input << endl;
des:
	h->inbox(ib);
	h->copyto(c, 0);
	h->inbox(ib);
	h->add(c, 0);
	h->outbox(ob);
	if(!ib->empty()) goto des;

	string ouput = ob->toString();
	cout << ouput << endl;

	for(int i = 0; i < 4; i++){
	}
}
