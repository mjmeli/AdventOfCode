## Day 11

#### Problem
When Santa's passwords expire, he finds his new password by incrementing his old
password repeatedly until it is valid.

Incrementing words as follows. You increase the rightmost letter one step. If it
was `z`, then it wraps around to `a`, and then the next letter to the left is
incremented. This repeats until one letter does not wraparound. For example,
`xz` will increment to `ya`, while `xx` will increment to `xy`.

At the same time, a new Security-Elf has implemented some drastic password
requirements:

* Passwords must include one increasing straight of at least three letters, like
`abc` or `xyz`.
* Passwords may not contain the letters `i`, `o`, or `l`.
* Passwords must contain at least two different, non-overlapping pairs of
letters, like `aa` or `zz`.

##### Part 1
Assuming Santa's expired password is `hepxcrrq`, what should Santa's next
password be?

##### Part 2
Assuming Santa's password from Part 1 now expires, what should Santa's next
password be?

#### Solution
The solution I developed for this problem is a straightforward C program. I
chose C because modifying strings in place is easy (the string will never grow),
especially with regards to incrementing (can just add `1` to the `char`). While
regex would have been useful for ensuring each possible password met the
requirements, ultimately the requirements are not too difficult to check for
through code and iterating through the string.

`day11.c` - C code file that implements solution
