//
// Created by Ismail Magdy on 17/08/2022.
//

#ifndef ARRAY_ARRAY_H
#define ARRAY_ARRAY_H

#include <iostream>

class Array {
    friend std::ostream& operator<<(std::ostream& ,const Array&);
    friend std::istream& operator>>(std::istream& ,Array&);
public:
    Array(size_t size = 10 );
    Array(const Array& );
    Array(std::initializer_list<int>);
    ~Array();
    size_t getSize()const{return size;}
    int& operator[](int);
    int operator[](int)const;
    const Array& operator=(const Array& other);
    bool  operator==(const Array& other)const;
    bool  operator!=(const Array& other)const;
    bool  operator>(const Array& other)const;
private:
    size_t size;
    int* ptr;
};


#endif //ARRAY_ARRAY_H
