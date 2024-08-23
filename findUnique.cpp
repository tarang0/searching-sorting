#include <iostream>
#include<vector>

using namespace std;

 int singleNonDuplicate(vector<int>& nums) {
    // 1,1,2,3,3
    // 0,1,2,3,4
    int low=0;
    int high=nums.size()-1;
    int mid;
    while(low<=high){
        for(int i=low;i<=high;i++){
            cout<<nums[i]<<" ";
        }
        mid=low+(high-low)/2;
        if(low==high){
            return low;
        }
        else if(mid%2==0){
            if(nums[mid]!=nums[mid+1]){
                high=mid;
            }
            else{
                low=mid+1;
            }
        }

        else{
            if(nums[mid]!=nums[mid+1]){
                low=mid+1;
            }
            else{
                high=mid-1;
            }
        } 
        
        cout<<endl;  
    }
    return -1;
        
}
int main(){
    // vector<int> num{1,1,2,3,3,4,4,8,8};
    vector<int> num{1};
    int ans=singleNonDuplicate(num);
    cout<<"Index: "<<ans<<" Element: "<<num[ans]<<endl;
}