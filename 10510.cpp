#include <iostream>
#include <string>
#define N 1000000007LL
using namespace std;

long long int fun(string);

int main() {
    string a;
    while(cin>>a){
        cout<<fun(a)<<endl;
    }
    return 0;
}

long long int fun(string a){
    //find '+'
    int tag=0;
    for(int i=0;i<a.length();++i){
        if(a[i]=='(')
            tag++;
        if(a[i]==')')
            tag--;
        if(a[i]=='+' && !tag){
            string b;
            b.assign(a,0,i);
            a.erase(a.begin(), a.begin()+i+1);
            return ( (fun(a)%N) + (fun(b)%N) )%N;
        }
    }
    //find '*'
    tag=0;
    for(int i=0;i<a.length();++i){
        if(a[i]=='(')
            tag++;
        if(a[i]==')')
            tag--;
        if(a[i]=='*' && !tag){
            string b;
            b.assign(a,0,i);
            a.erase(a.begin(), a.begin()+i+1);
            return ( (fun(a)%N) * (fun(b)%N) )%N;
        }
    }
    //erase '(' & ')'
    if(a[0]=='(' && *(a.end()-1)==')'){
        a.erase(a.begin(),a.begin()+1);
        a.erase(a.end()-1,a.end());
        return (fun(a)%N);
    }
    
    //return the one digit number
    return a[0]-'0';
}
