#include <iostream>
#include <vector>

using namespace std;
// all elements occur even number of times except 1
// all repeating elements occur in pairs
// pairs are not adjacent 
// ex- 22 55 22 44 55

// find element that appears odd number of times


int findOdd(vector<int> arr){
    int low=0;
    int high=arr.size()-1;
    int mid;

    while(low<=high){
        mid=low+(high-low)/2;

        if(low==high){
            return low;
        }
        else if(mid%2==0 ){
            if(arr[mid]==arr[mid+1]){
                low=mid+2;
            }
            else{
                // return mid;
                // 2 case: either element is odd occuring or we are in right side
                high=mid;
            }
        }
        else if(mid%2!=0){
            if(arr[mid]==arr[mid+1]){
                high=mid-1;
            }
            else{
                low=mid+1;
            }
        }
    }
    return -1;
}
int main()
{
    // vector<int> arr{1,1,2,2,4,4,5,5,7,7,3,600,600,4,4,1,1,100,100};
    vector<int> arr{4,4,5,5};
    // [1,1,2,2,3,3,4,4,3,600,600,4,4]
    // [0,1,2,3,4,5,6,7,8,9,10,11,12]
    // 1, 1 ,2
    // APPROACH-1: XOR everything only 1 will remain- O(n)
    int ans=findOdd(arr);
    if(ans!=-1){
        cout<<"odd occurring element at index: "<<ans<<" element: "<<arr[ans]<<endl;
    }
    else{
        cout<<"No Odd occuring element"<<endl;  
    }
}