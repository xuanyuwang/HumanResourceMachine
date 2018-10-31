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
		string toString(){
			this->reverse();
			string rep = "";
			for(std::list<Node>::iterator it = this->elements.begin(); it != this->elements.end(); it++){
				rep += (it->getRep() + " ");
			}
			rep += "\n";
			this->reverse();
			return rep;
		}
		void display(){
			cout << this->toString();
		}
};
#endif
