//
// Created by Ismail Magdy on 17/08/2022.
//

#include "Array.h"
using namespace std;

// Default Constructor
Array::Array(int size):size{size} {
    if(size>0)
        ptr = new int [size];
}



// Copy Constructor
Array::Array(const Array& other) {
    this->size=other.size;
    ptr = new int[size];
    for (int i = 0; i < size; ++i) {
        ptr[i]=other.ptr[i];
    }
}

// Destructor
Array::~Array() {
    delete[] ptr;
}


// Indexing [] as a Lvalue
int &Array::operator[](int position) {
    if(position>=size||position<0) // invalid Subscript (out of range)
        throw out_of_range {"Subscript out of Range\n"};
    return ptr[position];
}


// Indexing [] as a Const R value

int Array::operator[](int position) const {
    if(position>=size||position<0) // invalid Subscript (out of range)
        throw out_of_range {"Subscript out of Range\n"};
    return ptr[position];
}


// Assignment
const Array& Array::operator=(const Array &other){
    if(&other== this)// to avoid self assignment
        return *this;
    delete[]ptr;
    this->size = other.size;  // resize object to be of same size as right operand
    ptr = new int[size];
    for (int i = 0; i <size; ++i) {
        ptr[i]=other.ptr[i];
    }
    return *this;
}



// Equality
bool Array::operator==(const Array &other)const {
    if(other.size!=this->size)
        return false;
    for (int i = 0; i <size; ++i) {
        if(this->ptr[i]!=other.ptr[i])
            return false;
    }
    return true;
}

// Not equality
bool Array::operator!=(const Array &other) const{
    return !(*this==other);
}



// Relational
bool Array::operator>(const Array &other)const {
    if(other.size>this->size)
        return false;
    if(other.size< this->size)
        return true;
    for (int i = 0; i <size; ++i) {
        if(this->ptr[i]>other.ptr[i])
            return true;
        else if(this->ptr[i]<other.ptr[i])
            return false;
    }
    return false;
}


// Output
ostream& operator<<(ostream& out ,const Array& arr){
    for (int i = 0; i <arr.size; ++i) {
        out<<arr.ptr[i]<<" ";
    }
    return out ;
}


// input
istream & operator>>(istream& in ,Array&arr){
    for (int i = 0; i <arr.size; ++i) {
        in>>arr.ptr[i];
    }
    return in;
}
