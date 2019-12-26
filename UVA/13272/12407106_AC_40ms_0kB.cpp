// In the name of Allah the Most Merciful.

#include<bits/stdc++.h>
using namespace std;

char x[100005];
bool vis[100005];
int ans[100005];
int sum[100005];
int last[100005];

int main(void)
{
    int t , c = 0;
    scanf("%d",&t);
    while(t--){

        scanf("%s",&x);
        string ar(x);
        stack<pair<char , int> > st;

        memset(vis , false , sizeof(vis));
        memset(ans , 0 , sizeof(ans));
        memset(sum , 0 , sizeof(sum));
        memset(last , -1 , sizeof(last));

        int f = 0 , l = 0, si = ar.size();
        ar+="####";

        for(int i=0;i<=si;i++){

            if(i<si&&(ar[i]=='('||ar[i]=='{'||ar[i]=='['||ar[i]=='<')){

                st.push(make_pair(ar[i] , i));
            }

            else{

                char xx = '#';
                if(!st.empty())xx = st.top().first;

                if(ar[i]==')'&&xx=='('){

                    f = st.top().second;

                    l = i;
                    st.pop();

                    ans[f] = l-f+1;
                }

                else if(ar[i]=='}'&&xx=='{'){

                    f = st.top().second;

                    l = i;
                    st.pop();

                    ans[f] = l-f+1;
                }

                else if(ar[i]==']'&&xx=='['){

                    f = st.top().second;

                    l = i;
                    st.pop();

                    ans[f] = l-f+1;
                }

                else if(ar[i]=='>'&&xx=='<'){

                    f = st.top().second;

                    l = i;
                    st.pop();

                    ans[f] = l-f+1;
                }

                else{

                    for(int j=f;j<=l;j++)vis[j] = true;
                    while(!st.empty())st.pop();
                }
            }
        }

        for(int i=0;i<si;i++){

            if(i>0)sum[i] = sum[i]+sum[i-1];
            if(sum[i])vis[i] = true;
        }

        int counter = 0;

        for(int i=si-1;i>=0;i--){

            ans[i]+=ans[i+ans[i]];
        }

        printf("Case %d:\n",++c);

        for(int i=0;i<si;i++)printf("%d\n",ans[i]);
    }
    return 0;
}
