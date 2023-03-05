#include <iostream>
#include <algorithm>
using namespace std;

#define lli long long int

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    //c++의 표준 stream의 동기화를 끊는 역할을 하여 입출력의 속도를 높인다.

    lli n,m;
    cin>>n;

    lli *arr=new lli[n];

    for(lli i=0;i<n;i++){
        cin>>arr[i];
    }

    sort(arr,arr+n);

    cin>>m;
    for(lli i=0;i<m;i++){
        lli tmp;
        cin>>tmp;

        int left=lower_bound(arr,arr+n,tmp)-arr;
        int right=upper_bound(arr,arr+n,tmp)-arr;

        cout<<right-left<<" ";
    }

}