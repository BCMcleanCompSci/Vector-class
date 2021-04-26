#include <iostream>
#include "vector.h"
using namespace std;




Vector::Vector(sizeT dimen): dimen(dimen), data( new eleT[dimen] ){
    for (sizeT ind = 0; ind < dimen; ind++){
        data[ind] =0;
    }
}

ostream &operator<<(ostream &os, const Vector &vect){
    os << '{'<< vect.data[0];
    for (sizeT ind = 1;ind < vect.dimen; ind++){
        os << ',' << vect.data[ind];
    }
    os << '}';
    return os;
}

int main(){
    Vector vect(5);
    sizeT dims = vect.getDimentions();
    cout << vect;
    cout << dims;
    delete &vect;

    return 0;
}


