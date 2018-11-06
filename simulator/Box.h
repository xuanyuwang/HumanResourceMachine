#ifndef BOX_H 
#define BOX_H
#include <iostream>
#include <list>
#include <cstdlib>
#include <string>
#include "Node.h"

using namespace std;

class Box{
	private:
		int length;
	public:
		std::list<Node> elements;

		Box(){
			this->length = 0;
		}

		Box(int numberOfNodes){
			for(int i = 0; i < numberOfNodes; i++){
				this->push(new Node());
			}
		}

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

		// Tell if the list is empty
		bool empty(){
			return this->elements.empty();
		}

		void push(Node element){
			this->elements.push_front(element);
			this->length++;
		}
		void push(Node* element){
			this->elements.push_front(*element);
			this->length++;
		}

		void pop(){
			this->elements.pop_front();
			this->length--;
		}

		Node* top(){
			return &(this->elements.front());
		}

		void reverse(){
			this->elements.reverse();
		}

		string toString(){
			string rep = "";
			for(auto it = this->elements.begin(); it != this->elements.end(); it++){
				rep += (it->getRep() + " ");
			}
			rep += "\n";
			return rep;
		}

		void display(){
			cout << this->toString();
		}

		int getLength(){
			return this->length;
		}
};

#endif
