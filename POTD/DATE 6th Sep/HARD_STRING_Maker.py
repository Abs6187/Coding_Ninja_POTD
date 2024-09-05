from os import *
from sys import *
from collections import *
from math import *

def maker(a,b,c,x,y,z,la,lb,lc,dp):
    if z>=lc:
        return 1
    if x>=la and y>=lb:
        return 0
    if dp[x][y][z]!=-1:
        return dp[x][y][z]
    ans=0
    for i in range(x,la):
        if c[z]==a[i]:
            ans += maker(a,b,c,i+1,y,z+1,la,lb,lc,dp)
    for i in range(y,lb):
        if c[z]==b[i]:
            ans += maker(a,b,c,x,i+1,z+1,la,lb,lc,dp)
    dp[x][y][z]=ans
    return ans

def countWays(a,b,c):
    na=len(a)
    nb=len(b)
    nc=len(c)
    dp=[[[-1 for k in range(nc+1)] for j in range(nb+1)] for i in range(na+1)]
    return maker(a,b,c,0,0,0,na,nb,nc,dp)%(10**9+7)
