#include <iostream>
#include <time.h>
using namespace std;

struct coor{
    int x,y;
};

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
            if((a+left)->x>(a+right)->x){//왼쪽 노드의 x 좌표가 오른쪽 노드보다 더 클 경우
                if((a+left)->x>(a+s)->x){//왼쪽 노드의 x 좌표가 부모 노드보다 더 클 경우
                    swap(a+s,a+left);
                    s=left;
                }
                else if((a+left)->x==(a+s)->x){//왼쪽 노드의 x 좌표가 부모 노드와 같을 경우
                    if((a+left)->y>(a+s)->y){//y 좌표 비교
                        swap(a+s,a+left);
                        s=left;
                    }
                }
            }
            else if((a+left)->x<(a+right)->x){//왼쪽 노드의 x 좌표가 오른쪽 노드보다 작을 경우
                if((a+right)->x>(a+s)->x){//오른쪽 노드의 x좌표를 부모노드와 비교
                    swap(a+s,a+right);
                    s=right;
                }
                else if((a+right)->x==(a+s)->x){//x좌표가 같을 경우
                    if((a+right)->y>(a+s)->y){//y좌표와 비교
                        swap(a+s,a+right);
                        s=right;
                    }
                }
            }
            else{//왼쪽 노드의 x좌표와 오른쪽 노드의 x좌표가 동일할 경우
                if((a+left)->y>(a+right)->y){
                    if((a+left)->x>(a+s)->x){//왼쪽 노드의 x좌표를 부모 노드와 비교
                        swap(a+s,a+left);
                        s=left;
                    }
                    else if((a+left)->x==(a+s)->x){//왼쪽 노드의 x 좌표가 부모 노드와 같을 경우
                        if((a+left)->y>(a+s)->y){//y 좌표 비교
                            swap(a+s,a+left);
                            s=left;
                        }
                    }
                }
                else{
                    if((a+right)->x>(a+s)->x){//오른쪽 노드의 x좌표를 부모노드와 비교
                        swap(a+s,a+right);
                        s=right;
                    }
                    else if((a+right)->x==(a+s)->x){//x좌표가 같을 경우
                        if((a+right)->y>(a+s)->y){//y좌표와 비교
                            swap(a+s,a+right);
                            s=right;
                        }
                    }
                }
            }
        }
        else{//왼쪽 자식 노드만 범위 내에 있을 경우
            if((a+left)->x>(a+s)->x){//왼쪽 노드의 x좌표를 부모 노드와 비교
                swap(a+s,a+left);
                s=left;
            }
            else if((a+left)->x==(a+s)->x){//같을 경우
                if((a+left)->y>(a+s)->y){//y좌표를 비교
                    swap(a+s,a+left);
                    s=left;
                }
            }
        }
        if(s==r){
            break;
        }
    }
}

template <typename T>
void heap_sort(int n,T *a){
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

    int n;
    cin>>n;

    coor *arr=new coor[n];

    for(int i=0;i<n;i++){
        cin>>arr[i].x>>arr[i].y;
    }

    heap_sort<coor>(n,arr);

    for(int i=0;i<n;i++){
        cout<<arr[i].x<<" "<<arr[i].y<<'\n';
    }

    delete[] arr;
    return 0;
}