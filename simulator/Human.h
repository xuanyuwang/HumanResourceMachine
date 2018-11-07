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
		Node* inHand = new Node();
		bool isHaving = false;
	public:
		Human() = default;

	void copyto(Carpets* carpets, int pos){
			Node* target = (*carpets)[pos];
			target->setValue(this->inHand);
		}

		void copyfrom(Carpets* carpets, int pos){
			Node* src = (*carpets)[pos];
			this->inHand->setValue(src);
			this->isHaving = true;
		}

		void add(Carpets* carpets, int pos){
			Node* operand = carpets->at(pos);
			this->inHand->add(operand);
		}

		void inbox(InputBox* ib){
			Node* first = ib->provide();
			this->inHand->setValue(first);
			this->isHaving = true;
		}

		void outbox(OutputBox* ob){
			if(this->isHaving){
				ob->receive(this->inHand);
				this->isHaving = false;
			}
		}

		Node* getInHand(){
			return this->inHand;
		}
};
#endif
