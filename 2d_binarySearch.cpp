#include <iostream>
#include <vector>

using namespace std;

// struct Index{
//     int rowIndex=-1;
//     int colIndex=-1;
// };

bool binary_search(vector<vector<int>> arr,int target){
    int rows=arr.size();
    int cols=arr[0].size();
    int low=0;
    int high=rows*cols-1;
    int mid,rowIndex,colIndex;

    while(low<=high){
        mid=low+(high-low)/2;
        rowIndex=mid/cols;
        colIndex=mid%cols;

        if(arr[rowIndex][colIndex]==target){
            return true;
        }
        else if(arr[rowIndex][colIndex]>target){
            high=mid-1;
        }
        else{
            low=mid+1;
        }
    }
    return false;
}

int main()
{
    vector<vector<int>> arr{{1,2,3,4},{5,6,7,8},{9,10,11,12},{13,14,15,16}};
    int target=20;
    auto ans=binary_search(arr,target);

    if(ans){
        cout<<"Element found\n";
    }
    else{
        cout<<"Element not found\n";
    }
}