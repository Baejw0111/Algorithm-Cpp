#include <iostream>
#include <queue>
using namespace std;

struct dir{
    int x;//시간
    char c;//방향
};

struct snake{
    int x,y;
    snake(int x_,int y_){
        x=x_;
        y=y_;
    }

	snake operator+(snake &ref)
	{
		return snake(x+ref.x, y+ref.y);
	}
};

struct Board{
    int **b;

    int Boundary(snake s,int n){
        if(s.x<0||s.x>=n||s.y<0||s.y>=n){
            return 1;
        }

        return 0;
    }

    int Current(snake s){
        return b[s.x][s.y];
    }

    void Body(snake s){
        b[s.x][s.y]=-1;
    }

    void Empty(snake s){
        b[s.x][s.y]=0;
    }
};

int main(){
    int n;
    cin>>n;

    Board B;
    B.b=new int*[n];
    for(int i=0;i<n;i++){
        B.b[i]=new int[n]();
    }

    int k;//사과(1)
    cin>>k;
    for(int i=0;i<k;i++){
        int x,y;
        cin>>x>>y;

        B.b[x-1][y-1]=1;
    }

    int l;//방향 변환
    cin>>l;
    queue<dir> trans;

    for(int i=0;i<l;i++){
        dir tmp;
        cin>>tmp.x>>tmp.c;

        trans.push(tmp);
    }

    int time=0;
    queue<snake> body;//뱀의 몸이 놓여진 곳
    body.push({0,0});
    B.Body({0,0});

    snake compass[4]={{-1,0},{0,1},{1,0},{0,-1}};
    int sdir=1;//뱀의 현재 진행 방향

    if(trans.size()>0 && trans.front().x==time){
        switch(trans.front().x){
        case 'D':
            sdir=(sdir+1)%4;
            break;
        
        case 'L':
            sdir=(sdir+3)%4;
            break;
        }

        trans.pop();
    }

    while(1){
        time++;

        snake next=body.back()+compass[sdir];

        if(B.Boundary(next,n)){
            break;
        }
        else if(B.Current(next)==1){
            body.push(next);
            B.Body(next);
        }
        else if(B.Current(next)==0){
            body.push(next);
            B.Body(next);

            B.Empty(body.front());
            body.pop();
        }
        else{
            break;
        }

        if(trans.size()>0 && trans.front().x==time){
            switch(trans.front().c){
            case 'D':
                sdir=(sdir+1)%4;
                break;
            
            case 'L':
                sdir=(sdir+3)%4;
                break;
            }

            trans.pop();
        }

        // cout<<"time:"<<time<<endl;
        // for(int i=0;i<n;i++){
        //     for(int j=0;j<n;j++){
        //         switch (B.b[i][j])
        //         {
        //         case 0:
        //             cout<<"O";
        //             break;
        //         case 1:
        //             cout<<"M";
        //             break;
        //         case -1:
        //             cout<<"X";
        //             break;
        //         }
        //     }
        //     cout<<endl;
        // }
        // cout<<endl;
        // cout<<endl;
    }

    cout<<time;
    
    return 0;
}