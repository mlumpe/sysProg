import Splib hiding (x,r,i,l1,l2)
import Debug.Trace
import Types

--Einbinden der selbst geschriebenen Programme
import Mod_absolute
import Mod_factorial
import Mod_fibonacci
import Mod_isPrime
import Mod_nthPrime

--Code zum Testen der geschriebenen Funktionen
f1 n = 2*n-1
f2 n = sp_pow 2 n
f3 n = 'z'

main = do   putStrLn ("absolute -3: ")
            putStrLn (show (absolute (-3)))
            putStrLn ("absolute 2: ")
            putStrLn (show (absolute (2)))
            putStrLn ("absolute 0: ")
            putStrLn (show (absolute (0)))
            putStrLn ("factorial 0: ")
            putStrLn (show (factorial (0)))
            putStrLn ("factorial 1: ")
            putStrLn (show (factorial (1)))
            putStrLn ("factorial 4: ")
            putStrLn (show (factorial (4)))
            putStrLn ("factorial 5: ")
            putStrLn (show (factorial (5)))
            putStrLn ("fibonacci 0:")
            putStrLn (show (fibonacci (0)))
            putStrLn ("fibonacci 1:")
            putStrLn (show (fibonacci (1)))
            putStrLn ("fibonacci 2:")
            putStrLn (show (fibonacci (2)))
            putStrLn ("fibonacci 3:")
            putStrLn (show (fibonacci (3)))
            putStrLn ("fibonacci 6:")
            putStrLn (show (fibonacci (6)))
            putStrLn ("isPrime 0:")
            putStrLn ( show ( isPrime 0) )
            putStrLn ("isPrime 1:")
            putStrLn ( show ( isPrime 1) )
            putStrLn ("isPrime 2:")
            putStrLn ( show ( isPrime 2) )
            putStrLn ("isPrime 3:")
            putStrLn ( show ( isPrime 3) )
            putStrLn ("isPrime 4:")
            putStrLn ( show ( isPrime 4) )
            putStrLn ("isPrime 17:")
            putStrLn ( show ( isPrime 17) )
            putStrLn ("nthPrime 1")
            putStrLn (show ( nthPrime 1))
            putStrLn ("nthPrime 2")
            putStrLn (show ( nthPrime 2))
            putStrLn ("nthPrime 3")
            putStrLn (show ( nthPrime 3))
            putStrLn ("nthPrime 10")
            putStrLn (show ( nthPrime 10))
