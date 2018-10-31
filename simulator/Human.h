#ifndef HUMAN_H
#define HUMAN_H
#include "./Node.h"
#include "./Carpets.h"
#include "./InputBox.h"
#include "./OutputBox.h"

using namespace std;

class Human{
	private:
		Node* inHand;
		bool isHaving;
	public:
		void grab(Node* element){
			this->inHand = element;
			this->isHaving = true;
		}

		void copyfrom(Carpets* carpets, int pos){
			this->grab(carpets->at(pos));
		}

		void copyto(Carpets* carpets, int pos){
			Node* target = carpets->at(pos);
			target->setValue(this->inHand);
		}

		void inbox(InputBox* ib){
			this->grab(ib->provide());
		}

		void outbox(OutputBox* ob){
			if(this->isHaving){
				ob->receive(this->inHand);
				this->isHaving = false;
			}
		}

		Node* getInHand(){
			if(this->isHaving){
				return this->inHand;
			}else{
			}
		}
};
#endif
