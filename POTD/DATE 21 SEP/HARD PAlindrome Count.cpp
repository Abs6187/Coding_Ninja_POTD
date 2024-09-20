int palinCount(string str) {

// Write your code here.

unordered_map<int,int> m;

int res = 0, n = str.length(), mask = 0;

m[0] = 1;

for(int i=0 ; i<n ; i++) {

int c = str[i] - 'a';

mask ^= (1<<c);

 

for(int j=0 ; j<26 ; j++) {

res += m[mask ^ (1<<j)];

}

 

res += m[mask];

m[mask]++;

}

 

return res;

}
