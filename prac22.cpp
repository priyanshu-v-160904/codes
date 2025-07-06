
#include <stdio.h>
#include <string.h>

void findDistinctSubstrings(char str[]) {
    int length = strlen(str);
    printf("Distinct substrings are:\n");
    
    for (int i = 0; i < length; i++) {
        for (int j = i; j < length; j++) {
            for (int k = i; k <= j; k++) {
                printf("%c", str[k]);
            }
            printf("\n");
        }
    }
}

int main() {
    char str[100];
    printf("Enter a string: ");
    scanf("%s", str);

    findDistinctSubstrings(str);
	return 0;
}
