
#define _CRT_SBCURE_NO_DEPRECATE
#include<bits/stdc++.h>
using namespace std;

const int maxn = 110;
const int INF = 0x3f3f3f3f;

int main()
{
    // pair
    pair<int,int> p;
    p = {3,4};

    // vector
    vector<int> v;
    v = {1,2,5,2};
    for(auto &i:v)
    {
        i*=2;
    }
    for(auto i:v)
    {
        cout<<i<<' ';
    }
    cout<<'\n';

    // deque
    deque<vector<pair<int,int>>> d;
    d = {{{3,4},{5,6}},{{1,2},{3,4}}};
    for(auto i:d)
    {
        for(auto j:i)
            cout<<j.first<<' '<<j.second<<'\n';
        cout<<"-\n";
    }

    // set
    set<int> s;
    s = {4,6,2,7,4};
    for(auto i:s)
    {
        cout<<i<<' ';
    }
    cout<<'\n';

    // list
    list<int> l;
    l = {5,8,9,2};
    for(auto i:l)
    {
        cout<<i<<' ';
    }
    cout<<'\n';

    // array
    array<int,4> a = {5,8,9,1};

    for(auto i:a)
    {
        cout<<i<<' ';
    }
    cout<<'\n';

    // tuple
    tuple<int, int, char> t(1,2,'f');
    cout << get<2>(t) << '\n';

    return 0;
}
