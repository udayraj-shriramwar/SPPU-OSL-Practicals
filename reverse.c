// child.c
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
	printf("\nChild Program");
   
    int n = argc - 1;
    int arr[n];

    for (int i = 0; i < n; i++) {
        arr[i] = atoi(argv[i + 1]);
    }

    printf("\nArray in reverse order:\n");
    for (int i = n - 1; i >= 0; i--) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}

