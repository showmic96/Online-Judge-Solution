// In the name of Allah the Most Merciful.

#include<bits/stdc++.h>
using namespace std;

int main(void)
{
    string ans = "";
    for(int i=0;i<26;i++)ans+='A' + i;
    for(int i=0;i<26;i++)ans+='a' + i;

    int n;
    while(scanf("%d",&n)==1){

        printf("2 %d %d\n",n, n);

        for(int i=0;i<2;i++){

            for(int j=0;j<n;j++){

                for(int k=0;k<n;k++){

                    if(i==0)printf("%c",ans[k]);
                    else printf("%c",ans[j]);
                }

                printf("\n");
            }

            printf("\n");
        }
    }

    return 0;
}
