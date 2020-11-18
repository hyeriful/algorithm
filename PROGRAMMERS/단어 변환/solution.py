def dfs(begin, target, words, visited, idx, cnt):
    global answer
    if idx >= 0:
        visited[idx] = True
    if begin == target:
        return cnt
    for w in range(len(words)):
        # 다른 단어가 하나일 때
        if len([i for i in range(len(words[w])) if words[w][i] != begin[i]]) == 1:
            if not visited[w]:
                answer = min(answer, dfs(
                    words[w], target, words, visited, w, cnt+1))
                visited[w] = False
    return answer


def solution(begin, target, words):
    global answer
    answer = 51
    visited = [False for i in range(len(words))]
    if target not in words:
        return 0
    dfs(begin, target, words, visited, -1, 0)
    return answer


# a = [i for i in range(10) if i % 2 == 0]
# print(a)
