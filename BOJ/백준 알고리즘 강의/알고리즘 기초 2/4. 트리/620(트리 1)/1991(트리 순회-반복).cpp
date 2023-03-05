#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <queue>
#include <stack>
#include <map>
using namespace std;

#define ll long long

map<char,pair<char,char>> tree;
int n;

void preorder(){
    stack<char> s;

    s.push('A');

    while(!s.empty()){
        char parent=s.top();
        s.pop();
        cout<<parent;

        if(tree[parent].second!='.'){
            s.push(tree[parent].second);
        }
        if(tree[parent].first!='.'){
            s.push(tree[parent].first);
        }
    }
    cout<<endl;
}

void inorder(){
    stack<char> s;

    s.push('A');

    while(tree[s.top()].first!='.'){
        s.push(tree[s.top()].first);
    }

    while(!s.empty()){
        char parent=s.top();
        s.pop();
        cout<<parent;

        if(tree[parent].second!='.'){
            s.push(tree[parent].second);
            while(tree[s.top()].first!='.'){
                s.push(tree[s.top()].first);
            }
        }
    }
    cout<<endl;
}

void postorder(){
    stack<char> s;

    s.push('A');

    while(tree[s.top()].first!='.' || tree[s.top()].second!='.'){
        if(tree[s.top()].first!='.'){
            s.push(tree[s.top()].first);
        }
        else{
            s.push(tree[s.top()].second);
        }
    }

    while(1){
        char child=s.top();
        s.pop();
        cout<<child;

        if(s.empty()){
            break;
        }

        if(tree[s.top()].second!='.' && tree[s.top()].second!=child){
            s.push(tree[s.top()].second);
            while(tree[s.top()].first!='.' || tree[s.top()].second!='.'){
                if(tree[s.top()].first!='.'){
                    s.push(tree[s.top()].first);
                }
                else{
                    s.push(tree[s.top()].second);
                }
            }
        }
    }
    cout<<endl;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin>>n;

    for(int i=0;i<n;++i){
        char parent,child1,child2;
        cin>>parent>>child1>>child2;

        tree[parent]=make_pair(child1,child2);
    }

    preorder();
    inorder();
    postorder();

    return 0;
}