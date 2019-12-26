// In the name of Allah the Lord of the Worlds.

#include<bits/stdc++.h>
using namespace std;

const int MAX = 1e6 + 9;

int ar[MAX + 9] , br[MAX + 9];
bool th[MAX + 9];

int main(void)
{
    memset(ar , 0 , sizeof(ar));
    memset(br , 0 , sizeof(br));
    memset(th , true , sizeof(th));

    set<int>st;
    set<int>:: iterator it;

    int n , b , counter = 0;
    scanf("%d %d",&n , &b);

    bool alice = true , bob = true;

    for(int i=0;i<n;i++){

        int in;
        scanf("%d",&in);
        st.insert(in);

        if(in==b)counter++;

        else{

            if(ar[in]<counter)th[in] = false;
            else alice = false;

            ar[in]++;
        }
    }

    if(alice==true){

        printf("-1\n");
        return 0;
    }

    for(it = st.begin() ;it!=st.end();it++){

        if(th[*it]==true){

            if(ar[*it]>=counter){

                printf("%d\n",*it);
                return 0;
            }
        }
    }

    printf("-1\n");

    return 0;
}
