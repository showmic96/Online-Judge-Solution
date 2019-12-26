// In the name of Allah the Most Merciful.

#include<bits/stdc++.h>
using namespace std;

vector<pair<int , int > > edges1[27] , edges2[27];
int dis1[27] , dis2[27];

void setUp()
{
    for(int i=0;i<27;i++){

        edges1[i].clear();
        edges2[i].clear();
        dis1[i] = 123456;
        dis2[i] = 123456;
    }
}

void Dijkstra1(int s)
{
    priority_queue<pair<int , int> > current;

    dis1[s] = 0;

    current.push(make_pair(0 , s));

    while(!current.empty()){

        int u = current.top().second;
        int c1 = -current.top().first;
        current.pop();

        int si = edges1[u].size();

        for(int i=0;i<si;i++){

            int v = edges1[u][i].first;
            int c = edges1[u][i].second;

            if(dis1[v]>dis1[u]+c){

                dis1[v] = dis1[u] + c;

                current.push(make_pair(-dis1[v] , v));
            }
        }
    }
}

void Dijkstra2(int s)
{
    priority_queue<pair<int , int> > current;

    dis2[s] = 0;

    current.push(make_pair(0 , s));

    while(!current.empty()){

        int u = current.top().second;
        int c1 = -current.top().first;
        current.pop();

        int si = edges2[u].size();

        for(int i=0;i<si;i++){

            int v = edges2[u][i].first;
            int c = edges2[u][i].second;

            if(dis2[v]>dis2[u]+c){

                dis2[v] = dis2[u] + c;

                current.push(make_pair(-dis2[v] , v));
            }
        }
    }
}

int main(void)
{
    int n;
    while(cin >> n){

        if(!n)break;

        setUp();

        for(int i=0;i<n;i++){

            char a , d , f , t;
            int c;

            cin >> a >> d >> f >> t >> c;

            if(a=='Y'){

                if(d=='B'){

                    edges1[f-'A'].push_back(make_pair(t-'A' , c));
                    edges1[t-'A'].push_back(make_pair(f-'A' , c));
                }

                else {

                    edges1[f-'A'].push_back(make_pair(t-'A' , c));
                }
            }

            else{

                if(d=='B'){

                    edges2[f-'A'].push_back(make_pair(t-'A' , c));
                    edges2[t-'A'].push_back(make_pair(f-'A' , c));
                }

                else {

                    edges2[f-'A'].push_back(make_pair(t-'A' , c));
                }
            }
        }

        char s1 , s2;

        cin >> s1 >> s2;

        Dijkstra1(s1-'A');
        Dijkstra2(s2-'A');

        int mi = 12345 , ans = -1;
        vector<char>a;
        for(int i=0;i<26;i++){
            //cout << i << " " << dis1[i] << endl;
            if(dis1[i]+dis2[i]<mi){

                a.clear();
                mi = dis1[i] + dis2[i];
                ans = i;
                a.push_back('A'+i);
            }

            else if(dis1[i]+dis2[i]==mi){
                a.push_back('A' + i);
            }
        }

        if(ans==-1)cout << "You will never meet." << endl;
        else {
            cout << mi;
            for(int i=0;i<a.size();i++)cout << " " << a[i];
            cout << endl;
        }
    }
    return 0;
}
