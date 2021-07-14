from collections import deque

class stack:
    def __init__(self):
        self.__container = deque()

    def push(self, value):
        self.__container.append(value)

    def pop(self):
        _ = self.__container.pop()

    def top(self):
        return self.__container[-1]

    def empty(self):
        return len(self.__container) == 0

    def __repr__(self):
        return repr(self.__container)[6:-1]

class queue:
    def __init__(self):
        self.__container = deque()

    def push(self, value):
        self.__container.append(value)

    def pop(self):
        _ = self.__container.popleft()

    def front(self):
        return self.__container[0]

    def empty(self):
        return len(self.__container) == 0

    def __repr__(self):
        return str(self.__container)[6:-1]