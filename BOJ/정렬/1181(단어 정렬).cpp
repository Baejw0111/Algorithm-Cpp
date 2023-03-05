#include <iostream>
#include <string>
using namespace std;

void swap(string *a,string *b){
    string tmp=*a;
    *a=*b;
    *b=tmp;
}

void heap_adjust(int n,string *a,int s){
    while(s<n){
        int r=s;
        int left=2*s+1,right=2*s+2;
        if(left>=n&&right>=n){
            break;
        }

        if(right<n){
            if((*(a+left)).length()>(*(a+right)).length()){
                if((*(a+left)).length()>(*(a+s)).length()){
                    swap(a+s,a+left);
                    s=left;
                }
                else if((*(a+left)).length()==(*(a+s)).length()){
                    if((*(a+left)).compare(*(a+s))>0){
                        swap(a+s,a+left);
                        s=left;
                    }
                }
            }
            else if((*(a+left)).length()<(*(a+right)).length()){
                if((*(a+right)).length()>(*(a+s)).length()){
                    swap(a+s,a+right);
                    s=right;
                }
                else if((*(a+right)).length()==(*(a+s)).length()){
                    if((*(a+right)).compare(*(a+s))>0){
                        swap(a+s,a+right);
                        s=right;
                    }
                }
            }
            else{
                if((*(a+left)).compare(*(a+right))>0){
                    if((*(a+left)).length()>(*(a+s)).length()){
                        swap(a+s,a+left);
                        s=left;
                    }
                    else if((*(a+left)).length()==(*(a+s)).length()){
                        if((*(a+left)).compare(*(a+s))>0){
                            swap(a+s,a+left);
                            s=left;
                        }
                    }
                }
                else if((*(a+left)).compare(*(a+right))<0){
                    if((*(a+right)).length()>(*(a+s)).length()){
                        swap(a+s,a+right);
                        s=right;
                    }
                    else if((*(a+right)).length()==(*(a+s)).length()){
                        if((*(a+right)).compare(*(a+s))>0){
                            swap(a+s,a+right);
                            s=right;
                        }
                    }
                }
            }
        }
        else{
            if((*(a+left)).length()>(*(a+s)).length()){
                swap(a+s,a+left);
                s=left;
            }
            else if((*(a+left)).length()==(*(a+s)).length()){
                if((*(a+left)).compare(*(a+s))>0){
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

void heap_sort(int n,string *a){
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

    string *arr=new string[n];

    for(int i=0;i<n;i++){
        string tmp;
        int s=1;
        cin>>tmp;
        for(int j=0;j<i;j++){
            if(arr[j]==tmp){
                i--;
                n--;
                s=0;
            }
        }
        if(s){
            arr[i]=tmp;
        }
    }

    heap_sort(n,arr);

    for(int i=0;i<n;i++){
        if(i>0&&arr[i]==arr[i-1]){
            continue;
        }
        else{
            cout<<arr[i]<<'\n';
        }
    }

    return 0;
}