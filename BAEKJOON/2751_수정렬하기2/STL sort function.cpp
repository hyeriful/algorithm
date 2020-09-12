#include <iostream>
#include <algorithm>	//sort()
#include <vector>
using namespace std;


// sort함수는 정렬할 기준을 내가 정할 수 있다 (default: 오름차순)

bool compare(int a, int b) {
	return a > b;	//a>b 일 때 우선적으로 정렬 (내림차순)
}

bool compare2(pair<string, pair<int, int>> a, pair<string, pair<int, int>> b) {
	if (a.second.first == b.second.first)	//성적이 같으면
		return a.second.second > b.second.second;
	else
		return a.second.first > b.second.first;
}

int main() {
	int a[10] = { 9,3,5,4,1,10,8,6,7,2 };
	sort(a, a + 10, compare);
	for (int i = 0; i < 10; i++) {
		printf("%d ", a[i]);
	}
	printf("\n\n");


	vector<pair<int, string>> v;	//단순하게 정렬을 수행하면 맨 앞 int형에 따라서 정렬
	v.push_back(pair<int, string>(90, "Jane"));
	v.push_back(pair<int, string>(93, "Jully"));
	v.push_back(pair<int, string>(80, "Poll"));
	v.push_back(pair<int, string>(72, "Amy"));
	v.push_back(pair<int, string>(85, "Robert"));

	sort(v.begin(), v.end());
	for (unsigned int i = 0; i < v.size(); i++)
		cout << v[i].second << ' ';	//pair에서 first, second 라고 함
	printf("\n\n");



	// 성적이 높은 순으로 정렬하고, 성적이 같은 경우 나이가 더 어린 사람이 먼저 출력되도록 합니다.
	// 정렬기준 2개 - 이중 pair 사용
	vector<pair<string, pair<int, int>>> vec;
	vec.push_back(pair<string, pair<int, int>>("Jane", make_pair(90, 19961222)));
	vec.push_back(pair<string, pair<int, int>>("Jully", make_pair(95, 19930518)));
	vec.push_back(pair<string, pair<int, int>>("Poll", make_pair(90, 19950203)));
	vec.push_back(pair<string, pair<int, int>>("Amy", make_pair(95, 19931018)));
	vec.push_back(pair<string, pair<int, int>>("Robert", make_pair(88, 19990505)));

	sort(vec.begin(), vec.end(), compare2);
	for (unsigned int i = 0; i < vec.size(); i++)
		cout << vec[i].first << ' ';


	//정렬기준이 3개 이상인 경우에는 pair를 사용하는게 복잡할 수 있어서 class 쓰는게 나을 수도

	return 0;
}