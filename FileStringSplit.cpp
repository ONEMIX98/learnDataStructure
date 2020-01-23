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
    fstream f("input.txt");
    string line; // Each line of input.txt
    vector<string> words;
    while(getline(f,line)) // get each line of input.txt
    {
        split1(line, words); // Split each line into words
        words.clear(); // Clear words after parse each line
    }
    return 0;
}

