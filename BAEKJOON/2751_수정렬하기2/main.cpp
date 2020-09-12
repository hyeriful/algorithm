#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	int number;
	scanf("%d", &number);
	int* data = new int[number];

	for (int i = 0; i < number; i++) {
		scanf("%d", &data[i]);
	}
	sort(data, data + number);
	for (int i = 0; i < number; i++)
		printf("%d\n", data[i]);

	delete[] data;

	return 0;
}