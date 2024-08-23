#include <iostream>
using namespace std;
// The ceil index is the index of the smallest element in the array that is 
// greater than or equal to a given target value.

int ceilIndex(int arr[], int n, int target) {
    int left = 0;
    int right = n - 1;
    int ceil = -1;

    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (arr[mid] == target)
            return mid;
        else if (arr[mid] < target)
        {
            left = mid + 1;
            ceil = mid;
        }
        else{
            right = mid - 1;
        }
    }

    return ceil;
}

int main(){
    int arr[]={1,2,5,7,9};
    int n=sizeof(arr)/sizeof(arr[0]);
    int target=6;
    int ans=ceilIndex(arr,n,target);
    if(ans!=-1){
        cout<<"ceil index of "<<target<<" : "<<ans<<endl;
    }
    else{
        cout<<"No smaller element than "<<target<<endl;
    }
}