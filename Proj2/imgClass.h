/*
Author: Rhys B
Header file for img class.
This class uses the ImageLib library to provide a simplified interface for image manipulation.
*/

#include <iostream>
#include "ImageLib.h"
#include <ostream>
#include <string>
using namespace std;

//image class
//Description: This class holds an image and provides methods for image manipulation
class img {
public:

//constructor reads from a file using a filename and ReadGif()
//Precondition: none
//Postcondition: creates img object
img(string filename);

//constructor to create blank image
//Precondition: rows and cols are integers
//Postcondition: creates blank img object
img(int rows, int cols);

//copy constructor 
//Precondition: copy is a valid img object
//Postcondition: creates img object that is a copy of img passed in
img(const img& copy);

//destructor
//precondition: none
//postcondition: deallocates image memory
~img();

//precondition: filename is a valid string
//postcondition: writes the image to the specified file
void outputFile(string filename);



//===== getters and setters ======


//preconditon: none
//postcondition: returns number of rows
int getRows();

//precondition: none
//postcondition: returns number of columns
int getCols();

//precondition: row and col are valid pixel locations, color is 'r', 'g', or 'b'
//postcondition: returns the value of the specified color component at the given pixel
int getPixel(int row, int col, char color);

//setPixel: sets the pixel at (row, col) to the specified RGB values
//precondition: row and col are valid pixel locations, newRed, newGreen, newBlue are integers 0-255
//postcondition: sets the pixel at (row, col) to the specified RGB values
void setPixel(int row, int col, int red, int green, int blue);

//mirrorImage: creates and returns a mirror image of the img passed in
//precondition: i is a valid img object
//postcondition: returns a new img object that is the mirror image of i
img mirrorImage(img i);


// ===== operator overloads ======

//operator=
//precondition: rhs is a valid img object
//postcondition: assigns rhs img to this img
const img& operator=(const img &rhs);

//operator==
//precondition: rhs is a valid img object
//postcondition: returns true if the two images are identical, false otherwise
bool operator==(const img& rhs) const;

//operator!=
//precondition: rhs is a valid img object
//postcondition: returns true if the two images are different, false otherwise
bool operator!=(const img& rhs) const;

//operator>
//precondition: rhs is a valid img object
//postcondition: returns true if this img has more pixels than rhs, false otherwise
bool operator<(const img& rhs) const;

//operator<
//precondition: rhs is a valid img object
//postcondition: returns true if this img has less pixels than rhs, false otherwise
bool operator>(const img& rhs) const;

//operator<<
//precondition: os is a valid output stream, i is a valid img object
//postcondition: outputs the dimensions of the image to the output stream
friend ostream& operator<<(ostream& os, const img& i);


private:
//image data member
image myImage;
};

//operator<<
//precondition: os is a valid output stream, i is a valid img object
//postcondition: outputs the dimensions of the image to the output stream
//had to declare here for friend function
ostream& operator<<(ostream& os, const img& i);