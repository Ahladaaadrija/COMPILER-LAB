#include <stdio.h>
#include <ctype.h>
#include <string.h>

#define MAX 100

// List of C keywords
char *keywords[] = {
    "auto","break","case","char","const","continue","default",
    "do","double","else","enum","extern","float","for","goto",
    "if","int","long","register","return","short","signed",
    "sizeof","static","struct","switch","typedef","union",
    "unsigned","void","volatile","while"
};

int keywordCount = 32;

// Check whether a word is a keyword
int isKeyword(char str[])
{
    for(int i=0;i<keywordCount;i++)
    {
        if(strcmp(str, keywords[i])==0)
            return 1;
    }
    return 0;
}

int main()
{
    FILE *fp;
    char ch, buffer[MAX];
    int i;

    fp = fopen("input.c","r");

    if(fp==NULL)
    {
        printf("Cannot open input file.\n");
        return 0;
    }

    while((ch=fgetc(fp))!=EOF)
    {

        // Ignore spaces, tabs, newlines
        if(isspace(ch))
            continue;

        // Identifier or Keyword
        if(isalpha(ch) || ch=='_')
        {
            i=0;
            buffer[i++]=ch;

            while((ch=fgetc(fp))!=EOF &&
                 (isalnum(ch)||ch=='_'))
            {
                buffer[i++]=ch;
            }

            buffer[i]='\0';

            if(ch!=EOF)
                ungetc(ch,fp);

            if(isKeyword(buffer))
                printf("%-20s : KEYWORD\n",buffer);
            else
                printf("%-20s : IDENTIFIER\n",buffer);
        }

        // Number
        else if(isdigit(ch))
        {
            i=0;
            buffer[i++]=ch;

            while((ch=fgetc(fp))!=EOF &&
                  isdigit(ch))
            {
                buffer[i++]=ch;
            }

            buffer[i]='\0';

            if(ch!=EOF)
                ungetc(ch,fp);

            printf("%-20s : NUMBER\n",buffer);
        }

        // Comments
        else if(ch=='/')
        {
            char next=fgetc(fp);

            // Single line comment
            if(next=='/')
            {
                while((ch=fgetc(fp))!='\n' && ch!=EOF);
            }

            // Multi line comment
            else if(next=='*')
            {
                char prev=' ';
                while((ch=fgetc(fp))!=EOF)
                {
                    if(prev=='*' && ch=='/')
                        break;
                    prev=ch;
                }
            }

            else
            {
                printf("/                    : OPERATOR\n");
                if(next!=EOF)
                    ungetc(next,fp);
            }
        }

        // Operators
        else if(strchr("+-*=<>!%",ch))
        {
            printf("%c                    : OPERATOR\n",ch);
        }

        // Delimiters
        else if(strchr("(){}[],;#",ch))
        {
            printf("%c                    : DELIMITER\n",ch);
        }

        else
        {
            printf("%c                    : UNKNOWN\n",ch);
        }
    }

    fclose(fp);

    return 0;
}
