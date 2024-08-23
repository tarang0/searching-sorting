#include <iostream>
#include <vector>

using namespace std;

void firstOccurrence(vector<int> arr, int target){

    int low=0;
    int high=arr.size()-1;
    int ans=-1;
    int mid;

    while(low<=high){
        mid=(low+high)/2;

        if(arr[mid]==target){
            cout<<"Index: "<<mid<<" element "<<arr[mid]<<endl;
            ans=mid;
            high=mid-1;
        }
        else if(arr[mid]<target){
            low=mid+1;
        }
        else if(arr[mid]>target){
            high=mid-1;
        }
    }

    cout<<"Location of target element: "<<ans<<endl;
}

int main(){
    vector<int> arr{1,3,3,3,3,6,7,8};

    firstOccurrence(arr,4);
}