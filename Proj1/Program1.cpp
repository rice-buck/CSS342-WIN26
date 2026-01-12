/*
Author: Rhys Buckeye
The purpose of this program is to read a '.gif' file, manipulate the red and blue color channels of the image, 
flip the image horizontally, output to terminal the differing pixels, and finally output the image as a new '.gif' image file.
*/

#include <iostream>
#include "ImageLib.h"

//string for filename
const std::string fileName = "President_Barack_Obama.gif";

//forward declerations
void comparePixels(image in, image out);
void RBmodify(image in);
void flipImage(image in);

// main()
// Precondition:   test.gif exists and is a valid GIF image
// Postconditions: output.gif will be written and it will contain
//				   a manipulated version of the image in test.gif
int main(){
    //reads the input file
    image input = ReadGIF(fileName);

    //check if image is valid, exits if not
    if(input.rows == 0){
        cout << "Unable to open" << endl;
        return -1;
    }

    //manipulates red and blue channels of image
    RBmodify(input);

    //flip image horizontally
    flipImage(input);

    //save image to "output.gif"
    WriteGIF("output.gif", input);

    //read the output file
    image output = ReadGIF("output.gif");

    //compares pixels of input and output images
    comparePixels(input, output);

    //deallocate memory for images
    DeallocateImage(output);
    DeallocateImage(input);

    return 0;
}
//RBmodify: modifies the red and blue channels of the image based on row and column indices
//Preconditons: image 'in' has in.rows * in.cols pixels allocated
//Postconditions: modifies the red and blue channels of the image based on row and column indices
void RBmodify(image in){
    for (int row = 0; row < in.rows; row++){
		for (int col = 0; col < in.cols; col++){
            pixel &p = in.pixels[row][col];
            //modify blue and red channels
           int blueMod = (int)p.blue - (row % 7);
           int redMod = (int)p.red + (col % 9);
            //underflow and overflow checks
           if(blueMod < 0) blueMod = 0;
           if(redMod > 255) redMod = 255;
            //assign modified values back to pixel as bytes
           p.blue = (byte) blueMod;
           p.red = (byte) redMod;
        }
    }

}
//flipImage: flips the image horizontally
//Preconditions: image 'in' has in.rows * in.cols pixels allocated
//Postconditions: image 'in' is modified to be flipped horizontally
    void flipImage(image in) {
    image copy = CopyImage(in);
    for (int row = 0; row < in.rows; row++) {
        for (int col = 0; col < in.cols; col++) {
            //assign pixels from 'copy' to 'in' in reversed column order
            in.pixels[row][col] = copy.pixels[row][in.cols - 1 - col]; 
        }
    }
    DeallocateImage(copy);
}

//comparePixels: compares two images and outputs the number and percentage of differing pixels
//Preconditions: images 'in' and 'out' have the same dimensions and in.rows * in.cols pixels allocated
//Postconditions: outputs the number and percentage of differing pixels between the two images
void comparePixels(image in, image out){
    int differingPixels = 0;
    int ogPixels = in.rows * in.cols;
    for (int row = 0; row < in.rows; row++){
		for (int col = 0; col < in.cols; col++){
           pixel &inP = in.pixels[row][col]; 
            pixel &outP = out.pixels[row][col];
            //compare pixels, increment differingPixels if any color channel differs
            if(inP.blue != outP.blue || inP.green != outP.green || inP.red != outP.red) differingPixels++;
        }
    }
    //calculate percentage of differing pixels
    float percentChange = ((float)differingPixels / (float)ogPixels) * 100;
           cout << "Original pixels: " << ogPixels << endl << "Differing pixels: " << differingPixels << endl;
           cout << differingPixels << " / " << ogPixels << " changed or " << percentChange << "% changed" << endl;
}
