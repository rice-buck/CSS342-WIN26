#include <iostream>

int power1(int x, int n){
    int sum;
    
    for(int i = 1; i < n; ++i){
        sum += x * x;
    }
    return sum;
}
int main(){
    std::cout << power1(2, 2) << std::endl;
}