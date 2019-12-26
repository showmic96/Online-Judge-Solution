// In the name of Allah the Most Merciful.

#include<bits/stdc++.h>
using namespace std;

const int MAX = 1e5+10;

struct myStruct{

    int st , en;

}point[MAX+10];

bool cmp(myStruct A , myStruct B)
{
    return A.st<B.st;
}

int main(void)
{
    int t;
    cin >> t;
    bool space = false;
    while(t--){

        if(space)cout << endl;
        space = true;

        int in1 , in2 , d = 0 , m;

        cin >> m;

        while(cin >> in1 >> in2){

            if(!in1&&!in2)break;

            point[d].st = in1;
            point[d++].en = in2;
        }

        sort(point , point+d , cmp);
        
        bool check = true;

        int data1 = -1e9 , data2 = -1e9 , up = 0 , down =0;
        vector<pair<int ,int> > ans;

        for(int i=0;i<d;i++){

            int j = i , up_temp = up;

            while(point[j].st<=up){

                if(point[j].en>up_temp){

                    data1 = point[j].st;
                    data2 = point[j].en;
                    up_temp = data2;
                    
                }

                j++;
                if(j==d)break;
            }
        
            if(data2!=-1e9){

                ans.push_back(make_pair(data1 , data2));
                up = data2;
                if(data2>=m)break;
                data1 = -1e9 , data2 = -1e9;
            }

            else{

                check=false;break;
            }

            i = j-1;
        }
        
        if(data2<m)check=false;

        if(check==true){
            cout << ans.size() << endl;

            for(int i=0;i<ans.size();i++)cout << ans[i].first << " " << ans[i].second << endl;
        }

        else cout << 0 << endl;
    }
    return 0;
}
