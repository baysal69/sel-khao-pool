#include <stdlib.h>

char	**ft_split(char *str)
{
    int ri = 0;
    int i = 0;
    char **split;
    
    if (!(split =(char **)malloc(sizeof(char *) * 256)))
        return NULL;
    while (str[i] == ' ' || str[i] == '\t' || str[i] == '\n')
        i++;
    while(str[i])
    {
        int col = 0;
        if(!(split[ri] =(char *)malloc(sizeof(char) * 4096)))
            return NULL;
        while (str[i] && str[i] != ' ' && str[i] != '\t' && str[i] != '\n')
            split[ri][col++] = str[i++];
        split[ri][col] = '\0';
        ri++;
        while (str[i] == ' ' || str[i] == '\t' || str[i] == '\n')
            i++;
    }
    split[ri] = NULL;
    return (split);
}

#include <stdio.h>

int main() {
    char str[] = "  42  is  awesome!  "; // Test string with spaces
    char **result = ft_split(str);

    if (result) {
        for (int i = 0; result[i]; i++) {
            printf("Word %d: %s\n", i, result[i]);
        }
    } else {
        printf("Memory allocation failed.\n");
    }

    return 0;
}