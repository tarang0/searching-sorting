#include <iostream>
#include <vector>

// using binary search
using namespace std;


void findMissing(vector<int> arr,int target){
    int low=0;
    int high=arr.size()-1;
    int ans=-1;
    int mid;

    while(low<=high){
        mid=(low+high)/2;
        int el=arr[mid];
        

        if(el-mid==2){
            cout<<"Index: "<<mid<<" element "<<arr[mid]<<endl;
            ans=mid+1;
            high=mid-1;
        }
        else if(el-mid==1){
            low=mid+1;
        }
        // else if(arr[mid]>target){
        //     high=mid-1;
        // }
    }
    cout<<ans<<endl;
}
int main(){
    vector<int> arr{1,2,3,4,5,6,7,8,9};
    int max_range=9;
    findMissing(arr,max_range);
}