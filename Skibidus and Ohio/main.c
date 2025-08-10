#include <stdio.h>
#include <string.h>

int main() {
    int t;
    scanf("%d", &t);

    while (t--) {
        char s[101];
        scanf("%s", s);

        int l = strlen(s);
        int h = 0;

        for (int i = 0; i < l - 1; i++) {
            if (s[i] == s[i + 1]) {
                h = 1;
                break;
            }
        }

        if (h) {
            printf("1\n");
        } else {
            printf("%d\n", l);
        }
    }

    return 0;
}