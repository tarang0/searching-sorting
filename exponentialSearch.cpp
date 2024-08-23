#include <iostream>
#include <vector>
using namespace std;

int binary_search(vector<int> arr,int target,int low,int high){

    int mid;

    while(low<=high){
        mid=(low+high)/2;
        if(arr[mid]==target){
            
            return mid;
        }
        else if(arr[mid]<target){
            low=mid+1;
        }
        else if(arr[mid]>target){
            high=mid-1;
        }
    }
    
    return -1;

}

int exponentialSearch(vector<int> arr,int target){
    // part 1 is to find subarray

    if(arr[0]==target){
        return 0;
    }

    int i=1;
    int n=arr.size();
    while(i<n && arr[i]<=target){
        i=i*2;
    }
    cout<<"low: "<<i/2<<" high: "<<min(i,n-1)<<endl;
    
    return binary_search(arr,target,i/2,min(i,n-1));
}
int main(){
    // vector<int> arr{3,4,5,6,11,13,14,15, 56,70};
    // int target=13;
    vector<int> arr{3,4,5};
    int target =1;
    int ans=exponentialSearch(arr,target);

    if(ans!=-1){
        cout<<"Element: "<<target<<" found at index "<<ans<<endl;
    }
    else{
        cout<<"Element not found "<<endl;
    }
}