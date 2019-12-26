// In the name of Allah the Most Merciful.

#include<bits/stdc++.h>
using namespace std;

int main(void)
{
    int t;
    scanf("%d",&t);
    for(int i=0;i<t;i++){

        int n , m , k;
        scanf("%d %d %d",&n , &m , &k);

        int ar[n][k];

        for(int j=0;j<n;j++){

            for(int l=0;l<k;l++){

                scanf("%d",&ar[j][l]);
            }
        }

        int p;

        scanf("%d",&p);
        map<int , int>mp;

        bool is_there[m+1];
        memset(is_there , false , sizeof(is_there));

        for(int j=0;j<p;j++){

            int in;
            scanf("%d",&in);
            is_there[in] = true;
        }

        for(int j=1;j<=m;j++){

            if(is_there[j]==true)mp[j] = 1;
            else mp[-j] = 1;
        }

        bool ans = true , found = false;

        for(int j=0;j<n;j++){

            found = false;

            for(int l=0;l<k;l++){

                if(mp[ar[j][l]]==1){found=true;break;}
                //cout << ar[j][l] << endl;
            }

            ans = found;

            if(found==false)break;
        }

        if(ans==false)printf("Case %d: No\n",i+1);
        if(ans==true)printf("Case %d: Yes\n",i+1);
    }
    return 0;
}
