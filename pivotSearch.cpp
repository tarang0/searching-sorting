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

int pivotSearch(vector<int> arr,int target){
    int pivotIndex=pivotElement(arr);
    int low,high;

    if(target==arr[pivotIndex]){
        return pivotIndex;
    }
    else if(target>=arr[0]){
        low=0;
        high=pivotIndex-1;
    }
    else{
        low=pivotIndex+1;
        high=arr.size()-1;
    }
    return binary_search(arr,target,low,high);
}


int main(){
    vector<int> arr{8,9,10,2,3,4,6,7};
    int ans=pivotSearch(arr,8);
    
    if (ans==-1){
        cout<<"Element not found\n";
    }
    else{
        cout<<"Element found at index: "<<ans<<endl;
    }
}
