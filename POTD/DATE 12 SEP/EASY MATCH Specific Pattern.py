from os import *
from sys import *
from collections import *
from math import *

def matchSpecificPattern(words, n, pattern):

    # Write your code here

    # Return a list of words

    for i in range(n):

        if len(words[i]) != len(pattern):

            continue

        mat = dict()

        rmat = dict()

        for j in range(len(pattern)):

            if words[i][j] in mat:

                if mat[words[i][j]] != pattern[j] :

                    break

            elif pattern[j] in rmat:

                if rmat[pattern[j]] != words[i][j]:

                    break

            else:

                mat[words[i][j]] = pattern[j]

                rmat[pattern[j]] = words[i][j]

        else:

            yield words[i]
