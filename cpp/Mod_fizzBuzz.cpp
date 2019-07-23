#pragma once

//Signaturen
String fizzBuzz(Int n);
String fizzBuzz_h1(Int i);
Bool fizzBuzz_h2(String x);
String fizzBuzz_h3(String x, String y);

//Definitionen
String fizzBuzz(Int n) {
    return 
    reduce<String>(
        fizzBuzz_h3,
        filter<String>(
            fizzBuzz_h2,
            map<Int,String>(
                fizzBuzz_h1,
                firstNNumbers(n))));
}

String fizzBuzz_h1(Int i) {
    return 
    sp_if<String>( 
        sp_eq(sp_mod(i, 3), 0),
        sp_if<String>(
            sp_eq(sp_mod(i, 5), 0),
            join(show(i), " : 15"),
            join(show(i), " : 3")
        ),
        sp_if<String>(
            sp_eq(sp_mod(i,5),0),
            join(show(i)," : 5"),
            ""
        )
    ); 
} 

Bool fizzBuzz_h2(String x) {
    return sp_neq<String>(x,"");
}

String fizzBuzz_h3(String x, String y) {
    return join(join(x,"\n"),y);
}
