#include "ImageLib.h"
#include <stdexcept>
#include "img.h"

//constructor reads from a file using a filename and ReadGif()
//Precondition: none
//Postcondition: creates img object
img::img (string filename){
    myImage = ReadGIF(filename);
}


//constructor to create blank image
//Precondition: rows and cols are integers
//Postcondition: creates blank img object
img::img (int rows, int cols){
    //check for valid rows and cols
    if(rows <= 0 || cols <= 0){
        throw out_of_range("rows and cols must be positive integers at img constructor()");
    }
    //use CreateImage to create blank image
    myImage = CreateImage(rows, cols);
}

//copy constructor 
//Precondition: copy is a valid img object
//Postcondition: creates img object that is a copy of img passed in
img::img(const img& copy){
    //use CopyImage to copy the image
    myImage = CopyImage(copy.myImage);
}

//destructor
//precondition: none
//postcondition: deallocates image memory
img::~img(){
    //use DeallocateImage to free memory
    DeallocateImage(myImage);
}

//precondition: filename is a valid string
//postcondition: writes the image to the specified file
void img::outputFile(string filename){
    //use WriteGIF to write the image to file
    WriteGIF(filename, myImage);
}



//===== getters and setters ======


//preconditon: none
//postcondition: returns number of rows
int img::getRows() const{
    return myImage.rows;
}

//precondition: none
//postcondition: returns number of columns
int img::getCols() const{
    return myImage.cols;
}

//precondition: row and col are valid pixel locations, color is 'r', 'g', or 'b'
//postcondition: returns the value of the specified color component at the given pixel
int img::getPixel(int row, int col, char color) const{
    //check for valid pixel location
    if(row < 0 || row >= myImage.rows || col < 0 || col >= myImage.cols){
        throw out_of_range("Row or column is out of image bounds at getPixel()");
    }
   pixel p = myImage.pixels[row][col];
   //return the color component requested
    if(color == 'r'){
         return (int) p.red;
    }
    else if(color == 'g'){
         return (int) p.green;
    }
    else if(color == 'b'){
         return (int) p.blue;
    }
    else{
        throw invalid_argument("Invalid color component at getPixel()"); //invalid color 
   }
}

//setPixel: sets the pixel at (row, col) to the specified RGB values
//precondition: row and col are valid pixel locations, newRed, newGreen, newBlue are integers 0-255
//postcondition: sets the pixel at (row, col) to the specified RGB values
void img::setPixel(int row, int col, int newRed, int newGreen, int newBlue){
    //check for valid color values and pixel location
    if(newRed < 0 || newRed > 255 || newGreen < 0 || newGreen > 255 || newBlue < 0 || newBlue > 255){
        throw invalid_argument("Color values must be between 0 and 255 at setPixel()");
    }
    if(row < 0 || row >= myImage.rows || col < 0 || col >= myImage.cols){
        throw out_of_range("Row or column is out of image bounds at setPixel()");
    }
    //set the pixel values to the new values passed in
    pixel &p = myImage.pixels[row][col];
    p.red = (byte) newRed;
    p.green = (byte) newGreen;
    p.blue = (byte) newBlue;
}

//mirrorImage: creates and returns a mirror image of the img passed in
//precondition: i is a valid img object
//postcondition: returns a new img object that is the mirror image of i
img img::mirrorImage() const{
    //create new img object with same dimensions using img constructor
    img result(myImage.rows, myImage.cols); 
    for (int row = 0; row < myImage.rows; row++) {
        for (int col = 0; col < myImage.cols; col++) {
            //assign pixels from 'myImage' to 'result' in reversed column order
            result.myImage.pixels[row][col] = myImage.pixels[row][myImage.cols - 1 - col];  
        }
    }
    return result;
}

// ===== operator overloads ======

//precondition: rhs is a valid img object
//postcondition: assigns rhs img to this img
const img &img::operator=(const img &rhs) {
    //check if img is not equal to img on rhs
  if (this != &rhs) {		
    DeallocateImage(myImage);	
    myImage = CopyImage(rhs.myImage);	
  }
  return *this;
}

//precondition: rhs is a valid img object
//postcondition: returns true if the two images are identical, false otherwise
bool img::operator==(const img& rhs) const {
    //first check if dimensions are the same
    if (myImage.rows != rhs.myImage.rows || myImage.cols != rhs.myImage.cols){
        return false;
    }
    //compare each pixel in both images
       for (int row = 0; row < rhs.myImage.rows; row++){ 
		for (int col = 0; col < rhs.myImage.cols; col++){
           pixel inP = rhs.myImage.pixels[row][col]; 
            pixel outP = myImage.pixels[row][col]; 
            //compare each pixel color channel return false if any differ
            if(inP.blue != outP.blue || inP.green != outP.green || inP.red != outP.red){
                return false;
            }
        }
    }
    //if no differences found, images are equal and return true
    return true;
}

//precondition: rhs is a valid img object
//postcondition: returns true if the two images are different, false otherwise
bool img::operator!=(const img& rhs) const {
    //use the operator== for simplification
    //return true if images are not equal
    return !(*this == rhs);
}

//precondition: rhs is a valid img object
//postcondition: returns true if this img has more pixels than rhs, false otherwise
bool img::operator<(const img& rhs) const{
    int lhsPixels = myImage.rows * myImage.cols;
    int rhsPixels = rhs.myImage.rows * rhs.myImage.cols;
    //compare number of pixels in each image
    if (lhsPixels < rhsPixels){
        return true;
    } else {
        return false;
    }
}

//precondition: rhs is a valid img object
//postcondition: returns true if this img has less pixels than rhs, false otherwise
bool img::operator>(const img& rhs) const{
    //use the operator< for simplification
    return rhs < *this;
}

//precondition: os is a valid output stream, i is a valid img object
//postcondition: outputs the dimensions of the image to the output stream
ostream& operator<<(ostream& os, const img& i){
    //output the rows and columns of the image
    os << "Rows: " << i.getRows() << " |  Cols: " << i.getCols();
    return os;
}