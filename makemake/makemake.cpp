#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <string.h>

bool iscc(char * str)
{
    int len = strlen(str);
    if (len < 3) return false;
    if (str[len - 3] == '.' && str[len - 2] == 'c' && str[len - 1] == 'c') return true;
    return false;
}

char * fileToStr(FILE * in, const char * name = "Unknown file name")
{
    int i = 0;
    static char str[10000];
    while (fscanf(in, "%c", &str[i]) != EOF)
    {
        i++;
        if (i == 10000)
        {
            fprintf(stderr, "%s: File size too large\n", name);
            return NULL;
        }
    }
    str[i] = '\0';
    return str;
}

void cropName(char * res, const char * str, int l = 3)
{
    int len = strlen(str);
    strncpy(res, str, len - l);
    res[len - l] = '\0';
}

bool hasMain(FILE * in, const char * name = "Unknown file name")
{
    char * str = fileToStr(in, name);
    char * res = strstr(str, "main (");
    return (res != NULL);
}

int main (int argc, char ** argv)
{
    if (argc == 1)
    {
        printf("No input files\n");
        return 0;
    }

    bool mainFound = false;
    FILE * in;
    FILE * out = fopen("Makefile.t", "w");
    char progName[100];
    char depNames[100][100];
    char libNames[30][30][40];
    int libs[30];
    int depCnt = 0;
    int libCnt = 0;

    for (int i = 1; i < argc; i++)
    {
        if (!iscc(argv[i])) continue;
        in = fopen(argv[i], "r");
        if (!in)
        {
            fprintf(stderr, "%s: File not found\n", argv[i]);
            continue;
        }
        if (hasMain(in, argv[i]))
        {
            mainFound = true;
            cropName(progName, argv[i]);
        }

        cropName(depNames[depCnt], argv[i]);
        strcat(depNames[depCnt], ".o");

        libCnt = 0;
        rewind(in);
        char * cnt = fileToStr(in, argv[i]);
        char * next = strstr(cnt, "#include \"");
        while (next != NULL)
        {
            next += strlen("#include \"");
            int i = 0;
            while ((*next) != '\"')
            {
                libNames[depCnt][libCnt][i++] = *next;
                next ++;
            }
            libNames[depCnt][libCnt][i] = '\0';
            libCnt ++;
            next = strstr(next, "#include \"");
        }
        libs[depCnt] = libCnt;

        depCnt ++;
        fclose(in);
    }

    if (!mainFound)
    {
        printf("Main is missing\n");
        return 0;
    }

    fprintf(out, "#Automatically generated file\n");
    fprintf(out, "%s:", progName);
    for (int i=0; i<depCnt; i++) fprintf(out, " %s", depNames[i]);
    fprintf(out, "\n\tg++ -L/export/teach/1BRobot -o ");
    fprintf(out, "%s ", progName);
    for (int i=0; i<depCnt; i++) fprintf(out, " %s", depNames[i]);
    fprintf(out, " -lrobot\n\n");

    for (int i=0; i<depCnt; i++)
    {
        fprintf(out, "%s:", depNames[i]);
        char srcName[100];
        cropName(srcName, depNames[i], 2);
        strcat(srcName, ".cc");
        fprintf(out, " %s", srcName);
        for (int j=0; j<libs[i]; j++) fprintf(out, " %s", libNames[i][j]);
        fprintf(out, "\n");
        fprintf(out, "\tg++ -ansi -Wall -g -I/export/teach/1BRobot -c %s\n", srcName);
    }

    return 0;
}
