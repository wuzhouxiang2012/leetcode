local_run = False
import sys

N, k, m = None, None, None
loop = [0]*25

def go(p, d, t):
    global N, k, m, loop
    while t>0:
        t-=1
        while True:
            p = (p+d+N-1)%N+1
            if not loop[p]==0:
                break
    return p
        
def main():
    global N, k, m, loop
    if local_run:
        sys.stdin = open('input.txt', 'r')
        sys.stdout = open('output.txt', 'w')
    for line in sys.stdin:
        N,k,m = line.split(' ');
        N,k,m = int(N), int(k), int(m)
        if N==0 and k==0 and m==0:
            break
        for i in range(1,N+1):
            loop[i]=i
        left = N
        p1 = N
        p2 = 1
        while left>0:
            p1 = go(p1, 1, k)
            p2 = go(p2, -1, m)
            print('%3d' % loop[p1], end="")
            left -=1 
            if p2!= p1:
                left-=1
                print("%3d" % loop[p2], end="")
            loop[p1]=loop[p2]=0
            if left>0:
                print(",", end="")
        print("\n", end="")
            
if __name__ == "__main__":
    main()