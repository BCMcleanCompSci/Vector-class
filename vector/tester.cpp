#include "vector.h"

int main(){
    Vector v1;
    cout << "Hello, here is a default Vector called v1: " << v1 << endl;
    cout << "It only has one element. I will change it to 3.2. ";
    v1[0] = 3.2;
    cout << "Here it is again: " << v1 << endl;
    cout << "Please provide a vector, perferably a 3 dim vector: ";
    cin >> v1;
    cout << endl;
    cout << "This is now v1 :" << v1<<endl;
    cout << "I am going to copy your vector to v2. ";
    Vector v2(v1);
    cout << "ThESE ARE THE vectors: " << v1 << " " << v2;
    cout << endl;
    Vector v3 = move(v2);
    cout << "Now I will move v2 to v3." << endl;
    cout << "Here are the vectors: "<< v1 << " " << v2 << " " << v3 << endl;

    cout << "v1 + 42 = " << v1 + 42 << endl;
    cout << "v1 - 42 = " << v1 - 42 << endl;
    cout << "v1 * 42 = " << v1 * 42 << endl;
    cout << "v1 / 42 = " << v1 / 42 << endl;
    Vector v4(3);
    Vector v5;
    v4[0] = 2;
    v4[1] = 5;
    v4[1] = 7;

    if (v1.getDimensions()!=3){
        cout << "Please provide a 3-dimensional vector: ";
        cin >> v5;
        if (v5.getDimensions()!= 3){
            cout << "wrong dimensions";
            exit(1);
        }
    }
    else
        v5 = v1;


return 0;
}
