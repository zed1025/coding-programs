

import random

class lab01:
	def __init__(self):
		pass
	def notNeuron(self, x):
		if x<1:
			return 1
		return 0

	def orNeuron(self, n):
		seq_generated = []
		for i in range(n):
			seq_generated.append(random.randint(0, 1))
			
		print("Sequence Generated: ", seq_generated)
		x = 0
		x = sum(seq_generated)
		print('Sum: ', x)
		if x >= 1:
			return 1
		return 0

	def andNeuron(self, n):
		seq_generated = []
		for i in range(n):
			seq_generated.append(random.randint(0, 1))
			
		print("Sequence Generated: ", seq_generated)
		x = 0
		x = sum(seq_generated)
		print('Sum: ', x)
		if x >= n:
			return 1
		return 0
		

model = lab01()

print("OR Neuron")
x = model.orNeuron(5)
print('Output: ', x)

print("AND Neuron")
y = model.andNeuron(5)
print('Output: ', y)

print("NOT Neuron")
print('Output: ', model.notNeuron(1))
print('Output: ', model.notNeuron(0))



