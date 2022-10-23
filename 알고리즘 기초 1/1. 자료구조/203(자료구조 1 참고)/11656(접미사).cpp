#include <iostream>
#include <string>
using namespace std;

void swap(string *a,string *b){//두 인덱스의 값을 바꾸는 함수
    string tmp=*a;
    *a=*b;
    *b=tmp;
}

void quick_sort(string *a,int left,int right){//퀵 정렬. left에 첫 인덱스, right에 데이터 크기를 넣으면 된다.
    string *pivot=a+left;
    int i=left,j=right;

    if(left<right){//해당 조건 불만족 시 재귀 종료
        do{
            do{
                i++;
            }while(i<right && (*(a+i)).compare(*pivot)<0);

            do{
                j--;
            }while((*(a+j)).compare(*pivot)>0);

            if(i<j){
                swap(a+i,a+j);
            }

        }while(i<j);
        swap(a+j,pivot);
        quick_sort(a,left,j);
        quick_sort(a,j+1,right);
    }
}

int main(){
    string str;
    cin>>str;

    string s[str.length()];

    for(int i=0;i<str.length();i++){
        s[i]=str.substr(i);
    }

    quick_sort(s,0,str.length());

    for(int i=0;i<str.length();i++){
        cout<<s[i]<<endl;
    }

    return 0;
}