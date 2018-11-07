#ifndef CARPETS_H
#define CARPETS_H
#include "./Box.h"

using namespace std;

class Carpets: public Box{
public:
    Carpets():Box(){

    }

    explicit Carpets(int n): Box(n){

    }
};
#endif
