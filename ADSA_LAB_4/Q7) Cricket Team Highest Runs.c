#include <stdio.h>

struct Player {
    char name[50];
    int runs;
    int wickets;
};

int main() {
    int n, i, maxIndex = 0;
    printf("Enter number of players: ");
    scanf("%d", &n);

    struct Player players[n];
    for(i = 0; i < n; i++) {
        printf("Enter details of player %d\n", i+1);
        printf("Name: ");
        scanf("%s", players[i].name);
        printf("Runs: ");
        scanf("%d", &players[i].runs);
        printf("Wickets: ");
        scanf("%d", &players[i].wickets);
    }

    for(i = 1; i < n; i++) {
        if(players[i].runs > players[maxIndex].runs) {
            maxIndex = i;
        }
    }

    printf("Player with highest runs:\n");
    printf("Name: %s\n", players[maxIndex].name);
    printf("Runs: %d\n", players[maxIndex].runs);
    printf("Wickets: %d\n", players[maxIndex].wickets);

    return 0;
}
