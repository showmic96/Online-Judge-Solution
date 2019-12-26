// In the name of Allah the Most Merciful.

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

struct data{

    string name;
    ll l , r;

    data(string _name , ll _l , ll _r){

        name = _name;
        l = _l;
        r = _r;
    }
};

vector<data>v;

char ar[10101];

int main(void)
{
    int t;
    scanf("%d",&t);
    bool blank = false;

    while(t--){

        if(blank)printf("\n");blank = true;

        v.clear();

        int n;
        scanf("%d",&n);

        for(int i=0;i<n;i++){

            scanf("%s",&ar);
            string temp(ar , strlen(ar));
            ll in1 , in2;
            scanf("%lld %lld",&in1 ,&in2);
            v.push_back(data(temp , in1 , in2));
        }

        int q;
        scanf("%d",&q);

        while(q--){

            ll in;
            scanf("%lld",&in);

            string ans = "";
            int counter = 0;

            for(int i=0;i<n;i++){

                if(in>=v[i].l&&in<=v[i].r){

                    ans = v[i].name;
                    counter++;
                }
            }

            if(counter==1){

                int si = ans.size();

                for(int i=0;i<si;i++)printf("%c",ans[i]);

                printf("\n");
            }

            else printf("UNDETERMINED\n");
        }
    }

    return 0;
}
