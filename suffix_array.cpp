#include "suffix_array.hpp"

namespace SA{

long long diff_subwords(int lcp[], long long len){ // liczba roznych podslow

	long long sum = (len*(len+1))/2;
	for(int i = 0; i<len; i++) sum -= lcp[i];
	return sum;

}

void LCP(string nap, int sa[], int rank[], int lcp[]){ // Longest common prefix

	int len = nap.size();
	nap.push_back('#');

	lcp[0] = 0;

	////////////////////////////
	int l = 0;
	for(int i = 0; i < len; i++){
		if(rank[i] > 0){
			while( nap[(i + l)] == nap[sa[rank[i] - 1] + l]) l++;
		}
		lcp[rank[i]] = l;
		if(l > 0) l--;
	}
	////////////////////////////

}

void building_SA_with_KMR(string nap, int kmr[], int sa[]){ // Karp-Miller-Rosenberg

int len = nap.size(); 
int base = 1; 

/////////////
struct point{
	int st;
	int nd;
	int index;
};

auto check = [len, kmr](int val) {return ((val >= len) ? -1 : kmr[val]);};

auto cmp = [](const point &a, const point &b){
	if (a.st == b.st) return (a.nd < b.nd);
	else return (a.st < b.st);
};
////////////

// przypisywanie wartosci dla 2^0
for(int i = 0; i<len; i++) kmr[i] = nap[i] - 'a';

// obliczanie kmr dla kolejnych poteg 2
while( base < len ){

	// laczenie 2^k-1 w 2^k i sortowanie
	vector <point> pairs;
	for(int i = 0; i<len; i++){
		pairs.push_back({kmr[i], check(i+base) , i});
	}
	sort(pairs.begin(), pairs.end(), cmp); // brzydki sort == brzydkie zadanie

	// przypisywanie nowej kolejnosci
	int j = -1;
	for(int i = 0; i<len; i++){
		if(i > 0 && (pairs[i].st == pairs[i-1].st && pairs[i].nd == pairs[i-1].nd)) j--;
		j++; kmr[pairs[i].index] = j;
	}
	base *= 2;

}

for(int i = 0; i<len; i++) sa[kmr[i]] = i;

}

};