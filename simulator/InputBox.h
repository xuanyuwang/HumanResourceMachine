#ifndef INPUTBOX_H
#define INPUTBOX_H
#include "./Box.h"

using namespace std;

class InputBox: public Box{
	public:
		Node* provide(){
			Node* result = this->top();
			this->pop();
			return result;
		}
};
#endif
