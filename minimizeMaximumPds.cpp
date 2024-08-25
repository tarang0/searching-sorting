#include <iostream>
#include <vector>
using namespace std;

bool isValidDistribution(vector<int> quantities,int product,int stores){
    int storeCount=0;
    for(int i=0;i<quantities.size();i++){
        storeCount=storeCount+quantities[i]/product;

        if(quantities[i]%product!=0){
            storeCount++;
        }

        if(storeCount>stores){
            return false;
        }
    }

    return true;
}

int minimizeMaximum(vector<int> quantities,int stores){
    // low=1 to avoid divide by zero error
    int low=1;
    int high=0;
    for(int k:quantities){
        if(k>high){
            high=k;
        }
    }
    int ans=-1;
    while(low<=high){
        int mid=low+(high-low)/2;
        if(isValidDistribution(quantities,mid,stores)){
            ans=mid;
            high=mid-1;
        }
        else{
            low=mid+1;
        }
    }
    return ans;
}
int main(){
    // vector<int> quantities{15,10,10};
    // int stores=7;
    vector<int> quantities{1,4,4};
    int stores=3;
    int ans=minimizeMaximum(quantities,stores);

    cout<<"Minimized maximum of quantities assigned is: "<<ans<<endl;
}