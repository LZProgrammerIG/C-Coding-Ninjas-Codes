#include <iostream>
using namespace std;

//Binary Search only works on sorted (increasing order) arrays.

int Binarysearch(int arr[], int n, int target) {
    int start = 0;
    int end = n-1;
    while(start<=end)
    {
        int mid = (start + end)/2;
        if(target == arr[mid])
        {
            return mid;
        }
        else if( target < arr[mid])
        {
            end = mid - 1;
        }
        else {
            start = mid + 1;
        }
    }
    return -1;
}

void printArray(int arr[], int n){
    for (int i=0; i<n; i++){
        cout << arr[i] << " ";
    }
    cout << endl;
}

/*
By using recursion

int Search(int input[], int si, int ei, int x){
    //Base Case
    if (si>ei){
        return -1;
    }

    //Main Code
    int mid=(si+ei)/2;

    if (input[mid]==x){
        return mid;
    }else if(input[mid]>x){
        ei=mid-1;
        Search(input,si,ei,x);
    }else{
        si=mid+1;
        Search(input,si,ei,x);
    }
}



int binarySearch(int input[], int size, int element) {
    int startIndex=0;
    int endIndex=size-1;
    Search(input,startIndex,endIndex,element);

}
*/

int main(){
    int arra[7]={1, 2, 2, 3, 3, 12, 45};
    printArray(arra,7);
    int s=Binarysearch(arra,7,2);
    cout << "The position of required element is :- " << s << endl;

    return 0;
}
