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
			this->destroy();
			if(src->intValue != NULL){
			 	this->intValue = new int(*(src->intValue));
			}else if(src->stringValue != NULL){
				string* a = new string(*(src->stringValue));
			 	this->stringValue = new string(*(src->stringValue));
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

		//TODO: fix this function. It will change the src's value
		void destroy(){
			if(this->intValue != NULL){
				//delete this->intValue;
			}
			if(this->stringValue != NULL){
				//delete this->stringValue;
			}
			this->intValue = NULL;
			this->stringValue = NULL;
		}
};

#endif
