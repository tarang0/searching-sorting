#include <iostream>
#include <vector>

using namespace std;

void bubbleSort(vector<int> arr){
    bool swapped=false;
    for (int round=1;round<arr.size();round++){
        for(int j=0;j<arr.size()-round;j++){
            if(arr[j]>arr[j+1]){
                swapped=true;
                swap(arr[j],arr[j+1]);
            }
        }
        if(swapped==false){
            cout<<"Loop broken early"<<endl;
            break;
        }
    }
    for(int k:arr){
        cout<<k<<" ";
    }
    cout<<endl;
}


// shit algo
void gandaBubbleSort(vector<int> arr)
{
    for (int i=0;i<arr.size();i++){
        int maxIndex=i;
        cout<<"Round "<<i+1<<endl;
        for(int j=0;j<=arr.size()-1-i;j++){
            if(arr[j]>arr[maxIndex]){
                maxIndex=j;
            }
            else{
                swap(arr[j],arr[maxIndex]);
                maxIndex=j;
            }
            for (int k=0;k<arr.size();k++){
                cout<<arr[k]<<" ";
            }
            cout<<endl;
        }
    }
    
    for(int k: arr){
        cout<<k<<" ";
    }
    cout<<endl;
}
int main()
{
    vector<int> arr{1,2,3,4,5};
    bubbleSort(arr);
}