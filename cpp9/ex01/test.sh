#!/bin/bash
# Quick test script. Run with:  bash test.sh

echo "===== subject examples ====="
echo -n '"8 9 * 9 - 9 - 9 - 4 - 1 +"  expect 42  -> '; ./RPN "8 9 * 9 - 9 - 9 - 4 - 1 +"
echo -n '"7 7 * 7 -"                  expect 42  -> '; ./RPN "7 7 * 7 -"
echo -n '"1 2 * 2 / 2 * 2 4 - +"      expect 0   -> '; ./RPN "1 2 * 2 / 2 * 2 4 - +"
echo -n '"(1 + 1)"                    expect Error -> '; ./RPN "(1 + 1)"

echo
echo "===== order matters ====="
echo -n '"9 3 -"   expect 6  -> '; ./RPN "9 3 -"
echo -n '"8 2 /"   expect 4  -> '; ./RPN "8 2 /"

echo
echo "===== simple ====="
echo -n '"3 4 +"   expect 7  -> '; ./RPN "3 4 +"
echo -n '"5"       expect 5  -> '; ./RPN "5"

echo
echo "===== errors (all must print Error) ====="
echo -n 'no argument        -> '; ./RPN
echo -n 'too many args      -> '; ./RPN "1 2 +" "3"
echo -n 'empty string       -> '; ./RPN ""
echo -n '"1 +"              -> '; ./RPN "1 +"
echo -n '"+"                -> '; ./RPN "+"
echo -n '"1 2 3 +"          -> '; ./RPN "1 2 3 +"
echo -n '"5 0 /"            -> '; ./RPN "5 0 /"
echo -n '"12 3 +"           -> '; ./RPN "12 3 +"
echo -n '"a b +"            -> '; ./RPN "a b +"
echo -n '"1 2 %"            -> '; ./RPN "1 2 %"

echo
echo "===== stdout vs stderr ====="
echo "next line must be EMPTY (errors go to stderr, not stdout):"
./RPN "(1 + 1)" 2>/dev/null
echo "--- end ---"
