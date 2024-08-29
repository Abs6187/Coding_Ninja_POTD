#include <bits/stdc++.h>
using namespace std;

int minSwapsToMakeEqual(string str1, string str2, int n) {
    if (str2.length() != n || set<char>(str1.begin(), str1.end()) != set<char>(str2.begin(), str2.end())) {
        return -1;
    }

    vector<pair<char, char>> map_arr;

    for (int i = 0; i < n; ++i) {
        if (str1[i] != str2[i]) {
            map_arr.emplace_back(str1[i], str2[i]);
        }
    }

    n = map_arr.size();
    int count = 0;
    int i = 0;

    while (i < n) {
        int j = i + 1;
        while (j < n) {
            if (map_arr[i] == make_pair(map_arr[j].second, map_arr[j].first)) {
                map_arr.erase(map_arr.begin() + i);
                map_arr.erase(map_arr.begin() + j - 1);
                count++;
                n = map_arr.size();
            } else {
                j++;
            }
        }
        i++;
    }

    i = 0;

    while (i < n) {
        int j = i + 1;
        while (j < n) {
            if (map_arr[i].second == map_arr[j].first && map_arr[i].first != map_arr[i].second && map_arr[j].first != map_arr[j].second) {
                swap(map_arr[i].first, map_arr[j].first);
                count++;
                break;
            }
            j++;
        }
        i++;
    }

    return count;
}
