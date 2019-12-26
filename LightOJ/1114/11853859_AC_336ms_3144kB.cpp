// In the name of Allah the Lord of the Worlds.

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

char a[100005] , b[110];
map<string,int>mp;

int main(void)
{
    int t , c = 0;
    scanf("%d",&t);
    while(t--){
        
        mp.clear();
        
        int n;
        scanf("%d",&n);

        getchar();
        for(int i=0;i<n;i++){

            scanf("%s",&b);

            string ar (b , b+strlen(b));

            if(ar.size()>3){

                sort(ar.begin()+1 , ar.end()-1);
            }

            mp[ar]++;
        }

        printf("Case %d:\n",++c);
        int q;

        scanf("%d",&q);
        getchar();

        while(q--){

            ll ans = 1;

            gets(a);

            string ar(a , a+strlen(a));

            stringstream ss(ar);
            string temp;

            while(ss >> temp){

                if(temp.size()>3){

                    sort(temp.begin()+1 , temp.end()-1);

                }

                ans*=mp[temp];
            }

            printf("%lld\n",ans);
        }
    }
    return 0;
}
