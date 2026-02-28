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

//only uses ADT queue operations

QueueItem fItem;
Queue<QueueItem> tempQueue;
//pass by value to not modify original queue
void Queue<QueueItem>::display1(){ 
    while(!isEmpty()){
        getFront(fItem);
        cout << fItem << endl;

        //move item to temp queue
        dequeue();
        tempQueue.enqueue(fItem);
    }
    //add the original queue's data back
    while(!tempQueue.isEmpty()){
        tempQueue.getFront(fItem);
        tempQueue.dequeue(fItem);
        enqueue(fItem);
    }
}


//uses pointer-based implementation of queue

void Queue<QueueItem>::display2(){
    //use frontPtr to know our current starting point
    QueueNode *current = frontPtr;

    while(current != nullptr){
        cout << current->item << endl;
        current = current->next;
    }
}