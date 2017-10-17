#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <string.h>
#include <vector>

struct string
{
    static const int size = 20;
    char move[size];
    string() = default;
    string(const string & str)
    {
        for (int i = 0; i < size; ++i) this->move[i] = str.move[i];
    }
    string(const char * str)
    {
        for (int i = 0; i < size; ++i) this->move[i] = str[i];
    }
    string operator=(const string & str)
    {
        for (int i = 0; i < size; ++i) this->move[i] = str.move[i];
        return str;
    }
};

const int MAXN = 50;
int n;
bool vis[MAXN];
char start[10], move[10], end[10]; 
FILE * imap, * omap;
std::vector <int> d[MAXN];
std::vector <string> e[MAXN];

int parsePos(char * str)
{
    if (strlen(str) == 1) return str[0] - '0';
    if (str[0] == 'p') return str[1] - '0' + 2;
    return str[1] - '0' + 8;
}

inline int f(int a) { return a==0?a:a-2; }

string dfs(int start, int end)
{
    if (vis[start]) return string("");
    vis[start] = true;
    if (start == end) return string("T");
    
    for (int i = 0; i < d[start].size(); ++i)
    {
        string res = dfs(d[start][i], end);
        if (strcmp(res.move, "") == 0) continue;
        string res2;
        strcpy(res2.move, e[start][i].move);
        strcat(res2.move, res.move);
        return res2;
    }

    return("");
}

void reset(int n = MAXN)
{
    memset(vis, 0, n);
}

int main ()
{
    imap = fopen("map.txt", "r");
    omap = fopen("paths.txt", "w");

    // Create map
    fscanf(imap, "%d", &n);
    for (int i=0; i < n; ++i)
    {
        fscanf(imap, "%s %s %s", start, move, end);
        int nStart = parsePos(start), nEnd = parsePos(end);
        d[nStart].push_back(nEnd);
        e[nStart].push_back((string)move);
    }

    for (int i=0; i <= 13; ++i)
    {
        if (i == 1 || i == 2) continue;
        for (int j = 0; j <= 13; ++j)
        {
            if (j == 1 || j == 2 || i == j) continue;
            reset();
            string res = dfs(i, j);
            fprintf(omap, "%d %d %s\n", f(i), f(j), res.move);
        }
    }

    return 0;
}
