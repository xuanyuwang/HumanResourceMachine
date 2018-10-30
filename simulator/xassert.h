#ifndef XASSERT_H
#define XASSERT_H

void xassert(bool b, string msg){
	if(b){// Success
		assert(1);
	}else{// Failure
		cout << msg << endl;
		assert(0);
	}
}
void xassert(bool b){
	if(b){// Success
		assert(1);
	}else{// Failure
		assert(0);
	}
}

#endif
