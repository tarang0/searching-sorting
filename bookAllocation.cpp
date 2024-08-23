#include <iostream>
#include <vector>
using namespace std;


bool isPossibleSolution(vector<int> books,int pages,int students){
    int student=1;
    int currPages=0;
    for(int i=0;i<books.size();i++){
        if(books[i]+currPages<=pages){
            currPages+=books[i];
        }
        else{
            student++;
            currPages=books[i];
        }
        if(student>students){
            return false;
        }
    }
    return true;
}
int bookAllocation(vector<int> books,int students){
    if(students>books.size()){
        return -1;
    }

    int minPages=0;
    int maxPages=books[0];
    int ans=-1;
    for(int k:books)    maxPages+=k;
    // sum of all pages is max possible books to be assigned

    int mid;
    while(minPages<=maxPages){
        mid=minPages+(maxPages-minPages)/2;
        if(isPossibleSolution(books,mid,students)){
            cout<<"low at: "<<minPages<<" High at: "<<maxPages<<endl;
            cout<<"Pages possible: "<<mid<<endl;
            maxPages=mid-1;
            ans=mid;
        }
        else{
            cout<<"low at: "<<minPages<<" High at: "<<maxPages<<endl;
            minPages=mid+1;
        }
    }

    cout<<"final ans: "<<ans<<endl;
    return mid;

}
int main(){
    vector<int> books{12,34,67,90};
    int students=2;
    int ans=bookAllocation(books,students);
}