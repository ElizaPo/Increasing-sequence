#include <iostream>
using namespace std;

const unsigned int max_numTests = 25;
const unsigned long long max_length = 200000;
const unsigned long long max_order = 1000000000;

unsigned long long Longest_growing_order(unsigned long long a[], unsigned long long n) {
    unsigned long long * ending = new unsigned long long[n];
    unsigned long long length = 1;

    ending[0] = a[0];

    for (unsigned long long i = 1; i < n; ++i) {
        if (a[i] < ending[0]) {
            ending[0] = a[i];
        } else if (a[i] > ending[length - 1]) {
            ending[length++] = a[i];
        } else {
            unsigned long long first = 0, last = length - 1;
            while (first < last) {
                unsigned long long mid = first + (last - first) / 2;
                if (ending[mid] < a[i]) {
                    first = mid + 1;
                } else {
                    last = mid;
                }
            }
            ending[first] = a[i];
        }
    }

    delete[] ending;
    ending=NULL;

    return length;
}

int main() {
    int numTests;
    cin >> numTests;

    if (numTests < 1 or numTests > max_numTests) {
        cout << "Error" << endl;
        return 1;
    }

    unsigned long long *length=new unsigned long long [numTests];
    unsigned long long *result = new unsigned long long [numTests];

    for (unsigned long long test = 0; test < numTests; ++test) {
        cin >> length[test];
        bool error = false;

        if (length[test] > max_length) {
            cout << "Error" << endl;
            result[test] = 0;
            continue;
        }

        unsigned long long test_length = length[test];
        unsigned long long* order = new unsigned long long[test_length];
        for (unsigned long long i = 0; i < test_length; ++i) {
            cin >> order[i];

            if (order[i] > max_order) {
                cout << "Error" << endl;
                error = true;
                break;
            }
        }

        if (!error) {
            result[test] = Longest_growing_order(order, test_length);
            cout<<result[test]<<endl;
        }

        delete[] order;
        order=NULL;
    }

    delete[] length;
    length = NULL;

    delete[] result;
    result = NULL;

    return 0;
}
