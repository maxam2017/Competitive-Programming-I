#include <iostream>
#include <cstdio>
using namespace std;
long long int sum=0;
void solve(int *a,int n){
    if(n<=1)
        return;
    solve(a,n/2);
    solve(a+n/2,(n+1)/2);
    int *temp=new int[n]();
    int l=0,r=n/2;
    for(int i=0;i<n;i++){
        if(a[l]>a[r]){
            temp[i]=a[r];
            r++;
            sum+=n/2-l;
        }
        else{
            temp[i]=a[l];
            l++;
        }
        if(l==n/2){
            for(int j=r;j<n;j++){
                i++;
                temp[i]=a[j];
            }
            break;
        }
        if(r==n){
            for(int j=l;j<n/2;j++){
                i++;
                temp[i]=a[j];
            }
            break;
        }
    }
    for(int i=0;i<n;i++){
        a[i]=temp[i];
    }
    delete []temp;
}
int main() {
    int n;
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        ::sum=0;
        int t;
        scanf("%d",&t);
        int *a=new int[t];
        for(int i=0;i<t;i++){
            scanf("%d",&a[i]);
        }
        solve(a,t);
        printf("%lld\n",sum);
        delete []a;
    }
    return 0;
}
