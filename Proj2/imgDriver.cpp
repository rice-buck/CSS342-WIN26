#include "imgClass.h"

int main(){

    const char r = 'r';
    const char g = 'g';
    const char b = 'b';

    string filename = "test2.gif";
    //read image "test2.gif"
    img img1(filename);

    //Output the number of rows and columns using operator<<
    cout << img1 << endl;

    //Create a mirror-image using the member function
    img img2 = img1.mirrorImage(img1);

    //For every pixel, subtract row % 7 from the blue component and add col % 9 to the 
    // red component. Continue to check for (and correct) overflow and underflow.
       for (int row = 0; row < img2.getRows(); row++){
		for (int col = 0; col < img2.getCols(); col++){
            int redMod = img2.getPixel(row, col, r) + (col % 9);
            int greenMod = img2.getPixel(row, col, g);
            int blueMod = img2.getPixel(row, col, b) - (row % 7);
            //under/over flow checks
            if(redMod > 255) redMod = 255;
            if(blueMod < 0) blueMod = 0;

            img2.setPixel(row, col, redMod, greenMod, blueMod);
        }
    }

    //Write the image as “output.gif” and read that file back into a new variable.
    img2.outputFile("output.gif");

    img img3("output.gif");

    //Compare the image that you wrote to the image read in the previous step using your == operator for images.
    if (img2 == img3){
        cout << "Images match" << endl;
    }
    if(img2 != img3){
    //If the images are different, count the number of different pixels.
        int differingPixels = 0;
        int ogPixels = img2.getRows() * img2.getCols();
           for (int row = 0; row < img2.getRows(); row++){
		for (int col = 0; col < img2.getCols(); col++){ 
            int img2R = img2.getPixel(row, col, r);
            int img2G = img2.getPixel(row, col, g);
            int img2B = img2.getPixel(row, col, b);

            int img3R = img3.getPixel(row, col, r);
            int img3G = img3.getPixel(row, col, g);
            int img3B = img3.getPixel(row, col, b);

            if(img2R != img3R || img2B != img3B || img2G != img3G) differingPixels++;
        }
    }
    //Output the number of differences.
float percentChange = ((float)differingPixels / (float)ogPixels) * 100;
                cout << "Original pixels: " << ogPixels << endl << "Differing pixels: " << differingPixels << endl;
                cout << differingPixels << " / " << ogPixels << " changed or " << percentChange << "% changed" << endl;
        }

    return 0;
    }

