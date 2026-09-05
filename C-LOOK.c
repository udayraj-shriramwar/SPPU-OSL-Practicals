#include <stdio.h>
#include <stdlib.h>

int main() {
    int n, i, j, head, seekTime = 0;
    int requests[100], temp, index;

    printf("Enter number of disk requests: ");
    scanf("%d", &n);

    printf("Enter disk requests: ");
    for (i = 0; i < n; i++)
        scanf("%d", &requests[i]);

    printf("Enter initial head position: ");
    scanf("%d", &head);

    // Sort requests
    for (i = 0; i < n - 1; i++) {
        for (j = 0; j < n - i - 1; j++) {
            if (requests[j] > requests[j + 1]) {
                temp = requests[j];
                requests[j] = requests[j + 1];
                requests[j + 1] = temp;
            }
        }
    }

    // Find position where head currently is
    for (i = 0; i < n; i++) {
        if (head < requests[i]) {
            index = i;
            break;
        }
    }

    printf("\nSeek Sequence: ");
    // Move toward higher tracks
    for (i = index; i < n; i++) {
        printf("%d ", requests[i]);
        seekTime += abs(requests[i] - head);
        head = requests[i];
    }

    // Jump directly to lowest request (circular)
    seekTime += abs(requests[n - 1] - requests[0]);
    head = requests[0];

    // Serve remaining requests
    for (i = 0; i < index; i++) {
        printf("%d ", requests[i]);
        seekTime += abs(requests[i] - head);
        head = requests[i];
    }

    printf("\nTotal Seek Time = %d\n", seekTime);
    printf("Average Seek Time = %.2f\n", (float)seekTime / n);
    return 0;
}
