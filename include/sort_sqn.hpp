#include <vector>
#include <queue>
std::vector<int> top_sqrtN_sorted(const std::vector<int>& A){
    using namespace std;
    int N = static_cast<int>(A.size());
    if(N == 0) return {};

    int k = static_cast<int>(ceil(sqrt(static_cast<double>(N))));

    vector<int> heapContainer;
    heapContainer.reserve(static_cast<size_t>(k) + 1);
    priority_queue<int, vector<int>, greater<int>> minHeap(greater<int>(), std::move(heapContainer));

    for (int x : A){
        minHeap.push(x);
        if (static_cast<int>(minHeap.size()) > k){
            minHeap.pop();
        }
    }

    vector<int> result;
    result.reserve(minHeap.size());
    while(!minHeap.empty()){
        result.push_back(minHeap.top());
        minHeap.pop();
    }
    reverse(result.begin(), result.end());
    return result;
}