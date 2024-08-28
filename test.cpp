#include <iostream>
using namespace std;


void change(int arr[5]){
    arr[0]=5;
}
int main(){
    int arr[5]={1,2,3,4,5};
    change(arr);
    cout<<arr[0]<<endl;
}