#include <iostream>
#include <string>
using namespace std;
int main() {
	int num, sum = 0;
	scanf_s("%d", &num);
	string s;
	cin >> s;
	for (int i = 0; i < s.size(); i++) {
		sum += s[i] - '0';	//sum은 int형임을 주의한다
	}
	printf("%d\n", sum);
	return 0;
}