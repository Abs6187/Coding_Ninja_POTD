class Solution:
  def __init__(self):
      self.temp = [None] * 4
      self.tempPointer = 0
      self.tempCount = 0
  def read(self, obj, buf, n):
      counter = 0
      while (counter < n):
          if (self.tempPointer == 0):
              self.tempCount = obj.read4(self.temp)
          
          if (self.tempCount == 0):
              break
          while (counter < n and self.tempPointer < self.tempCount):
              buf[counter] = self.temp[self.tempPointer]
              counter += 1
              self.tempPointer += 1
          
          if (self.tempPointer == self.tempCount):
              self.tempPointer = 0
      
      return counter
