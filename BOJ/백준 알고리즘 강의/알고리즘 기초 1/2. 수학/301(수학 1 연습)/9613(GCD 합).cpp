#include <iostream>
#include <string>
using namespace std;

long int gcd(long int a,long int b){
    if(a%b==0){
        return b;
    }
    else{
        return gcd(b,a%b);
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    //c++의 표준 stream의 동기화를 끊는 역할을 하여 입출력의 속도를 높인다.

    int t;
    cin>>t;

    for(int i=0;i<t;i++){
        int n;
        cin>>n;
        long int *arr=new long int[n],total=0;

        for(int j=0;j<n;j++){
            cin>>arr[j];
        }

        for(int j=0;j<n-1;j++){
            for(int k=j+1;k<n;k++){
                long int a=arr[j],b=arr[k];
                if(a<b){
                    long int tmp=a;
                    a=b;
                    b=tmp;
                }

                total+=gcd(a,b);
            }
        }
        cout<<total<<endl;
        delete[] arr;
    }

    return 0;
}