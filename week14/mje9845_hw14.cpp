#include <iostream>
#include <vector>
using namespace std; 

//pass vector starting index low and ending index high to findMinMax function 
//recursively divide array into two halves until we have one or two elements, Then compare
//minimum and maxiumum of each half and combine them to find the min and max of whole array 
//result is stored in minMax and returned by func 

vector<int> findMinMax(vector<int>& arr, int low, int high); 
//vector<int> divideAndConquer (const vector<int>& minMax1, const vector<int>& minMax2);
int main(){
    vector<int> arr {1,2,3,4,5,2,4,5,6};
    int n = arr.size(); 
    //vector<int> minMax = findMinMax(vector, 0, n - 1); 
    vector<int> minMax = findMinMax(arr, 0, n - 1);

    cout << "Minimum value = " << minMax[0] << ", Maximum Value = " << minMax[1];

    return 0;

}

vector<int> findMinMax(vector<int>& arr, int low, int high) {
    vector<int> minMax(2);//global vec of size 2
    int mid = (low + high) / 2;
    //high = low + 1;

    //base case: if there is one element
    if(low == high){
        minMax[0] = arr[low]; 
        minMax[1] = arr[low];
        return minMax; 
    }
    //two elements
    if(high == low + 1){
        if (arr[low] < arr[high]) {
            minMax[0] = arr[low];
            minMax[1] = arr[high];
        } 
        else {
            minMax[0] = arr[high];
            minMax[1] = arr[low];
        }
        return minMax;
    }
    vector<int> leftMinMax = findMinMax(arr, low, mid);
    vector<int> rightMinMax = findMinMax(arr, mid + 1, high);

    //compare the minimum of the left half with the minimum of the right half
    if (leftMinMax[0] < rightMinMax[0]) {
        minMax[0] = leftMinMax[0];
    }
    else{
        minMax[0] = rightMinMax[0];
    }

    //compare the maximum of the left half with the maximum of the right half
    if (leftMinMax[1] > rightMinMax[1]) {
        minMax[1] = leftMinMax[1];
    } 
    else{
        minMax[1] = rightMinMax[1];
    }
    return minMax;
}