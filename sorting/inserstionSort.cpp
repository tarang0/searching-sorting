#include <iostream>
#include <vector>

using namespace std;


void insertionSort(vector<int> arr){
    int n=arr.size();

    // rounds 1 to n-1
    for (int round=1;round<n;round++){
        // STEP 1- fetch
        cout<<"round "<<round<<endl;
        int val=arr[round];
        int j;
        for (j=round-1;j>=0;j--){

            // STEP -2 compare
            // STEP -3 shift
            if(arr[j]>val){
                cout<<"shifting "<<arr[j+1]<<" with "<<arr[j]<<endl;
                arr[j+1]=arr[j];
            }
            else{
                break;
            }
        }
        // STEP -4 copy
        cout<<"copying "<<val<<endl;
        arr[j+1]=val;

        for (int k: arr){
            cout<<k<<" ";
        }
        cout<<endl;
    }

    for (int k:arr){
        cout<<k<<" ";
    }
    cout<<endl;
}
int main(){
    vector<int> arr{5,4,3,2,1};
    insertionSort(arr);
}