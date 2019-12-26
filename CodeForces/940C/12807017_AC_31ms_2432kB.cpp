// In the name of Allah the Lord of the Worlds.

#include<bits/stdc++.h>
using namespace std;

char ar[100005];
bool vis[26];
int n , k;

void print(string ar)
{
    for(int i=0;i<ar.size();i++){

        printf("%c",ar[i]);
    }

    printf("\n");
}

string fin_string(int now)
{
    string s = "";

    for(int i=0;i<now;i++){

        s+=ar[i];
    }

    for(int i=0;i<26;i++){

        if(vis[i]==true){

            if(i>ar[now]-'a'){

                s+='a'+i;
                break;
            }
        }
    }

    for(int i=now+1;i<k;i++){

        for(int j=0;j<26;j++){

            if(vis[j]){

                s+='a'+j;
                break;
            }
        }
    }

    return s;
}

string make(string s)
{
    int idx = -1;

    for(int i=0;i<k;i++){

        int temp = ar[k-i-1];

        for(int j=0;j<26;j++){

            if(j+'a'>temp&&vis[j]==true){

                idx = k-i-1;
                break;
            }
        }

        if(idx!=-1)break;
    }

    s = fin_string(max(idx,0));

    return s;
}

string mk(string s)
{
    for(int i=0;i<k-n;i++){

        for(int j=0;j<26;j++){

            if(vis[j]==true){

                s+='a'+j;
                break;
            }
        }
    }

    return s;
}

int main(void)
{
    scanf("%d %d",&n , &k);
    scanf("%s",&ar);

    memset(vis , false , sizeof(vis));

    int si = strlen(ar);
    string s;

    for(int i=0;i<si;i++)s+=ar[i];
    for(int i=0;i<si;i++)vis[ar[i]-'a'] = true;

    if(k>n){

        print(mk(s));
    }

    else{

        print(make(s));
    }

    return 0;
}
