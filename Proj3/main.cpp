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


void shrinkFlip(img& source, img& dest, Rectangle& srcRect, Rectangle& destRect){
    for(int row = 0; row < destRect.getHeight(); ++row){
        for(int col = 0; col < destRect.getWidth(); ++col){
            //for fomula 
            int r2 = srcRect.getStartRow() + 2 * row;
            int c2 = srcRect.getStartCol() + 2 * col;
            int maxR = source.getRows() - 1;
            int maxC = source.getCols() - 1;
            //avg formula for even
            // output(r, c) = (input(maxR – 2r, maxC – 2c) + input(maxR – 2r – 1, maxC – 2c) + input(maxR – 2r, maxC – 2c – 1) + input(maxR – 2r – 1, maxC – 2c – 1) ) / 4
            int rInt = (source.getPixel(maxR - r2, maxC - c2, 'r') + source.getPixel(maxR - r2 - 1, maxC - c2, 'r') + source.getPixel(maxR - r2, maxC - c2 - 1, 'r') + source.getPixel(maxR - r2 - 1, maxC - c2 - 1, 'r')) / 4;
            int gInt = (source.getPixel(maxR - r2, maxC - c2, 'g') + source.getPixel(maxR - r2 - 1, maxC - c2, 'g') + source.getPixel(maxR - r2, maxC - c2 - 1, 'g') + source.getPixel(maxR - r2 - 1, maxC - c2 - 1, 'g')) / 4;
            int bInt = (source.getPixel(maxR - r2, maxC - c2, 'b') + source.getPixel(maxR - r2 - 1, maxC - c2, 'b') + source.getPixel(maxR - r2, maxC - c2 - 1, 'b') + source.getPixel(maxR - r2 - 1, maxC - c2 - 1, 'b')) / 4;
            dest.setPixel(destRect.getStartRow() + row, destRect.getStartCol() + col, rInt, gInt, bInt);
        }
    }
}


void makeFractal(img& source, img& dest, Rectangle srcRect, Rectangle destRect)
{
    // Base case
    if (destRect.getWidth() < 2 || destRect.getHeight() < 2)
        return;

    // Shrink source into destRect
    shrink(source, dest, srcRect, destRect);

    Rectangle tR(destRect.getStartCol() + destRect.getWidth(), destRect.getStartRow(), destRect.getWidth() / 2, destRect.getHeight() / 2);
    Rectangle bR(destRect.getStartCol() + destRect.getWidth(), destRect.getStartRow(), destRect.getWidth() / 2, destRect.getHeight() / 2);
    Rectangle bL(destRect.getStartCol(), destRect.getStartRow() + destRect.getHeight(), destRect.getWidth() / 2, destRect.getHeight() / 2);
    // Create next rectangle to the right (half size)
    
    // Recurse using the newly shrunk region
    makeFractal(dest, dest, destRect, tR);
    makeFractal(dest, dest, tR, bL);
}

int main(){
string filename = "test-256.gif";

img input(filename);

img output(input.getRows(), input.getCols());

Rectangle rec(0, 0, input.getCols(), input.getRows());

Rectangle first(0, 0, input.getCols() / 2, input.getRows() / 2);

makeFractal(input, output, rec, first);

output.outputFile("shrunk image.gif");

return 0;
}

