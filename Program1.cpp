#include <iostream>
#include "ImageLib.h"

//string for filename
const std::string fileName = "test1.gif";

void RBmodify(image in);
void flipImage(image in);
void testPixel(image in, int row, int col);

int main(){
    image input = ReadGIF(fileName);
    //check if image is valid
    if(input.rows == 0){
        cout << "Unable to open" << endl;
        return -1;
    }
    int testRow;
    int testCol;
    cout << "Enter test row and column: ";

    cin >> testRow >> testCol;
    cout << "/n";

    cout << "Unmodified pixel at (" << testRow << ", " << testCol << "): " << endl;
    testPixel(input, testRow, testCol);

    RBmodify(input);

    

    cout << "Modified pixel at (" << testRow << ", " << testCol << "): " << endl;
    testPixel(input, testRow, testCol);
    flipImage(input);

    WriteGIF("output.gif", input);

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

            if((int)p.blue < 0){
                p.blue = (byte) 0;
            }
            if((int)p.red > 255){
                p.red = (byte) 255;
            }
        }
    }

}


void testPixel(image in, int row, int col){
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