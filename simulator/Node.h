#include <utility>

#ifndef NODE_H
#define NODE_H 
#include <iostream>
#include <list>
#include <cstdlib>
#include <string>

#define EMPTY_NODE "empty node"

using namespace std;

class Node{
	private:
    	int* intValue;
    	string* stringValue;
	public:
		Node(){
			this->intValue = nullptr;
			this->stringValue = nullptr;
		}

	explicit Node(int i);

	explicit Node(string s);

		string toString(){
			if(this->stringValue == nullptr && this->intValue != nullptr){
				return std::to_string(*(this->intValue));
			}else if(this->intValue == nullptr && this->stringValue != nullptr){
				return *(this->stringValue);
			}else{
				return string(EMPTY_NODE);
			}
		}

		void setValue(Node* src){
			this->destroy();
			if(src->getInt() != nullptr){
			 	this->intValue = new int(*(src->getInt()));
			}else if(src->getString() != nullptr){
			 	this->stringValue = new string(*(src->getString()));
			}
		}

		void add(Node* n){
			int value = *(n->getInt());
			*(this->intValue) += value;
		}

		int* getInt(){
			return this->intValue;
		}

		string* getString(){
			return this->stringValue;
		}

		void destroy(){
			delete this->intValue;
			delete this->stringValue;
			this->intValue = nullptr;
			this->stringValue = nullptr;
		}
};

Node::Node(int i) {
	this->intValue = new int(i);
	this->stringValue = nullptr;
}

Node::Node(string s) {
	this->stringValue = new string(s);
	this->intValue = nullptr;
}

#endif
