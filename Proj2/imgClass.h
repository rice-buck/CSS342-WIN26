/*
Author: Rhys B
Header file for img class. Implements functions which unitilizes the image library, simpliying the user interface. 
*/

#include <iostream>
#include "ImageLib.h"
#include <ostream>
#include <string>
using namespace std;

//image class
class img {
public:

//constructor reads from a file using a filename and ReadGif()
img(string filename);

//constructor to create blank image
img(int rows, int cols);

//copy constructor 
img(const img& copy);

//destructor
~img();

//operator=
const img& operator=(const img &rhs);

//getRows()
int getRows();

//getCols()
int getCols();

//getPixel()
int getPixel(int row, int col, char color);

//setPixel()
void setPixel(int row, int col, int red, int green, int blue);

//output
void outputFile(string filename);

// ===== operator overloads ======

//operator==
bool operator==(const img& rhs) const;
//operator!=
bool operator!=(const img& rhs) const;
//operator>
bool operator<(const img& rhs) const;
//operator<
bool operator>(const img& rhs) const;
//operator<<
//Question: why do i have to use friend if its in the class??
friend ostream& operator<<(ostream& os, const img& i);

//mirror image -- pass img obj by value, which in turn makes a copy of the img, then return that copy
img mirrorImage(img i);

img mirrorImage2();

private:
image myImage;
};
//operator<<
//have to use friend or cant access private member vars, but have to use friend in class?? 
//friend ofstream& operator<<(ostream& os, const img& i);
//confused...
ostream& operator<<(ostream& os, const img& i);