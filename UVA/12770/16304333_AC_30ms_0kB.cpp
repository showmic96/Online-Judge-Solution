// In the name of Allah the Most Merciful.

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

char ar[505];

void print(string s)
{
    for(int i=0;i<s.size();i++)printf("%c",s[i]);
    printf("\n");
}

int main(void)
{
    while(scanf("%s",&ar)==1){

        if(ar[0]=='#')break;

        int fr[26];
        memset(fr , 0 , sizeof(fr));
        string ans = "";

        int odd = 0;

        for(int i=0;i<strlen(ar);i++)fr[ar[i]-'a']++;
        for(int i=0;i<26;i++)if(fr[i]%2==1)odd++;

        for(int i=0;i<26;i++){

            if(odd>1&&fr[i]%2==1){

                odd--;
                ans+='a'+i;
            }
        }

        if(ans.size()!=0)print(ans);
        else printf("\n");
    }
    return 0;
}
