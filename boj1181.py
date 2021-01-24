'''
백준 1181번
단어 정렬
SILVER 5

python의 기본 정렬은 stable정렬
'''

n = int(input())
li = []
for _ in range(n):
    li.append(input())
li = sorted(li) 
li = sorted(li, key = lambda x: len(x))		
for i,s in enumerate(li):
    if i==0 or li[i-1] != s:
        print(s)
