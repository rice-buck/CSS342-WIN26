/*
Author: Rhys B
Implementation file for container class.
This class uses a linked list to store pixel data via a PixelNode struct. 
*/

#include "container.h"
#include "ImageLib.h"
#include <algorithm>

    //===Default constructor===
    //container head set to nullptr
    container::container() {
        head = nullptr;
    }


    //===Copy Helper Function==== 
    //Base case: stop when originalNode == nullptr and return nullptr
    //Recursive step:
    //create a new node and set its next pointer to the result of copying the rest of the list
    //newNode = original nodes data 
    //next newNode = copyHelper(next orignalNode)

    //once the base case is hit and the last node is set to nullptr,
    //it will return the head node of the newly copied list
    PixelNode *container::copyHelper(PixelNode *originalNode){
        //base case and set last node to nullptr
        //also handles if original container is empty
        if(originalNode == nullptr) return nullptr;

        //new copy node with original nodes data
        PixelNode *newNode = new PixelNode(originalNode->row, originalNode->col, originalNode->pix);

        //recursive call
        newNode->next = copyHelper(originalNode->next);

        //returns head of newly copied list
        return newNode;
    }


    //====Copy Constructor====
    //copy list head = nullptr
    //This will utilize the helper function above
    //Start the recursive copying from the had of the new empty list
    // head of copy list = copyHelper(originalList's head)

    // newly copied container now contains head node linked to all the 
    // copied data of the original container
    container::container(const container& other){
        //contains the head of copied container
        head = copyHelper(other.head);
    }


    //====Destructor====
    //~container(){
    //current node = first node in list 
    // while loop until last node{
    //     next node = node after current node
    //     delete node currently on
    //     move onto the next node  
    //     current = next
    // }
    // after everythings deleted set
    // set head pointer to nullptr
    //}
    container::~container(){
        PixelNode *current = head;
        while(current != nullptr){
            PixelNode *nextNode = current->next;//save next node
            delete current; //deallocate current node
            current = nextNode; //move to next node
        }
        head = nullptr; //set head to nullptr at end
    }


    //==== Assignment Operator ====
    //Check for self assignment
    //If self assignment, return *this
    //If not self assignment, delete current list data
    //Copy the data from the right hand side container to the left hand 
    // side container using the copy helper function
    //Return *this
    container& container::operator=(const container& rhs){
        //check for self assignement 
        if(this == &rhs) return *this;
        else{
            delete this; //delete lhs data
            this->copyHelper(rhs.head); //copy data from rhs to lhs
            return *this; 
        }
    }

    //==== addPixel ====
    //Check for valid demensions
    //Create a new Node for pixel data to be stored
    //Check if the list is empty and if it is then set the head of the list equal to the new node and return
    //If the list ins't empty, then:
    //Add the new node to the head of the list by setting the new node's next pointer to the current head of the list.
    //Update the head of the list to be the new node.
    //Since we have row and col data stored in the node, we can easily access the pixel data.
    //So there is no need to add the new node to the end of the list, we can just add it to the head.
    void container::addPixel(int row, int col, const pixel&p){
        //check for valid dimensions

        //create new node for pixel data
        PixelNode *newNode = new PixelNode(row, col, p);

        //check if list is empty
        if(head == nullptr) {
            head = newNode;
            return;
        } else {
            //add new node to front of container
            newNode->next = head;
            head = newNode;
        }
    }
void container::print(){

        PixelNode* current = head;

        while(current != nullptr){
            int red = (int)current->pix.red;
            int green = (int)current->pix.green;
            int blue = (int)current->pix.blue;
            int row = current->row;
            int col = current->col;

            std::cout << "Pixel location: " << "(" << row << ", " << col << ")"<< std::endl;
            std::cout << "RGB = " << "(" << red << ", " << green << ", " << blue << ")" << std::endl;
            current = current->next;
        }
    }
    
    // ==== Merge Containers ====
    // create a copy of the container passed in using the copy helper function.
    // check: copy of list passed in != empty
    // if master list == empty  set the head of the master list to the head of the copied list and return
    // if master list != empty, then:
    void container::merge(const container other){
        PixelNode *copyHead = copyHelper(other.head);
        PixelNode *masterCurrent = head;

        if (head == nullptr) {
            head = copyHead;
        } else {
            while (masterCurrent->next != nullptr){
                masterCurrent = masterCurrent->next;
            }
            //set last node of master to head of passed in container
            masterCurrent->next = copyHead;
        }
    }

    // while loop {
    //  get current node to last node of master list
    //}
    //  Set next node of last node of master list to head of copied list
    //  this effectively merges the two lists together without altering the original list passed in


    // ==== Average Color ====
    //check for empty list 
    //while loop through the list and add up all the color values of the pixels
    //keep track of how many pixels there are in the list
    //return pixel with color value divided by the number of pixels (effectively averaging)
    pixel const container::averageColorValue(){
        pixel p;
        p.red = (byte)0;
        p.green = (byte)0;
        p.blue = (byte)0;
        //when container is empty
        if(head == nullptr){
            std::cout << "WARNING: Container you're trying to average is empty!" << std::endl;
            return p;
        } else {
            PixelNode *current = head;
            int redSum = 0, blueSum = 0, greenSum = 0, counter = 0;
            while (current != nullptr){
                redSum += (int)current->pix.red;
                greenSum += (int)current->pix.green;
                blueSum += (int)current->pix.blue;
                counter++;
                current = current->next;
            }
            int redAvg = redSum / counter;
            int greenAvg = greenSum / counter;
            int blueAvg = blueSum / counter;
            p.red = (byte)redAvg;
            p.green = (byte)greenAvg;
            p.blue = (byte)blueAvg;
            std::cout << "(" << redAvg << ", " << greenAvg << ", " << blueAvg << ")" << std::endl;
            return p;
        }
    }


