#include <iostream>

int sum(int arr[], int n){
    
    if(n<=1) return arr[0];

    return arr[n-1] + sum(arr, n-1);
}

int sum2(int arr[], int n) {
    if (n == 0) return 0;
    return arr[n - 1] + sum(arr, n - 1);
}
int mystery(int n) {
    if (n == 0) return 0;
    return mystery(n / 2) + 1;
}

int g(int n) {
    if (n == 0) return 0;
    return g(n - 1) + n;
}
int f(int n) {
    if (n <= 1) return 1;
    return f(n - 1) + f(n - 2);
}

int main(){
    int nums[] = {3, 5, 6};
    std::cout << sum(nums, 3) << std::endl;
    std::cout << sum2(nums, 3) << std::endl;
    //std::cout << f(4) << std:: endl;
}
