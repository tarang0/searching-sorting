#include <iostream>
#include <vector>
using namespace std;  
   
bool isValidDays(vector<int> bloomDay,int mid,int m,int k){
        int bouqetCount=0;
        int flowerCount=0;
        for(int i=0;i<bloomDay.size();i++){
            if(mid>=bloomDay[i]){
                flowerCount++;
                if(flowerCount==k){
                    flowerCount=0;
                    bouqetCount++;

                    if(bouqetCount==m){
                        return true;
                    }
                }

            } 
            else{
                flowerCount=0;
            }
        }

        return false;
}

int minDays(vector<int> bloomDay, int m, int k) {
    cout<<"hello"<<endl;
        if((m*k)>bloomDay.size()){
            return -1;
        }
    // cout<<"size of vector: "<<bloomDay.size()<<endl;
        int low=bloomDay[0];
        int high=bloomDay[0];
        for(int k:bloomDay){
            if(k<low){
                low=k;
            }
            else if(k>high){
                high=k;
            }
        }
        int ans=high;
        while(low<=high){
            int mid=low+ (high-low)/2;
            cout<<"checking for: "<<mid<<endl;
            if(isValidDays(bloomDay,mid,m,k)){
                ans=mid;
                high=mid-1;
                cout<<"valid days: "<<mid<<endl;
            }
            else{
                low=mid+1;
            }
        }

        return ans;
}

int main(){
    vector<int> bloomDay{1,10,3,10,2};
    int m=3;
    int k=1;

    minDays(bloomDay,m,k);
}