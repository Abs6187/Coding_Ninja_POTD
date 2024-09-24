#include <bits/stdc++.h> 
string findShortestRoute(string &str) 
{
	string ans;
	int x = 0, y = 0;
	for(auto &it: str){
		if(it == 'N')y++;
		if(it == 'S')y--;
		if(it == 'E')x++;
		if(it == 'W')x--;
	}

	if(x<=0){
		int num = abs(x);
		while(num--)ans+='W';
	}
	else while(x--)ans+='E';

	if(y<=0){
		int num = abs(y);
		while(num--)ans+='S';
	}
	else while(y--)ans+='N';

	sort(begin(ans),end(ans));

	return ans;
}
