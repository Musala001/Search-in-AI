import matplotlib.pyplot as plt
from collections import defaultdict

bfs = defaultdict(list)
a1 = defaultdict(list)
a2 = defaultdict(list)

with open("results.txt") as f:
    for line in f:
        parts = line.strip().split()
        if len(parts) != 5:
            continue

        puzzle = parts[0]
        sol = int(parts[1])
        bfs_nodes = int(parts[2])
        a1_nodes = int(parts[3])
        a2_nodes = int(parts[4])

        bfs[sol].append(bfs_nodes)
        a1[sol].append(a1_nodes)
        a2[sol].append(a2_nodes)

def average(d):
    xs = sorted(d.keys())
    ys = []
    for k in xs:
        ys.append(sum(d[k]) / len(d[k]))
    return xs, ys

x1, y1 = average(bfs)
x2, y2 = average(a1)
x3, y3 = average(a2)

plt.figure()

plt.plot(x1, y1, marker='o', label="BFS")
plt.plot(x2, y2, marker='o', label="A*-h1")
plt.plot(x3, y3, marker='o', label="A*-h2")

plt.yscale("log")

plt.xlabel("Solution Length")
plt.ylabel("Nodes Expanded (log scale)")
plt.title("Search Algorithm Comparison")
plt.legend()

plt.savefig("graph.png")
plt.show()