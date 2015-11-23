#include <bits/stdc++.h>

using namespace std;

vector<string> trans;
bool data[1000][1000];
string name[1111];
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
    while (inp >> u)
    {
        //cout << u << endl;
        if (atts[u] == 0)
            atts[u] = atts.size();
        name[atts[u]] = u;
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
    //cin >> n;
   // getline(cin,s);
   // cout << s;
    while (getline(cin,s))
    {

        s = standardize(s);
        getAtts(s);
        trans.push_back(s);
       // cout << s << endl;
    }
  //  cout << trans.size();
    /* code */

     for(map<string,int>::iterator it = atts.begin(); it != atts.end(); ++it)
     {
         cout << it->first << ' ' << it->second << endl;
     }

     for(int i = 0; i < trans.size(); ++i)
     {
         stringstream inp(trans[i]);
         string att;
         while (inp >> att)
         {
             data[i][atts[att]] = true;
         }
     }

    //
    freopen("mydata.arff", "w", stdout);

    cout << "@relation transaction" << endl << endl;
    for(int i = 1; i <= atts.size(); ++i)
     {
         cout << "@attribute " << name[i] << " {TRUE,FALSE}" << endl;
     }

    cout << "@data" << endl << endl;
     for(int i = 0; i < trans.size(); ++i)
     {
         stringstream out;

         for(int j = 1; j <= atts.size(); ++j)
         {
               if (data[i][j])
                out << " TRUE,";
               else
                out <<  " ?,";
         }
         string s = out.str();
         s.erase(s.length()-1,1);

         cout << s << endl;
         cout << endl;

     }

    return 0;
}
