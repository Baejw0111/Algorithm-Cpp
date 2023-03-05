#include <iostream>
using namespace std;

//시계 방향으로 90도 회전하는 행렬
void rotate(int mat1[7][7],int mat2[7][7],int n){
  for(int i=0;i<n;++i){
    for(int j=0;j<n;++j){
      mat2[i][j]=mat1[n-1-j][i];
    }
  }
}

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  int test_case;
  int T;

  cin>>T;
  
  for(test_case = 1; test_case <= T; ++test_case){
    int n;

    //입력 받는 행렬
    int mat[7][7]={0};

    //각각 90도, 180도, 270도 회전한 행렬
    int rot90[7][7]={0};
    int rot180[7][7]={0};
    int rot270[7][7]={0};
    
    cin>>n;
    
    for(int i=0;i<n;++i){
      for(int j=0;j<n;++j){
        cin>>mat[i][j];
      }
    }

    rotate(mat,rot90,n);
    rotate(rot90,rot180,n);
    rotate(rot180,rot270,n);

    cout<<'#'<<test_case<<'\n';
    for(int i=0;i<n;++i){
      for(int j=0;j<n;++j){
        cout<<rot90[i][j];
      }
      cout<<' ';
      
      for(int j=0;j<n;++j){
        cout<<rot180[i][j];
      }
      cout<<' ';
      
      for(int j=0;j<n;++j){
        cout<<rot270[i][j];
      }
      cout<<'\n';
      
    }
  }
  return 0;
}