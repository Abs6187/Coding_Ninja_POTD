#include <bits/stdc++.h>

void manageWhitespaces(string& str, int& wsLength, int& wsRemain) {
    for (int i = 1; i <= wsLength; i++) str += " ";
    if (wsRemain-- > 0) str += " ";
}

string justifyText(queue<string>& q, string str, int& width, int& maxWidth) {
    int size = q.size();
    if (size == 1) size++;    // To avoid the case for divisible by zero
    
    int wsTotal = maxWidth - width + (size - 1);
    int wsLength = wsTotal / (size - 1);
    int wsRemain = wsTotal % (size - 1);
    
    while (!q.empty()) {
        if (str != "") manageWhitespaces(str, wsLength, wsRemain);
        
        str += q.front();
        q.pop();
    }
    
    return str;
}

vector<string> fullJustify(vector<string> &words, int maxWidth) {
    // Write your code here
    queue<string> q;
    int width = 0, ws = 0;
    
    vector<string> text;
    for (string word : words) {
        if (width + word.length() + ws <= maxWidth) {
            q.push(word);
            width += word.length() + ws;
            ws = 1;
        }
        else {
            string str = justifyText(q, "", width, maxWidth);
            text.push_back(str);
            
            q.push(word);
            width = word.length();
        }
    }
    
    if (!q.empty()) {
        string str = "";
        while (!q.empty()) {
            str += q.front() + " ";
            q.pop();
        }
        
        text.push_back(str);
    }
    
    return text;
}
