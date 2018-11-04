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
	public:
		Human(){
			this->inHand = NULL;
		}
		
		void grab(Node* element){
			this->inHand = element;
		}

		void copyfrom(Carpets* carpets, int pos){
			this->grab(carpets->at(pos));
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
