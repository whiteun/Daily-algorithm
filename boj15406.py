'''
백준 15406번
Check the Check
BRONZ 2

python 시스템 입출력
'''

import sys
input = sys.stdin.readline

def eat():
    total = 0
    while 1:
        menu = input()
        if menu == 'TOTAL\n':
            bill = int(input())
            return 'PAY' if bill <= total else 'PROTEST'
        x, y = map(int, input().split())
        total += (x*y)
    return 'PROTEST'
if __name__ == '__main__':
    print(eat())
