
#include <iostream>
using namespace std;

//검증수

int main(){
    int tmp,ans=0;
    for(int i=0;i<5;++i){
        cin>>tmp;
        ans+=tmp*tmp;
    }

    cout<<ans%10;

    return 0;
}