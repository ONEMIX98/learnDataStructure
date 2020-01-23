#define _CRT_SBCURE_NO_DEPRECATE
#include<bits/stdc++.h>
using namespace std;

const int maxn = 110;
const int INF = 0x3f3f3f3f;

template <class Container>
void split1(const string& str, Container& cont)
{
    istringstream iss(str);
    copy(istream_iterator<string>(iss),
         istream_iterator<string>(),
         back_inserter(cont));
}
int main()
{
    string str = "The quick brown fox jumps over the lazy dog";
    vector<string> words;
    split1(str, words);
    copy(words.begin(), words.end(),
    ostream_iterator<string>(cout, "\n"));
    return 0;
}

