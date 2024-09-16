def covidSpread( houses: list ):
	
	ans = -1
	d = [ ( 1, 0 ), ( 0, 1 ), ( -1, 0 ), ( 0, -1 ) ]
	m = len( houses[0] )
	n = len( houses )
	o = 0
	p = []

	for i in range( n ):
		for j in range( m ):
			if houses[i][j] > 1:
				p.append( ( i, j ) )
			elif houses[i][j] > 0:
				o += 1

	while len( p ) > 0:
		ans += 1
		q = []

		for r, s in p:
			for i, j in d:
				u = r + i
				v = s + j

				if u >= 0 and u < n and v >= 0 and v < m and houses[u][v] == 1:
					houses[u][v] = 2
					q.append( ( u, v ) )
					o -= 1

		p = q
		
	if o > 0:
		return -1

	return ans
