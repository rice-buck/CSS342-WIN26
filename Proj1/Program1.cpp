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
void forloop(image in);
void underOverFlow(pixel p);
void comparePixels(image in, image out);
void RBmodify(image in);
void flipImage(image in);
void testPixel(image in, int row, int col);

int main(){
    //reads the input file
    image input = ReadGIF(fileName);

    image copyInput = CopyImage(input);
    //check if image is valid
    if(input.rows == 0){
        cout << "Unable to open" << endl;
        return -1;
    }
   int testRow;
   int testCol;

    cout << "Enter test row and column: ";
    cin >> testRow >> testCol;

    //gets RGB value before modification
    testPixel(input, testRow, testCol);
    
    //manipulate colors
    RBmodify(input);
    //flip image horizontally
    flipImage(input);

    testPixel(input, testRow, testCol);

    //save image to "output.gif"
    WriteGIF("output.gif", input);

    //create new image varibale from the recently output file
    image output = ReadGIF("output.gif");
    
    //compare the initially read image to the recently saved one
    comparePixels(copyInput, output);

    //deallocate memory for image
    DeallocateImage(input);

    return 0;

}

void RBmodify(image in){
    for (int row = 0; row < in.rows; row++){
		for (int col = 0; col < in.cols; col++){
            int bMod = row % 7;
            int rMod = col % 9;
            pixel& p = in.pixels[row][col];
            p.blue = (byte) ((int)p.blue - bMod);
            p.red = (byte) ((int)p.red + rMod);
           underOverFlow(p); 
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

void flipImage(image in){
    //create copy to pull from
    image copy = CopyImage(in);
    for (int row = 0; row < in.rows; row++){
		for (int col = 0, i = in.cols; col < in.cols; col++, i--){
            pixel &p = in.pixels[row][col];
                pixel s = copy.pixels[row][i];
            p.red = s.red;
            p.green = s.green;
            p.blue = s.blue;
        }
    }
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

    void underOverFlow(pixel p){
            if((int)p.blue < 0){
                p.blue = (byte) 0;
            }
            if((int)p.blue > 255){
                p.blue = (byte) 255;
            }
            if((int)p.red < 0){
                p.red = (byte) 0;
            }
            if((int)p.red > 255){
                p.red = (byte) 255;
            }
        }

