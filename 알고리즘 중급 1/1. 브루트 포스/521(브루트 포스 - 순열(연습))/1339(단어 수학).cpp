#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <queue>
#include <stack>
#include <map>
using namespace std;

#define ll long long

int n,num[10]={0},u[10]={0},ans=0;
string word[10];
vector<char> result[10];
map<char,int> alphabet;

int calculate(){
    int total=0,digit=1;

    for(int i=0;i<10;++i){
        if(result[i].size()==0){
            break;
        }

        int tmp=0;

        for(int j=0;j<result[i].size();++j){
            tmp+=num[alphabet[result[i][j]]];
        }

        total+=digit*tmp;
        digit*=10;
    }

    return total;
}

void permutation(int s){
    if(s==alphabet.size()){
        ans=max(ans,calculate());
        return;
    }
    for(int i=10-alphabet.size();i<10;++i){
        if(!u[i]){
            num[s]=i;
            u[i]=1;
            permutation(s+1);
            u[i]=0;
        }
        else{
            continue;
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin>>n;

    int value=0;
    for(int i=0;i<n;++i){
        cin>>word[i];
        int s=word[i].size();
        for(int j=s-1,k=0;j>=0;--j,k++){
            result[k].push_back(word[i][j]);
            //단어 끝부분(1의 자리)부터 result에 집어넣기
            if(!alphabet.count(word[i][j])){
            //alphabet 맵으로 입력된 각 알파벳들에 숫자 할당하기
                alphabet[word[i][j]]=value;
                value+=1;
            }
        }
    }
    //모든 경우에 수에 대해 최대합 도출

    permutation(0);
    cout<<ans;

    return 0;
}