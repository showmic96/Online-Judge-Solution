// In the name of Allah the Most Merciful.

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

char ar[1005];
vector<char>v;

int main(void)
{
    int c = 0;
    while(scanf("%s",&ar)==1){

        if(ar[0]=='e')break;

        v.clear();

        for(int i=0;i<strlen(ar);i++){

            char now = ar[i];
            bool check = false;

            for(int j=0;j<v.size();j++){

                if(v[j]>=now){

                    v[j] = now;
                    check = true;
                    break;
                }
            }

            if(check==false){
                v.push_back(now);
            }
        }

        printf("Case %d: %d\n",++c , v.size());
    }

    return 0;
}
