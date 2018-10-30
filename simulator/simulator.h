#ifndef SIMULATOR_H
#define SIMULATOR_H
#include <iostream>
#include <list>
#include <cstdlib>
#include <string>

using namespace std;

class OutputBox: public Box{
	public:
		void receive(Node element){
			this->push(element);
		}
		void receive(Node* element){
			this->push(element);
		}
		void display(){
			this->reverse();
			cout << this->toString();
		}
};

class Carpets: public Box{
	public:
		Node* at(int position){
			std::list<Node>::iterator it;
			int counter = 0;
			for(it = this->elements.begin(); it != this->elements.end(); it++){
				if(counter < position){
					counter++;
				}else{
					return &(*it);
				}
			}
		}
};

class Human{
	private:
		Node inHand;
		bool isHaving;
		void grab(Node element){
			this->inHand = element;
			this->isHaving = true;
		}
	public:
		void copyfrom(Carpets* carpets, int pos){
			this->grab(carpets->at(pos));
		}

		void copyto(Carpets* carpets, int pos){
			Node* target = carpets->at(pos);
			target->setValue(this->inHand);
		}

		void inbox(InputBox* ib){
			this->inHand = ib->provide();
			this->isHaving = true;
		}

		void outbox(OutputBox* ob){
			if(this->isHaving){
				ob->receive(this->inHand);
				this->isHaving = false;
			}
		}

		Node getInHand(){
			if(this->isHaving){
				return this->inHand;
			}else{
			}
		}
};

Box* makeCarpets(int quantity){
	Box* carpets = new Box(quantity);
	return carpets;
}

#endif
