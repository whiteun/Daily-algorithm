'''
백준 1654번
랜선 자르기
SILVER 3
'''
k, n = map(int, input().split())

li = []
for _ in range(k):
    li.append(int(input()))

# x길이로 n개를 만들 수 있는가 ?
# 길이가 길수록 n은 작아짐
# n개 이상 만들 수 있다면 길이 x는 더 길어져야함.
def check(x):
    cnt = 0
    for i in li:
        cnt += (i // x)
    if cnt >= n:
        return True
    else:
        return False

def parametric():
    low = 0
    high = 2**31
    while (low + 1 < high):
        mid = (low + high) // 2
        if check(mid):
            low = mid
        else:
            high = mid
    return low
# 길이 x에 대하여 파라메트릭 서치 결과의 분포는 True.....False 임 (길이가 짧을때 가능)
# 그래서 Low 반환
print(parametric())

