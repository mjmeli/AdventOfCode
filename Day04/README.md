## Day 4

#### Problem
Santa wants to mine some AdventCoins (very similar to bitcoins) to use as gifts.
To do this, he needs to find MD5 hashes which, in hexadecimal, start with a
certain number of zeroes. Assume the following:

* Santa's secret key is `bgvyzdsv`.
* The input to the MD5 hash is the secret key followed by a decimal number.
* The decimal number will be positive with no leading zeroes.

Based on these assumptions, determine the following:

1. What is the lowest positive number that produces a hash with **at least
five** leading zeroes?
2. What is the lowest positive number that produces a hash with **at least
six** leading zeroes?

#### Solution
Perhaps this is the easiest puzzle so far, assuming you don't try to implement
the MD5 hashing function yourself. To solve this, I decided to use Python, as it
makes getting an MD5 hash very easy. In essence, I increment through all the
positive numbers until I find a hash with 5 leading zeroes. I then continue from
this number until I find a hash with 6 leading zeroes (if you did not find 5
leading zeroes, you couldn't have found 6 leading zeroes).
