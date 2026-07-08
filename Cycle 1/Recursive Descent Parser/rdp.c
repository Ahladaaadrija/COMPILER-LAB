#include <stdio.h>
#include <string.h>
#define SUCCESS 1
#define FAILED 0
int E(), Edash(), T(), Tdash(), F();
const char *cursor;
char string[64];
int main()
{
FILE *fp = fopen("input.txt", "r");
if (fp == NULL)
{
printf("Error: Unable to open file input.txt\n");
return 1;
}
if (fscanf(fp, "%s", string) != 1)
{
printf("Error: Could not read string from file\n");
fclose(fp);
return 1;
}
fclose(fp);
cursor = string;
puts("");
puts("Input Action");
puts("--------------------------------");
if (E() && *cursor == '\0')
{ // If parsing is successful and the cursor has reached the end
puts("--------------------------------");
puts("String is successfully parsed");
return 0;
}
else
{
puts("--------------------------------");
puts("Error in parsing String");
return 1;
}
}
int E()
{
printf("%-16s E -> T E'\n", cursor);
if (T())
{
if (Edash())
{ // Call non-terminal E'
return SUCCESS;
}
}
return FAILED;
}
int Edash()
{
if (*cursor == '+')
{
printf("%-16s E' -> + T E'\n", cursor);
cursor++;
if (T() && Edash())
{
return SUCCESS;
}
return FAILED;
}
else
{
printf("%-16s E' -> $\n", cursor);
return SUCCESS;
}
}
int T()
{
printf("%-16s T -> F T'\n", cursor);
if (F() && Tdash())
{
return SUCCESS;
}
return FAILED;
}
int Tdash()
{
if (*cursor == '*')
{
printf("%-16s T' -> * F T'\n", cursor);
cursor++;
if (F() && Tdash())
{
return SUCCESS;
}
return FAILED;
}
else
{
printf("%-16s T' -> $\n", cursor);
return SUCCESS;
}
}
int F()
{
if (*cursor == '(')
{
printf("%-16s F -> ( E )\n", cursor);
cursor++;
if (E() && *cursor == ')')
{
cursor++;
return SUCCESS;
}
return FAILED;
}
else if (*cursor == 'i')
{
printf("%-16s F -> i\n", cursor);
cursor++;
return SUCCESS;
}
return FAILED;
}
