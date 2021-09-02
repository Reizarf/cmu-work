#include <vector>
#include <algorithm>
#include <cstdlib>
#include <ctime>

using namespace std;

int shellSort(vector<int> &arr);
int mergE(vector<int> &arr, int start, int middle,int end, int &comparisons);
int mergeSorT(vector<int> &arr, int start, int end,int &comparisons);
int heapify(vector<int> &arr, int i, int size_);
void buildMaxHeap(vector<int> &arr);
void swtichh(vector<int> &arr, int x, int y);
int quickSort(vector<int> &vec, int L, int R, int &Comparisons);
