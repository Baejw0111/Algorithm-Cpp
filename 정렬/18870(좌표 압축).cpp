#include <iostream>
using namespace std;

template <typename T>
void swap(T *a,T *b){//두 인덱스의 값을 바꾸는 함수
    T tmp=*a;
    *a=*b;
    *b=tmp;
}

template <typename T>
void heap_adjust(int n,T *a,int s){//힙 재조정. s는 노드 인덱스 값으로, 해당 노드가 내려가는 걸 계속 추적하며 반복한다.
    while(s<n){//s가 부모 노드가 된다
        int r=s;//s가 바뀌었는지 확인하기 위한 변수
        int left=2*s+1,right=2*s+2;//왼쪽 자식, 오른쪽 자식 노드의 인덱스
        if(left>=n&&right>=n){//두 인덱스 모두 범위를 벗어날 경우 반복문 종료
            break;
        }

        if(right<n){//오른쪽 자식 노드가 범위 내일 경우
            if(*(a+left)>*(a+right)){//왼쪽 노드가 오른쪽 노드보다 더 클 경우
                if(*(a+left)>*(a+s)){//왼쪽 노드를 부모 노드와 비교
                    swap(a+s,a+left);
                    s=left;
                }
            }
            else{
                if(*(a+right)>*(a+s)){//아니면 오른쪽 노드를 부모 노드와 비교
                    swap(a+s,a+right);
                    s=right;
                }

            }
        }
        else{//왼쪽 자식 노드만 범위 내에 있을 경우
            if(*(a+left)>*(a+s)){//왼쪽 노드를 부모 노드와 비교
                swap(a+s,a+left);
                s=left;
            }
        }
        if(s==r){
            break;
        }
    }
}

template <typename T>
void heap_sort(int n,T *a){
    for(int i=n/2;i>=0;i--){//adjust 알고리즘을 n/2번 실행해 완전 이진트리 힙 구성
        heap_adjust(n,a,i);
    }

    for(int i=n-1;i>0;i--){//adjust 알고리즘을 n-1번 실행해 힙을 오름차순으로 재구성
        swap(a,a+i);
        heap_adjust(i,a,0);
    }
}

template <typename T>
int binary_search(T n,T *a,int start,int end){//이진 탐색 함수.n이 찾는 수이다. start에 첫 인덱스를, end에 전체 데이터 개수를 넣으면 됨.
    int mid;

    while(1){
        mid=(end+start)/2;
        if(start==end||a[mid]==n){
            break;
        }

        if(a[mid]>n){
            end=mid;
        }
        else if(a[mid]<n){
            start=mid+1;
        }
    }

    if(a[mid]==n){
        return mid;
    }
    else{
        return -1;
    }

}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    //c++의 표준 stream의 동기화를 끊는 역할을 하여 입출력의 속도를 높인다.

    int n,m;
    cin>>n;
    m=n;

    int *arr=new int[n],*sorted=new int[n];

    for(int i=0,j=0;i<n;i++,j++){
        cin>>arr[i];
        sorted[j]=arr[i];
    }

    heap_sort<int>(n,sorted);

    for(int i=0,j=0;i<n;i++,j++){
        if(i>0 && sorted[i]==sorted[i-1]){
            j--;
            m--;
            continue;
        }
        sorted[j]=sorted[i];
    }

    for(int i=0;i<n;i++){
        cout<<binary_search<int>(arr[i],sorted,0,m)<<' ';
    } 

    delete[] arr;
    delete[] sorted;
}