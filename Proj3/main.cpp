#include "Rectangle.h"
#include "img.h"
#include <string>

using namespace std;

void shrink(img& source, img& dest, Rectangle& srcRect, Rectangle& destRect){
    for(int row = 0; row < destRect.getHeight(); ++row){
        for(int col = 0; col < destRect.getWidth(); ++col){
            //for fomula
            int r2 = srcRect.getStartRow() + 2 * row;
            int c2 = srcRect.getStartCol() + 2 * col;

            //avg formula for even dimensions
            //output(r, c) = (input(2r, 2c) + input(2r+1, 2c) + input(2r, 2c+1) + input(2r+1, 2c+1) ) / 4
            int rInt = (source.getPixel( r2,  c2, 'r') + source.getPixel(r2 + 1, c2, 'r') + source.getPixel(r2, c2 + 1, 'r') + source.getPixel(r2 + 1, c2 + 1, 'r')) / 4;
            int gInt = (source.getPixel( r2,  c2, 'g') + source.getPixel(r2 + 1, c2, 'g') + source.getPixel(r2, c2 + 1, 'g') + source.getPixel(r2 + 1, c2 + 1, 'g')) / 4;
            int bInt = (source.getPixel( r2,  c2, 'b') + source.getPixel(r2 + 1, c2, 'b') + source.getPixel(r2, c2 + 1, 'b') + source.getPixel(r2 + 1, c2 + 1, 'b')) / 4;
            dest.setPixel(destRect.getStartRow() + row, destRect.getStartCol() + col, rInt, gInt, bInt);
        }
    }
}

// // output(r, c) = (input(maxR – 2r, maxC – 2c) + input(maxR – 2r – 1, maxC – 2c) + input(maxR – 2r, maxC – 2c – 1) + input(maxR – 2r – 1, maxC – 2c – 1) ) / 4
// void shrinkFlip(img& source, img& dest, Rectangle& rect){
//     for(int row = 0; row < rect.getHeight(); ++row){
//         for(int col = 0; col < rect.getWidth(); ++col){
//             //for fomula 
//             int r2 = 2 * row;
//             int c2 = 2 * col;
//             int maxR = source.getRows() - 1;
//             int maxC = source.getCols() - 1;
//             //avg formula for even
//             int rInt = (source.getPixel(maxR - r2, maxC - c2, 'r') + source.getPixel(maxR - r2 - 1, maxC - c2, 'r') + source.getPixel(maxR - r2, maxC - c2 - 1, 'r') + source.getPixel(maxR - r2 - 1, maxC - c2 - 1, 'r')) / 4;
//             int gInt = (source.getPixel(maxR - r2, maxC - c2, 'g') + source.getPixel(maxR - r2 - 1, maxC - c2, 'g') + source.getPixel(maxR - r2, maxC - c2 - 1, 'g') + source.getPixel(maxR - r2 - 1, maxC - c2 - 1, 'g')) / 4;
//             int bInt = (source.getPixel(maxR - r2, maxC - c2, 'b') + source.getPixel(maxR - r2 - 1, maxC - c2, 'b') + source.getPixel(maxR - r2, maxC - c2 - 1, 'b') + source.getPixel(maxR - r2 - 1, maxC - c2 - 1, 'b')) / 4;
//             dest.setPixel(rect.getStartRow() + row, rect.getStartCol() + col, rInt, gInt, bInt);
//         }
//     }
// }

void makeFractal(img& source, img& dest, Rectangle& rect){
    //base case:
    if(rect.getWidth() < 2 || rect.getHeight() < 2) return;

    //create four sub rects
    Rectangle tL(rect.getStartCol(), rect.getStartRow(), rect.getWidth() / 2, rect.getHeight() / 2);
    Rectangle tR(rect.getStartCol() + rect.getWidth() / 2, rect.getStartRow(), rect.getWidth() / 2, rect.getHeight() / 2);
    Rectangle bL(rect.getStartCol(), rect.getStartRow() + rect.getHeight() / 2, rect.getWidth() / 2, rect.getHeight() / 2);
    Rectangle bR(rect.getStartCol() + rect.getWidth() / 2, rect.getStartRow() + rect.getHeight() / 2, rect.getWidth() / 2, rect.getHeight() / 2);

    //fill top left
    shrink(source, dest, rect, tL);

    //fill bottom right 
    //shrinkFlip(source, dest, bR);
    
    //recursive part
    makeFractal(dest, dest, tR);
    //makeFractal(dest, dest, bL);
}


int main(){
string filename = "test-256.gif";

img input(filename);

img output(256, 256);

Rectangle rec(0, 0, input.getCols(), input.getRows());

// Rectangle r(0, 0, input.getRows() / 2, input.getCols() / 2);
// Rectangle r2(128, 0, r.getWidth() /2, r.getHeight() / 2);
// Rectangle r3(192, 0, r2.getWidth() / 2, r2.getHeight() / 2);


makeFractal(input, output, rec);

//shrink image
// shrink(input, output, r);
// shrink(output, output, r2);
// shrink(output, output, r3);

//shrink(output, output, r2);
//shrink(output, output, r3);
// shrinkFlip(input, output, r2);

//makeFractal(input, output, rec);

// img img1(shrink(input, output, r));

// img i(r.getWidth(), r.getHeight());
//     for(int row = 0; row < r.getHeight(); ++row){
//         for(int col = 0; col < r.getWidth(); ++col){
//             i.setPixel(row, col, output.getPixel(r.getStartRow() + row,  r.getStartCol() + col, 'r'), output.getPixel(r.getStartRow() + row,  r.getStartCol() + col, 'g'), output.getPixel(r.getStartRow() + row,  r.getStartCol() + col, 'b'));
//     }
// }
// img img2(shrink(i, output, r2));

// img i2(r2.getWidth(), r2.getHeight());
//     for(int row = 0; row < i2.getRows(); ++row){
//         for(int col = 0; col < i2.getCols(); ++col){
//             i2.setPixel(row, col, output.getPixel(r2.getStartRow() + row,  r2.getStartCol() + col, 'r'), output.getPixel(r2.getStartRow() + row,  r2.getStartCol() + col, 'g'), output.getPixel(r2.getStartRow() + row,  r2.getStartCol() + col, 'b'));
//         }
//     }

// img img3(shrink(i2, output, r3));

//shrink(input, output, r3);
//shrink(input, output, rec);
//Rectangle rec2(127, 0, 128, 128);
//shrink(output, output, rec2);

output.outputFile("shrunk image.gif");

return 0;
}