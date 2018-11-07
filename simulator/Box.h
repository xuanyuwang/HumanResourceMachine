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
		std::list<Node> elements;
	public:

		Box(){
		};

		Box(int numberOfNodes){
			Node emptyNode;
		    this->elements.assign(numberOfNodes, emptyNode);
		}

		Node* at(int position){
			auto it = this->elements.begin();
			int counter = 0;
			for(; it != this->elements.end(); it++){
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

		void append(Node element){
			this->elements.push_back(element);
		}
		void append(Node* element){
			this->elements.push_back(*element);
		}

		void removeFirst(){
			auto it = this->elements.begin();
			this->elements.erase(it);
		}

		Node* first(){
			return &(this->elements.front());
		}

		string toString(){
			string rep;
			for(auto it = this->elements.begin(); it != this->elements.end(); it++){
				rep += (it->toString() + " ");
			}
			rep += "\n";
			return rep;
		}

		void display(){
			cout << this->toString();
		}

		Node* operator[](int pos){
			return this->at(pos);
		}
};

#endif
