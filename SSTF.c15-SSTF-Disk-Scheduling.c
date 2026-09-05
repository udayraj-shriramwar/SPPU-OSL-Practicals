#include <stdio.h>
#include <stdlib.h>

int main() {
    int n, i, j, head, min, diff, seekTime = 0;
    int requests[100], visited[100] = {0}, count = 0;

    printf("Enter number of disk requests: ");
    scanf("%d", &n);

    printf("Enter disk requests: ");
    for (i = 0; i < n; i++)
        scanf("%d", &requests[i]);

    printf("Enter initial head position: ");
    scanf("%d", &head);

    printf("\nSeek Sequence: ");
    while (count < n) {
        min = 9999;
        int index = -1;

        for (i = 0; i < n; i++) {
            if (!visited[i]) {
                diff = abs(requests[i] - head);
                if (diff < min) {
                    min = diff;
                    index = i;
                }
            }
        }

        visited[index] = 1;
        seekTime += min;
        head = requests[index];
        printf("%d ", head);
        count++;
    }

    printf("\nTotal Seek Time = %d\n", seekTime);
    printf("Average Seek Time = %.2f\n", (float)seekTime / n);

    return 0;
}
