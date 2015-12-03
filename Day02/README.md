## Day 2

#### Problem
The elves are running low on wrapping paper and ribbon, and so they need to
submit an order for more. They have a list of the dimensions (length `l`, width
`w`, and height `h`) of each present, and only want to order exactly as much as
they need. Assume the following:

* The dimensions are contained in `input.txt` and are given in feet.
* Every present is a box, so the surface area of each present is given by
`2*l*w + 2*w*h + 2*h*l`.
* The elves also order extra paper for each present, equal to the area of the
smallest side.
* The elves require ribbon equal to the perimeter of the smallest side, plus
ribbon equal to the volume of the box for the bow.

Based on these assumptions, determine the following:

1. How many total square feet of wrapping paper should the elves order?
2. How many total feet of ribbon should the elves order?

#### Solution
To solve this problem, I did a similar solution to Day 1 where I implemented a
scanner generator (using Flex), but also implemented a parser generator (using
Bison) on top of that. The parser's operation should be obvious: it analyzes
each dimension, which is in the form `NUMxNUMxNUM\n`, and computes the needed
paper and ribbon for each dimension. It then sums together these values for each
dimension it encounters in the file.

Scanner: `day2.lex`

Parser: `day2.y`
