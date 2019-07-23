{-
  Hier können globale Funktionen und Typaliase reingeschrieben
  werden, welche für alle Funktionen gebraucht werden.   
-}

module Types where
import Splib


--Nachfolgend einige Beispiele 
type ListInt = [Int]
type List2Int = [[Int]]
type ListString = [String]


firstNNumbers n = [1..n]