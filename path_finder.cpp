#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <string.h>
#include <string>
#include <vector>

const int MAXN = 50;
int n;
bool vis[MAXN];
char start[10], move[10], end[10]; 
FILE * imap, * omap;
std::vector <int> d[MAXN];
std::vector <std::string> e[MAXN];

int parsePos(char * str)
{
    if (strlen(str) == 1) return str[0] - '0';
    if (str[0] == 'p') return str[1] - '0' + 2;
    return str[1] - '0' + 8;
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
        e[nStart].push_back((std::string)move);
    }

    return 0;
}
