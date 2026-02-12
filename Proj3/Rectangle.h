#include <iostream> 
#include <ostream>

using namespace std;

class Rectangle{
public:

//defualt constructor 
Rectangle();

//paramterized constructor 
Rectangle(int x, int y, int w, int h);

//getters and setters for member variables
int getStartRow() const;

int getStartCol() const;

int getWidth() const;

int getHeight() const;

void setStartCol(int x);

void setStartRow(int y);

void setWidth(int w);

void setHeight(int h);

//operator overloads
bool operator==(const Rectangle& rhs) const;

bool operator!=(const Rectangle& rhs) const;
//member variables
private:
int startRow, startCol, width, height;
};

//operator<<
ostream& operator<<(ostream& os, const Rectangle& r);