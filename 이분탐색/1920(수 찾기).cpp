#include <iostream>
#include <algorithm>
using namespace std;

template <typename T>
int binary_search(T n,T *a,int length){//이진 탐색 함수. n이 찾는 수이다. length는 배열의 길이다.
    int mid,start=0,end=length-1;
    //배열 길이가 0일 때 end가 length값과 같을 경우 쓰레기 값을 읽을 수 있다.

    while(start<=end){
        mid=(end+start)/2;
        if(a[mid]>n){
            end=mid-1;
        }
        else if(a[mid]<n){
            start=mid+1;
        }
        else{
            return mid;
        }

    }

    return -1;//찾지 못할 경우 -1 반환
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    //c++의 표준 stream의 동기화를 끊는 역할을 하여 입출력의 속도를 높인다.

    int n;
    cin>>n;

    int *arr=new int[n];

    for(int i=0;i<n;i++){
        cin>>arr[i];
    }

    sort(arr,arr+n);

    int m,t;
    cin>>m;

    for(int i=0;i<m;i++){
        cin>>t;

        if(binary_search(t,arr,n)==-1){
            cout<<0<<'\n';
        }
        else{
            cout<<1<<'\n';
        }
    }

    delete[] arr;

    return 0;
}