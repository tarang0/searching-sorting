#include <iostream>
#include <vector>

using namespace std;


int binary_search(vector<int> arr,int target){

    int low=0;
    int high=arr.size()-1;
    int mid;

    while(low<=high){
        mid=low+(high-low)/2;
        if(arr[mid]==target){
            return mid;
        }
        else if(mid-1>=low && arr[mid-1]==target){
            return mid-1;
        }
        else if(mid+1<=high && arr[mid+1]==target){
            return mid+1;
        }

        else if(arr[mid]>target){
            high=mid-2;
        }
        else{
            low=mid+2;
        }
    }
    return -1;
}

int main()
{
    vector<int> arr{10,3};
    int target=10;
    int ans=binary_search(arr,target);
    if(ans!=-1){
        cout<<"Element "<<target<<" found at index: "<<ans<<endl;
    }
    else{
        cout<<"ELement not found"<<endl;
    }

}