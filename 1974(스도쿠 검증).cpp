#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <queue>
#include <stack>
#include <map>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int test_case;
    int T;

	cin>>T;
	for(test_case = 1; test_case <= T; ++test_case)
	{
        //입력 받으면서 동시에 판별
        int ans=1;

        //열
        int col[9][9]={0};
        //칸
        int cell[9][9]={0};

        for(int i=0;i<9;++i){
            //행
            int row[9]={0};
            for(int j=0;j<9;++j){
                int tmp;
                cin>>tmp;
                //입력되는 수는 1~9의 수이기 때문에 인덱스 범위인 0~8과 맞춰줄 필요가 있다.
                tmp-=1;

                //검사 과정은 ans가 1일 때, 즉 겹치는 숫자가 없을 때 행한다.
                if(ans){
                    //행 검사
                    if(row[tmp]==0){
                        row[tmp]=1;
                    }
                    else{
                        //중복되는 수가 있음을 의미
                        ans=0;
                        row[tmp]++;
                    }

                    //칸 검사
                    if(cell[i/3*3+j/3][tmp]==0){
                        cell[i/3*3+j/3][tmp]=1;
                    }
                    else{
                        ans=0;
                        cell[i/3*3+j/3][tmp]++;
                    }

                    //열 검사
                    if(col[j][tmp]==0){
                        col[j][tmp]=1;
                    }
                    else{
                        ans=0;
                        col[j][tmp]++;
                    }
                }
            }
        }

        cout<<'#'<<test_case<<" "<<ans<<'\n';
	}

    return 0;
}