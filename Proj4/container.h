/*
Author: Rhys B
Header file for container class and node struct.
This class uses a linked list to store pixel data via a PixelNode struct. 
*/

#include <iostream>
#include "ImageLib.h"

//Node struct description:
//This struct represents a single node in the linked list. It contains the row and column of the pixel,
//the pixel data itself, and a pointer to the next node in the list. 
struct PixelNode {
    int row; 
    int col;
    pixel pix;
    
    //pointer to the next node in the list
    PixelNode *next;

    //constructor for PixelNode that initializes the row, column, pixel data, and sets the next pointer to nullptr
    PixelNode(int r, int c, const pixel& p) : row(r), col(c), pix(p), next(nullptr) {}
};

//container class description:
//This class represents a container for storing pixel data using a linked list. It provides methods for
//adding pixels, merging containers, and calculating the average color value of the pixels in the container.
class container{
private:
    //head pointer for the linked list of PixelNodes
    PixelNode *head;

    //helper function for copying a linked list of PixelNodes
    //precondition: originalNode is a pointer to the head of a linked list of PixelNodes
    //postcondition: returns a pointer to the head of a new linked list that is a copy of the original list
    PixelNode *copyHelper(PixelNode *originalNode);

public:
    //constuctor
    //precondition: none
    //postcondition: creates an empty container with head set to nullptr
    container();

    //copy constructor
    //precondition: other is a valid container object
    //postcondition: creates a new container that is a copy of the other container
    container(const container& other);

    //destructor
    //precondition: none
    //postcondition: deallocates all memory used by the container and sets head to nullptr
    ~container();

    //operator= 
    //precondition: rhs is a valid container object
    //postcondition: assigns the contents of rhs to the current container, deallocating any
    //previously used memory and copying the data from rhs using the copyHelper function
    container& operator=(const container& rhs);

    //addPixel: adds a pixel to the container
    //precondition: row and col are valid pixel locations, p is a valid pixel object
    //postcondition: creates a new PixelNode with the given row, column, and pixel
    void addPixel(int row, int col, const pixel& p);

    //merge: merges another container into the current container
    //precondition: other is a valid container object
    //postcondition: all pixels from the other container are added to the end of current container, and
    // the other container is left unchanged
    void merge(const container other);

    //averageColorValue: calculates the average color value of all pixels in the container
    //precondition: the container is not empty
    //postcondition: returns a pixel object that represents the average color value of all pixels in 
    // the container, with each color channel averaged separately
    pixel const averageColorValue();
};