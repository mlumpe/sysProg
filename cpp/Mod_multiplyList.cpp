template <typename T>
List<T> multiplyList(List<T> list, Int n) {
    List<T> resultList = {};
    
    for (int i = 0; i < length(list); i++) {
        for (int j = 0; j < n; j++) {
            resultList = append(resultList, get(list, i));
        }
    }
    
    return resultList;
}
