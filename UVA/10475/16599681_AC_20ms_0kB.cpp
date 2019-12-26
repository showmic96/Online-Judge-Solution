// In the name of Allah the Most Merciful.

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int n , m , k;
char in[25];
vector<string>v;
map<string , int>mp;
map<int , string>ump;
vector<int>rival[25] , st;

bool cmp(string A , string B)
{
    if(A.size()==B.size()){

        return A<B;
    }
    return A.size()>B.size();
}

void f(int u , int i , int c)
{
    if(i==n+1){

        if(c==k){

            string temp = ump[u];
            for(int j=0;j<temp.size();j++)printf("%c",temp[j]);
            for(int i1=1;i1<k;i1++){

                printf(" ");
                temp = ump[st[i1]];
                for(int j=0;j<temp.size();j++)printf("%c",temp[j]);
            }

            printf("\n");
        }
        return ;
    }

    if(u==i){

        f(u , i+1 , c);
        return ;
    }

    bool check = true;

    for(int j=0;j<rival[i].size();j++){

        for(int i1=0;i1<st.size();i1++){

            if(rival[i][j]==st[i1])check = false;
        }
    }

    if(check==true){

        st.push_back(i);
        f(u , i+1 , c+1);
        st.erase(st.begin()+st.size()-1);
    }

    f(u , i+1 , c);
}

int main(void)
{
    int t , c = 0;
    scanf("%d",&t);
    while(t--){

        scanf("%d %d %d",&n , &m , &k);
        v.clear();mp.clear();ump.clear();

        for(int i=0;i<n;i++){

            scanf("%s",&in);
            string now(in);

            for(int j=0;j<now.size();j++){

                if(now[j]>='a'&&now[j]<='z')now[j]-=32;
            }

            v.push_back(now);
        }

        for(int i=0;i<25;i++)rival[i].clear();

        sort(v.begin() , v.end() , cmp);

        for(int i=0;i<n;i++){

            mp[v[i]] = i+1;
            ump[i+1] = v[i];
        }

        for(int i=0;i<m;i++){

            scanf("%s",&in);
            string in1(in);

            for(int j=0;j<in1.size();j++){

                if(in1[j]>='a'&&in1[j]<='z')in1[j]-=32;
            }

            scanf("%s",&in);
            string in2(in);

            for(int j=0;j<in2.size();j++){

                if(in2[j]>='a'&&in2[j]<='z')in2[j]-=32;
            }

            rival[mp[in1]].push_back(mp[in2]);
            rival[mp[in2]].push_back(mp[in1]);
        }

        st.clear();
        printf("Set %d:\n",++c);

        st.push_back(1);
        for(int i=1;i<=n;i++){

            st[0] = i;
            f(i , i+1 , 1);
        }
        printf("\n");
    }
    return 0;
}
