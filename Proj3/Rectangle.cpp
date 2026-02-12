#include <iostream>
#include "Rectangle.h"

//defualt constructor
Rectangle::Rectangle() : startCol(0), startRow(0), width(0), height(0){}

//parameterized constructor
Rectangle::Rectangle(int x, int y, int w, int h) : startCol(x), startRow(y), width(w), height(h) {}

int Rectangle::getStartRow() const {
    return startRow;
}

int Rectangle::getStartCol() const {
    return startCol;
}   

int Rectangle::getWidth() const {
    return width;
}

int Rectangle::getHeight() const {
    return height;
}

void Rectangle::setStartCol(int x) {
    startCol = x;
}

void Rectangle::setStartRow(int y) {
    startRow = y;
}


void Rectangle::setWidth(int w) {
    width = w;
}

void Rectangle::setHeight(int h) {
    height = h;
}

//operator overloads
ostream& operator<<(ostream& os, const Rectangle& r){
    os << "Row: " << r.getStartRow() << " Col: " << r.getStartCol() << " |  Height: " << r.getHeight() << " Width: " << r.getWidth() << endl;
    return os;
}

bool Rectangle::operator==(const Rectangle& rhs) const{
    return (startRow == rhs.getStartRow() && startCol == rhs.getStartCol() && height == rhs.getHeight() && width == rhs.getWidth());
}

bool Rectangle::operator!=(const Rectangle& rhs) const{
    return !(*this == rhs);
}



