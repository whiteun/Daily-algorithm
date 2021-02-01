'''
백준 8772번
Szyfr Cezara
BRONZ 2
싸이퍼 암호
'''
import sys
input = sys.stdin.readline

T = int(input())
while T:
    T -= 1
    z = input()
    string = input().rstrip()
    char = list(input().rstrip())
    # print(char)
    diff = (ord(char[0])-ord(string[0]) + 26) % 26
    for c in string[1:]:
        num = ord(c) + diff
        if num > 122:
            num %= 122
            num += 96
        char.append(chr(num))
    print(''.join(char))
