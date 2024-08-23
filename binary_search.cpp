#include <iostream>
#include <vector>

using namespace std;

int binary_search(vector<int> arr,int target){
    int low=0;
    int high=arr.size()-1;

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

int main(){
    vector<int> arr{1,2,3,4,5,6};
    int target=7;

    int ans=binary_search(arr,target);

    if(ans==-1){
        cout<<"Element not found "<<endl;
    }
    else{
        cout<<"Found element at: "<<ans<<endl;
    }
}