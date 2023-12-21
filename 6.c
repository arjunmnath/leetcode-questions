#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define N_CASES 8


/*
RUNTIME: 0ms beats 100%
Memory: 7.30Mb beats 71.88%
Date: 21-Dec-2023, 18:00
*/

char *convert(char *s, int numRows)
{
    if (numRows == 1)
        return s;
    int strLength = strlen(s), idx = 0;
    char *out = malloc(sizeof(char) * (strLength + 1));
    for (int i = 0; i < strLength; i += (numRows - 1) * 2)
    {
        *(out + idx++) = *(s + i);
    }
    for (int i = 1; i < numRows - 1; i++)
    {
        for (int j = i; j < strLength;)
        {
            *(out + idx++) = *(s + j);
            j += (numRows - (i + 1)) * 2;
            if (j >= strLength)
                break;
            *(out + idx++) = *(s + j);
            j += 2 * i;
        }
    }
    for (int i = numRows - 1; i < strLength; i += (numRows - 1) * 2)
    {
        *(out + idx++) = *(s + i);
    }
    *(out + idx++) = '\0';
    return out;
}

typedef struct test_case
{
    int num;
    char s[100];
    char out[100];
} Case;

void main()
{
    Case *Cases = malloc(N_CASES * sizeof(Case));
    *Cases = (Case){3, "PAYPALISHIRING", "PAHNAPLSIIGYIR"};
    *(Cases + 1) = (Case){4, "PAYPALISHIRING", "PINALSIGYAHRPI"};
    *(Cases + 2) = (Case){2, "ABCDE", "ACEBD"};
    *(Cases + 3) = (Case){1, "ABCD", "ABCD"};
    *(Cases + 4) = (Case){1, "A", "A"};
    *(Cases + 5) = (Case){3, "", ""};
    *(Cases + 6) = (Case){4, "HELLO", "HELOL"};
    *(Cases + 7) = (Case){6, "LEETCODEISHIRING", "LHESIEIRTEICDNOG"};

    char *out;
    for (int i = 0; i < N_CASES; i++)
    {
        printf("Test Case %d ", i + 1);
        out = convert(Cases[i].s, Cases[i].num);
        if (strcmp(out, Cases[i].out) == 0)
        {
            printf("✅\n");
        }
        else
        {
            printf("❌ (input=%s, output=%s, expected=%s, *input=%p, *output=%p)\n", Cases[i].s, out, Cases[i].out, &Cases[i].s, out);
        }
        if (out != Cases[i].s)
        {
            free(out);
        }
    }
    free(Cases);
}
