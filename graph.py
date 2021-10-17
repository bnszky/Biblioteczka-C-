import matplotlib.pyplot as plt
import networkx as nx
G = nx.Graph()
R = nx.Graph()

m = input()
for i in range(0, int(m)):
    a = (input().split())
    G.add_edge(a[0], a[1])

r = int(input())
for i in range(0, int(r)):
    a = (input().split())
    R.add_edge(a[0], a[1])

#nx.draw(G, with_labels = True)

edge_colors = ['black' if not edge in R.edges() else 'red' for edge in G.edges()]
print(edge_colors)

#values = [val_map.get(node, 'b') for node in G.nodes()]
pos=nx.spring_layout(G)
nx.draw_networkx(G, pos, with_labels = True, width = 5, node_size = 1000, edge_color = edge_colors)
plt.show()

#labels = nx.get_edge_attributes(G,'weight')
#nx.draw_networkx_edge_labels(G, pos, edge_labels=labels)
