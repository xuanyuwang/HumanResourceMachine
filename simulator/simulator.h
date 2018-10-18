#ifndef SIMULATOR_H
#define SIMULATOR_H
#include <iostream>
#include <list>
#include <cstdlib>
#include <string>

#define STRING_TYPE "string"
#define INT_TYPE "int"

using namespace std;

class Node{
	private:
		// Store the values of different types into different pointers
		int* intValue;
		string* stringValue;
	public:
		Node* before;
		Node* after;
		Node(){
			this->intValue = NULL;
			this->stringValue = NULL;
			this->before = NULL;
			this->after = NULL;
		}
		Node(int i){
			this->intValue = new int(i);
			this->stringValue = NULL;
			this->before = NULL;
			this->after = NULL;
		}

		Node(string s){
			this->stringValue = new string(s);
			this->intValue = NULL;
			this->before = NULL;
			this->after = NULL;
		}

		string getRep(){
			if(this->stringValue == NULL){
					return std::to_string(*(this->intValue));
			}else if(this->intValue == NULL){
				return *(this->stringValue);
			}
		}

		void destroy(){
			this->before = NULL;
			this->after = NULL;
			delete this->intValue;
			delete this->stringValue;
		}
};

class Box{
	private:
	public:
		std::list<Node> elements;
		bool empty(){
			return this->elements.empty();
		}

		void push(Node element){
			this->elements.push_front(element);
		}
		void push(Node* element){
			this->elements.push_front(*element);
		}

		void pop(){
			this->elements.pop_front();
		}

		Node top(){
			return this->elements.front();
		}

		void reverse(){
			this->elements.reverse();
		}

		string toString(){
			string rep = "";
			for(std::list<Node>::iterator it = this->elements.begin(); it != this->elements.end(); it++){
				rep += (it->getRep() + " ");
			}
			rep += "\n";
			return rep;
		}

		void display(){
			cout << this->toString();
		}
};

class InputBox: public Box{
	public:
		Node provide(){
			Node result = this->top();
			this->pop();
			return result;
		}
};

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


class Human{
	private:
		Node inHand;
		bool isHaving;
		void grab(Node element){
			this->inHand = element;
			this->isHaving = true;
		}
	public:
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
