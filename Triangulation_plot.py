import matplotlib.pyplot as plt

triangles = []
with open("triangles.txt") as f:
    for line in f:
        x1,y1,x2,y2,x3,y3 = map(float, line.split())
        triangles.append([[x1,y1],[x2,y2],[x3,y3]])

for tri in triangles:
    x = [p[0] for p in tri] + [tri[0][0]]  # close triangle
    y = [p[1] for p in tri] + [tri[0][1]]
    plt.plot(x, y, 'b-')

all_x = [p[0] for tri in triangles for p in tri]
all_y = [p[1] for tri in triangles for p in tri]
plt.scatter(all_x, all_y, c='r')

plt.show()
