#include <iostream>
#include <cmath>
using namespace std;

int sum=0;
bool ch(int a[9][9],int r,int c){
    for(int i=0;i<9;i++)
        if(a[r][i]==2 || a[i][c]==1 || a[i][c]==2 )
            return false;
    for(int i=0;i<9;i++){
        for(int j=0;j<9;j++){
            if(abs(i-r)==abs(j-c) && i!=r && (a[i][j]==1 || a[i][j]==2))
                return false;
        }
    }
    return true;
}


void fun(int a[9][9],int row){
    if(row==9){
        sum++;
    }
    else{
        for(int i=0;i<9;i++){
            if(a[row][i]==2){
                fun(a,row+1);
                break;
            }
            else if(ch(a,row,i)){
                a[row][i]=1;
                fun(a,row+1);
                a[row][i]=0;
            }
        }
    }
    return ;
}


int main() {
    int n;
    
    cin>>n;
    for(int i=0;i<n;i++){
        int r,c;
        sum=0;
        cin>>r>>c;
        int a[9][9]={{0}};
        a[r-1][c-1]=2;
        fun(a,0);
        cout<<sum<<endl;
    }
    
    return 0;
}
