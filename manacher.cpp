#include "manacher.hpp"

// oblicza ilosc wszystkich palindromow w podciagach (nap)
template <class typ>
typ manachers_algorithm(string nap){

	int dp[2][nap.length() + 5];
	for(int i = 0; i <= nap.size()+1; i++) {dp[0][i] = 0; dp[1][i] = 0;}
	
	int dl = nap.length();
	typ result=0;

	nap = "#" + nap + "$";

	//nieparzyste - j = 1
	//parzyste - j = 0
	//result - ilosc palindromow
	
	for(int j=0;j<=1;j++){

	dp[j][0] = 0; int i=1;
	int r = 0;
	while(i <= dl) {
		while(nap[i - r] == nap[i + j + r]) r ++;
		dp[j][i] = r;
		result += r;
		int k = 1;
		while (k < r && (dp[j][i-k] != (r - k))){
			dp[j][i+k] = min( dp[j][i-k], r-k );
			result += dp[j][i+k];
			k++;
		}

		r = max(r-k, 0);
		i+=k;
	}

	}

	return result;

}