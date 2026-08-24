#!/bin/bash
# Run with: bash test.sh

echo "===== subject example ====="
./PmergeMe 3 5 9 7 4

echo
echo "===== your paper examples ====="
./PmergeMe 5 3 8 1 9 2 7
./PmergeMe 6 2 9 4 1 8
./PmergeMe 3 7 1 9 4 6 2

echo
echo "===== edge cases ====="
echo "- one element:"
./PmergeMe 42
echo "- two elements reversed:"
./PmergeMe 9 1
echo "- already sorted:"
./PmergeMe 1 2 3 4 5
echo "- duplicates:"
./PmergeMe 5 3 5 1 3

echo
echo "===== errors (must print Error on stderr) ====="
echo -n "no args        -> "; ./PmergeMe
echo -n "negative       -> "; ./PmergeMe "-1" "2"
echo -n "letters        -> "; ./PmergeMe 1 2 abc
echo -n "over INT_MAX   -> "; ./PmergeMe 2147483648
echo -n "empty string   -> "; ./PmergeMe ""

echo
echo "===== 3000 numbers (subject requirement) ====="
./PmergeMe $(shuf -i 1-100000 -n 3000 | tr "\n" " ") | head -c 300
echo "..."
./PmergeMe $(shuf -i 1-100000 -n 3000 | tr "\n" " ") | tail -n 2

echo
echo "===== verify 3000 are actually sorted ====="
./PmergeMe $(shuf -i 1-100000 -n 3000 | tr "\n" " ") \
	| grep "^After" | tr ' ' '\n' | grep -E '^[0-9]+$' | sort -nc \
	&& echo "SORTED OK" || echo "NOT SORTED - BUG"
