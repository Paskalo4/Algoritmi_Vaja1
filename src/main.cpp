#include "sorting.hpp"

int main(int argc, const char* argv[]) {
    std::vector<int> A;

    if (argc < 3) return 0;
    if (!Branje_Stevil(A, argv[2])) return 0;

    if (argv[1][0] == '0') {
        Counting_Sort(A);
    } else {
        Roman_Sort(A);
    }
    Izpis_Stevil(&A[0], A.size());

    return 0;
}
