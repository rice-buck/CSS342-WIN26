#include "imgClass.h"

int main(){

    char r = 'r';
    char g = 'g';
    char b = 'b';

    img img1("test2.gif");

    
    cout << "Cols: " << img1.getCols() << endl;
    cout << "Rows: " << img1.getRows() << endl;
    cout << "Red: " << img1.getPixel(10, 50, r);

    //draw line
    for(int i = 0; i < img1.getCols(); i++){
        img1.setPixel(10, i, 50, 50, 50);
    }

    //img1.setPixel(50, 50, 150, 130, 10);
    cout << "\n";
    cout << "Red: " << img1.getPixel(10, 50, r);

    //mirror img
    img img3 = img1.mirrorImage(img1);
    img1.outputFile("TestOutput.gif");
    img3.outputFile("Flipped.gif");


    //black img
    img img2(10, 10);

    img2.outputFile("BlackImg.gif");



    return 0;
}
