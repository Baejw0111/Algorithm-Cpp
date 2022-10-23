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

void preorder(char root){
    if(root=='.'){
        return;
    }
    cout<<root;
    preorder(tree[root].first);
    preorder(tree[root].second);
}

void inorder(char root){
    if(root=='.'){
        return;
    }
    inorder(tree[root].first);
    cout<<root;
    inorder(tree[root].second);
}

void postorder(char root){
    if(root=='.'){
        return;
    }
    postorder(tree[root].first);
    postorder(tree[root].second);
    cout<<root;
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

    preorder('A');
    cout<<endl;
    inorder('A');
    cout<<endl;
    postorder('A');
    cout<<endl;

    return 0;
}