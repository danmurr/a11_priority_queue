#include <vector>
std::vector<int> top_sqrtN_sorted(const std::vector<int>& A){
    using namespace std;
    int N = A.size();
    int M = static_cast<int>(sqrt(N));
    vector<int> result;
    result.reserve(M);
    
    for(int i = N - M; i < N; ++i){
        result.push_back(A[i]);
    }
    
    sort(result.begin(), result.end());
    return result;
}