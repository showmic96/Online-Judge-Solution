// In the name of Allah the Most Merciful.

#include<bits/stdc++.h>
using namespace std;

const int MAX = 100;

struct myStruct{
    int index , value;
}team[MAX] , table[MAX];

bool cmp(struct myStruct A , struct myStruct B){

    return A.value > B.value;
}

int main(void)
{

    int n , m;
    while(cin >> n >> m){

        if(!n&&!m)break;

        for(int i=0;i<n;i++){

            team[i].index = i;
            cin >> team[i].value;
        }

        for(int i=0;i<m;i++){

            table[i].index = i;
            cin >> table[i].value;
        }

        sort(team , team+n , cmp);
        sort(table , table+m , cmp);

        bool check = true;
        vector<int>ans[MAX];

        for(int i=0;i<n;i++){

            int d = 0;

            while(team[i].value!=0){

                if(table[d].value>0){

                    ans[team[i].index].push_back(table[d].index);
                    team[i].value--;
                    table[d].value--;
                }

                d++;
                if(team[i].value==0)break;
                if(d==m){

                    check=false;
                    break;
                }

            }

            if(check==false)break;
        }

        if(check==false)cout << 0 << endl;
        else{
            
            cout << 1 << endl;
            for(int i=0;i<n;i++){

                sort(ans[i].begin() , ans[i].end());
                cout << ans[i][0]+1;

                for(int j=1;j<ans[i].size();j++)cout << " " << ans[i][j]+1;

                cout << endl;
            }
        }
    }

    return 0;
}
