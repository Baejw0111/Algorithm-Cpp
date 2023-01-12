#include <iostream>
#include <queue>
using namespace std;

int n,k;

void Josephus(){
    queue<int> ring;
    //순서
    int order=1;

    //1부터 n까지 큐에 넣기
    for(int i=1;i<=n;++i){
        ring.push(i);
    }

    cout<<'<';
    while(!ring.empty()){
        //큐의 가장 앞 원소를 임시 변수에 저장
        int tmp=ring.front();

        ring.pop();

        //k번째 번호 제거 후 출력
        if(order%k==0){
            cout<<tmp;
            if(!ring.empty()){
                cout<<", ";
            }
        }
        else{
            ring.push(tmp);
        }

        order++;
    }

    cout<<'>';
}

int main(){
    cin>>n>>k;

    Josephus();

    return 0;
}