def findAllSelfDividingNumbers( lower, upper, ans = None ):
    
    if ans is None:
        ans = []
        
    d = set( str( lower ) )
    
    if "0" not in d:
        ans.append( lower )
        
        for i in d:
            if lower % int( i ) != 0:
                ans.pop()
                break
            
    if lower == upper:
        return ans
    else:
        return findAllSelfDividingNumbers( lower + 1, upper, ans )
