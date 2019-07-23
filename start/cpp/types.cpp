/*
  Hier können globale Funktionen und Typaliase reingeschrieben
  werden, welche für alle Funktionen gebraucht werden.   
*/

#pragma once


//Nachfolgend einige Beispiele 
using ListInt = List<Int>;            
using List2Int = List<List<Int>>;            
using ListString = List<String>;


ListInt firstNNumbers(Int n) {
    ListInt res;
    for(int i=1; i<=n; i++) {
        res = append(res, i);
    }
    return res;
}