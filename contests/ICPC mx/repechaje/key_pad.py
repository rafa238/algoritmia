from collections import defaultdict

keypad_codes = ["2", "2", "2", "3", "3", "3", "4", "4", "4", "5", "5", "5", "6", "6", "6", "7", "7", "7", "7", "8", "8", "8", "9", "9", "9", "9"]
""""
for i in range(2,10):
    repetitions = 4 if i in (7,9) else 3 
    aux = [i]*repetitions 
    keypad_codes.extend(aux)
"""
(n, q) = input().split(" ")
n = int(n)
q = int(q)
#print(keypad_codes)


dc = {}

for i in range(n):
    identifier = input()
    identifier_str = ""
    for letter in identifier:
        identifier_str += keypad_codes[ord(letter) - ord('a')]
    try:
        dc[identifier_str] += 1
    except KeyError:
        dc[identifier_str] = 1

codes = [] 
for i in range(q):
    code = input()
    try:
        print(dc[code])
    except KeyError:
        print(0)