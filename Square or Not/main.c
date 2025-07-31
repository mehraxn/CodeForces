#include <stdio.h>

char s[200005];

int main() {
    int t;
    scanf("%d", &t);
    while (t--) {
        int n;
        scanf("%d%s", &n, s);

        int k = 0;
        while (k * k < n)
            k++;

        if (k * k != n) {
            printf("No\n");
            continue;
        }

        int f = 1;
        for (int i = 0; i < k && f; i++)
            for (int j = 0; j < k; j++) {
                char c = s[i * k + j];
                if (i > 0 && i < k - 1 && j > 0 && j < k - 1) {
                    if (c != '0') {
                        f = 0;
                        break;
                    }
                } else if (c != '1') {
                    f = 0;
                    break;
                }
            }

        printf(f ? "Yes\n" : "No\n");
    }
}
