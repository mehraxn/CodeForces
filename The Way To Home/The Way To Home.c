#include<stdio.h>
int main(){
    int n,d,p=0,j=0,i,k,t;
    char s[101];
    if(scanf("%d%d",&n,&d)!=2)
        return 0;
    scanf("%s",s);
    while(p<n-1){
        k=-1;t=p+d;if(t>n-1)t=n-1;
        for(i=t;i>p;--i)if(s[i]=='1')
        {k=i;break;}
        if(k<0)
        {printf("-1");return 0;}
        p=k;j++;
    }
    printf("%d",j);
    return 0;
}