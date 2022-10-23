#include <iostream>
#include <string>
using namespace std;

#define lli long long int

//랜선 자르기

lli *a,n,k;//*a는 k개의 랜선의 길이를 저장할 배열

lli total(lli m){//한 랜선의 길이가 m일 때 만들 수 있는 랜선의 개수 반환
    lli total=0;
    for(int i=0;i<k;++i){
        total+=a[i]/m;
    }

    return total;
}

int binary_search(lli max){//문제에서 요구하는 답 반환
    lli mid,start=1,end=max,ans=0;

    while(start<=end){
        mid=(end+start)/2;

        lli t=total(mid);

        if(t>=n){
            start=mid+1;
            if(ans<mid){
                ans=mid;
            }
        }//원하는 값 나올때까지 더하는 것보다는 이렇게 조건 될때만 갱신하는 게 훨씬 빠르다.
        else if(t<n){
            end=mid-1;
        }
    }

    return ans;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    //c++의 표준 stream의 동기화를 끊는 역할을 하여 입출력의 속도를 높인다.

    lli max=0;//가능한 랜선의 최대 길이
    cin>>k>>n;

    a=new lli[k];

    for(int i=0;i<k;++i){
        cin>>a[i];
        max+=a[i];
    }

    max/=n;//모든 랜선이 하나라고 가정했을 때 n개의 랜선을 만들 수 있는 한 랜선의 최대 길이

    if(total(max)>=n){
        cout<<max;
    }
    else{
        cout<<binary_search(max);
    }

    return 0;
}