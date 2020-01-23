#define what_is(x) cerr << #x << " is " << x << endl;
#define error(args...) { string _s = #args; replace(_s.begin(), _s.end(), ',', ' '); stringstream _ss(_s); istream_iterator<string> _it(_ss); err(_it, args); }

#include<bits/stdc++.h>
using namespace std;

const int maxn = 110;
const int INF = 0x3f3f3f3f;

void err(istream_iterator<string> it) {}
template<typename T, typename... Args>
void err(istream_iterator<string> it, T a, Args... args) {
	cerr << *it << " = " << a << endl;
	err(++it, args...);
}

int main()
{
    int a = 4, b = 8, c = 9;
	error(a, b, c);

    return 0;
}
