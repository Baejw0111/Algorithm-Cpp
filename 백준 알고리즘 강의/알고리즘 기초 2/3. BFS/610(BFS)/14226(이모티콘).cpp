#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <queue>
using namespace std;

#define ll long long
const int MAX=2000;

int s,emo_num[MAX][MAX]={0};
//화면의 이모티콘 개수, 클립보드 이모티콘 개수
//모두 복사, 모두 붙여넣기, 삭제

void bfs(){
    queue<pair<int,int>> q;

    q.push({1,0});

    while(!q.empty()){
        int num=q.front().first,clip=q.front().second,new_num;
        q.pop();

        new_num=num-1;
        if(new_num>=0 && emo_num[new_num][clip]==0){//삭제
            q.push({new_num,clip});
            emo_num[new_num][clip]=emo_num[num][clip]+1;

            if(new_num==s){
                cout<<emo_num[new_num][clip]<<'\n';
                return;
            }
        }

        if(clip>0){//클립보드가 비어있지 않을 경우에만 붙여넣기 실행
            new_num=num+clip;
            if(new_num<MAX && emo_num[new_num][clip]==0){
                q.push({new_num,clip});
                emo_num[new_num][clip]=emo_num[num][clip]+1;

                if(new_num==s){
                    cout<<emo_num[new_num][clip]<<'\n';
                    return;
                }
            }
        }

        //복사
        if(emo_num[num][num]==0){
            q.push({num,num});
            emo_num[num][num]=emo_num[num][clip]+1;
        }
        
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin>>s;

    bfs();

    return 0;
}