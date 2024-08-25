#include <iostream>
#include <vector>
using namespace std;

bool validSolution(vector<int> pos, int distance, int cows){
    int currCow=1;
    int currPos=pos[0];
    for(int i=1;i<pos.size();i++){
        if(pos[i]-currPos>=distance){
            currCow++; 
            // cow placed
            currPos=pos[i];
        }
        if(currCow==cows) return true;
    }

    return false;
}
int aggressiveCows(vector<int> pos,int cows){
    int low=1;
    int high=pos[pos.size()-1]-pos[0];
    int ans=-1;
    while(low<=high){
        int mid=low+(high-low)/2;
        if(validSolution(pos,mid,cows)){
            ans=mid;
            low=mid+1;
        }
        else{
            high=mid-1;
        }
    }

    return ans;
}
int main(){
    vector<int> positions{1,2,5,8,9};
    int cows=3;
    int ans=aggressiveCows(positions,cows);
    cout<<ans<<endl;
}