import matplotlib.pyplot as plt
import networkx as nx

colors = ['red', 'green', 'blue', 'chocolate', 'peru', 'darkorange', 'lime', 'cyan', 'indigo', 'violet', 'midnightblue', 'pink']

G = nx.Graph()

m = input()
for i in range(0, int(m)):
    a = (input().split())
    G.add_edge(a[0], a[1])

am = int(input())
for j in range(0, am):
    r = int(input())
    for i in range(0, int(r)):
        a = (input().split())
        G[a[0]][a[1]]['color'] = colors[j]

art_points = int(input())
H = nx.Graph()
for i in range(0, art_points):
    r = (input())
    H.add_node(r)

node_colors = ['grey' if not node in H.nodes() else 'red' for node in G.nodes()]
print(node_colors)

#nx.draw(G, with_labels = True)
edge_colors = nx.get_edge_attributes(G,'color').values()
print(edge_colors)

#values = [val_map.get(node, 'b') for node in G.nodes()]
pos=nx.spring_layout(G)
nx.draw_networkx(G, pos, edgecolors = 'black', node_color = node_colors, with_labels = True, width = 5, node_size = 1000, edge_color = edge_colors)
plt.show()