#include <iostream>
#include <string>
using namespace std;

int main(){
    string str;
    cin>>str;
    int a[26]={0};

    for(int i=0;i<str.length();i++){
        a[str[i]-'a']+=1;
    }

    for(int i=0;i<26;i++){
        cout<<a[i]<<" ";
    }

    return 0;
}