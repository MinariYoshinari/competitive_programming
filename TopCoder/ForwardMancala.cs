class ForwardMancala(object):
	def findMoves(self, start):
		ans = []
		start = list(start)
		i = 1
		while(sum(1 for item in start if item > 0) != 1):
			while(i == 0):
				i = (i+1)%(n-1)+1;
			ans.append(i);
			m = start[i]
			start[i] = 0
			for j in range(m):
				start[(i+j+1)%m] += 1
		return tuple(ans)