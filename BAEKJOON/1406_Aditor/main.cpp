#include <iostream>
#include <list>
#include <string>
using namespace std;

int main() {
	list<char> aditor;
	string str, com;
	int M;

	cin >> str;
	scanf_s("%d", &M);
	cin.ignore();
	//getchar();
	for (char c : str)
		aditor.push_back(c);

	auto cursor = aditor.end();

	for (int i = 0; i < M; i++) {
		getline(cin, com);
		if (com[0] == 'P')
			aditor.insert(cursor, com[2]);
		else if (com[0] == 'L') {
			if (cursor != aditor.begin()) cursor--;
		}
		else if (com[0] == 'D') {
			if (cursor != aditor.end()) cursor++;
		}
		else if (com[0] == 'B') {
			if (cursor != aditor.begin()) {
				cursor--;
				cursor = aditor.erase(cursor);
			}
		}
	}

	for (char c : aditor)
		printf("%c", c);
	printf("\n");
	
	return 0;
}