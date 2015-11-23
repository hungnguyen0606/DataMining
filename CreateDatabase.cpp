#include <bits/stdc++.h>

using namespace std;

vector<string> trans;

string standardize(string s)
{
    string res = "";
    for(int i = 0; i < s.length(); ++i)
        if (s[i] == ',')
            res.push_back(' ');
        else
            res.push_back(s[i]);
 //   cout << "hello " << res << "end" << endl;
    return res;
}

map<string,int> atts;

void getAtts(const string& s)
{
    stringstream inp(s);
    string u;
    while (cin >> u)
    {
   //     cout << u << endl;
        if (atts[u] == 0)
            atts[u] = atts.size();
    }
}
int main(int argc, char const *argv[])
{
    freopen("input.txt", "r", stdin);

    string s;
    int n = 0;
    // cout << getline(cin,s) << endl;
    // cout << getline(cin,s) << endl;
    // cout << getline(cin,s) << endl;
    cin >> n;
   // getline(cin,s);
   // cout << s;
    while (cin >> s)
    {
       // getline(cin,s);
        s = standardize(s);
        cout << "bon" << s << endl;
        getAtts(s);
        trans.push_back(s);
       // cout << s << endl;
    }
  //  cout << trans.size();
    /* code */
    
    // for(map<string,int>::iterator it = atts.begin(); it != atts.end(); ++it)
    // {
    //   //  cout << 3;
    //     cout << it->first << ' ' << it->second << endl;
    // }

    return 0;
}