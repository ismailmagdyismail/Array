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
    Array(int size = 10 );
    Array(const Array& );
    ~Array();
    int getSize()const{return size;}
    int& operator[](int);
    const Array& operator=(const Array& other);
    bool  operator==(const Array& other)const;
    bool  operator!=(const Array& other)const;
    bool  operator>(const Array& other)const;
private:
    int size;
    int* ptr;
};


#endif //ARRAY_ARRAY_H
