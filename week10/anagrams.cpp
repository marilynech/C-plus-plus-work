#include <iostream>
#include <string>
using namespace std; 

bool areAnagrams(string str1, string str2){
    int A[26] = {0};
    int B[26] = {0};\
    int len1= str1.length();
    int len2 = str2.length();

    for(int i = 0; i < len1; i++){
        A[str1[i]- 'a']++;
        B[str2[i]- 'a']++;
    }
    for(int i = 0; i < 26; i++){
        if(A[i] != B[i]){
            return false; 
        }
    }
    return true; 
}