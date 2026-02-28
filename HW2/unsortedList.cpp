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

    
void deleteLargest(Node *head){
    //find max
    int max = 0;
    Node* current = head; 

    while(current != nullptr){
        if(current->data > max) max = current->data;
        current = current->next;
    }

    cout << "Max Value: " << max << endl;
    //if head node is the largest
    while(head != nullptr && head->data == max){
        Node *temp = head;
        head = head->next;
        delete temp;
    }

    current = head;
    Node *prev = nullptr;

    while(current != nullptr){
        if (current->data == max){

            prev->next = current->next;
            delete current;
            current = prev->next;
        } else {
            prev = current;
            current = current->next;
        }
    }
}

Node* getHead(){
        return head;
    }

};


int main(){
    //initilize list
    LinkedList list;

    list.insert(60);
    list.insert(50);
    list.insert(90);
    list.insert(10);
    list.insert(20);


    list.print();

    cout << "\n" << endl;

    list.deleteLargest(list.getHead());

    cout << "Deleting largest value " << endl;

    list.print();
    
     
}