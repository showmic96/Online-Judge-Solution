// In the name of Allah the Most Merciful.

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int main(void)
{
    int n;

    while(scanf("%d",&n)==1){

        if(n==0)break;

        int first;
        while(scanf("%d",&first)==1){

            if(first==0)break;

            vector<int>v;
            v.push_back(first);

            for(int i=0;i<n-1;i++){

                int in;
                scanf("%d",&in);
                v.push_back(in);
            }

            stack<int>st;

            int i = 1 , j = 0;

            while(true){

                if(st.empty()&&j==n){

                    break;
                }

                if(st.empty()&&i<=n){

                    st.push(i);
                    i++;
                }
                if(st.top()==v[j]){

                    j++;
                    st.pop();
                }
                else if(st.top()!=v[j]){

                    if(i>n)break;
                    st.push(i);
                    i++;
                }
            }

            if(st.empty())printf("Yes\n");
            else printf("No\n");
        }

        printf("\n");
    }
    return 0;
}
