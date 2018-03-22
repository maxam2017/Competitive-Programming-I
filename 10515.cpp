#include <iostream>

using namespace std;

void fun( int *ans,int *f,int *g,int pos ,int num,int l){
    if(num<=32){
       for(int i=0;i<num;i++){
            for(int j=0;j<num;j++){
                ans[l+i+j]+=f[pos+i]*g[pos+j];
            }
        }
    }
    else{
        int s=(num+1)/2;
         int *temp1=new  int [2*s-1](),*temp2=new  int [num/2*2-1]();
        //ll
        int p=2*pos , w=pos+s;
        int *a=new int[s](),*b=new int[s]();
        for(int i=0;i<s;i++){
            a[i]=f[pos+i];
            b[i]=g[pos+i];
        }
        fun(temp1,a,b,0,s,0);
        for(int i=0;i<2*s-1;i++){
            ans[p+i]+=temp1[i];
           ans[w+i]-=temp1[i];
        }
        //hh
        int q=(pos+s)*2;
        int *d=new int[num/2](),*e=new int[num/2]();
        for(int i=0;i<num/2;i++){
            
            d[i]=f[w+i];
            e[i]=g[w+i];
        }
        fun(temp2,d,e,0,num/2,0);
        for(int i=0;i<num/2*2-1;i++){
            
            ans[q+i]+=temp2[i];
            ans[w+i]-=temp2[i];
        }
         //l+h h+l
         int *r=new int [s](),*t=new int [s]();
         for(int i=0;i<s;i++){
         if(s+i<num)
             r[i]=f[pos+i]+f[pos+s+i];
         else
             r[i]=f[pos+i];
         }
         
         for(int i=0;i<s;i++){
         if(s+i<num)
             t[i]=g[pos+i]+g[pos+s+i];
         else
             t[i]=g[pos+i];
         }
         int *temp3=new  int[2*s-1]();
         fun(temp3,r,t,0,s,0);
        for(int i=0;i<2*s-1;i++){
            ans[w+i]+=temp3[i];
        }
        delete [] temp1;
        delete [] temp2;
        delete [] temp3;
        delete [] a;
        delete [] b;
        delete [] d;
        delete [] e;
    }
}

int main() {
    int n;
    cin>>n;
    for(int i=0;i<n;i++){
        int t;
        cin>>t;
        if(t<=0)
            continue;
        int *p=new int [t],*q=new int [t];
        int *ans=new  int [2*t-1]();
        for(int i=0;i<t;i++){
            cin>>p[i];
        }
        for(int i=0;i<t;i++){
            cin>>q[i];
        }
        fun(ans,p, q,0,t,0);
        
        cout<<ans[0];
        for(int i=1;i<2*t-1;i++){
            cout<<' '<<ans[i];
        }
        cout<<endl;
        delete [] ans;
        delete [] p;
        delete [] q;
    }
    return 0;
}
