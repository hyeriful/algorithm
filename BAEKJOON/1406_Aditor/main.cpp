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
				//list는 (vector와 달리) 해당원소가 삭제되면 iterator가 갈 곳을 잃음.
				//erase함수의 리턴값은 삭제 원소 사음에 있는 원소 iterator.
			}
		}
	}

	for (char c : aditor)
		printf("%c", c);
	printf("\n");
	
	return 0;
}