# [프로그래머스 - 더 맵게](https://programmers.co.kr/learn/courses/30/lessons/42626)

## 해결 아이디어

**heap**을 사용한다.

※ 아래 코드는 효율성 통과못하는 코드  
처음에 sort함수를 사용했는데 정확성에서는 통과하지만 효율성에서 통과하지 못한다.

```python
def solution(scoville, K):
    answer = 0
    scoville.sort()
    while len(scoville) > 1 and scoville[0] < K:
        scoville.append(scoville.pop(0) + (scoville.pop(0) * 2))
        scoville.sort()
        answer += 1

    if scoville[0] < K:
        return -1
    return answer
```

섞은 스코빌지수를 리스트에 추가할 때마다 sort(O(nlogn))를 하면 시간복잡도가 n\*nlogn이 된다.  
하지만 solution코드에서처럼 heap을 사용하면 heap을 만드는데 nlogn, heap push logn 이므로 최종적으로 시간복잡도가 nlogn이다.
