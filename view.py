import matplotlib.pyplot as plt
import matplotlib.lines as lines

points_x = []
points_y = []

n = int(input())
for i in range(0,n):
    c = (input().split())
    points_x.append(int(c[0]))
    points_y.append(int(c[1]))

ax = plt.subplot(1, 1, 1)
ax.scatter(points_x, points_y)

m = int(input())
last_X = -1
last_Y = -1
first_X = -1
first_Y = -1
for i in range(0,m):

    a = input().split()
    if i == 0:
        first_X = int(a[0])
        first_Y = int(a[1])

    if i > 0:
        line = lines.Line2D([last_X, int(a[0])], [last_Y, int(a[1])],)
        ax.add_line(line)

    last_X = int(a[0])
    last_Y = int(a[1])

line = lines.Line2D([last_X, first_X], [last_Y, first_Y],)
ax.add_line(line)

plt.show()