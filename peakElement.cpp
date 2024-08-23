#include <iostream>
#include<vector>
using namespace std;

void mountainElement(vector <int> arr){
    int low=0;
    int high=arr.size()-1;
    int mid;
    
    while (low<=high)
    {
        mid=(low+high)/2;
        cout<<" Mid at index: "<<mid<<" element: "<<arr[mid]<<endl;

        if(arr[mid]>arr[mid-1] && arr[mid]>arr[mid+1]){
            cout<<"Peak element is "<<arr[mid]<<endl;
            return;
        }
        else if(arr[mid]>arr[mid+1]){
            
            high=mid-1;
            cout<<"New high: "<<high<< " element: "<<arr[high]<<endl;
        }
        else if(arr[mid]>arr[mid-1]){
            low=mid+1;
            cout<<"New low: "<<low<< " element: "<<arr[low]<<endl;
        }
    }

    cout<<"No peak found\n";
    
}

int main(){
    vector<int> arr{0,10,5};
    mountainElement(arr);
}