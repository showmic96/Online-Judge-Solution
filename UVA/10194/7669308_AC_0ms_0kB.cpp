// In the name of Allah the most Merciful .

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

struct myStruct{

    string name;
    int game_palyed , point , goal_given , goal_get , win , lose , draw;

}ans[1010];

bool cmp(myStruct A , myStruct B)
{

    if(A.point==B.point){

        if(A.win==B.win){

            if(A.goal_given-A.goal_get == B.goal_given - B.goal_get){

                if(A.goal_given==B.goal_given){

                    if(A.game_palyed==B.game_palyed){

                        string ar="" , br="";
                        int si = A.name.size();
                        for(int i=0;i<si;i++)ar+=tolower(A.name[i]);
                        si = B.name.size();
                        for(int i=0;i<si;i++)br+=tolower(B.name[i]);

                        return ar < br;
                    }

                    return A.game_palyed < B.game_palyed;
                }

                return A.goal_given > B.goal_given;
            }

            return (A.goal_given-A.goal_get) > (B.goal_given - B.goal_get);

        }

        return A.win > B.win;
    }

    return A.point > B.point;
}

void print(int n)
{

//    1) Brazil 6p, 3g (2-0-1), 3gd (6-3)

    for(int i=1;i<=n;i++){

        cout << i << ") " << ans[i].name << " " << ans[i].point << "p, ";
        cout << ans[i].game_palyed << "g (" << ans[i].win << "-" << ans[i].draw << "-" << ans[i].lose;
        cout << "), " << ans[i].goal_given - ans[i].goal_get << "gd (" << ans[i].goal_given << "-";
        cout << ans[i].goal_get << ")" << endl;
    }


}

int main(void)
{
    int t , n;
    cin >> t;
    cin.get();
    map<string , int>maping;
    bool p = false;
    while(t--){
        if(p)cout << endl;
        p=true;
        maping.clear();

        string ar , br;
        //scanf("\n");
        getline(cin , ar);

        cin >> n;

        int n2 = n;
        cin.get();
        for(int i=1;i<=n;i++){

            getline(cin, ans[i].name);
            //cout << ans[i].name;
            ans[i].game_palyed = 0;
            ans[i].point = 0;
            ans[i].goal_given = 0;
            ans[i].goal_get = 0;
            ans[i].draw = 0;
            ans[i].win = 0;
            ans[i].lose = 0;

            maping[ans[i].name] = i;

        }

        cin >> n;

        int n_temp = n;
		scanf("\n");
        while(n_temp--){

            getline(cin , br);

            br+="#";

            string cr="" , dr = "";

            int d = 0;

            while(br[d]!='#'){cr+=br[d];d++;}
            d++;

            int temp1  = maping[cr];

            cr = "";

            while(br[d]!='@'){cr+=br[d];d++;}
            d++;

            int a , b;

            stringstream (cr) >> a;

            cr = "";

            while(br[d]!='#'){cr+=br[d];d++;}
            d++;

            stringstream(cr) >> b;

            cr = "";

            while(br[d]!='#'){cr+=br[d];d++;}
            d++;

            int temp2 = maping[cr];
            //cout << cr << 1 << endl;
            if(a==b){

                ans[temp1].draw++;
                ans[temp1].point++;
                ans[temp2].draw++;
                ans[temp2].point++;
            }

            else if(a>b){

                ans[temp1].win++;
                ans[temp2].lose++;
                ans[temp1].point+=3;
            }

            else{

                ans[temp2].win++;
                ans[temp1].lose++;
                ans[temp2].point+=3;
            }

            ans[temp1].goal_given+=a;
            ans[temp2].goal_given+=b;
            ans[temp1].goal_get+=b;
            ans[temp2].goal_get+=a;
            ans[temp1].game_palyed++;
            ans[temp2].game_palyed++;


        }

        sort(ans+1 , ans+n2+1 , cmp);
        cout << ar << endl;

        print(n2);
    }

    return 0;
}
