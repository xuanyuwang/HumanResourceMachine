#ifndef SIMULATOR_H
#define SIMULATOR_H
#include <iostream>
#include <stack>

using namespace std;

class Input{
	private:
		std::stack<int> input;
	public:
		int provide(){
			if(!this->input.empty()){
				int top = this->input.top();
				this->input.pop();
				return top;
			}else{
			}
		}

		void set(int element){
			this->input.push(element);
		}

		bool isEmpty(){
			return this->input.empty();
		}

		void display(){
			cout << "The Input:" << endl;
			std::stack<int> tmp;

			// Pop each element and store them in another stack
			while(!this->input.empty()){
				int element = this->input.top();
				this->input.pop();
				tmp.push(element);
				cout << element << " ";
			}

			// Put the elements back
			while(!tmp.empty()){
				this->input.push(tmp.top());
				tmp.pop();
			}

			cout << endl;
		}

};

class Output{
	private:
		std::stack<int> output;
	public:
		void receive(int element){
			this->output.push(element);
		}

		int get(){
			if(!this->output.empty()){
				int top = this->output.top();
				this->output.pop();
				return top;
			}else{
			}
		}


		void display(){
			cout << "The output:" << endl;
			std::stack<int> tmp;

			// Pop each element and store them in another stack
			while(!this->output.empty()){
				tmp.push(this->output.top());
				this->output.pop();
			}

			// Put the elements back
			while(!tmp.empty()){
				cout << tmp.top() << " ";
				this->output.push(tmp.top());
				tmp.pop();
			}

			cout << endl;
		}
};

class Human{
	private:
		int inHand;
		bool isHaving;
	public:
		void grab(int element){
			this->inHand = element;
			this->isHaving = true;
		}

		void inbox(Input* input){
			this->inHand = input->provide();
			this->isHaving = true;
		}

		void outbox(Output* output){
			if(this->isHaving){
				output->receive(this->inHand);
				this->isHaving = false;
			}
		}

		int getInHand(){
			if(this->isHaving){
				return this->inHand;
			}else{
			}
		}
};

#endif
