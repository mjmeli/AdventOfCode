## Day 16

#### Problem
Aunt Sue gave you a great gift and you want to send her a thank you card.
However, you actually have 500 Aunt Sue's and need help figuring out who to send
it to.

You try to figure it out using your knowledge of certain traits of each Sue. The
possible traits are:

* `children`, by human DNA age analysis.
* `cats`. It doesn't differentiate individual breeds.
* Several seemingly random breeds of dog: `samoyeds`, `pomeranians`, `akitas`,
and `vizslas`.
* `goldfish`. No other kinds of fish.
* `trees`, all in one group.
* `cars`, presumably by exhaust or gasoline or something.
* `perfumes`, which is handy, since many of your Aunts Sue wear a few kinds.

You know the following out the Sue who gave you the gift:

    children: 3
    cats: 7
    samoyeds: 2
    pomeranians: 3
    akitas: 0
    vizslas: 0
    goldfish: 5
    trees: 3
    cars: 2
    perfumes: 1

You only remember three traits for each Sue. Things missing from the list aren't
zero - you simply do not remember them. The descriptions of each Sue are in
`input.txt`.

##### Part 1

What is the number of the Sue that got you the gift?

##### Part 2

Now assume that the traits you have are slightly inaccurate. The `cats` and `trees`
values in the input file indicates that there are **greater than** that many,
while the `pomeranians` and `goldfish` readings indicate that there are **fewer
than** that many.

What is the number of the real Sue now?

#### Solution
I implemented this with a simple C program. I parsed the input and considered
each Sue individually. I checked that the values for each of the three traits
matched those of the Sue I know, and then if all three match, I assume I found
the right Sue and stop.

This is pretty straightforward. I did some tricks to make implementation easier.
When I read a trait name from the file (i.e. the word `children`), I call a
function that checks what the value of this trait should be. Then when I read
the actual number, I check that they match. I had to do it this way because by
using `fscanf`, I am only able to read a word at a time, so by the time I can
consider the value, I would have forgotten what trait I am comparing it for. Of
course, I could have remembered the string, but my implementation of remembering
the value instead is just as effective and is more efficient as it does not
require string copies or large numbers of string comparisons.

`day16.c` - C code that implements solution

`day16.h` - Header file containing some `#define`s to make code more readable
