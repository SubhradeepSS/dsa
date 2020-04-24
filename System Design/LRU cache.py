"""
Design and implement a data structure for Least Recently Used (LRU) cache. It should support the following operations: get and put.

get(key) - Get the value (will always be positive) of the key if the key exists in the cache, otherwise return -1.
put(key, value) - Set or insert the value if the key is not already present. When the cache reached its capacity, it should invalidate the least recently used item before inserting a new item.

The cache is initialized with a positive capacity.

Follow up:
Could you do both operations in O(1) time complexity?

Example:

LRUCache cache = new LRUCache( 2 /* capacity */ );

cache.put(1, 1);
cache.put(2, 2);
cache.get(1);       // returns 1
cache.put(3, 3);    // evicts key 2
cache.get(2);       // returns -1 (not found)
cache.put(4, 4);    // evicts key 1
cache.get(1);       // returns -1 (not found)
cache.get(3);       // returns 3
cache.get(4);       // returns 4
"""

class LRUCache(object):

    def __init__(self, capacity):
        """
        :type capacity: int
        """
        self.di={}
        self.capacity=capacity
        self.recent={}
        self.recent_v=0

    def get(self, key):
        """
        :type key: int
        :rtype: int
        """
        if key not in self.di:
            return -1
        self.recent_v+=1
        self.recent[key]=self.recent_v
        return self.di[key]

    def put(self, key, value):
        """
        :type key: int
        :type value: int
        :rtype: None
        """
        self.recent_v+=1
        if key in self.di:
            self.di[key]=value
            #self.recent[key]=self.recent_v
        else:
            if len(self.di)==self.capacity:
                t=self.recent
                l=sorted(t.items(),key=lambda x:(x[1],x[0]))
                key_least=l[0][0]
                del self.di[key_least]
                del self.recent[key_least]
            #self.recent.update({key:self.recent_v})
            self.di.update({key:value})
        self.recent.update({key:self.recent_v})
            #self.recent.update({key:self.recent_v})
# Your LRUCache object will be instantiated and called as such:
# obj = LRUCache(capacity)
# param_1 = obj.get(key)
# obj.put(key,value)
