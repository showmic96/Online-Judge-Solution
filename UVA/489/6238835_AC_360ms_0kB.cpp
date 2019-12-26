#include<bits/stdc++.h>
typedef long long ll;
using namespace std;

int main(void)
{
    int a;
    char ar[1000],br[1000];
    while(cin >> a){
        if(a<=0)break;
        cin >> ar >> br;
        int i = strlen(ar);
        int j = strlen(br);
        //sort(ar,ar+i);
        //sort(br,br+j);
        int match = 0 , unmatch=0 ;
        bool lose = false;
        for(int y=0;y<j;y++){
            bool check = false;
            for(int x=0;x<i;x++){

                if(lose==false)if(ar[x]==br[y]){check = true;match++;ar[x]='\0';}

            }

            if(check==false)unmatch++;
            if(unmatch==7)lose=true;
            br[y]='\0';
        }

        printf("Round %d\n",a);
        if(match>=i)cout << "You win." << endl;
        else if(lose==true)cout << "You lose." << endl;
        else cout << "You chickened out." << endl;


    }

    return 0;
}
