#include <vector>
#include <queue>
std::vector<int> top_sqrtN_sorted(const std::vector<int>& A){
    using namespace std;
    int N = A.size();
    int k = static_cast<int>(sqrt(N));
    
    priority_queue<int, vector<int>, greater<int>> minHeap;
    
    for(int i = 0; i < N; ++i){
        minHeap.push(A[i]);
        if(minHeap.size() > k){
            minHeap.pop();
        }
    }
    
    vector<int> result;
    while(!minHeap.empty()){
        result.push_back(minHeap.top());
        minHeap.pop();
    }
    
    sort(result.begin(), result.end());
    return result;
}