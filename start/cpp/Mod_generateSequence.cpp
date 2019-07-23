template <typename T>
List<T> generateSequence(T (*f)(int), int n) {
    List<T> res = {};
    for (int i = 0; i < n; i++) {
        res = append(res, (*f)(i+1));
    }
    
    return res;
}
