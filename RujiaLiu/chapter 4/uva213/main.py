"""
TNM AEIOU
001|0,1, 011|000111, 010|00;10;01;11, 011|001;111, 000

T, A, N, BLK, M, E
T->0,  0
N->00, 0
M->01, 1
BLK->10 2
A->000 0
E->001 1
I->010 2
O->011 3
U->100 4

build 2D matrix 
{len: index }
1: 0
2: 0 1 2 
3: 0 1 2 3 4 5 6 7 
msg fill the 2D matrix

"""

local_run = False
import sys

msg = ""
decoding = ""
code  = [[' ' for _ in range(1<<8)] for _ in range(8)]

def fill_code():
    global code, msg
    idx = 0
    for l in range(1,8):
        for i in range(1<<l)-1:
            if idx<len(msg):
                code[l][i]=msg[idx]
                idx+=1
            else:
                return
def

def main():
    global msg, decoding, code
    if local_run:
        sys.stdin = open('input.txt', 'r')
        sys.stdout = open('output.txt', 'w')
    flag_read_msg = True
    for line in sys.stdin:
        if flag_read_msg:
            msg = line.strip()
            # fill msg into 2D matrix
            fill_code()
            flag_read_msg = False
        else:
            decoding+=line.strip()
            if len(decoding)>=3 and decoding[-1]=='0' and decoding[-2]=='0' and decoding[-3]=='0':
                ret = ''
                readlen
                
                
            
if __name__ == "__main__":
    main()