#include <fstream>
#include <vector>
using namespace std;

bool Branje_Stevil(vector<int> &vec, const char s[]) {
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

    for (int i = 0; i<velikost; i++)
        output << polje[i] << ' ';
}
void Counting_Sort(vector<int>& A) {
    // Min, Max v A
    int min_val = A[0];
    int max_val = A[0];
    for (int i = 1; i < A.size(); i++) {
        if (A[i] < min_val) {
            min_val = A[i];
        }
        if (A[i] > max_val) {
            max_val = A[i];
        }
    }

    int range = max_val - min_val + 1; // Razpon števil
    vector<int> C(range, 0); // Pomožno polje C, inicializirano na 0

    // Prilagodimo vrednosti v A na pozitiven interval
    for (int i = 0; i < A.size(); i++) {
        A[i] -= min_val;  // Pomaknemo vse vrednosti tako, da so pozitivne
    }

    for (int num : A) {
        C[num]++;
    }

    // Seštevanje vrednosti v C za prilagoditev indeksa
    for (int i = 1; i < range; i++) {
        C[i] += C[i - 1];
    }

    vector<int> B(A.size());
    // Populiramo polje B in zmanjšamo število v C
    for (int i = A.size() - 1; i >= 0; i--) {
        B[C[A[i]] - 1] = A[i];
        C[A[i]]--;
    }

    A = B; // Kopiramo izhodno polje B nazaj v A
    // Po sortiranju vrnemo vrednosti nazaj v izvorni interval [min, max]
    for (int i = 0; i < A.size(); i++) {
        A[i] += min_val;
    }
}

void Roman_Sort(vector<int>& A) {
    int min_val = A[0];
    int max_val = A[0];
    for (int i = 1; i < A.size(); i++) {
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

    // Populiramo polje B tako, da za vsako neničelno vrednost v C ponovimo to vrednost v B
    for (int i = 0; i < range; i++) {
        while (C[i] > 0) {
            B[idx++] = i + min_val;
            C[i]--;
        }
    }

    // Kopiramo izhodno polje B nazaj v A
    A = B;
}

int main(int argc, const char* argv[]) {
    vector<int> A;

    if (argc < 3) return 0;
    if (!Branje_Stevil(A, argv[2])) return 0;

    if (argv[1][0] == '0') {
        //counting sort
        Counting_Sort(A);
    }
    else {
        //roman sort
        Roman_Sort(A);
    }
    Izpis_Stevil(&A[0],A.size());

    return 0;
}