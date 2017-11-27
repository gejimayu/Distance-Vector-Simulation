#include <iostream>

using namespace std;

typedef struct {
	int distance;
	int nextHop;
} table;

int main() {
	int N, M;
	cin >> N >> M;
	
	//initialize
	bool connection[N+1][N+1];
	for(int i = 1; i <= N; i++)
		for(int j = 1; j <= N; j++)
			connection[i][j] = false;
		
	//set up connection between nodes	
	int u, v;
	for(int i = 1; i <= M; i++) {
		cin >> u >> v;
		connection[u][v] = true;
		connection[v][u] = true;
 	}
	
	//create routing table
	table** RT = new table* [N+1];
	for (int i = 0; i <= N; i++)
		RT[i] = new table [N+1];

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
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
	cin >> S;
	while(S--) {
		int from, to;
		cin >> from >> to;
		if (connection[from][to]) {
			//loop through source's connection
			for (int i = 1; i <= N; i++) {
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
	
	//output result
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			cout << RT[i][j].distance << " " << RT[i][j].nextHop << endl;
		}
	}

	for (int i = 0; i <= N; i++)
		delete [] RT[i];
	delete [] RT;
	
}