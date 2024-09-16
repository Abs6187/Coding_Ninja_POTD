def f( a, m, n, o ):
    
    if m < 1 and n < 1:
        return
    
    if o == 0:
        if m < n or m < 2:
            a.append( "0" )
            m -= 1
        else:
            a.append( "00" )
            m -= 2 
    elif n < m or n < 2:
        a.append( "1" )
        n -= 1
    else:
        a.append( "11" )
        n -= 2
        
    return f( a, m, n, 1 - o )
    
        
        
def strThree0Three1( m, n ):
    
    if m < n:
        o = 1
    else:
        o = 0
        
    ans = []
    f( ans, m, n, o )
    
    return "".join( ans )
