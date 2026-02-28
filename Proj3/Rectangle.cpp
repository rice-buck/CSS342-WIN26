/*
 * File: Rectangle.cpp
 * Purpose: Implementation of the Rectangle class used to manage image sub-regions for "book keeping"
 * Functionality: Stores boundaries (start column, start row, width, height) of a region.
 * Assumptions: Coordinates and dimensions are non-negative integers.
 * Author: Rhys Buckeye
 */

#include <iostream>
#include "Rectangle.h"

using namespace std;

// Purpose: Default constructor initializing all boundaries to zero.
// Pre-condition: None.
// Post-condition: A Rectangle object is created with all members set to 0.
Rectangle::Rectangle() : startCol(0), startRow(0), width(0), height(0) {}

// Purpose: Parameterized constructor to define a specific region.
// Pre-condition: x, y, w, and h should be non-negative integers.
// Post-condition: A Rectangle object is created with the specified dimensions.
Rectangle::Rectangle(int x, int y, int w, int h) : startCol(x), startRow(y), width(w), height(h) {}

// Purpose: Get the starting row (y-coordinate).
// Pre-condition: None.
// Post-condition: Returns the integer value of startRow.
int Rectangle::getStartRow() const {
    return startRow;
}

// Purpose: Get the starting column (x-coordinate).
// Pre-condition: None.
// Post-condition: Returns the integer value of startCol.
int Rectangle::getStartCol() const {
    return startCol;
}   

// Purpose: Get the width of the rectangle.
// Pre-condition: None.
// Post-condition: Returns the integer width.
int Rectangle::getWidth() const {
    return width;
}

// Purpose: Get the height of the rectangle.
// Pre-condition: None.
// Post-condition: Returns the integer height.
int Rectangle::getHeight() const {
    return height;
}

// Purpose: Set the starting column.
// Pre-condition: x is a non-negative integer.
// Post-condition: startCol is updated to x.
void Rectangle::setStartCol(int x) {
    startCol = x;
}

// Purpose: Set the starting row.
// Pre-condition: y is a non-negative integer.
// Post-condition: startRow is updated to y.
void Rectangle::setStartRow(int y) {
    startRow = y;
}

// Purpose: Set the width.
// Pre-condition: w is a non-negative integer.
// Post-condition: width is updated to w.
void Rectangle::setWidth(int w) {
    width = w;
}

// Purpose: Set the height.
// Pre-condition: h is a non-negative integer.
// Post-condition: height is updated to h.
void Rectangle::setHeight(int h) {
    height = h;
}

// Purpose: Compares two rectangles for equality.
// Pre-condition: rhs is a valid Rectangle.
// Post-condition: Returns true if all members match, false otherwise.
bool Rectangle::operator==(const Rectangle& rhs) const {
    return (startRow == rhs.getStartRow() && startCol == rhs.getStartCol() && height == rhs.getHeight() && width == rhs.getWidth());
}

// Purpose: Compares two rectangles for inequality.
// Pre-condition: rhs is a valid Rectangle.
// Post-condition: Returns true if any member differs, false otherwise.
bool Rectangle::operator!=(const Rectangle& rhs) const {
    return !(*this == rhs);
}

// Purpose: Outputs the rectangle boundaries in human-readable format.
// Pre-condition: os is a valid output stream, r is a valid Rectangle.
// Post-condition: Rectangle info is sent to the stream; returns the stream.
ostream& operator<<(ostream& os, const Rectangle& r) {
    os << "Row: " << r.getStartRow() << " Col: " << r.getStartCol() << " | Height: " << r.getHeight() << " Width: " << r.getWidth() << endl;
    return os;
}