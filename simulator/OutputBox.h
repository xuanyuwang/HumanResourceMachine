#ifndef OUTPUTBOX_H
#define OUTPUTBOX_H
#include "./Box.h"

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
#endif
