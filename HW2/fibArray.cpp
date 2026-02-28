#include <iostream>

int* makeFibAr(int n){
    //check for valid answer
    if(n <= 0) return nullptr;

    int* fibArray = new int[n];

    //easily known numbers
    if(n >= 1) fibArray[0] = 0;
    if(n >= 2) fibArray[1] = 1;

    for(int i = 2; i < n; ++i){
        //add last two numbers
        fibArray[i] = fibArray[i-1] + fibArray[i-2];
    }
    return fibArray;
}

//must pass ptr by refrence to actually set the original ptr to nullptr
void deallocateArray(int*& allocatedArr){

    delete[] allocatedArr;
    allocatedArr = nullptr;
    std::cout << "deleted allocated memory!" << std::endl;
}


int main(){
    int n = 10;
    int* ptr = makeFibAr(n);

    std::cout << "printing array: " << std::endl;

    for(int i = 0; i < n; ++i){
        std::cout << ptr[i] << std::endl;
    }

    deallocateArray(ptr);

    if(ptr == nullptr) std::cout << "Succesfully deleted memory" << std::endl;
}