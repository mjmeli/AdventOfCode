## Day 12

#### Problem
Santa's Accounting-Elves need help balancing the books after a recent order.
Unfortunately, their accounting software uses a peculiar storage format. That's
where you come in.

They have a JSON document which contains a variety of things: arrays (`[1,2,3]`),
objects (`{"a":1, "b":2}`), numbers, and strings. Your first job is to simply
find all of the numbers throughout the document and add them together.

The input file is `input.json`.

##### Part 1
What is the sum of all the numbers in the document?

##### Part 2
Ignore any object (and all of it's children) which has any property with the
value `"red"`. Do this only for objects (`{...}`), not arrays (`[...]`).

#### Solution
For this problem, I decided to make use of Python's JSON library. This made the
task relatively simple. I made use of recursion to delve deeper into the JSON
object, finding integers or finding objects with "red". Overall, the script
is relatively simple, but I think my solution is cool because it was the first
time that I made use of list comprehension, lambda's and the map function in Python.

`day12.py` - Python file that implements solution
