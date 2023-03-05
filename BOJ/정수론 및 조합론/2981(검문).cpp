#include <iostream>
#include <string>
#include <stack>
#include <math.h>
using namespace std;

long long int gcd(long long int a,long long int b){
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

    int n;
    cin>>n;
    long long int *arr=new long long int[n-1],tmp,tmp2;

    cin>>tmp;

    for(int i=0;i<n-1;i++){
        cin>>tmp2;

        if(tmp>tmp2){
            arr[i]=tmp-tmp2;
        }
        else{
            arr[i]=tmp2-tmp;
        }
    }

    long long int g;

    if(n==2){
        g=arr[0];
    }
    else{
        if(arr[0]<arr[1]){
            g=gcd(arr[1],arr[0]);
        }
        else{
            g=gcd(arr[0],arr[1]);
        }

        for(int i=2;i<n-1;i++){
            g=gcd(g,arr[i]);
        }

    }
    
    stack<long long int> ans;

    for(int i=2;i<=sqrt(g);i++){
        if(g%i==0){
            cout<<i<<" ";
            ans.push(i);
        }
    }

    while(ans.size()>0){
        if(g/ans.top()!=ans.top()){
            cout<<g/ans.top()<<" ";
        }
        ans.pop();
    }
    cout<<g;

    delete[] arr;

    return 0;
}