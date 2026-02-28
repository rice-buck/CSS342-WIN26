/*
 * File: Rectangle.cpp
 * Purpose: Implementation of the Rectangle class used to manage image sub-regions for "book keeping"
 * Functionality: Stores boundaries (start column, start row, width, height) of a region.
 * Assumptions: Coordinates and dimensions are non-negative integers.
 * Author: Rhys Buckeye
 */
#include <iostream> 
#include <ostream>

using namespace std;

class Rectangle{
public:

// Purpose: Default constructor initializing all boundaries to zero.
// Pre-condition: None.
// Post-condition: A Rectangle object is created with all members set to 0.
Rectangle();

// Purpose: Parameterized constructor to define a specific region.
// Pre-condition: x, y, w, and h should be non-negative integers.
// Post-condition: A Rectangle object is created with the specified dimensions.
Rectangle(int x, int y, int w, int h);

// Purpose: Get the starting row (y-coordinate).
// Pre-condition: None.
// Post-condition: Returns the integer value of startRow.
int getStartRow() const;

// Purpose: Get the starting column (x-coordinate).
// Pre-condition: None.
// Post-condition: Returns the integer value of startCol.
int getStartCol() const;

// Purpose: Get the width of the rectangle.
// Pre-condition: None.
// Post-condition: Returns the integer width.
int getWidth() const;

// Purpose: Get the height of the rectangle.
// Pre-condition: None.
// Post-condition: Returns the integer height.
int getHeight() const;

// Purpose: Set the starting column.
// Pre-condition: x is a non-negative integer.
// Post-condition: startCol is updated to x.
void setStartCol(int x);

// Purpose: Set the starting row.
// Pre-condition: y is a non-negative integer.
// Post-condition: startRow is updated to y.
void setStartRow(int y);

// Purpose: Set the height.
// Pre-condition: h is a non-negative integer.
// Post-condition: height is updated to h.
void setWidth(int w);

// Purpose: Set the height.
// Pre-condition: h is a non-negative integer.
// Post-condition: height is updated to h.
void setHeight(int h);

// Purpose: Compares two rectangles for equality.
// Pre-condition: rhs is a valid Rectangle.
// Post-condition: Returns true if all members match, false otherwise.
bool operator==(const Rectangle& rhs) const;

// Purpose: Compares two rectangles for inequality.
// Pre-condition: rhs is a valid Rectangle.
// Post-condition: Returns true if any member differs, false otherwise.
bool operator!=(const Rectangle& rhs) const;
//member variables
private:
int startRow, startCol, width, height;
};

// Purpose: Outputs the rectangle boundaries in human-readable format.
// Pre-condition: os is a valid output stream, r is a valid Rectangle.
// Post-condition: Rectangle info is sent to the stream; returns the stream.
ostream& operator<<(ostream& os, const Rectangle& r);