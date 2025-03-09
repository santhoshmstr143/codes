#include <string.h>

char *simplifyPath(char *s)
{
    int n = strlen(s);
    static char str[3000];
    char a[n][1000];
    int top = -1;

    a[++top][0] = '/';
    a[top][1] = '\0';

    int ind = 0;

    for (int i = 1; i < n; i++)
    {
        if (s[i] == '/')
        {
            continue;
        }
        else if (s[i] == '.' && (i + 1 == n || s[i + 1] == '/'))
        {
            continue;
        }
        else if (s[i] == '.' && s[i + 1] == '.' && (i + 2 == n || s[i + 2] == '/'))
        {
            if (top > 0)
            {
                top--;
            }
            i++;
        }
        else
        {
            a[++top][0] = s[i];
            int j = 1;
            while (i + 1 < n && s[i + 1] != '/')
            {
                i++;
                a[top][j++] = s[i];
            }
            a[top][j] = '\0';
        }
    }

    if (top == 0)
    {
        str[ind++] = '/';
    }
    else
    {
        for (int i = 1; i <= top; i++)
        {
            str[ind++] = '/';
            int j = 0;
            while (a[i][j] != '\0')
            {
                str[ind++] = a[i][j++];
            }
        }
    }
    str[ind] = '\0';

    return str;
}
