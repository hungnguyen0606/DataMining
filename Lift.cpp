#include <bits/stdc++.h>

using namespace std;
#define maxn 1111
double supA[maxn], supB[maxn], supAB[maxn], conf[maxn], lev[maxn], lift[maxn], conv[maxn];
int trans, rules;
int main(int argc, char const *argv[])
{
    freopen("LiftInput.txt", "r", stdin);
    freopen("LiftOutput.txt", "w", stdout);
    cin >> trans;
    cin >> rules;
    for(int i = 0; i < rules; ++i)
    {
        cin >> supA[i] >> supB[i] >> supAB[i];
        supA[i] /= trans;
        supB[i] /= trans;
        supAB[i] /= trans;
    }
    for(int i = 0; i < rules; ++i)
    {
        conf[i] = supAB[i]/supA[i];
        lev[i] = supAB[i] - supA[i]*supB[i];
        lift[i] = conf[i]/supB[i];
        conv[i] = -1;
        if (fabs(conf[i]-1) > 1e-6)
            conv[i] = (1 - supB[i])/(1-conf[i]);
       // cout << conf[i] << endl;
    }

    
    printf("\\begin{tabular}{c |}\n");
    printf("Rule Id & Confidence & Lift & Leverage & Conviction\\\\ \\hline \n");
    for(int i = 0; i < rules; ++i)
    {
        printf("%d & %0.2f & %0.2f & %0.2f & %0.2f \\\\ \n", i+1, conf[i], lift[i], lev[i], conv[i]);
    }
    printf("\\end{tabular}");
    /* code */
    
    return 0;
}