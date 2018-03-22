#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
unsigned long long fac[21]={1,1,2,6,24,120,720,5040,40320,362880,3628800,39916800,479001600,6227020800,87178291200,1307674368000,20922789888000,355687428096000,6402373705728000,121645100408832000,2432902008176640000};

int main() {
    int t;
    scanf("%d",&t);
    for(int i=0;i<t;i++){
        int n;
        unsigned long long r;
        scanf("%d%llu",&n,&r);
        int s=1,l=min(n,20),mid;
        int fit;
        while(1){
            if(r>=fac[20]){
                fit=20;
                break;
            }
            if(s+1==l){
               
                if(r==fac[l]){
                    fit=l;
                }
                else{
                    fit=s;
                }
                break;
            }
            mid=(s+l)/2;
            if(fac[mid]>r){
                l=mid;
            }
            else if(fac[mid]<r){
                s=mid;
            }
            else {
                fit=mid;
                break;
            }
        }
        long long int k=r/fac[fit];
        r%=fac[fit];
        if(r==0){
            if(k==1){
            k=k*fit-1;
            fit--;
            r=fac[fit];
            }
            else{
                k--;
                r=fac[fit];
            }
        }
        int x=n-fit-1;
        printf("(");
        for(int i=0;i<x;i++){
            printf("%d",i+1);
            if(i!=x-1)
                printf(",");
        }
        bool num[64]={0};
        int t=-1;
        for(int j=0;j<n-x;j++){
            if(num[x+j]==0){
                t++;
            }
            if(t==(int)k){
                num[x+j]=1;
                if(x>0)
                    printf(",");
                printf("%d",x+j+1);
                break;
            }
        }
        for(int i=fit-1;i>=1;i--){
            long long int k=r/fac[i];
            r%=fac[i];
            if(r==0){
                k--;
                r=fac[i];
            }
            int t=-1;
            for(int j=0;j<n-x;j++){
                if(num[x+j]==0){
                    t++;
                }
                if(t==(int)k){
                    num[x+j]=1;
                    printf(",%d",x+j+1);
                    break;
                }
            }
            
        }
        for(int j=0;j<n-x;j++){
            if(num[x+j]==0){
                printf(",%d",x+j+1);
                break;
            }
        }
        printf(")\n");
        
    }
    return 0;
}
