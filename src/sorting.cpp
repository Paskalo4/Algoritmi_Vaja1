#include <fstream>
#include <vector>
using namespace std;

bool Branje_Stevil(vector<int>& vec, const char s[]) {
    ifstream input(s);
    int st;

    if (!input.is_open()) {
        return false;
    }

    while (!input.eof()) {
        input >> st;
        vec.push_back(st);
        while (isspace(input.peek())) input.get();
    }
    input.close();
    return true;
}

void Izpis_Stevil(int* polje, unsigned int velikost) {
    ofstream output("out.txt");

    for (unsigned int i = 0; i < velikost; i++)
        output << polje[i] << ' ';
}

void Counting_Sort(vector<int>& A) {
    int min_val = A[0];
    int max_val = A[0];
    for (size_t i = 1; i < A.size(); i++) {
        if (A[i] < min_val) {
            min_val = A[i];
        }
        if (A[i] > max_val) {
            max_val = A[i];
        }
    }

    int range = max_val - min_val + 1;
    vector<int> C(range, 0);

    for (int i = 0; i < A.size(); i++) {
        A[i] -= min_val;
    }

    for (int num : A) {
        C[num]++;
    }

    for (int i = 1; i < range; i++) {
        C[i] += C[i - 1];
    }

    vector<int> B(A.size());
    for (int i = A.size() - 1; i >= 0; i--) {
        B[C[A[i]] - 1] = A[i];
        C[A[i]]--;
    }

    A = B;
    for (int i = 0; i < A.size(); i++) {
        A[i] += min_val;
    }
}

void Roman_Sort(vector<int>& A) {
    int min_val = A[0];
    int max_val = A[0];
    for (size_t i = 1; i < A.size(); i++) {
        if (A[i] < min_val) {
            min_val = A[i];
        }
        if (A[i] > max_val) {
            max_val = A[i];
        }
    }

    int range = max_val - min_val + 1;
    vector<int> C(range, 0);

    for (int num : A) {
        C[num - min_val]++;
    }

    vector<int> B(A.size());
    int idx = 0;

    for (int i = 0; i < range; i++) {
        while (C[i] > 0) {
            B[idx++] = i + min_val;
            C[i]--;
        }
    }

    A = B;
}
