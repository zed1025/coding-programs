
import itertools

class truth_table_generator:
	def __init__(self, n):
		self.n = n
		self.table = list(itertools.product([True, False], repeat=n))
		
	def andTT(self):
		table_ = self.table.copy()
		results = []
		for i in range(len(table_)):
			result = sum(table_[i])
			if result >= self.n:
				results.append(1)
			else:
				results.append(0)
		for i in range(len(table_)):
			print(table_[i], '\t', results[i])
	
	def orTT(self):
		table_ = self.table.copy()
		results = []
		for i in range(len(table_)):
			result = sum(table_[i])
			if result >= 1:
				results.append(1)
			else:
				results.append(0)
		for i in range(len(table_)):
			print(table_[i], '\t', results[i])


n = 4
tt = truth_table_generator(n)
print('Truth table for AND')
tt.andTT()
print('Truth table for OR')
tt.orTT()


