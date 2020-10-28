def solution(n):
    answer = ""
    while(n > 0):
        n, mod = divmod(n, 3)
        answer = "412"[mod] + answer
        if mod == 0:
            n -= 1
    return answer
