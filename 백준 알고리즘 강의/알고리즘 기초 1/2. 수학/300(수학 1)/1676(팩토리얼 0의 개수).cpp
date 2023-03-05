#include <iostream>
#include <string>
using namespace std;

int main(){
    int n,two=0,five=0,tmp;
    cin>>n;

    for(int i=2;i<=n;i++){
        tmp=i;
        if(tmp%10==0){
            while(tmp%10==0){
                two++;
                five++;
                tmp/=10;
            }
        }

        if(tmp%2==0){
            while(tmp%2==0){
                two++;

                tmp/=2;
            }
        }
        else if(tmp%5==0){
            while(tmp%5==0){
                five++;

                tmp/=5;
            }
        }
    }

    if(two>five){
        cout<<five;
    }
    else{
        cout<<two;
    }

    return 0;
}