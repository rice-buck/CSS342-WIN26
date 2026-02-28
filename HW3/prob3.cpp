// Consider a pointer-based implementation for ADT queue (QueueP.cpp) that uses a circular list, but no front pointer. 
// (You can get to the front by going to the element after the back, unless the list is empty.) 
// Write the enqueue member operation (as it would appear in the cpp file). The prototype is:

template <typename QueueItem>
class Queue {
public:
  bool isEmpty() const;
  bool enqueue(QueueItem newItem);
  bool dequeue();
  bool dequeue(QueueItem& queueFront);
  bool getFront(QueueItem& queueFront) const;

private:
  struct QueueNode { 
    QueueItem item;
    QueueNode *next;
  };
  QueueNode *frontPtr;
  QueueNode *backPtr;
};

template <typename QueueItem>
bool Queue<QueueItem>::enqueue(QueueItem newItem){
    
    QueueNode *newNode = new QueueNode; 
    newNode->item = newItem; 
    //we can replace frontPtr with backPtr->next 
    if(isEmpty()) {  //when the list is empty
        backPtr = newNode;
        backPtr->next = backPtr; //point to itself to close the circle
    } else {
        newNode->next = backPtr->next; //newNode->next points to front of circle
        backPtr->next = newNode;
        backPtr = newNode;
    }
    return true;
}