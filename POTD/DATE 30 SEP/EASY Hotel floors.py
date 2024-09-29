from os import *
from sys import *
from collections import *
from math import *


def hotelBookings(queries):
    count = 0
    for i in queries:
        if i and i[0]=='+':
            count += 1
    return count
