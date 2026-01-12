/*
Author: Rhys Buckeye
The purpose of this program is to read a '.gif' file, manipulate the red and blue color channels of the image, 
flip the image horizontally, output to terminal the differing pixels, and finally output the image as a new '.gif' image file.
*/

#include <iostream>
#include "ImageLib.h"

//string for filename
const std::string fileName = "test1.gif";

//forward declerations

void comparePixels(image in, image out);
void RBmodify(image in);
void flipImage(image in);
void testPixel(image in, int row, int col);

int main(){
    //reads the input file
    image input = ReadGIF(fileName);

    //check if image is valid
    if(input.rows == 0){
        cout << "Unable to open" << endl;
        return -1;
    }
    
    /*
   int testRow;
   int testCol;

    cout << "Enter test row and column: ";
    cin >> testRow >> testCol;

    //gets RGB value before modification
    testPixel(input, testRow, testCol);
   */ 
    //manipulate colors
    RBmodify(input);
    //flip image horizontally
    flipImage(input);

    //testPixel(input, testRow, testCol);

    //save image to "output.gif"
    WriteGIF("output.gif", input);

    //
    image output = ReadGIF("output.gif");

    //
    comparePixels(input, output);

    //deallocate memory for images
    DeallocateImage(output);
    DeallocateImage(input);

    return 0;

}

void RBmodify(image in){
    for (int row = 0; row < in.rows; row++){
		for (int col = 0; col < in.cols; col++){
            pixel &p = in.pixels[row][col];
           int blueMod = (int)p.blue - (row % 7);
           int redMod = (int)p.red + (col % 9);

           if(blueMod < 0) blueMod = 0;
           if(redMod > 255) redMod = 255;

           p.blue = (byte) blueMod;
           p.red = (byte) redMod;
        }
    }

}


void testPixel(image in, int row, int col){

    //allows user to see RGB value at specific coordinate

    cout << in.rows << " x " << in.cols << " image" << endl; 
    cout << "Pixel at (" << row << ", " << col << "): " << endl;
    pixel tP = in.pixels[row][col];
    cout << "Red: " << (int) tP.red << endl;
    cout << "Green: " << (int) tP.green << endl;
    cout << "Blue: " << (int) tP.blue << endl;
}

    void flipImage(image in) {
    image copy = CopyImage(in);
    for (int row = 0; row < in.rows; row++) {
        for (int col = 0; col < in.cols; col++) {
            in.pixels[row][col] = copy.pixels[row][in.cols - 1 - col]; 
        }
    }
    DeallocateImage(copy);
}

void comparePixels(image in, image out){
    int differingPixels = 0;
    int ogPixels = 0;
    ogPixels = in.rows * in.cols;
    for (int row = 0; row < in.rows; row++){
		for (int col = 0; col < in.cols; col++){
           pixel &inP = in.pixels[row][col]; 
            pixel &outP = out.pixels[row][col];
            if(inP.blue != outP.blue || inP.green != outP.green || inP.red != outP.red) differingPixels++;
        }
    }
    float percentChange = ((float)differingPixels / (float)ogPixels) * 100;
           cout << "Original pixels: " << ogPixels << endl << "Differing pixels: " << differingPixels << endl;
           cout << differingPixels << " / " << ogPixels << " changed or " << percentChange << "% changed" << endl;
}
