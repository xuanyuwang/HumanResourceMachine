#ifndef SIMULATOR_H
#define SIMULATOR_H
#include <iostream>
#include <list>
#include <cstdlib>
#include <string>

using namespace std;

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
#endif
