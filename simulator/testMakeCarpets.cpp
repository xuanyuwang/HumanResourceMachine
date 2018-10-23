#include <iostream>
#include <cstdlib>
#include "./simulator.h"

using namespace std;

void testMakeCarpets(){
	Node* c = makeCarpets(3);

	for(int i = 0; i < 3; i++){
		cout << c[0].getRep() << endl;
	}
	cout << c[3].getRep() << endl;
}

int main(){
	testMakeCarpets();
}
