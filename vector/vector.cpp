#include "vector.h"
using namespace std;

//move constructor
Vector::Vector(Vector &&old){
    this->dimen = old.dimen;
    this->data = new eleT[old.dimen];
    for (sizeT i=0; i<old.dimen; ++i){
    this->data[i]=old.data[i];
    }
    old.reset();
}
//copy constructor
Vector::Vector(const Vector &rhVector){
    this->dimen = rhVector.dimen;
    this->data = new eleT[this->dimen];
    for (sizeT i=0; i<rhVector.dimen; ++i){
        this->data[i]=rhVector.data[i];
    }
}
//Creates a new vector with default 1 dimension if none is specified;
Vector::Vector(sizeT dimen): dimen(dimen), data( new eleT[dimen] ){
    for (sizeT ind = 0; ind < dimen; ++ind)
        data[ind] =0;
}
//mutator funtion will reset all values to 0
void Vector::reset(){
    for (sizeT i = 0; i < this->dimen; ++i)
        this->data[i] = 0;
}
//creates a deep copy of a vector
Vector &Vector::operator= (const Vector &rhVector){
    this->data = new eleT[dimen];
    this->dimen = rhVector.dimen;
    for (sizeT i=0; i<rhVector.dimen; ++i){
        this->data[i]=rhVector.data[i];
    }
}

//prints the contents of a vector in a friendly format
ostream &operator<<(ostream &os, const Vector &vect){
    os << '{'<< vect.data[0];
    for (sizeT ind = 1;ind < vect.dimen; ++ind)
        os << ',' << vect.data[ind];
    os << '}';
    return os;
}

//takes input from the user to assign dimension and values to a vector
istream &operator>>(istream &is, Vector &newVect){
    char c;
	is >> c;
	if (c != '{')
        exit(1);
    vector<eleT> vect;
    eleT newEle;
    is >> newEle;
    vect.push_back(newEle);
    is >> c;
    while (c!='}'){
        is >> newEle;
        vect.push_back(newEle);
        is >> c;
    }
    newVect.dimen = vect.size();
    for (sizeT i = 0; i < newVect.dimen; ++i)
        newVect.data[i] = vect[i];
    return is;
}

//adds two vectors together and returns the result.
Vector Vector::operator+ (const Vector &rhVect)const {
    if (this->dimen!=rhVect.dimen)
        exit(-10);
    Vector sumVect(rhVect.dimen);
    for (sizeT i=0; i<rhVect.dimen; ++i)
        sumVect.data[i]=this->data[i]+rhVect.data[i];
    return sumVect;
}

//adds each element of a vector to a scalar and returns the result
Vector Vector::operator+ (const eleT  &scalar)const {
    Vector newVect(this->dimen);
    for (sizeT i=0; i<this->dimen; ++i)
        newVect.data[i]=this->data[i]+scalar;
    return newVect;
}

//subtracts two vectors and returns the result.
Vector Vector::operator- (const Vector &rhVect)const{
    if (this->dimen!=rhVect.dimen){
        exit(-10);
    }
    Vector difVect(rhVect.dimen);
    for (sizeT i=0; i<rhVect.dimen; ++i)
        difVect.data[i]=this->data[i]-rhVect.data[i];
    return difVect;
}

//subracts a scalar from each element of a vector returns the result
Vector Vector::operator- (const eleT &scalar)const{
    Vector newVect(this->dimen);
    for (sizeT i=0; i<this->dimen; ++i)
        newVect.data[i]=this->data[i]-scalar;
    return newVect;
}

//multiplies each element of a vector by a scalar and returns the result
Vector Vector::operator* (const eleT &scalar)const{
    Vector newVect(this->dimen);
    for (sizeT i=0; i<this->dimen; ++i)
        newVect.data[i]=this->data[i]*scalar;
    return newVect;
}

//divides each element of a vector by a scalar and returns the result
Vector Vector::operator/ (const eleT &scalar)const{
    Vector newVect(this->dimen);
    for (sizeT i=0; i<this->dimen; ++i)
        newVect.data[i]=this->data[i]/scalar;
    return newVect;
}

//returns the dot product of two vectors
double Vector::operator* (const Vector &rhVect)const{
    if (this->dimen!=rhVect.dimen)
        exit(-10);
    double dotProd;
    for (sizeT i=0; i<this->dimen; ++i)
        dotProd+=this->data[i]*rhVect.data[i];
    return dotProd;
}

//returns the cross product of two 3-dim vectors only.
Vector Vector::operator/ (const Vector &rhVect)const{
    if(this->dimen!=3||rhVect.dimen!=3)
        exit(1);
    Vector newVect(3);
    for (sizeT i=0; i<3; ++i)
        newVect[i]=this->data[(i+1)%3]*rhVect.data[(i+2)%3]-
                    this->data[(i+2)%3]*rhVect.data[(i+1)%3];
    return newVect;
}


