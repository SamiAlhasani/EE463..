#include <stdio.h>

int main() {
    int count = 0; // Variable to count the number of combinations
    for (char a = 'a'; a <= 'z'; ++a) { // Loop for the first letter
        for (char b = 'a'; b <= 'z'; ++b) { // Loop for the second letter
            if (b == a) continue; // Skip if the second letter is the same as the first
            for (char c = 'a'; c <= 'z'; ++c) { // Loop for the third letter
                if (c == a || c == b) continue; // Skip if the third letter matches the first or second
                for (char d = 'a'; d <= 'z'; ++d) { // Loop for the fourth letter
                    if (d == a || d == b || d == c) continue; // Skip if the fourth letter matches any of the previous ones
                    printf("%c%c%c%c\n", a, b, c, d); // Print the combination
                    count++; // Increment the count of combinations
                }
            }
        }
    }
    printf("Total combinations: %d\n", count); // Print the total number of combinations
    return 0;
}
