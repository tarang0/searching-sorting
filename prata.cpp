#include <iostream>
#include <vector>
using namespace std;
bool isValidTime(vector<int> ranks,int mid,int pratas){
    int totalPratas=0;
    for(int i=0;i<ranks.size();i++){
        int timeLapse=0;
        int curPratas=1;
        cout<<" for rank: "<<ranks[i]<<endl;
        while (true){
            timeLapse=timeLapse+ curPratas*ranks[i];
            if(timeLapse<=mid){
                curPratas++;
                totalPratas++;
                if(totalPratas>=pratas){
                    return true;
                }
            }
            else{
                cout<<"pratas made: "<<totalPratas<<endl;
                break;
            }   
        } 
    }
    return false;
}
int prataSpoj(vector<int> ranks,int pratas){
    // min time and max time to cook pratas
    int low=0;
    int high=(ranks[0]*pratas*(pratas+1))/2;
    int ans=-1;
    while (low<=high)
    {
        int mid=low+(high-low)/2;
        cout<<"checking for minutes: "<<mid<<endl;
        if(isValidTime(ranks,mid,pratas)){
            cout<<mid<<" minutes valid"<<endl;
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
    // vector<int> ranks{1,2,3,4};
    // int pratas=10;
    vector<int> ranks{1,1,1,1,1,1,1,1};
    int pratas=8;
    int ans=prataSpoj(ranks,pratas);

    cout<<" Min time: "<<ans<<" to cook "<<pratas<<endl;
}