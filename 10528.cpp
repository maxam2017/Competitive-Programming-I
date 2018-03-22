#include <cstdio>
using namespace std;
int main(){
    int t,n,x,y;
    bool tag,zero;
    long long p,s;
    scanf("%d",&t);
    for(int i=0;i<t;i++){
        tag=0,zero=0;
        p=1,x=0,y=0;
        scanf("%d",&n);
        for(int j=0;j<n;j++){
            scanf("%lld",&s);
            p*=s;
            if(p==0){
                zero=1;
                for(int k=j+1;k<n;k++){
                    scanf("%lld",&s);
                }
                break;
            }
            if(!tag && p>=10000)
                tag=1;
            if(tag){
                while(p%10==0){
                    p/=10;
                }
                while(p%2==0){
                    p/=2;
                    x++;
                }
                while(p%5==0){
                    p/=5;
                    y++;
                }
                if(p>10000)
                    p%=10000;
            }
        }
        if(zero){
            printf("0000\n");
            continue;
        }
        int m=x-y;
        if(m>0){
            while(m--){
                p*=2;
                if(p>10000)
                    p%=10000;
            }
        }
        else if(m<0){
            while(m++){
                p*=5;
                if(p>10000)
                    p%=10000;
            }
        }
        printf("%04lld\n",p);
    }
    return 0;
}
