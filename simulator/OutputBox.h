#ifndef OUTPUTBOX_H
#define OUTPUTBOX_H
#include "./Box.h"

using namespace std;

class OutputBox: public Box{
	public:
		void receive(Node element){
			Node n;
			n.setValue(&element);
			this->append(n);
		}
		void receive(Node* element){
			Node n;
			n.setValue(element);
			this->append(n);
		}
};
#endif
