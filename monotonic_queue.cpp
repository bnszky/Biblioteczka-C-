#include "monotonic_queue.hpp"

template <class T>
class monotonic_queue{

	#define num numeric_limits<T>

	struct element{
		T v;
		T maxi;
		T mini;
	};

	stack <element> s1, s2;

	void flip(){
		if (s2.size() > 1) return;

		while(s1.size() > 1){

			T val = s1.top().v;
			s1.pop();

			s2.push({
				val,
				std::max(val, s2.top().maxi),
				std::min(val, s2.top().mini)
			});

		}
	}

public:

	monotonic_queue(){
		s1.push({-1, num::min(), num::max()});
		s2.push({-1, num::min(), num::max()});
	}

	void push(T val){
		s1.push({
			val,
			std::max(val, s1.top().maxi),
			std::min(val, s1.top().mini)
		});
	} 

	void pop(){
		flip(); s2.pop();
	}

	T min() {return std::min(s1.top().mini, s2.top().mini);}
	T max() {return std::max(s1.top().maxi, s2.top().maxi);}

	T front(){
		flip(); return s2.top().v;
	}

	size_t size() {return s1.size() + s2.size() - 2;}
	bool empty() {return ((s1.size() + s2.size() - 2) == 0);}

};

template <class T>
class monotonic_stack{

	#define num numeric_limits<T>

	struct element{
		T v;
		T maxi;
		T mini;
	};

	stack <element> S;

public:

	monotonic_stack() { S.push({-1, num::min(), num::max()});}

	void push(T val){
		S.push({
			val,
			std::max(S.top().maxi, val),
			std::min(S.top().mini, val)
		});
	}

	void pop() {S.pop();}
	T top() { return S.top().v;}
	T max() { return S.top().maxi; }
	T min() { return S.top().mini; }

	size_t size() { return S.size()-1; }
	bool empty() { return (S.size()-1 == 0); }

};