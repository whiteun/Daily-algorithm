'''
백준 2869번
달팽이는 올라가고 싶다
BRONZ 2
'''
a, b, h = map(int, input().split())  

def snail(h, d, n):
    ret = (h-d) // (d-n) +1
    if d>h: return 1
    return ret if not ((h-d) % (d-n)) else ret +1

print(snail(h, a, b))