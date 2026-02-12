#include <iostream>

int power2(int x, int n){
    //base case
    if(n == 1) return x;

    return x * power2(x, n-1);
}

int main (){
    std::cout << power2(5,4) << std::endl;
}