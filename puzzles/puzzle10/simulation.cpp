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
    Human* h = new Human();
    InputBox* ib = new InputBox();
    OutputBox* ob = new OutputBox();
    Carpets* c = new Carpets(3);

    generator(ib);
    int* input = new int[8];
    for(int i = 0; i < 8; i++){
        input[i] = *((*ib)[i]->getInt());
    }

    do{
        h->inbox(ib);
        h->copyto(c, 0);
        h->add(c, 0);

        h->copyto(c, 0);
        h->add(c, 0);

        h->copyto(c, 0);
        h->add(c, 0);

        h->outbox(ob);
    }while(!ib->empty());

    for(int i = 0; i < 8; i++){
        int out = *((*ob)[i]->getInt());
        int in = input[i];
        assert(out == in * 8);
    }
}
