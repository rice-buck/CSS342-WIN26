#include <vector>
#include <iostream>


// std::vector <int> multiply(std::vector<int> v1, std::vector<int> v2){
//     std::vector <int> topVec;
//     std::vector<int> botVec;
//     std::vector <int> resultVec;

//     if(v1.size() >= v2.size() ){
//         topVec = v1;
//         botVec = v2;
//     } else {
//         topVec = v2;
//         botVec = v1;
//     }
//     //multiply vectors with "grade school algorithm"
//     for(int i = 0;  i < botVec.size(); ++i){
//         for(int j = 0; j < topVec.size(); ++j){
//             resultVec.push_back(botVec[i] * topVec[j]);
            
//         }
//     }
//     return resultVec;
// }

std::vector<int> multiply(std::vector<int> a, std::vector<int> b) {
  if ((a.size() == 1 && a[0] == 0) || (b.size() == 1 && b[0] == 0)) {
        return {0};
    }
  int n = a.size();
  int m = b.size();
  // Maximum size of product is n + m digits
  std::vector<int> result(n + m, 0);

  // Grade-school multiplication
  for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
          result[i + j] += a[i] * b[j];
      }
  }

  // Handle carries
  int carry = 0;
  for (int i = 0; i < result.size(); i++) {
      int total = result[i] + carry;
      result[i] = total % 10;
      carry = total / 10;
  }

  // Remove leading zeros (from most significant side)
  while (result.size() > 1 && result.back() == 0) {
      result.pop_back();
  }

  return result;
}

int main(){
    std::vector <int> numsVec = {4, 5 , 0, 1};

    std::vector <int> numsVec2 = {6, 7, 8, 5};



    for (const auto& num : numsVec) {
        std::cout << num << " ";
    }

    std::cout << "\n" << std::endl;

    for (const auto& num : numsVec2) {
        std::cout << num << " ";
    }

    std::vector <int> productVec = multiply(numsVec, numsVec2);

    std::cout << "\n" << std::endl;

    for (const auto& num : productVec) {
        std::cout << num << " ";
    }
}

