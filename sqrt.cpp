#include <iostream>
#include <vector>
#include <iomanip>

using namespace std;
int sqrt_BS(int num){
    int low=0;
    int high=num;
    int mid,ans;

    while(low<=high){
        mid= low+(high-low)/2;
        if(mid*mid==num){
            return mid;
        }
        else if(mid*mid>num){
            high=mid-1;
        }
        else{
            ans=mid;
            low=mid+1;
        }
    }
    return ans;
}
int main()
{
    int num=10;
    int ans=sqrt_BS(num);
    // cout<<"SQRT of "<<num<<" is "<<ans<<endl;

    double finalans=ans;
    double step=0.1;
    int precision=7;

    for (int i=0;i<precision;i++){

        for (double j=finalans;j*j<=num;j=j+step){
            finalans=j;
        }
        step=step*0.1;
    }

    cout<<"square root of "<<num<<" is "<<fixed<<setprecision(precision)<<finalans<<endl;
}