#include <bits/stdc++.h> 
vector<string> findStrobogrammatic(int n) {
	vector<string> ans;
	if(n % 2 != 0){
		ans.push_back("0");
		ans.push_back("1");
		ans.push_back("8");

		n--;
	}else{
		ans.push_back("");
	}

	while(n-2 >= 0){
		vector<string> temp;
		for(auto num: ans){
			if(n-2 != 0){
				temp.push_back('0'+num+'0');
			}
			temp.push_back('1'+num+'1');
			temp.push_back('6'+num+'9');
			temp.push_back('8'+num+'8');
			temp.push_back('9'+num+'6');
		}
		ans = temp;
		n -= 2;
	}

	return ans;
}
