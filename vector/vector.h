#ifndef VECTOR_H
#define VECTOR_H
#include <iostream>
#include <vector>
using namespace std;

typedef unsigned int sizeT;
typedef double eleT;
class Vector {

private:
    sizeT dimen;
    eleT *data;

public:
    //Creates a new vector with default 1 dimension if none is specified;
    explicit Vector(sizeT dimen = (sizeT)1);

    //Copy constructor;
    Vector(const Vector &old);

    //Move constructor
    Vector(Vector &&old);


    //mutator funtion will reset all values to 0
    void reset();
    //accessor function will return the size of the vector
    sizeT getDimensions(){return dimen;}
    //creates a deep copy of a vector
    Vector &operator= (Vector const &rhVector);

    //prints the contents of a vector in a friendly format
    friend ostream &operator<<(ostream &os, const Vector &vect);
    //takes input from the user to assign dimension and values to a vector
    friend istream &operator>>(istream &is, Vector &newVect);

    //operator which allows direct access to the data in a vector and gives the ability to change it.
    eleT &operator[] (sizeT ind){return this->data[ind];}
    //operator which allows direct access to the data in a vector without allowing changes.
    const eleT &operator[] (sizeT ind) const {return this->data[ind];}

    /* The next group of operator overloads are binary for the
    mathematical operations on a vector*/

    //adds two vectors together and returns the result.
    Vector operator+ (Vector const &rhVect)const;
    //adds each element of a vector to a scalar and returns the result
    Vector operator+ (eleT const &scalar)const;
    //subtracts two vectors and returns the result.
    Vector operator- (Vector const &rhVect)const;
    //subracts a scalar from each element of a vector returns the result
    Vector operator- (eleT const &scalar)const;
    //multiplies each element of a vector by a scalar and returns the result
    Vector operator* (eleT const &scalar)const;
    //divides each element of a vector by a scalar and returns the result
    Vector operator/ (eleT const &scalar)const;
    //returns the dot product of two vectors
    double operator* (Vector const &rhVect)const;
    //returns the cross product of two 3-dim vectors only.
    Vector operator/ (Vector const &rhVect)const;


    ~Vector() {
		delete data;
	}
};



#endif
