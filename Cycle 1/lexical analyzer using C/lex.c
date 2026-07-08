#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>

#define MAX_LENGTH 1000

/*----------------------------------------------------------
    Function Prototypes
----------------------------------------------------------*/
bool isDelimiter(char ch);
bool isOperator(char ch);
bool isSpecialCharacter(char ch);
bool isKeyword(char *str);
bool isValidIdentifier(char *str);
bool isInteger(char *str);
char *getSubstring(char *str, int start, int end);
void lexicalAnalyzer(char *input);

/*----------------------------------------------------------
    Utility Functions
----------------------------------------------------------*/

bool isDelimiter(char ch)
{
    return (isspace(ch) ||
            ch == '+' || ch == '-' || ch == '*' || ch == '/' ||
            ch == ',' || ch == ';' || ch == '%' ||
            ch == '>' || ch == '<' || ch == '=' ||
            ch == '(' || ch == ')' ||
            ch == '[' || ch == ']' ||
            ch == '{' || ch == '}');
}

bool isOperator(char ch)
{
    return (ch == '+' || ch == '-' || ch == '*' ||
            ch == '/' || ch == '>' || ch == '<' ||
            ch == '=');
}

bool isSpecialCharacter(char ch)
{
    return (ch == '#' || ch == '.');
}

bool isValidIdentifier(char *str)
{
    if (str == NULL || str[0] == '\0')
        return false;

    if (!(isalpha(str[0]) || str[0] == '_'))
        return false;

    for (int i = 1; str[i] != '\0'; i++)
    {
        if (!(isalnum(str[i]) || str[i] == '_'))
            return false;
    }

    return true;
}

bool isKeyword(char *str)
{
    const char *keywords[] =
    {
        "auto","break","case","char","const","continue","default","do",
        "double","else","enum","extern","float","for","goto","if",
        "int","long","register","return","short","signed","sizeof",
        "static","struct","switch","typedef","union","unsigned",
        "void","volatile","while",
        "include","stdio","stdlib","string","math","time"
    };

    int count = sizeof(keywords) / sizeof(keywords[0]);

    for (int i = 0; i < count; i++)
    {
        if (strcmp(str, keywords[i]) == 0)
            return true;
    }

    return false;
}

bool isInteger(char *str)
{
    if (str == NULL || *str == '\0')
        return false;

    int i = 0;

    if (str[i] == '+' || str[i] == '-')
        i++;

    if (!isdigit(str[i]))
        return false;

    for (; str[i] != '\0'; i++)
    {
        if (!isdigit(str[i]))
            return false;
    }

    return true;
}

char *getSubstring(char *str, int start, int end)
{
    int length = end - start + 1;

    char *sub = (char *)malloc(length + 1);

    if (sub == NULL)
    {
        printf("Memory Allocation Failed\n");
        exit(1);
    }

    strncpy(sub, str + start, length);
    sub[length] = '\0';

    return sub;
}

/*----------------------------------------------------------
    Lexical Analyzer
----------------------------------------------------------*/

void lexicalAnalyzer(char *input)
{
    int left = 0;
    int right = 0;

    int length = strlen(input);

    int lineNumber = 1;
    int tokenNumber = 1;

    printf("%-10s %-10s %-18s %s\n",
           "Line No", "Token No", "Token Type", "Lexeme");

    printf("---------------------------------------------------------------\n");

    while (right <= length && left <= right)
    {
        if (input[right] == '\n')
        {
            lineNumber++;
            tokenNumber = 1;
            right++;
            left = right;
            continue;
        }

        if (isSpecialCharacter(input[right]))
        {
            printf("%-10d %-10d %-18s %c\n",
                   lineNumber,
                   tokenNumber++,
                   "Special Character",
                   input[right]);

            right++;
            left = right;
            continue;
        }

        if (!isDelimiter(input[right]))
        {
            right++;
        }

        if (isDelimiter(input[right]) && left == right)
        {
            if (isOperator(input[right]))
            {
                printf("%-10d %-10d %-18s %c\n",
                       lineNumber,
                       tokenNumber++,
                       "Operator",
                       input[right]);
            }
            else if (!isspace(input[right]))
            {
                printf("%-10d %-10d %-18s %c\n",
                       lineNumber,
                       tokenNumber++,
                       "Delimiter",
                       input[right]);
            }

            right++;
            left = right;
        }
        else if ((isDelimiter(input[right]) && left != right) ||
                 (right == length && left != right))
        {
            char *token = getSubstring(input, left, right - 1);

            if (isKeyword(token))
            {
                printf("%-10d %-10d %-18s %s\n",
                       lineNumber,
                       tokenNumber++,
                       "Keyword",
                       token);
            }
            else if (isInteger(token))
            {
                printf("%-10d %-10d %-18s %s\n",
                       lineNumber,
                       tokenNumber++,
                       "Integer",
                       token);
            }
            else if (isValidIdentifier(token))
            {
                printf("%-10d %-10d %-18s %s\n",
                       lineNumber,
                       tokenNumber++,
                       "Identifier",
                       token);
            }
            else
            {
                printf("%-10d %-10d %-18s %s\n",
                       lineNumber,
                       tokenNumber++,
                       "Unidentified",
                       token);
            }

            free(token);
            left = right;
        }
    }
}

/*----------------------------------------------------------
    Main Function
----------------------------------------------------------*/

int main()
{
    FILE *file = fopen("input.c", "r");

    if (file == NULL)
    {
        printf("Error: Unable to open input.c\n");
        return 1;
    }

    char buffer[MAX_LENGTH];

    size_t bytesRead = fread(buffer, 1, MAX_LENGTH - 1, file);
    buffer[bytesRead] = '\0';

    fclose(file);

    printf("\nLexical Analysis of input.c\n\n");

    lexicalAnalyzer(buffer);

    return 0;
}
