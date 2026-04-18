class MinStack:

    def __init__(self):
        self.minStack = []
        self.normalStack = []

    def push(self, val: int) -> None:
        self.normalStack.append(val)
        if not self.minStack or self.minStack[-1] >= val:
            self.minStack.append(val)
        
    def pop(self) -> None:
        if self.minStack[-1] == self.normalStack[-1]:
            self.minStack.pop()
        self.normalStack.pop()

    def top(self) -> int:
        if self.normalStack:
            return self.normalStack[-1]

    def getMin(self) -> int:
        if self.minStack:
            return self.minStack[-1]

