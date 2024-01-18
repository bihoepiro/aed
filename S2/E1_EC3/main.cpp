#include <iostream>
#include <cassert>
#include <map>
#include <cmath>
using namespace std;

/*
 * Ian Gonzales
 * Samanta Chang
 * Bihonda Epiquien
 * */

class Solution {
public:
    int maxNumberOfBalloons(string text) {
		// add your code
        map<char, int> mapeo;
        for (char letra: text) {
            mapeo[letra]++;
        }
        int valor_minimo = mapeo['b'];
        if (valor_minimo > mapeo['a']) {
            valor_minimo = mapeo['a'];
        }
        if (valor_minimo > floor(mapeo['l'] / 2)) {
            valor_minimo = floor(mapeo['l'] / 2);
        }
        if (valor_minimo > floor(mapeo['o'] / 2)) {
            valor_minimo = floor(mapeo['o'] / 2);
        }
        if (valor_minimo > mapeo['n']) {
            valor_minimo = mapeo['n'];
        }
		return valor_minimo;
    }
};

void test(){
	assert(Solution().maxNumberOfBalloons("nlaebolko") == 1);
	assert(Solution().maxNumberOfBalloons("loonbalxballpoon") == 2);
	assert(Solution().maxNumberOfBalloons("baalooncokjanshbalokkbalooknlnno") == 2);
	assert(Solution().maxNumberOfBalloons("nobalonccoooouuugklllllonxxxxzzzz") == 1);
	assert(Solution().maxNumberOfBalloons("jkabdikljiurgjhbsadfkjfuabasdfjdfuahdbao") == 0);
}

int main(){
	test();
	return 0;
}
