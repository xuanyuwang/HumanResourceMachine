#ifndef NODE_H
#define NODE_H 
#include <iostream>
#include <list>
#include <cstdlib>
#include <string>

using namespace std;

class Node{
	private:
	public:
		// Store the values of different types into different pointers
		int* intValue;
		string* stringValue;
		Node(){
			this->intValue = NULL;
			this->stringValue = NULL;
		}
		Node(int i){
			this->intValue = new int(i);
			this->stringValue = NULL;
		}

		Node(string s){
			this->stringValue = new string(s);
			this->intValue = NULL;
		}

		string getRep(){
			if(this->stringValue == NULL && this->intValue != NULL){
				return std::to_string(*(this->intValue));
			}else if(this->intValue == NULL && this->stringValue != NULL){
				return *(this->stringValue);
			}else{
				return string("empty node");
			}
		}

		void setValue(Node* src){
			if(src->intValue != NULL){
				this->destroy();
			 	this->intValue = new int(*(src->intValue));
			}else if(src->stringValue != NULL){
				this->destroy();
			 	this->stringValue = new string(*(src->stringValue));
			}
		}

		void destroy(){
			delete this->intValue;
			delete this->stringValue;
			this->intValue = NULL;
			this->stringValue = NULL;
		}
};

#endif
