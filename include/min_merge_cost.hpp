#include <queue>
#include <vector>

int min_merge_cost(const std::vector<int>& fileSizes) {
    using namespace std;
    priority_queue<int, vector<int>, greater<int>> minHeap(fileSizes.begin(), fileSizes.end());
    
    int totalCost = 0;
    
    while (minHeap.size() > 1) {
        int first = minHeap.top(); minHeap.pop();
        int second = minHeap.top(); minHeap.pop();
        
        int mergeCost = first + second;
        totalCost += mergeCost;
        
        minHeap.push(mergeCost);
    }
    
    return totalCost;
}