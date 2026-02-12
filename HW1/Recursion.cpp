#include <iostream>


int binary(int n){
    //check if n is negative 
    if(n < 0){
        n = -n;
    }
    //base case 
    if(n == 0){
        return 0;
    }
    //recursive call 
    return (n % 2) + binary(n/2);
}
int main(){
    std::cout << binary(-25) << std::endl;
}



