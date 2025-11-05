#include <vector>
#include <queue>
#include <cmath>
#include <algorithm>

std::vector<int> top_sqrtN_sorted(const std::vector<int>& A) {
    const size_t N = A.size();
    if (N == 0) return {};

    size_t k = static_cast<size_t>(std::ceil(std::sqrt(static_cast<double>(N))));
    if (k == 0) return {};

    std::priority_queue<int, std::vector<int>, std::greater<int>> pq;
    pq = std::priority_queue<int, std::vector<int>, std::greater<int>>();

    for (int x : A) {
        if (pq.size() < k) {
            pq.push(x);
        } else if (x > pq.top()) {
            pq.pop();
            pq.push(x);
        }
    }

    std::vector<int> result;
    result.reserve(pq.size());
    while (!pq.empty()) {
        result.push_back(pq.top());
        pq.pop();
    }

    std::sort(result.begin(), result.end(), std::greater<int>());

    return result;
}