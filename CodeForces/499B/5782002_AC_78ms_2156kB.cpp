#include<stdio.h>
#include<string.h>
int main(void)
{
    int a,b,k[20],m[20],i,j;

    scanf("%d %d",&a,&b);
    char c[b+1][20],d[b+1][20],z[a+1][20],l[b+1][20];
    for(i=0;i<b;i++)
    {
        scanf("%s",&c[i]);
        scanf("%s",&d[i]);
        k[i]=strlen(c[i]);
        m[i]=strlen(d[i]);

        if(k[i]>m[i])
        {
           strcpy(l[i],d[i]);
        }
        else
        {
            strcpy(l[i],c[i]);

        }

    }
    for(i=0;i<a;i++)
    scanf("%s",&z[i]);


for(i=0;i<a;i++)
{
    for(j=0;j<b;j++)
    {
        if(strcmp(c[j],z[i])==0)
        {
            strcpy(z[i],l[j]);
        }
        else if(strcmp(d[j],z[i])==0)
        {
            strcpy(z[i],l[j]);
        }
    }
}
for(i=0;i<a;i++)
    printf("%s ",z[i]);
    printf("\n");

return 0;

}