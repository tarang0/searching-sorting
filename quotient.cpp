#include <iostream>
using namespace std;

// finds only the before decimal part

int findQuotient(int dividend,int divisor){
    int low=0;
    int high=abs(dividend);
    int mid,ans;

    while(low<=high){
        mid=low+(high-low)/2;

        if(abs(mid*divisor)==abs(dividend)){
            ans=mid;
            break;
        }
        else if(abs(mid*divisor)>abs(dividend)){
            high=mid-1;
        }
        else{
            ans=mid;
            low=mid+1;
        }
    }
    if(!((dividend>0 && divisor>0 ) || (dividend<0 && divisor<0))){
        ans=ans*(-1);
    }
    return ans;
}
int main(){
    int dividend=-36;
    int divisor=6;
    int ans=findQuotient(dividend,divisor);
    cout<<"Quotient is "<<ans<<endl;

}