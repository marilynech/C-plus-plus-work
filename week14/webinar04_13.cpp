#include <iostream>
#include <vector>
using namespace std; 

int linearSearch(vector<int>& v, int toFind){//runtime ;theta(n); 
    for(int i = 0; i < v.size(); i++)
        if(v[i] == toFind)
            return i; 
    return -1;  //for this one it takes 50 years 
}

//gets rid of half of the elements half of the vector with each iteration of the loop 
//each iteration gets rid of a signficant part of the vector 
//if you have a 1000000 in bank how many years does it take to empty bank account: 20
int binarySearch(vector<int>& v, int toFind, int start, int end){//Runtime: theta log n 
    if(start > end)
        return -1; 
    int mid = (start+ end) / 2; 
    if(v[mid] > toFind)
        return binarySearch(v, toFind, 0, mid -1); 
    else if(v[mid]<toFind)
        return binarySearch(v, toFind, mid +1, end); 
    else
        return mid; 
}

//selecting element for a positon 
void selectionSort(vector<int>& v){ //runtime theta n^2;
    for(int i =0; i < v.size(); i++){
        int minIndex = 1; 
        for(int j = i+1; j <v.size(); j++)
            if(v[j] < v[minIndex])
                minIndex = j;
        int temp = v[i];
        v[i] = v[minIndex]; 
        v[minIndex] = temp;
    }
}

void insertionSort(vector<int>& v, int start, int end){ //runtime: best case: theta(n) bc vector is presorted, worst case: theta(n^2)
    for(int i =start + 1; i < end; i++){
        int j=i; 
        int temp = v[j];
        while(j > 0 && v[j -1] > temp){//presorted it then the while loop will happen once 
            v[j]=v[j -1];
            j--;
        }
        v[j] = temp; //move elements backward 
    }
}

void merge(vector<int>& v, vector<int>& temp, int leftStart, int leftEnd, int rightEnd){
    int tempIndex = leftStart;
    int orginalStart = leftStart; 
    int rightStart = leftEnd+1; 
    while(leftStart <= leftEnd && rightStart <= rightEnd){
        if(v[leftStart]< v[rightStart])
            temp[tempIndex++] = v[leftStart++]; 
        else
            temp[tempIndex++] = v[rightStart++]; 
    }
    while(leftStart <= leftEnd)
        temp[tempIndex++] = v[leftStart++]; 
    while(rightStart <= rightEnd)
        temp[tempIndex++] = v[rightStart++]; 
    for(int i = orginalStart; i <= rightEnd; i++)
        v[i] = temp[i];
}

void mergeSort(vector<int>& v, vector<int>& temp, int start, int end){//runtime theta(nlogn)
//space is the downside
    if(start < end);

}

void quicksort(vector<int>& v, int start, int end){//worst case theta(n^2) average: theta(nlogn)
    if((start+10)>end){
        insertionSort(v, start, end);
        return; 
    }
    int center = (start+end) /2; 
    if(v[center]<v[start])
        swap(v[center], v[start]); 
    if(v[end] < v[start])
        swap(v[end], v[start]); 
    if(v[end] < v[start])
        swap(v[end], v[center]);

    int pivot = v[center]; 
    swap(v[center], v[end -1]); 
    int i = start; 
    int j = end -1; 
    for(;;){}//same as while(true)

}

int binarySearch(vector<int>& v, int toFind){//driver
    return binarySearch(v, toFind, 0, v.size() -1);
}