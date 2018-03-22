#include <cstdio>
using namespace std;
int main(){
    int t,n,q,k,x;
    scanf("%d",&t);
    for(int i=0;i<t;i++){
        int rec[30][50000];
        scanf("%d%d",&n,&q);
        int v;
        for(int j=0;j<n;j++){
            scanf("%d",&v);
            rec[0][j]=v-1;
        }
        for(int j=1;j<30;j++){
            for(int k=0;k<n;k++)
                rec[j][k]=rec[j-1][rec[j-1][k]];
        }
        for(int j=0;j<q;j++){
            int t=0;
            scanf("%d%d",&k,&x);
            x--;
            while(k>0){
                if(k&1){
                    x=rec[t][x];
                }
                k>>=1;
                t++;
            }
            x++;
            printf("%d\n",x);
        }
    }
    return 0;
}

