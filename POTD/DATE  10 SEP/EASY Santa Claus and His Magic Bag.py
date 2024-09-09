def giftsLeft(n, k, q, demands):

    bag_gifts = n

    result = []

 

    for demand in demands:

        if bag_gifts < demand:

            result.append(-1) 

        else:

            bag_gifts -= demand

            if bag_gifts < k:

                bag_gifts = n

            result.append(bag_gifts)

 

    return result
