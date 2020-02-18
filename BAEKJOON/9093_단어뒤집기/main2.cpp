#include <iostream>
#include <stack>
#include <string>
using namespace std;
int main() {
	stack<char> stk;
	int testcase;
	scanf_s("%d", &testcase);
	cin.ignore();

	for (int i = 0; i < testcase; i++) {
		int start = 0, end = -1;
		string original;
		getline(cin, original);

		for (unsigned int j = 0; j < original.length(); j++) {
			if (original[j] == ' ') {
				while (!stk.empty()) {
					printf("%c", stk.top());
					stk.pop();
				}
				printf(" ");
				continue;
			}
			stk.push(original[j]);
		}
		while (!stk.empty()) {
			printf("%c", stk.top());
			stk.pop();
		}
		printf("\n");
	}
	return 0;
}