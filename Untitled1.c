#include<stdio.h>
int main()
{
    int N,i,j,a;
    int m[100];
    scanf("%d",&N);
    int min=10000000000000;
    for(i=2;i<=N/2;i++){
        if(N%i==0){
            j=N/i;
            if(j>=10){
            a=(i*100)+j;
            printf("%d\n",a);
            }
            else{
            a=(i*10)+j;
            printf("%d\n",a);
            }
            if(min>a){
                min=a;
            }
        }
    }
    printf("\n\n%d\n",min);
}
