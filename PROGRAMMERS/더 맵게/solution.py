import heapq  # default: min heap


def solution(scoville, K):
    answer = 0
    heapq.heapify(scoville)

    while scoville[0] < K and len(scoville) >= 2:
        n1 = heapq.heappop(scoville)
        n2 = heapq.heappop(scoville)
        heapq.heappush(scoville, n1 + n2 * 2)
        answer += 1

    if scoville[0] < K:
        return -1
    return answer
