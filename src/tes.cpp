#include <iostream>

using namespace std;

typedef struct {
	short distance;
	short nextHop;
} table;

int main() {
	int N = 1000;

	table** connection = new table* [N+1];
	for (int i = 0; i <= N; i++)
		connection[i] = new table [N+1];

	for (int i = 0; i <= N; i++)
		delete [] connection[i];
	delete [] connection;
}