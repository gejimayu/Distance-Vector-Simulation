#include <iostream>

using namespace std;

typedef struct {
	int distance;
	int nextHop;
} table;

int main() {
	int N;
	cin >> N;
	
	//initialize
	bool connection[N+1][N+1];
	for(int i = 1; i <= N; i++)
		for(int j = 1; j <= N; j++)
			connection[i][j] = false;
		
	//set up connection between nodes	
	for(int i = 1; i <= N; i++) {
		string temp;
		cin >> temp;
		int k = 0;
		while (k < temp.length()) {
			int m = k;
			int number = 0;
			int multiplier = 1;
			while(m < temp.length() && temp[m] != ',') {
				int temp2 = temp[m] - '0';
				number += multiplier * temp2;
				multiplier *= 10;
				m++; k++;
			}
			connection[i][number] = true;
			k++;
		}
 	}
	
	//create routing table
	table RT[N+1][N+1];
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
	
}