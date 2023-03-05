#include <iostream>
#include <math.h>
using namespace std;

void swap(int *a,int *b){//두 인덱스의 값을 바꾸는 함수
    int tmp=*a;
    *a=*b;
    *b=tmp;
}

void heap_adjust(int n,int *a,int s){//힙 재조정. s는 노드 인덱스 값으로, 해당 노드가 내려가는 걸 계속 추적하며 반복한다.
    while(s<n){
        int r=s;
        int left=2*s+1,right=2*s+2;
        if(left>=n&&right>=n){
            break;
        }

        if(right<n){
            if(*(a+left)>*(a+right)){
                if(*(a+left)>*(a+s)){
                    swap(a+s,a+left);
                    s=left;
                }
            }
            else{
                if(*(a+right)>*(a+s)){
                    swap(a+s,a+right);
                    s=right;
                }

            }
        }
        else{
            if(*(a+left)>*(a+s)){
                swap(a+s,a+left);
                s=left;
            }
        }
        if(s==r){
            break;
        }
    }
}

void heap_sort(int n,int *a){
    for(int i=n/2;i>=0;i--){
        heap_adjust(n,a,i);
    }

    for(int i=n-1;i>0;i--){
        swap(a,a+i);
        heap_adjust(i,a,0);
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    //c++의 표준 stream의 동기화를 끊는 역할을 하여 입출력의 속도를 높인다.

    int n,min,max;
    double total=0;
    cin>>n;

    int *arr=new int[n],count[8001]={0};

    for(int i=0;i<n;i++){
        cin>>arr[i];
        if(i==0){
            max=arr[i];
            min=arr[i];
        }
        else{
            if(max<arr[i]){
                max=arr[i];
            }
            if(min>arr[i]){
                min=arr[i];
            }
        }
        total+=arr[i];
        count[arr[i]+4000]+=1;
    }

    int range=max-min;

    double avg=total/n;
    if(round(avg)==-0){
        cout<<0<<'\n';
        //-1/3을 round로 반올림하면 -0으로 출력되는 문제가 발생함.
    }
    else{
        cout<<round(avg)<<'\n';//산술평균
    }

    heap_sort(n,arr);

    cout<<arr[n/2]<<'\n';//중앙값

    max=0;
    int maxi=0,c=0;
    for(int i=0;i<8001;i++){
        if(count[i]>max){
            max=count[i];
            maxi=i;
            c=0;
        }
        else if(count[i]==max&&c==0){
            c=1;
            maxi=i;
        }
    }

    cout<<maxi-4000<<'\n';//최빈값

    cout<<range<<'\n';//범위

    return 0;
}