#include <iostream>
using namespace std; 

int sortedSearch(int srtArr[], int srtArrSize, int val);

int main(){
    int srtArr[10] = {1,3,5,7,9,11,13,15,17,19};
    cout<<sortedSearch(srtArr, 10,13)<<endl; //expected to get index of 13 6

    return 0; 
}

int sortedSearch(int srtArr[], int srtArrSize, int val){
    int low, high, mid; 
    int ind; 
    bool found; //flags value
    low = 0; 
    high = srtArrSize -1; 
    found = false; 

    while((found == false) && (low <= high)){
        mid = (low + high) / 2; 
        if(srtArr[mid] == val ){//compare val to middle post
            ind = mid; 
            found = true;
        }
        else if(val < srtArr[mid])
            high = mid - 1; //change the mid is less than 
        else // val is greater than the srtArr[mid]
            low = mid + 1; 
        }
    if(found == true)
        return ind; 
    else
        return -1;
}
