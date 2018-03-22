#include <stdio.h>

int main(void) {
    int n;
    while(scanf("%d",&n) && n!=0){
        int i,a[5]={0};
        for(i=0;i<n;i++){
            scanf("%d",&a[i]);
        }
        int tag=0;
        for(i=0;i<n;i++){
            if(a[i]!=i+1 && a[a[i]-1]!=a[i]){
                tag=1;
                break;
            }
        }
        if(tag)
            printf("no\n");
        else
            printf("yes\n");
    }
    return 0;
}
