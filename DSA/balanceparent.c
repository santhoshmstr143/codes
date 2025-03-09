#include<stdio.h>
#include<string.h>
int isValid(char* s) {
    int n = strlen(s);
    char a[n];
    int top = -1;

    for(int i=0;i<n;i++)
    {
        if(s[i]=='(' || s[i]=='[' || s[i]=='{')
        {
            top++;
            a[top]=s[i];
        }
        else
        {
            if(top == -1) return 0;
            if ((s[i] == ')' && a[top] == '(') ||
                (s[i] == '}' && a[top] == '{') ||
                (s[i] == ']' && a[top] == '[')) {
                top--;
            }
            else
                return 0;
        }
    }
    if(top==-1) 
        return 1;
    else 
        return 0;
}
int main()
{
    int n;
    scanf("%d",&n);
    char s[n+1];
    scanf("%s",s);
    int t = isValid(s);
    if(t==1) printf("YES");
    else printf("NO");
}