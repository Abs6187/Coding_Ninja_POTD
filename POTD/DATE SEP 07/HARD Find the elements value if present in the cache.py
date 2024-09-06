from collections import OrderedDict

 

def findCacheValue(arr, m, n):

    cache = OrderedDict()

    freq = {}

 

    res = []

 

    for i in range(m):

        op = arr[i]

 

        if op[0] == 1:

            uid = op[1]

            val = op[2]

 

            if uid in cache:

                cache[uid] = val

                freq[uid] += 1

            else:

                if len(cache) == n:

                    least_freq_uid = min(freq, key=freq.get)

                    del cache[least_freq_uid]

                    del freq[least_freq_uid]

 

                cache[uid] = val

                freq[uid] = 1

 

        elif op[0] == 2:

            uid = op[1]

 

            if uid in cache:

                res.append(cache[uid])

                freq[uid] += 1

            else:

                res.append(-1)

 

    return res
