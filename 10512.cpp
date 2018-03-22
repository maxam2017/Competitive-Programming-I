#include <iostream>
#include <algorithm>
using namespace std;
int main() {
    int n;
    while(cin>>n){
        if(n==0)
            break;
        long long int sum=0;
        long long int *p=new long long int[n+1](),v;
        for(int i=1;i<=n;i++){
            cin>>v;
            p[i]=p[i-1]+v;//Several previous sum
            
        }
        sort(p, p+n+1);
        
        long long int comp=p[0];
        long long int last=0;
        
        for(int i=0;i<=n;i++){
            
            if(p[i]!=comp){
                long long int t=i-last;
                if(t>1){
                    
                    sum+=(long long int)((t*(t-1))/2);
                }
                last=i;
                comp=p[i];
            }
            else if(i==n && p[i]==comp){
                long long int t=i-last+1;
                if(t>1)
                    sum+=(long long int)((t*(t-1))/2);
            }
            
        }
        delete [] p;
        cout<<sum<<endl;
    }
    
    return 0;

}

