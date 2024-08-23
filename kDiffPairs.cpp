#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
using namespace std;


int findPairs(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end());
        int i=0;
        int j=1;
        int pairs=0;
        set <pair<int,int>> ans;
        while (j<nums.size())
        {
            int diff=nums[j]-nums[i];
            if(diff==k){
                pairs++;
                cout<<"pair "<<pairs<<": "<<nums[i]<<" "<<nums[j]<<endl;
                ans.insert({nums[i],nums[j]});
                i++;
                j++;
            }
            else if(diff<k){
                j++;
            }
            else{
                i++;
            }
            if(i==j)    j++;
        }
        return ans.size();
        
    }

int bs(vector<int> nums,int low,int target){
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
int usingBinarySearch(vector<int> nums,int k){
    // after sorting iterate to each element to find out nums[i]+kth element in the right
    // because nums[i]+k-nums[i]=k which is what we are looking for
    sort(nums.begin(),nums.end());
    set<pair<int,int>> allPairs;
    for (int i=0;i<nums.size();i++){
        // fetch nums[i]+k element to form pair for nums[i]
        int target=nums[i]+k;
        int ans=bs(nums,i+1,target);
        if(ans!=-1){
            allPairs.insert({nums[i],nums[ans]});
            // insert all valid pairs in set
            cout<<"Pair "<<nums[i]<<" ,"<<nums[ans]<<endl;
        }
    }

    return allPairs.size();
}

int main(){
    vector<int> nums{3,1,4,1,5};
    int k=2;
    // vector<int> nums{1,1};
    // int k=0;
    // vector<int> nums{1,3,1,5,4};
    // int k=0;
    // 1 1 3 4 5
    // int ans=findPairs(nums,k);
    int ans=usingBinarySearch(nums,k);

    cout<<" Number of pairs are: "<<ans<<endl;
}