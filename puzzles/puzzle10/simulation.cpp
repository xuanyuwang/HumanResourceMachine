#include "../../simulator/simulator.h"

using namespace std;

void generator(InputBox* ib){
    srand(8);
    for(int i = 0; i < 8; i++){
        ib->push(new Node(rand() % 20 - 10));
    }
}

int main(){
    Human* h = new Human();
    InputBox* ib = new InputBox();
    OutputBox* ob = new OutputBox();
    Carpets* c = new Carpets(3);

    generator(ib);
    ib->display();
    int* input = new int[8];
    for(int i = 0; i < 8; i++){
        input[i] = *(ib->at(0)->getInt());
    }

    do{
        h->inbox(ib);
        h->copyto(c, 0);
        h->add(c, 0);
        c->display();

        h->copyto(c, 0);
        h->add(c, 0);

        h->copyto(c, 0);
        h->add(c, 0);

        h->outbox(ob);
    }while(!ib->empty());

    ob->reverse();
    ob->display();

}
