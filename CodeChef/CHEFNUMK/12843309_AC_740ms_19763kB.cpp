// In the name of Allah the Lord of the Worlds.

#include<bits/stdc++.h>
using namespace std;

struct s{

    int l , r , d , idx;

    s(int _l , int _r , int _d , int _idx){

        l = _l;
        r = _r;
        d = _d;
        idx = _idx;
    }
};

vector<int>v , ans;
vector<s>query;
int block;
unordered_map<int , int>mp;
int fr[200005] , ar[200005], a;

bool cmp(s A , s B)
{
    if(A.l/block!=B.l/block){

        return A.l/block<B.l/block;
    }

    return A.r<B.r;
}

void add(int idx)
{
    ar[v[idx]]++;

    fr[ar[v[idx]]-1]++;
}

void rem(int idx)
{
    ar[v[idx]]--;

    fr[ar[v[idx]]]--;
}

int main(void)
{
    int t;
    scanf("%d",&t);
    while(t--){

        int n , q;
        scanf("%d %d",&n , &q);

        v.clear();
        mp.clear();
        block = sqrt(n);

        memset(fr , 0 , sizeof(fr));
        memset(ar , 0 , sizeof(ar));

        set<int>st;
        vector<int>data;

        for(int i=0;i<n;i++){

            int in;
            scanf("%d",&in);
            st.insert(in);
            data.push_back(in);
        }

        int c = 1;

        for(set<int>::iterator it = st.begin();it!=st.end();it++){

            mp[*it] = c;
            c++;
        }

        for(int i=0;i<n;i++){

            v.push_back(mp[data[i]]);
        }

        query.clear();
        ans.clear();

        for(int i=0;i<q;i++){

            int in1 , in2 , in3;
            scanf("%d %d %d",&in1 , &in2 , &in3);

            in1--;in2--;

            query.push_back(s(in1 , in2 , in3 , i));
            ans.push_back(0);
        }

        sort(query.begin() , query.end() , cmp);

        int l = 0 , r = 0;
        a = 0;

        for(int i=0;i<q;i++){

            int left = query[i].l;
            int right = query[i].r;

            while(l>left){

                add(l-1);
                l--;
            }
            while(l<left){

                rem(l);
                l++;
            }

            while(r<=right){

                add(r);
                r++;
            }
            while(r>right+1){

                rem(r-1);
                r--;
            }

            ans[query[i].idx] = fr[0]-fr[query[i].d];
        }

        for(int i=0;i<q;i++)printf("%d\n",ans[i]);
    }
    return 0;
}
