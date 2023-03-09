

import itertools
import random

class PerceptronOR:
    def __init__(self, n) -> None:
        self.inputs = list(itertools.product([True, False], repeat=n))
        self.results = self._findResults()
        self.n = n
        # self.bias = random.uniform(-1, 1)
        self.bias = -1
        self.weights = self._intializeWeight()

    def _findResults(self):
        table_ = self.inputs.copy()
        results = []
        for i in range(len(table_)):
            result = sum(table_[i])
            if result >= 1:
                results.append(1)
            else:
                results.append(0)
        return results
    
    def _intializeWeight(self):
        # randomly initialize weights
        weights = []
        for i in range(self.n):
            weights.append(random.uniform(-1,1))
        print('Original Weights: ', weights)
        return weights

    def orTT(self):
        table_ = self.inputs.copy()
        results = []
        for i in range(len(table_)):
            result = sum(table_[i])
            if result >= 1:
                results.append(1)
            else:
                results.append(0)
        for i in range(len(table_)):
            print(table_[i], '\t', results[i])
    
    def _singlePass(self, row):
        x = self.inputs[row]
        sum = 0
        for i in range(self.n):
            sum = sum + x[i]*self.weights[i]

        return sum+self.bias

    def learnOR(self): 
        self.orTT()
        incorrectExamples = self.n
        maxIters = 100
        while incorrectExamples > 0 and maxIters:
            maxIters -= 1
            incorrectExamples = 0
            for i in range(2**self.n):
                onePass = self._singlePass(i)
                if self.results[i] == 1 and onePass < 0:
                    # +ve examples classified as negative
                    incorrectExamples += 1
                    self.bias += 1
                    # update weights
                    currentInput = self.inputs[i]
                    for j in range(self.n):
                        self.weights[j] = self.weights[j] + int(currentInput[j])
                elif self.results[i] == 0 and onePass >= 0:
                    # -ve example classified as positive
                    incorrectExamples += 1
                    self.bias -= 1
                    # update weights
                    currentInput = self.inputs[i]
                    for j in range(self.n):
                        self.weights[j] = self.weights[j] - int(currentInput[j])

        return self.weights

    def evaluateModel(self):
        results = []
        # print(type(self.inputs), len(self.inputs))
        for i in range(len(self.inputs)):
            x = self.inputs[i]
            sum = 0
            for j in range(self.n):
                sum = sum + x[j]*self.weights[j]
            if(sum > 1):
                results.append(1)
            else:
                results.append(0)
            print("Printing Evaluation Results: ")
            print(x, sum, results[-1])
        return results==self.results















class PerceptronAND:
    def __init__(self, n) -> None:
        self.n = n
        self.inputs = list(itertools.product([True, False], repeat=n))
        self.results = self._findResults()
        # self.bias = random.uniform(-1, 1)
        self.bias = -1
        self.weights = self._intializeWeight()

    def _findResults(self):
        table_ = self.inputs.copy()
        results = []
        for i in range(len(table_)):
            result = sum(table_[i])
            if result >= self.n:
                results.append(1)
            else:
                results.append(0)
        return results
    
    def _intializeWeight(self):
        # randomly initialize weights
        weights = []
        for i in range(self.n):
            weights.append(random.uniform(-1,1))
        print('Original Weights: ', weights)
        return weights

    def andTT(self):
        table_ = self.inputs.copy()
        results = []
        for i in range(len(table_)):
            result = sum(table_[i])
            if result >= self.n:
                results.append(1)
            else:
                results.append(0)
        for i in range(len(table_)):
            print(table_[i], '\t', results[i])
    
    def _singlePass(self, row):
        x = self.inputs[row]
        sum = 0
        for i in range(self.n):
            sum = sum + x[i]*self.weights[i]

        return sum+self.bias

    def learnAND(self):
        self.andTT()
        incorrectExamples = self.n
        maxIters = 100
        while incorrectExamples > 0 and maxIters:
            maxIters -= 1
            incorrectExamples = 0
            for i in range(2**self.n):
                onePass = self._singlePass(i)
                if self.results[i] == 1 and onePass < self.n:
                    # +ve examples classified as negative
                    incorrectExamples += 1
                    self.bias += 1
                    # update weights
                    currentInput = self.inputs[i]
                    for j in range(self.n):
                        self.weights[j] = self.weights[j] + int(currentInput[j])
                if self.results[i] == 0 and onePass >= self.n:
                    # -ve example classified as positive
                    incorrectExamples += 1
                    self.bias -= 1
                    # update weights
                    currentInput = self.inputs[i]
                    for j in range(self.n):
                        self.weights[j] = self.weights[j] - int(currentInput[j])

        return self.weights

    def evaluateModel(self):
        results = []
        # print(type(self.inputs), len(self.inputs))
        for i in range(len(self.inputs)):
            x = self.inputs[i]
            sum = 0
            for j in range(self.n):
                sum = sum + x[j]*self.weights[j]
            if(sum > self.n):
                results.append(1)
            else:
                results.append(0)
            print("Printing Evaluation Results: ")
            print(x, sum, results[-1])
        return results==self.results


# driver for OR       
model = PerceptronOR(2)
weighs = model.learnOR()
print(weighs)
print(model.evaluateModel())
    

# driver for AND
print('\n\n')
model = PerceptronAND(2)
weighs = model.learnAND()
print(weighs)
print(model.evaluateModel())


