#include <iostream>

using namespace std;

typedef struct {
	int distance;
	int next_hop;
} routing_table;

int n;
bool **connection = new bool*[n];
routing_table table[n+1][n+1];

// initialize
void init() {
	for (int i = 0; i < n; i++){
		connection[i] = new bool[n];
	}

	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++)
			connection[i][j] = false;
}

// set up connection between nodes	
void setConnection() {
	for (int i = 1; i <= n; i++) {
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
}

// create routing table
void createTable() {
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (i == j) {
				table[i][j].distance = 0;
				table[i][j].next_hop = i;
			}
			else
			if (connection[i][j]) {
				table[i][j].distance = 1;
				table[i][j].next_hop = j;
			}
			else {
				table[i][j].distance = -1;
				table[i][j].next_hop = -1;
			}
		}
	}
}

void doScenario() {
	int s; // number of scenarios
	cin >> s;
	while(s--) {
		int from, to;
		cin >> from >> to;
		if (connection[from][to]) {
			// loop through source's connection
			for (int i = 1; i <= n; i++) {
				if ((table[from][i].distance > 0) && (i != to)) {
					if ((table[to][i].distance == -1) ||
						(table[from][i].distance + table[to][from].distance < table[to][i].distance)) {
						table[to][i].distance = table[from][i].distance + table[to][from].distance;
						table[to][i].next_hop = from;
					}
				}
			}
		}
	}
}

// print table
void printTable() {
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			cout << table[i][j].distance << " " << table[i][j].next_hop << endl;
		}
	}
}

// delete table
void freeTable() {
	for (int i = 0; i < n; i++){
		delete [] connection[i];
	}
	delete [] connection;
}

int main() {
	cin >> n;
	init();
	setConnection();
	createTable();
	doScenario();
	printTable();
	freeTable();
}