/*
Author: Rhys B
Implementation file for container class.
This class uses a linked list to store pixel data via a PixelNode struct. 
*/

#include "container.h"

    //===Default constructor===
    //container head set to nullptr


    //===Copy Helper Function==== 
    //Base case: stop when originalNode == nullptr and return nullptr
    //Recursive step:
    //create a new node and set its next pointer to the result of copying the rest of the list
    //newNode = original nodes data 
    //next newNode = copyHelper(next orignalNode)

    //once the base case is hit and the last node is set to nullptr,
    //it will return the head node of the newly copied list


    //====Copy Constructor====
    //copy list head = nullptr
    //This will utilize the helper function above
    //Start the recursive copying from the had of the new empty list
    // head of copy list = copyHelper(originalList's head)

    // newly copied container now contains head node linked to all the 
    // copied data of the original container


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


    //==== Assignment Operator ====
    //Check for self assignment
    //If self assignment, return *this
    //If not self assignment, delete current list data
    //Copy the data from the right hand side container to the left hand 
    // side container using the copy helper function
    //Return *this


    //==== addPixel ====
    //Check for valid demensions
    //Create a new Node for pixel data to be stored
    //Check if the list is empty and if it is then set the head of the list equal to the new node and return
    //If the list ins't empty, then:
    //Add the new node to the head of the list by setting the new node's next pointer to the current head of the list.
    //Update the head of the list to be the new node.
    //Since we have row and col data stored in the node, we can easily access the pixel data.
    //So there is no need to add the new node to the end of the list, we can just add it to the head.


    
    // ==== Merge Containers ====
    // create a copy of the container passed in using the copy helper function.
    // check: copy of list passed in != empty
    // if master list == empty  set the head of the master list to the head of the copied list and return
    // if master list != empty, then:

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
    


