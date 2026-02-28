// Suppose that you have a stack aStack and an empty auxiliary stack auxStack. Show how you can do each of the following tasks by using only the ADT stack operations. 
// Write code fragments, not functions. Make no assumptions about the stack implementation (it could be any). You may assume that “StackItem” is a previously declared template type variable 
// for the method you are within. The following methods (from StackP.h) are available:

// bool isEmpty() const;
// bool push(StackItem newItem);
// bool pop();
// bool pop(StackItem& StackTop);
// bool getTop(StackItem& StackTop) const;
 

// Display the contents of aStack in reverse order; that is, display the top last.

while(!aStack.isEmpty()){
    //move over all items from aStack to auxStack from top to bottom
    StackItem element;
    aStack.getTop(element);

    aStack.pop();

    auxStack.push(element);
}

while(!auxStack.isEmpty()){
    //since the way the elements were transfered, printing and popping will print the reverse order of aStack
    StackItem topElement;
    auxStack.getTop(topElement);

    cout << topElement << endl;

    auxStack.pop();
    //add elements back to the original aStack in correct order
    aStack.push(topElement);
}




// Count the number of items in aStack, leaving aStack unchanged.

int counter = 0;

while(!aStack.isEmpty()){
    //move over all items from aStack to auxStack from top to bottom
    StackItem element;
    aStack.getTop(element);

    aStack.pop();

    auxStack.push(element);

    counter++;
}

while(!auxStack.isEmpty()){
    //add elements back to the original aStack in correct order
    StackItem topElement;
    auxStack.getTop(topElement);

    auxStack.pop();

    aStack.push(topElement);
}




// Delete every occurrence of a specified item from aStack, leaving the order of the remaining items unchanged.
//I'm asuming targetElement is already defined
StackItem targetElement;

while(!aStack.isEmpty()){
    //move over all items from aStack to auxStack from top to bottom
    StackItem element;
    aStack.getTop(element);

    aStack.pop();

    //only add non target items to the auxStack, effectively filtering out the target item
    if(element != targetElement) auxStack.push(element);
}

while(!auxStack.isEmpty()){
    //add elements back to the original aStack in correct order
    StackItem topElement;
    auxStack.getTop(topElement);

    auxStack.pop();

    aStack.push(topElement);
}