#include <iostream>
#include <vector>
using namespace std;

int bs(vector<int> nums,int target){
    int low=0;
    int high=nums.size()-1;
    int mid;
    while(low<=high){
        mid=low+(high-low)/2;
        if(nums[mid]==target){
            return mid;
        }
        else if(nums[mid]>target){
            high=mid-1;
        }
        else{
            low=mid+1;
        }
    }
    return -1;
}
vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        
    vector<int> ans;
    int i=0;
    while(ans.size()<k){
        int target=i+x;
        cout<<" i is "<<i<<endl;
        cout<<"Searching for "<<target<<endl;
        int index=bs(arr,target);
        if(index!=-1){
            ans.push_back(arr[index]);
        }
        if(i==0){
            i=-1;
        }
        else if (i>0){
            i++;
            i=i*(-1);
        }
        else{
            i=i*(-1);
        }
    }
    for(auto k: ans){
        cout<<k<<" ";
    }
    cout<<endl;
    return ans;
}

vector<int> twoPtrMethod(vector<int> arr,int k,int x){
    int low=0;
    int high=arr.size()-1;
    while(high-low>=k){
        if(x-arr[low]>arr[high]-x){
            low++;
        }
        else{
            high--;
        }
    }

    vector<int> ans;
    for (int i=low;i<=high;i++){
        ans.push_back(arr[i]);
        cout<<arr[i]<<" ";
    }
    cout<<endl;
    return ans;
}
int lowerBound(vector<int> arr,int target){
    int low=0;
    int high=arr.size()-1;
    int ans=high; 
    //  3 5 8 10 no lower bound will be found since trget greater than greatest of array element
    // that's why ans=-1 changed to high

    while(low<=high){
        int mid=low+(high-low)/2;
        if(arr[mid]==target){
            ans=mid;
            break;
        }
        if(arr[mid]>target){
            // cout<<"mid: "<<arr[mid]<<" greater than equal to target: "<<target<<endl;
            ans=mid;
            high=mid-1;
        }
        else if(target>arr[mid]){
            // cout<<"mid: "<<arr[mid]<<" less than target: "<<target<<endl;
            low=mid+1;
        }
    }
    return ans;

}

vector<int> binarySearchMethod(vector<int> arr,int k,int x){
    int high=lowerBound(arr,x);
    cout<<"lower bound: "<<arr[high]<<endl;
    int low=high-1;
    cout<<"low: "<<arr[low]<<endl;
    while(k--){
        if(low<0){
            high++;
        }
        else if(high>arr.size()-1){
            low--;
        }
        else if(x-arr[low]>arr[high]-x){
            cout<<x-arr[low]<<" greater than  "<<arr[high]-x<<endl;
            high++;
        }
        else{
            low--;
        }
    }
    vector<int> result;
    for (int i = low + 1; i < high; i++) {
        result.push_back(arr[i]);
    }

    return result;
}
int main(){
    // vector<int> arr{1,2,3,4,5};
    // int k=4;
    // int x=-1;
    vector<int> arr{3,5,8,10};
    int k=2;
    int x=15;
    for(int y:arr)  cout<<y<<" ";
    cout<<endl;
    // vector<int> arr{12,16,22,30,35,39,42,45,48,50,53,55,56};
    // int k=4;
    // int x=35;
    // vector<int> ans=findClosestElements(arr,k,x);
    // vector<int> ans=twoPtrMethod(arr,k,x);
    vector<int> result = binarySearchMethod(arr, k, x);
    for (int num : result) {
        cout << num << " ";
    }
    cout << endl;

}

// approach-1 
// loop till ans array is less than k
// loop through 0 to k-1 (i) 
// find all elements that are equal to i+x

// approach-2
// 2 pointer method