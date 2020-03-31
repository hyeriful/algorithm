#include <iostream>
#include <stack>
#include <vector>
using namespace std;

int main() {
	int number, temp = 1;	//temp: stack에 push해야하는 숫자순서
	stack<int> stck;
	vector<char> pushORpop;		//push, pop연산 기억하는 벡터
	scanf_s("%d", &number);
	int* ary = new int[number];

	for (int i = 0; i < number; i++)	//원하는 수열 입력
		scanf_s("%d", &ary[i]);

	for (int i = 0; i < number; i++) {
		while (temp <= ary[i]) {
			stck.push(temp);
			pushORpop.push_back('+');
			temp++;
		}

		if (!stck.empty()) {
			if (stck.top() == ary[i]) {
				stck.pop();
				pushORpop.push_back('-');
			}
		}
	}
	//결과
	if (stck.empty()) {
		for (int i = 0; i < pushORpop.size(); i++)
			printf("%c ", pushORpop.at(i));
	}
	else
		printf("NO");
	printf("\n");

	delete[] ary;
	return 0;
}