import math


def solution(w, h):
    answer = w*h - (w+h-math.gcd(w, h))
    return answer


if __name__ == "__main__":
    w, h = list(map(int, input().split()))
    answer = solution(w, h)
    print(answer)
