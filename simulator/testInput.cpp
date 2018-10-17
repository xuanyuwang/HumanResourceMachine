#include <iostream>
#include "simulator.h"

using namespace std;

// Todo
void testTheStackHadBeenInitialized(Input input){
}

void testInputSet(Input input){
	input.set(3);
	input.set(4);
	input.set(5);
	input.display();
}

void testOutputSet(Output output){
	output.receive(3);
	output.receive(4);
	output.receive(5);
	output.display();
}

int main(){
	Input input;
	Output output;
	testInputSet(input);
	testOutputSet(output);
}
