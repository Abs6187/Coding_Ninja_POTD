from os import *
from sys import *
from collections import *
from math import *
class TrieNode:
    def __init__(self):
        self.children = {}
        self.countPrefix = 0
        self.isEndWord = 0
class Trie:
    def __init__(self):
        self.root = TrieNode()
    
    def insert(self, word):
        temp = self.root
        for i in range(0 , len(word)):
            if word[i] not in temp.children:
                new_node = TrieNode()
                temp.children[word[i]] = new_node
            temp = temp.children[word[i]]
            temp.countPrefix += 1
        temp.isEndWord += 1
    def countWordsEqualTo(self, word):
        temp = self.root
        
        for i in range(len(word)):
            if word[i] in temp.children:
                temp = temp.children[word[i]]
            else:
                return 0
        return temp.isEndWord
        
    def countWordsStartingWith(self, word):
        temp = self.root
        for i in range(len(word)):
            if word[i] in temp.children:
                temp = temp.children[word[i]]
            else:
                return 0
        return temp.countPrefix
        
    def erase(self, word):
        temp = self.root
        for i in range(len(word)):
            if word[i] in temp.children:
                temp = temp.children[word[i]]
                temp.countPrefix -= 1
            else:
                return 
        temp.isEndWord -= 1 
