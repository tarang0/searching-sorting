#include <iostream>
#include <vector>

using namespace std;
bool checkWood(vector<long long int> heights,long long int check,long long int wood){
    long long int totalwood=0;
    for(long long int i=0;i<heights.size();i++){
        if(heights[i]>check){
            totalwood=totalwood+(heights[i]-check);

            if(totalwood>=wood) return true;
        }
    }
    return false;
}
long long int findWood(vector<long long int> heights,long long int check){
    long long int wood=0;
    for(long long int i=0;i<heights.size();i++){
        if(heights[i]>check){
            wood=wood+(heights[i]-check);
        }
    }
    return wood;
}
long long int maxHeight(vector<long long int> heights,long long int wood){
    long long int low=0;
    long long int high=0;
    for(long long int k:heights){
        if(k>high)  high=k;
    }

    long long int ans=-1;
    while(low<=high){
        long long int mid=low+(high-low)/2;
        // cout<<"checking for "<<mid<<" foundwood: "<<woodFound<<endl;
        if(checkWood(heights,mid,wood)){
            ans=mid;
            low=mid+1;
        }
        else{
            high=mid-1;
        }
    }
    // while(low<=high){
    //     long long int mid=low+(high-low)/2;
    //     long long int woodFound=findWood(heights,mid);
    //     cout<<"checking for "<<mid<<" foundwood: "<<woodFound<<endl;
    //     if(woodFound==wood){
    //         ans=mid;
    //         break;
    //     }
    //     else if(woodFound>wood){
    //         low=mid+1;
    //     }
    //     else{
    //         high=mid-1;
    //     }
    // }

    return ans;
}
int main(){
    // vector<long long int> heights{20,15,10,17};
    // long long int wood=7;
    // vector<long long int> heights{4,42,40,26,46};
    // long long int wood=20;
    long long int n,m;
    cin>>n>>m;
    vector<long long int> heights;
    while(n--){
        long long int val;
        cin>>val;
        heights.push_back(val);
    }
    long long int ans=maxHeight(heights,m);
    // cout<<" Max Height to be set to cut "<<wood <<" metres is: "<<ans<<endl;
    cout<<ans<<endl;
}