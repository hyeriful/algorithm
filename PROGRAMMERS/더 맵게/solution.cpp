#include <string>
#include <vector>
#include <queue>

using namespace std;

int solution(vector<int> scoville, int K) {
    int answer = 0;
    priority_queue<int, vector<int>, greater<int>> heap(scoville.begin(), scoville.end()); //min heap

    while (heap.top() < K && heap.size() >= 2) {
        int n1 = heap.top();
        heap.pop();
        int n2 = heap.top();
        heap.pop();
        heap.push(n1 + n2 * 2);
        answer++;
    }
    if (heap.top() < K) return -1;

    return answer;
}