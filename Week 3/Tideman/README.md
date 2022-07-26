# Tideman
For this program, you’ll implement a program that runs a Tideman election, per the below.

```
$ ./tideman Alice Bob Charlie
Number of voters: 5
Rank 1: Alice
Rank 2: Charlie
Rank 3: Bob

Rank 1: Alice
Rank 2: Charlie
Rank 3: Bob

Rank 1: Bob
Rank 2: Charlie
Rank 3: Alice

Rank 1: Bob
Rank 2: Charlie
Rank 3: Alice

Rank 1: Charlie
Rank 2: Alice
Rank 3: Bob

Charlie
```

-check50
-[x] :) tideman.c exists
-[x] :) tideman compiles
-[x] :) vote returns true when given name of candidate
-[x] :) vote returns false when given name of invalid candidate
-[x] :) vote correctly sets rank for first preference
-[x] :) vote correctly sets rank for all preferences
-[x] :) record_preferences correctly sets preferences for first voter
-[x] :) record_preferences correctly sets preferences for all voters
-[x] :) add_pairs generates correct pair count when no ties
-[x] :) add_pairs generates correct pair count when ties exist
-[x] :) add_pairs fills pairs array with winning pairs
-[x] :) add_pairs does not fill pairs array with losing pairs
-[x] :) sort_pairs sorts pairs of candidates by margin of victory
-[x] :) lock_pairs locks all pairs when no cycles
-[x] :) lock_pairs skips final pair if it creates cycle
-[x] :) lock_pairs skips middle pair if it creates a cycle
-[x] :) print_winner prints winner of election when one candidate wins over all others
-[x] :) print_winner prints winner of election when some pairs are tied

-style50
-[x] Looks good!
