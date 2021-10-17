#makefile
.SILENT: main

main:
	g++ main.cpp -o man
	@echo "-----------------------\n"
	./man
	@echo "\n-----------------------\n"

bridge:
	g++ bridges.cpp -o bri
	./bri

bipgraph:
	g++ bipartite_graph.cpp -o bigraph
	./bigraph < input.txt
