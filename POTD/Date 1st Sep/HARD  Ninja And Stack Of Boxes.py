from os import *
from sys import *
from collections import *
from math import *



def m( x, y ):
    return ( max( x, y ), min( x, y ) )
    
    
    
def ninjaAndBoxStack( l, b, h, n ):       
    a = {}  
    d = defaultdict( int )
    
    for i in range( n ):
        o = m( l[i], b[i] )
        a[o] = d[o] = max( d[o], h[i] )
        o = m( b[i], h[i] )
        a[o] = d[o] = max( d[o], l[i] )
        o = m( h[i], l[i] )
        a[o] = d[o] = max( d[o], b[i] )
        
    c = sorted( a )
    o = len( c )
    
    for i in range( o ):
        for j in range( i + 1, o ):
           if c[i][0] < c[j][0] and c[i][1] < c[j][1]:
                a[ c[j] ] = max( a[ c[i] ] + d[ c[j] ], a[ c[j] ] )
                
    return max( a.values() )
