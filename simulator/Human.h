#ifndef HUMAN_H
#define HUMAN_H
#include "./Node.h"
#include "./Carpets.h"
#include "./InputBox.h"
#include "./OutputBox.h"

using namespace std;

class Human{
	private:
		/*
		Life cycle of inHand:
			- Initialization: NULL
			- Grab from inbox: not NULL
			- outbox: set back to NULL
			- Copyfrom: create a new Node by Human it self
			- Copyto: do not set to NULL after doing this
		*/
		Node* inHand;
	public:
		Human(){
			this->inHand = NULL;
		}

		void grab(Node* element){
			this->inHand = element;
		}

		void copyfrom(Carpets* carpets, int pos){
			if(this->inHand != NULL){
				delete this->inHand;
			}
			Node* src = carpets->at(pos);
			this->inHand = new Node();
			this->inHand->setValue(src);
		}

		void copyto(Carpets* carpets, int pos){
			Node* target = carpets->at(pos);
			target->setValue(this->getInHand());
		}

		void inbox(InputBox* ib){
			this->grab(ib->provide());
		}

		void outbox(OutputBox* ob){
			if(this->inHand != NULL){
				ob->receive(this->inHand);
				this->inHand = NULL;
			}
		}

		Node* getInHand(){
			if(this->inHand != NULL){
				return this->inHand;
			}else{
			}
		}
};
#endif
