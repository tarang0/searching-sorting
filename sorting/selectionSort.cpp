#include <iostream>
#include <vector>
using namespace std;


void selectionSort(vector<int> arr)
{
    for (int i=0;i<arr.size();i++){
        int min=arr[i];
        for(int j=i;j<arr.size();j++){
            if(arr[j]<min){
                min=arr[j];
            }
        }
        swap(min,arr[i]);
    }

    for (int k:arr){
        cout<<k<<" ";
    }
    cout<<endl;
}
int main(){
    vector<int> arr{1,2,3,4,5};
    selectionSort(arr);
}