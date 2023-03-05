#include <iostream>
using namespace std;

//음계

int main(){
    int arr[8];

    for(int i=0;i<8;++i){
        cin>>arr[i];
    }

    int i=1;
    if(arr[0]==1){
        for(;i<8;++i){
            if(arr[i]!=arr[i-1]+1){
                break;
            }
        }
        if(i==8){
            cout<<"ascending";
        }
        else{
            cout<<"mixed";

        }
    }
    else if(arr[0]==8){
        for(;i<8;++i){
            if(arr[i]!=arr[i-1]-1){
                break;
            }
        }
        if(i==8){
            cout<<"descending";
        }
        else{
            cout<<"mixed";

        }
    }
    else{
        cout<<"mixed";
    }

    return 0;
}