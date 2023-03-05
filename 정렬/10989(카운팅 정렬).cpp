#include <iostream>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    //c++의 표준 stream의 동기화를 끊는 역할을 하여 입출력의 속도를 높인다.

    int n;
    cin>>n;

    int count[10001]={0};

    for(int i=0;i<n;i++){
        int tmp;
        cin>>tmp;
        count[tmp]+=1;
    }

    for(int i=1;i<10001;i++){
        for(int j=0;j<count[i];j++){
            cout<<i<<'\n';
            //endl은 실행 시 출력 버퍼를 지워주는 flush()함수를 호출하기 때문에
            //\n을 넣는 것보다 속도가 느리다.
        }
    }

    return 0;
}