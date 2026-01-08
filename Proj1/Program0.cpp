// Program0.cpp
// Author:  Clark Olson
// Purpose: Reads a test image (hardcoded to "test.gif"), then
//          creates a negative of the image (all colors are inverted)
//          and outputs the result to "output.gif".

#include "ImageLib.h"
#include <iostream>

// forward declarations
void photonegative(image in);
void invertPixel(pixel &p);

const string inputFile = "test1.gif";
// main()
// Precondition:   test.gif exists and is a valid GIF image
// Postconditions: output.gif will be written and it will contain
//				   a photonegative of the image in test.gif
int main() {
	// Read test image from file
	image input = ReadGIF(inputFile);
	if (input.rows == 0) {
		cout << "Unable to open file: " << inputFile << endl;
		return -1;
	}

	// Create negative image
	photonegative(input);

	// Output results
	cout << "The dimensions of the image are: " << input.rows << " rows by " << input.cols << " columns." << endl;
	WriteGIF("output.gif",input);	
	
	// Wait for user input before exiting
	DeallocateImage(input);
	system("PAUSE");
	
	return 0;
}


// photonegative: modifies the input image to create a photonegative
// Preconditions: the input image (in) has in.rows * in.cols pixels allocated
// Postconditions: the input image is modified such that all of the pixel colors are inverted
void photonegative(image in) {
	for (int row = 0; row < in.rows; row++)
		for (int col = 0; col < in.cols; col++)
			invertPixel(in.pixels[row][col]);
}


// invertPixel: inverts the color of a single pixel
// Preconditions:  None
// Postconditions:  Each color band of the input pixel p has been inverted (255-color)
void invertPixel(pixel &p)
{
	p.blue = (byte) (255 - (int) p.blue);
	p.red = (byte) (255 - (int) p.red);
	p.green = (byte) (255 - (int) p.green);
	
}
