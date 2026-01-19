#include "ImageLib.h"
#include "imgClass.h"

//loads a file
img::img (string filename){
    myImage = ReadGIF(filename);
}
//creates blank image
img::img (int rows, int cols){
    myImage = CreateImage(rows, cols);
}
//copy constructor
img::img(const img& copy){
    myImage = CopyImage(copy.myImage);
}
//destructor
img::~img(){
    DeallocateImage(myImage);
}
//=operator
const img &img::operator=(const img &rhs) {
  if (this != &rhs) {		
    DeallocateImage(myImage);	
    myImage = CopyImage(rhs.myImage);	
  }
  return *this;
}

//getRows 
int img::getRows(){
    return myImage.rows;
}

//getCols
int img::getCols(){
    return myImage.cols;
}

//getPixels
int img::getPixel(int row, int col, char color){
   pixel p = myImage.pixels[row][col];
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
         return -1; //invalid color 
   }
}

//setPixel
void img::setPixel(int row, int col, int newRed, int newGreen, int newBlue){
    pixel &p = myImage.pixels[row][col];
    p.red = (byte) newRed;
    p.green = (byte) newGreen;
    p.blue = (byte) newBlue;
}

//output file 
void img::outputFile(string filename){
    WriteGIF(filename, myImage);
}

//mirror image passed by value 
img img::mirrorImage(img i){
    image copy = CopyImage(myImage);
    for (int row = 0; row < i.myImage.rows; row++) {
        for (int col = 0; col < i.myImage.cols; col++) {
            //assign pixels from 'copy' to 'in' in reversed column order
            i.myImage.pixels[row][col] = copy.pixels[row][i.myImage.cols - 1 - col]; 
        }
    }
    DeallocateImage(copy);
    return i;
}

//this will modify the image because it uses a pointer
img img::mirrorImage2(){
    image copy = CopyImage(myImage);
    for (int row = 0; row < this->getRows(); row++) {
        for (int col = 0; col < this->getCols(); col++) {
            //assign pixels from 'copy' to 'in' in reversed column order
            this->myImage.pixels[row][col] = copy.pixels[row][this->myImage.cols - 1 - col]; 
        }
    }
    //deallocate memory for copy image - no longer needed
    DeallocateImage(copy);
    //derefrence the img pointer
    return *this;
}

bool img::operator==(const img& rhs) const {
       for (int row = 0; row < rhs.myImage.rows; row++){ 
		for (int col = 0; col < rhs.myImage.cols; col++){
           pixel inP = rhs.myImage.pixels[row][col]; 
            pixel outP = myImage.pixels[row][col]; //this-> or myImage??
            //compare pixels
            if(inP.blue != outP.blue || inP.green != outP.green || inP.red != outP.red){
                return false;
            }
        }
    }
    return true;
}

bool img::operator!=(const img& rhs) const {
    //use the operator== for simplification
    //'this' is lhs img (* for dereference)
    return !(*this == rhs);
}


bool img::operator<(const img& rhs) const{
    int lhsPixels = myImage.rows * myImage.cols;
    int rhsPixels = rhs.myImage.rows * rhs.myImage.cols;
    if (lhsPixels < rhsPixels){
        return true;
    } else {
        return false;
    }
}

bool img::operator>(const img& rhs) const{
    //use the operator<
    return rhs < *this;
}
//cant use friend version in definition?
ostream& operator<<(ostream& os, const img& i){
    os << "Rows: " << i.myImage.rows << " |  Cols: " << i.myImage.cols;
    return os;
}
//Question: why would we make a operator overload not in a member function?
//Question: is it okay to use overloaded operators in other operator overloads