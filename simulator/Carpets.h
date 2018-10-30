#ifndef CARPETS_H
#define CARPETS_H
#include "./Box.h"

using namespace std;

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
#endif
