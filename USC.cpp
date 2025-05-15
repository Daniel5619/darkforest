#include <iostream>
#include <unordered_map>
#include <string>

int UniqueStringCount(std::string S [], int N){
    int finalCount = 0;
    std::unordered_map <std::string, int> uniqueNum;

    for (int i=0; i<N;i++){
        uniqueNum[S[i]] += 1;
    }

    finalCount = uniqueNum.size();
    
    return finalCount;
}

int main () {
    int n = 0;
    std::string s[] = {"banana", "hamock","pizza","paul","orange", "banana", "paul", "banana", "pizza"};
    
    if (s != nullptr){
        n = sizeof(s) / sizeof(s[0]);
    }

    std::cout << UniqueStringCount(s, n);
    

    return 0;
}