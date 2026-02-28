/*
 * File: main.cpp
 * Purpose: Recursively generates an image fractal based on a provided GIF.
 * Functionality: Uses an Image class and a Rectangle class to shrink and flip 
 * quadrants of an image repeatedly.
 * Assumptions: "test3.gif" exists. Input image dimensions are at least 1x1.
 * Author: Rhys Buckeye
 */

#include "Rectangle.h"
#include "img.h"
#include <string>

using namespace std;

// Purpose: Averages 2x2 blocks from a source region and writes to a destination region.
// Pre-condition: source and dest are valid img objects. srcRect and destRect define valid regions.
// Post-condition: destRect in the dest image is filled with a shrunken version of srcRect.
void shrink(img& source, img& dest, Rectangle srcRect, Rectangle destRect) {
    for (int row = 0; row < destRect.getHeight(); ++row) {
        for (int col = 0; col < destRect.getWidth(); ++col) {
            
            int rSum = 0, gSum = 0, bSum = 0, count = 0;

            // Average the 4 pixels in the source that correspond to 1 pixel in the dest
            for (int i = 0; i < 2; ++i) {
                for (int j = 0; j < 2; ++j) {
                    int src_r = srcRect.getStartRow() + 2 * row + i;
                    int src_c = srcRect.getStartCol() + 2 * col + j;

                    // Bounds check to handle odd-sized source regions safely
                    if (src_r < srcRect.getStartRow() + srcRect.getHeight() && 
                        src_c < srcRect.getStartCol() + srcRect.getWidth()) {
                        
                        rSum += source.getPixel(src_r, src_c, 'r');
                        gSum += source.getPixel(src_r, src_c, 'g');
                        bSum += source.getPixel(src_r, src_c, 'b');
                        count++;
                    }
                }
            }

            // Perform integer division to find the average color
            if (count > 0) {
                dest.setPixel(destRect.getStartRow() + row, destRect.getStartCol() + col, rSum / count, gSum / count, bSum / count);
            }
        }
    }
}

// Purpose: Averages 2x2 blocks and flips them vertically and horizontally.
// Pre-condition: source and dest are valid img objects. srcRect and destRect define valid regions.
// Post-condition: destRect in dest is filled with a shrunken, 180-degree rotated version of srcRect.
void shrinkFlip(img& source, img& dest, Rectangle srcRect, Rectangle destRect) {
    int maxR = srcRect.getStartRow() + srcRect.getHeight() - 1;
    int maxC = srcRect.getStartCol() + srcRect.getWidth() - 1;

    for (int row = 0; row < destRect.getHeight(); ++row) {
        for (int col = 0; col < destRect.getWidth(); ++col) {
            
            int rSum = 0, gSum = 0, bSum = 0, count = 0;

            for (int i = 0; i < 2; ++i) {
                for (int j = 0; j < 2; ++j) {
                    // Apply the flipping formula: (max - 2r)
                    int src_r = maxR - 2 * row - i;
                    int src_c = maxC - 2 * col - j;

                    if (src_r >= srcRect.getStartRow() && src_c >= srcRect.getStartCol()) {
                        rSum += source.getPixel(src_r, src_c, 'r');
                        gSum += source.getPixel(src_r, src_c, 'g');
                        bSum += source.getPixel(src_r, src_c, 'b');
                        count++;
                    }
                }
            }

            if (count > 0) {
                dest.setPixel(destRect.getStartRow() + row, destRect.getStartCol() + col, rSum / count, gSum / count, bSum / count);
            }
        }
    }
}

// Purpose: Recursively defines the 4 quadrants of the fractal.
// Pre-condition: source and dest images are initialized. destRect defines the target area.
// Post-condition: The fractal is drawn into the dest image within the destRect boundary.
void makeFractal(img& source, img& dest, Rectangle srcRect, Rectangle destRect) {
    // Base case 
    if (destRect.getWidth() <= 0 || destRect.getHeight() <= 0) {
        return;
    }

    // Determine sub-quadrant dimensions --- Odd sizes by adding remainders to top/left 
    int leftW = destRect.getWidth() / 2 + destRect.getWidth() % 2;
    int rightW = destRect.getWidth() / 2;
    int topH = destRect.getHeight() / 2 + destRect.getHeight() % 2;
    int bottomH = destRect.getHeight() / 2;

    // Create the four quadrant rectangles
    Rectangle TL(destRect.getStartCol(), destRect.getStartRow(), leftW, topH);
    Rectangle TR(destRect.getStartCol() + leftW, destRect.getStartRow(), rightW, topH);
    Rectangle BL(destRect.getStartCol(), destRect.getStartRow() + topH, leftW, bottomH);
    Rectangle BR(destRect.getStartCol() + leftW, destRect.getStartRow() + topH, rightW, bottomH);

    // Normal shrink into Top-Left and flipped shrink into Bottom-Right
    shrink(source, dest, srcRect, TL);
    shrinkFlip(source, dest, srcRect, BR);

    // Use the Top-Left quadrant the input for the next level
    if (destRect.getWidth() > 1 || destRect.getHeight() > 1) {
        // Recursion for the Top-Right and Bottom-Left
        makeFractal(dest, dest, TL, TR);
        makeFractal(dest, dest, TL, BL);
    }
}

// Purpose: Driver for the fractal program.
// Pre-condition: None.
// Post-condition: Reads test3.gif and produces output.gif. Returns 0 on success.
int main() {
        string filename = "test-256.gif";
        img input(filename);
        img output(input.getRows(), input.getCols());

        // Initialize the full image boundary for the initial call
        Rectangle fullRec(0, 0, input.getCols(), input.getRows());

        // Generate the fractal pattern
        makeFractal(input, output, fullRec, fullRec);

        // Save result
        output.outputFile("output.gif");

    return 0;
}