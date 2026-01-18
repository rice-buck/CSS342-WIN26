#include "ImageLib.h"
#include <algorithm>
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

//mirror image
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
