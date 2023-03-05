#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <queue>
#include <stack>
#include <map>
using namespace std;

#define ll long long
const int MAX=10001;

int n,tree[MAX][2]={0},subtree_num[MAX][2]={0},position[MAX]={0},ans[2]={0};

void postorder(int root){
    if(root==-1){
        return;
    }
    int c1=tree[root][0],c2=tree[root][1];
    postorder(c1);
    postorder(c2);

    if(c1==-1&&c2==-1){
        subtree_num[root][0]=0;
        subtree_num[root][1]=0;
    }
    else{
        if(c1!=-1){
            subtree_num[root][0]=subtree_num[c1][0]+subtree_num[c1][1]+1;
        }
        if(c2!=-1){
            subtree_num[root][1]=subtree_num[c2][0]+subtree_num[c2][1]+1;
        }
    }
}

void bfs(int root){
    queue<pair<int,int>> q;//노드,레벨
    q.push({1,root});//레벨,노드
    int cur_level=1,min_node=root,max_node=root,width;

    while(!q.empty()){
        int level=q.front().first,node=q.front().second;
        q.pop();
        if(cur_level==level-1){
            width=position[max_node]-position[min_node]+1;
            if(ans[1]<width){
                ans[0]=cur_level;
                ans[1]=width;
            }
            cur_level=level;
            min_node=node;
            max_node=node;
        }
        else{
            max_node=node;
        }

        int c1=tree[node][0],c2=tree[node][1];
        if(c1!=-1){
            q.push({level+1,c1});
            position[c1]=position[node]-subtree_num[c1][1]-1;
        }
        if(c2!=-1){
            q.push({level+1,c2});
            position[c2]=position[node]+subtree_num[c2][0]+1;
        }

    }

    width=position[max_node]-position[min_node]+1;
    if(ans[1]<width){
        ans[0]=cur_level;
        ans[1]=width;
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin>>n;
    int root=1;

    for(int i=1;i<=n;++i){
        int parent,child1,child2;
        cin>>parent>>child1>>child2;

        tree[parent][0]=child1;
        tree[parent][1]=child2;
    }

    while(1){
        int s=1;
        for(int i=1;i<=n;++i){
            int c1=tree[i][0],c2=tree[i][1];
            if(c1==root || c2==root){
                root=i;
                s=0;
                break;
            }
        }
        if(s){
            break;
        }
    }

    postorder(root);
    bfs(root);

    cout<<ans[0]<<" "<<ans[1];

    return 0;
}