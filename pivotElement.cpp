#include <iostream>
#include <vector>

using namespace std;


int pivotElement(vector<int> arr){
    int low=0;
    int high=arr.size()-1;
    int mid;

    while(low<=high){
        mid=low+ (high-low)/2;
        if(low==high){
            return low;
        }
        if(arr[mid]>arr[mid+1] && mid+1<=high){
            return mid;
        }
        else if(arr[mid-1]>arr[mid] && mid-1>=low){
            return mid-1;
        }

        else if(arr[0]>arr[mid]){
            high=mid-1;
        }
        else if(arr[0]<arr[mid]){
            low=mid+1;
        }
    }
    return -1;
}
int main(){
    vector<int> arr{9,10,2,3,4,6,7};
    // if mid is 10
    // mid > mid+1 return mid

    // if mid is 2
    // mid-1> mid return mid-1
    int ans=pivotElement(arr);
    if(ans==-1)
        cout<<"element not found\n";
    else{
    cout<<" Pivot element is "<<arr[ans]<<" with index "<<ans<<endl;
    }
}