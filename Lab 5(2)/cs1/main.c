#include <stdio.h>

void calculateScoringCombinations(int score) {
    printf("Possible combinations of scoring plays:\n");

    for (int td1 = 0; td1 <= score / 6; ++td1) {
        for (int two_pt1 = 0; two_pt1 <= (score - td1 * 6) / 2; ++two_pt1) {
            for (int td2 = 0; td2 <= (score - td1 * 6 - two_pt1 * 2) / 6; ++td2) {
                for (int three_pt = 0; three_pt <= (score - td1 * 6 - two_pt1 * 2 - td2 * 6) / 3; ++three_pt) {
                    int remainingScore = score - td1 * 6 - two_pt1 * 2 - td2 * 6 - three_pt * 3;
                    int safety = remainingScore / 2;

                    // Check if the combination results in the desired score
                    if (td1 * 6 + two_pt1 * 2 + td2 * 6 + three_pt * 3 + safety * 2 == score) {
                        printf("%d TD + %d 2pt, %d TD + %d 3pt FG, %d Safety\n", td1, two_pt1, td2, three_pt, safety);
                    }
                }
            }
        }
    }
}

int main() {
    int score;

    while (1) {
        printf("\nEnter a score (enter 0 or a negative number to exit): ");
        scanf("%d", &score);

        if (score <= 1) {
            printf("\nExiting program.\n");
            break;
        }

        if (score < 2) {
            printf("\nInvalid score. Please enter a score of 2 or higher.\n");
            continue;
        }

        calculateScoringCombinations(score);
    }

    return 0;
}

