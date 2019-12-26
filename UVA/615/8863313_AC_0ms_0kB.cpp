// In the name of Allah the Lord of the Worlds.

#include<bits/stdc++.h>
using namespace std;

vector<int>edges[12345];
bool isVisited[12345] , check;

void setUp()
{
    for(int i=0;i<12345;i++){

        edges[i].clear();
        isVisited[i] = false;
    }
}

void dfs(int i)
{
    //cout << "DFS : " << i << endl;
    if(isVisited[i]==true){check=false;return;}
    isVisited[i] = true;

    int si = edges[i].size();

    for(int j=0;j<si;j++){

        dfs(edges[i][j]);
    }
}

int main(void)
{
    int in1 , in2 , c = 0;
    while(cin >> in1 >> in2){
        setUp();
        if(in1<0&&in2<0)break;

        map<int , int>mp;
        map<int, int>mp2;
        int v = 1;

        set<int>data;
        set<int>:: iterator it;
        int zero = 0;

        while(true){
            if(!in1&&!in2)break;
            if(mp2[in1]==0)mp2[in1] = v++;
            if(mp2[in2]==0)mp2[in2] = v++;

            edges[mp2[in1]].push_back(mp2[in2]);
            data.insert(mp2[in1]);
            data.insert(mp2[in2]);
            mp[mp2[in2]]++;

            cin >> in1 >> in2;

        }

        for(it=data.begin() ; it!=data.end();it++){

            //cout << "DATA : " << *it << endl;
            if(mp[*it]==0){zero = *it;}
        }
        //cout << "FOUND ROOT : " << zero << endl;
        check = true;

        dfs(zero);

        for(it=data.begin();it!=data.end();it++){

            if(isVisited[*it]==false)check=false;
        }

        //cout << zero << endl;

        if(check==true)printf("Case %d is a tree.\n",++c);
        else printf("Case %d is not a tree.\n",++c);
    }

    return 0;
}
