g++ convex_hull.cpp -o conv
g++ gen.cpp -o gen

./gen > input.txt
./conv < input.txt > output.txt
python3 view.py < output.txt