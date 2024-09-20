class Deque:

    def __init__(self, size):

        self.queue = []

        self.size = size

 

    def pushFront(self, x):

        if self.isFull():

            return False

 

        self.queue.insert(0, x)

        return True

    

    def pushRear(self, x):

        if self.isFull():

            return False

        

        self.queue.append(x)

        return True

 

    def popFront(self):

        if self.isEmpty():

            return -1

        

        return self.queue.pop(0)

 

    def popRear(self):

        if self.isEmpty():

            return -1

        

        return self.queue.pop()

 

    def getFront(self):

        if self.isEmpty():

            return -1

        

        return self.queue[0]

 

    def getRear(self):

        if self.isEmpty():

            return -1

        

        return self.queue[-1]

 

    def isEmpty(self):

        return self.queue == []

 

    def isFull(self):

        return len(self.queue) >= self.size
