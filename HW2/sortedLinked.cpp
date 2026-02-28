#include <iostream>

using namespace std;
struct Node{
    int data;
    Node *next;

    //constructor for new nodes
    Node(int value) {
        data = value;
        next = nullptr;
    }
};

class LinkedList {
private: 
    Node* head = nullptr; // pointer to first node

public:
    LinkedList(){
        head = nullptr; //empty list
    }


void insert(int x)
    {
        Node* temp = new Node(x);

        if (head == nullptr) {
            head = temp;
            return;
        }
        else {
            Node* t = head;
            while (t->next != nullptr) {
                t = t->next;
            }
            t->next = temp;
        }
    }

void print(){
    Node* current = head;
    while (current != nullptr) {
        std::cout << current->data << " ";
        current = current->next;
    }
}


int median(Node *head){
    int size = 0, index, count = 0, firstMiddle = 0; 

    //traverse list to get number of elements
    Node* current = head;
        while(current != nullptr){
            ++size;
            current = current->next;
        }
        
        bool isEven = (size % 2 == 0);
        index = size / 2;
            
    //reset current position
    current = head; 
 
    // Traverse the list again 
    while (current != nullptr) {
        if (isEven && count == index - 1){
            firstMiddle = current->data;
        }
        if (count == index) {
            if(isEven){
                return (firstMiddle + current->data) / 2;
            } else{
                return current->data;
        }
    }
        current = current->next; 
        count++;
    }
        return 0;
    }


    Node* getHead(){
        return head;
    }

};


int main(){
    //initilize list
    LinkedList list;

    Node *head = nullptr;
    list.insert(10);
    list.insert(20);
    list.insert(30);
    list.insert(40);
    //list.insert(50);

    list.print();

    cout << "\nMedian of list is: " << list.median(list.getHead()) << endl;

    cout << "testing!!!" << endl;
     
}