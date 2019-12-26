// In the name of Allah the Lord of the Worlds.

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int ar[27][27];

int main(void)
{
    int t;
    scanf("%d",&t);
    while(t--){

        int n;
        scanf("%d",&n);
        int sn = sqrt(n);

        for(int i=0;i<n;i++){

            for(int j=0;j<n;j++){

                scanf("%d",&ar[i][j]);
            }
        }

        set<int>st;

        bool check = true;

        for(int i=0;i<n;i++){

            st.clear();

            for(int j=0;j<n;j++){

                st.insert(ar[i][j]);
            }

            if(st.size()!=n)check = false;
            st.clear();

            for(int j=0;j<n;j++){

                st.insert(ar[j][i]);
            }
            if(st.size()!=n)check = false;
        }

        for(int i=0;i<n;i+=sn){

            for(int j=0;j<n;j+=sn){

                st.clear();

                for(int i1=0;i1<sn;i1++){

                    for(int j1=0;j1<sn;j1++){

                        st.insert(ar[i+i1][j+j1]);
                    }
                }

                if(st.size()!=n)check = false;
            }
        }

        if(check==true)printf("yes\n");
        else printf("no\n");
    }
    return 0;
}
