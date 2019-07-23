module Mod_addBinary ( addBinary ) where
import Prelude hiding (and, or) 
import Debug.Trace
import Splib
import Types
import Mod_toBinary
import Mod_fromBinary

addBinary l1 l2 = toBinary (l1dec+l2dec)
                  where
                    l1dec = fromBinary l1
                    l2dec = fromBinary l2