#include <iostream>
#include <vector>
#include <map>
#include <cassert>
using namespace std;

class Solution {
public:
    int maxNumberOfFamilies(int n, vector<vector<int>>& reservedSeats) {
        vector<char> filas(10, 'X');
        vector<vector<char>> cine(n, filas);

        map<int, vector<int>> ocupado;
        for (const vector<int>& asiento : reservedSeats) {
            ocupado[asiento[0]-1].push_back(asiento[1]);
        }

        int posit = 0;

        for (int i = 0; i < n; i++) {
            int posi = 2;
            auto it = ocupado.find(i);
            if (it != ocupado.end()) {
                for (int j: it->second) {
                    cine[i][j - 1] = 'o';
                }

                if (cine[i][1] == 'o' || cine[i][2] == 'o' || cine[i][3] == 'o' || cine[i][4] == 'o') {
                    posi--;
                }

                if ((cine[i][5] == 'o' || cine[i][6] == 'o' || cine[i][7] == 'o' || cine[i][8] == 'o') ) {
                    posi--;
                }
                if(posi==2){
                    if (cine[i][3] == 'o' || cine[i][4] == 'o' || cine[i][5] == 'o' || cine[i][6] == 'o') {
                        posi--;
                    }
                }

            }
            posit += posi;

            // Imprimir la matriz cine en cada iteración
            cout << "Matriz cine después de la iteración " << i + 1 << ":\n";
            for (const auto& fila : cine) {
                for (char asiento : fila) {
                    cout << asiento << " ";
                }
                cout << endl;
            }
            cout << endl;
        }





        return posit;
    }
};

int main() {
    Solution solution;

    vector<vector<int>> reservedSeats1 = {{2, 1}, {1, 8}, {2, 6}};
    cout << "Test 1: Reserved Seats: " << reservedSeats1.size() << ", Result: " << solution.maxNumberOfFamilies(2, reservedSeats1) << " (expected: 2)\n";

    vector<vector<int>> reservedSeats2 = {{4, 3}, {1, 4}, {4, 6}, {1, 7}};
    cout << "Test 2: Reserved Seats: " << reservedSeats2.size() << ", Result: " << solution.maxNumberOfFamilies(4, reservedSeats2) << " (expected: 4)\n";

    vector<vector<int>> reservedSeats3 = {{1, 2}, {1, 3}, {1, 8}, {2, 6}, {3, 1}, {3, 10}};
    cout << "Test 3: Reserved Seats: " << reservedSeats3.size() << ", Result: " << solution.maxNumberOfFamilies(3, reservedSeats3) << " (expected: 4)\n";

    vector<vector<int>> reservedSeats4 = {{1, 1}, {1, 4}, {1, 7}, {2, 5}, {3, 2}, {3, 10}};
    cout << "Test 4: Reserved Seats: " << reservedSeats4.size() << ", Result: " << solution.maxNumberOfFamilies(3, reservedSeats4) << " (expected: 2)\n";

    return 0;
}
