#include <iostream>

int power3(int x, int n){
    //base case
    if(n == 0) return 1;
 
    int half = power3(x, n / 2);
        if(n % 2 == 0) return half * half;
        else return x * half * half;
}

int main(){
    std::cout << power3(5, 9) << std::endl;
}