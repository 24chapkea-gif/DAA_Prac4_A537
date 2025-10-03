#include <stdio.h>

int main() {
    int array[] = {2, 2, 2, 2};
    int n = sizeof(array) / sizeof(array[0]);
    int constraint = 5;

    if (n == 0) {
        printf("Array is empty.\n");
        return 0;
    }

    int max_sum = -1;
    int current_sum = 0;
    int start = 0;
    int best_start = 0, best_end = 0;

    for (int end = 0; end < n; end++) {
        current_sum += array[end];

        while (current_sum > constraint && start <= end) {
            current_sum -= array[start];
            start++;
        }

        if (current_sum > max_sum) {
            max_sum = current_sum;
            best_start = start;
            best_end = end;
        }
    }

    if (max_sum == -1) {
        printf("No subarray possible with a sum <= %d\n", constraint);
    } else {
        printf("Max Sum Subarray is: ");
        for (int i = best_start; i <= best_end; i++) {
            printf("%d ", array[i]);
        }
        printf("\nSum of Max Subarray is: %d\n", max_sum);
    }

    return 0;
}
