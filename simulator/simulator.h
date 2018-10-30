#ifndef SIMULATOR_H
#define SIMULATOR_H
#include <iostream>
#include <list>
#include <cstdlib>
#include <string>

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

		int getLength(){
			return this->length;
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

class Human{
	private:
		Node inHand;
		bool isHaving;
		void grab(Node element){
			this->inHand = element;
			this->isHaving = true;
		}
	public:
		void copyfrom(Carpets* carpets, int pos){
			this->grab(carpets->at(pos));
		}

		void copyto(Carpets* carpets, int pos){
			Node* target = carpets->at(pos);
			target->setValue(this->inHand);
		}

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

Box* makeCarpets(int quantity){
	Box* carpets = new Box(quantity);
	return carpets;
}

#endif
