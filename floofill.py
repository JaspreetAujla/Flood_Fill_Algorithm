M = 6
N = 6

def floodFillUtil(screen, a, b, previous, newScreen):
	
	if (a < 0 or a >= M or b < 0 or
		b >= N or screen[a][b] != previous or screen[a][b] == newScreen):
		return

	screen[a][b] = newScreen


	floodFillUtil(screen, a + 1, b, previous, newScreen)
	floodFillUtil(screen, a - 1, b, previous, newScreen)
	floodFillUtil(screen, a, b + 1, previous, newScreen)
	floodFillUtil(screen, a, b - 1, previous, newScreen)

def floodFill(screen, a, b, newScreen):
	previous = screen[a][b]
	if(previous==newScreen):
	 return
	floodFillUtil(screen, a, b, previous, newScreen)

screen = [
        [1, 1, 1, 1, 1,1],
		[1, 1, 1, 1, 1,0],
		[1, 0, 0, 1, 1,1],
		[1, 2, 2, 2, 2,1],
		[1, 1, 1, 2, 2,0],
		[1, 1, 1, 2, 2,1],
        ]

a = 3
b = 3
newScreen = 3
floodFill(screen, a, b, newScreen)

print ("New screen after call to floodFill:")
for i in range(M):
	for j in range(N):
		print(screen[i][j], end = ' ')
	print()


 