'''
백준 1213번
팰린드롬 만들기
SILVER 4
'''
pal = input()

visit = [0 for i in range(26)]
for p in pal:
    visit[ord(p)-ord('A')] += 1
ret = ''
fchar = ''
flag = False
for i,v in enumerate(visit[::-1]):
    if v%2 and fchar != '':
        print('I\'m Sorry Hansoo')
        flag = True
        break
    elif v%2:
        fchar = chr(25-i+ord('A'))
    ret = chr(25-i+ord('A'))*(v//2) + ret + chr(25-i+ord('A'))*(v//2)

if not flag:
    ret = ret[:len(ret)//2] + fchar + ret[len(ret)//2:]
    print(ret)