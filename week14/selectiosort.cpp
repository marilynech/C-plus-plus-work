#include <iostream>
using namespace std; 

int findIndexOfMin(int arr[], int low, int high);
void selectionSort(int arr[], int arrSize){
    int i, midInd; 

    for(i = 0; i < arrSize; i++){
        midInd = findIndexOfMin(arr, i, arrSize - 1);
        swap(arr[i], arr[midInd]);
    }
}

int findIndexOfMin(int arr[], int low, int high){
    //accumalte index of min element and minimumm val itself
    int min, minInd;
    int i; 
    min = arr[low];
    minInd = low; 
    for(i = low+1; i <=high; i++){
        if(arr[i]< min){
            min = arr[i]; 
            minInd = i; 
        }
    }
    return minInd; 
}

//selectio sort t(n)= O(n^2) quadratic running time 