#include <iostream>
#include <algorithm>
#include <string>
#include <stack>
using namespace std;

int arr[1000001]={0};

void opt(int n){
    if(n%6==0){
        arr[n]=min(min(arr[n/3],arr[n/2]),arr[n-1])+1;
    }
    else if(n%3==0){
        arr[n]=min(arr[n/3],arr[n-1])+1;
    }
    else if(n%2==0){
        arr[n]=min(arr[n/2],arr[n-1])+1;
    }
    else{
        if(n==1){
            return;
        }
        else{
            arr[n]=arr[n-1]+1;
        }
    }
}

int main(){
    int n;
    cin>>n;

    for(int i=1;i<=n;i++){
        opt(i);
    }

    cout<<arr[n];

    return 0;
}