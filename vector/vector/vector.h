#ifndef VECTOR_H_INCLUDED
#define VECTOR_H_INCLUDED
#include <iostream>
using namespace std;

typedef uint64_t sizeT;
typedef double eleT;
class Vector {

private:
    sizeT dimen;
    eleT *data;

public:
    //Creating a new vector with default 1 dimension if none is specified;
    Vector(sizeT dimen = (sizeT)1);

    sizeT getDimentions(){return dimen;}

    friend ostream &operator<<(ostream &os, const Vector &vect);

     ~Vector() {
		delete[] data;
	}
};



#endif // VECTOR_H_INCLUDED
