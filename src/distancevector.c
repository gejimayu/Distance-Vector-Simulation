#include <stdio.h>
#include <stdlib.h>

#define true 1
#define false 0

typedef struct {
	int distance;
	int nextHop;
} table;

int main() {
	int N, M, i, j;
	scanf("%d %d", &N, &M);
	
	// initialize 
	char connection[N+1][N+1];
	for(i = 1; i <= N; i++)
		for(j = 1; j <= N; j++)
			connection[i][j] = false;
		
	// set up connection between nodes	
	int u, v;
	for(i = 1; i <= M; i++) {
		scanf("%d %d", &u, &v);
		connection[u][v] = true;
		connection[v][u] = true;
 	}
	
	// create routing table
	table** RT = (table **)malloc((N+1) * sizeof(table *));
	for (i = 0; i <= N; i++)
		RT[i] = (table *)malloc((N+1) * sizeof(table));

	for (i = 1; i <= N; i++) {
		for (j = 1; j <= N; j++) {
			if (i == j) {
				RT[i][j].distance = 0;
				RT[i][j].nextHop = i;
			}
			else
			if (connection[i][j]) {
				RT[i][j].distance = 1;
				RT[i][j].nextHop = j;
			}
			else {
				RT[i][j].distance = -1;
				RT[i][j].nextHop = -1;
			}
		}
	}
	
	int S;
	scanf("%d", &S);
	while(S--) {
		int from, to;
		scanf("%d %d", &from, &to);
		if (connection[from][to]) { // change information between nodes
			// loop through source's connection
			for (i = 1; i <= N; i++) {
				if ((RT[from][i].distance > 0) && (i != to)) {
					if ((RT[to][i].distance == -1) || (RT[from][i].distance + RT[to][from].distance < RT[to][i].distance)) { 
						RT[to][i].distance = RT[from][i].distance + RT[to][from].distance;
						RT[to][i].nextHop = from;
					}
					else 
					if ((RT[from][i].distance + RT[to][from].distance == RT[to][i].distance) && (from < RT[to][i].nextHop)) {
						RT[to][i].nextHop = from;
					}
				}
			}
		}
	}
	
	// output result
	for (i = 1; i <= N; i++) {
		for (j = 1; j <= N; j++) {
			printf("%d %d\n", RT[i][j].distance, RT[i][j].nextHop);
		}
	}

	for (i = 0; i <= N; i++)
		free(RT[i]);
	free(RT);

	return 0;
}
