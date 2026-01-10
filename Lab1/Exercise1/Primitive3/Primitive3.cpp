//Author: Rhys B
#include <vector> 
#include <iostream>
#include <cmath>

//functions
void myRoundingFunction(double num){
    int answer = 0;
    double integerPart;
    double fractional = std::modf(num, &integerPart);

    //for positive values
    if(num > 0){ 
        if( fractional >= 0.5 ) answer = std::ceil(num);
     else {answer = floor(num);}
    }

    //for negative values
    if(num < 0){
        if(fractional <= -0.5) answer = floor(num);
     else {answer = ceil(num);}
    }
    std::cout << "Unrounded number = " << num << " Rounded number = " << answer << std::endl;
}

int main(){
std::vector<double>myNums = {1.2, 1.5, 1.7, 1.9, -1.3, -1.6, -1.5, -1.9};
for (int i = 0; i < myNums.size(); i++){
    myRoundingFunction(myNums[i]);
    }
}