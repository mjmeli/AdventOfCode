## Day 10

#### Problem

Today, the Elves are playing a game called look-and-say. They take turns making
sequences by reading aloud the previous sequence and using that reading as the
next sequence. For example, `211` is read as "one two, two ones", which becomes
`1221` (`1` `2`, `2` `1`s).

Look-and-say sequences are generated iteratively, using the previous value as
input for the next step. For each step, take the previous value, and replace
each run of digits (like `111`) with the number of digits (`3`) followed by the
digit itself (`1`).

The input that you should use is **1113222113**.

##### Part 1
After applying the look-and-say process 40 times on the puzzle input, what is
the length of the result?

##### Part 2
Now apply the process 50 times. What is the length of the new result?

#### Solution
A great way to solve this problem is by using a StringBuilder in Java. To do the
look-and-say process, I simply iterate over a string and count how many times
a character occurs in a row. Each time a new character starts, I append to the
StringBuilder the count and the character I was counting, and then I start
the process again. I do this over 40 iterations, where each iteration takes the
input of the previous iteration. The length of the string can then be taken.

The result shows that the string gets to be very large. My answer for Part 2 was
`3579328`. Assuming the string is encoded with UTF-16, this means the final
string grows to over 7 MB!

Java code: `Day10.java`
