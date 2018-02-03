#include<bits/stdc++.h>
using namespace std;

/// M A C R O Starts Here
#define pf printf
#define sf scanf
#define MAX 500000
#define MOD 100000007
#define INF INT_MAX
#define pi acos(-1.0)
#define get_stl(s) getline(cin,s)
#define sif(a) scanf("%d",&a)
#define pif(a) printf("%d\n",a)
#define puf(a) printf("%llu\n",a)
#define pii pair<int, int>
#define mem(name, value) memset(name, value, sizeof(name))

string grid[61];
int row,col,x,y;
char o ='N';

void direct(char c)
{
    if(o=='N')
    {
        (c=='R') ? o = 'E' : o = 'W';
    }
    else if(o=='S')
    {
        (c=='R') ? o = 'W' : o = 'E';
    }
    else if(o=='E')
    {
        (c=='R') ? o = 'S' : o = 'N';
    }
    else if(o=='W')
    {
        (c=='R') ? o = 'N' : o = 'S';
    }
}

void forward()
{
    if(o=='N')
    {
        if(grid[x-1][y]!='*')   --x;
    }

    else if(o=='S')
    {
        if(grid[x+1][y]!='*')   ++x;
    }

    else if(o=='E')
    {
        if(grid[x][y+1]!='*')   ++y;
    }

    else if(o=='W')
    {
        if(grid[x][y-1]!='*')   --y;
    }
}

int main()
{
    //freopen("in.txt","r", stdin);
    //freopen("out.txt","w", stdout);

    char c, str[200];
    int test;
    cin >> test;
    bool flag = false;

    while (test--)
    {
        cin >> row >> col;
        cin.getline(str, sizeof(str)); // eat blank line
        for (int i = 0; i < row; ++i)
        {
            cin.getline(str, sizeof(str));
            grid[i] = str;
        }

        cin >> x >> y;
        o = 'N';
        --x;
        --y;

        while ( (c = cin.get()) != 'Q')
        {
            switch(c)
            {
                case 'R':
                    direct(c);
                    break;
                case 'L':
                    direct(c);
                    break;
                case 'F':
                    forward();
                    break;
            }
        }
        if (flag) cout << endl;
        flag = true;
        cout << x+1 << " " << y+1 << " " << o << endl;
    }

    return 0;
}
