import numpy as np
N= int(input())
array=list(map(int, input().split()))
array= np.sort(array)
for i in range(0, N):
	print(array[i], end=' ')