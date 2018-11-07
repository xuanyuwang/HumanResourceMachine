#include <iostream>
#include "./Carpets.h"

using namespace std;

void testInit(){
	Carpets c(1);
	assert(c.toString() == "empty node \n");
}

int main(){
	testInit();
}
