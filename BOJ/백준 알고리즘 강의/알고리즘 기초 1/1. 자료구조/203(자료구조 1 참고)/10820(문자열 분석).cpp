#include <iostream>
#include <string>
using namespace std;

int main(){
    string str;
    while(getline(cin,str)){
        int a[4]={0};

        for(int i=0;i<str.length();i++){
            if(str[i]>='a' && str[i]<='z'){
                a[0]+=1;
            }
            else if(str[i]>='A' && str[i]<='Z'){
                a[1]+=1;
            }
            else if(str[i]>='0' && str[i]<='9'){
                a[2]+=1;
            }
            else if(str[i]==' '){
                a[3]+=1;
            }
        }

        for(int i=0;i<4;i++){
            cout<<a[i]<<" ";
        }

        cout<<endl;
    }


    return 0;
}