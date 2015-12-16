## Day 15

#### Problem
Today, you set out on the task of perfecting your milk-dunking cookie recipe.
All you have to do is find the right balance of ingredients.

Your recipe leaves room for exactly `100` teaspoons of ingredients. You make a
list of the remaining ingredients you could use to finish the recipe
(your puzzle input) and their properties per teaspoon:

* `capacity` (how well it helps the cookie absorb milk)
* `durability` (how well it keeps the cookie intact when full of milk)
* `flavor` (how tasty it makes the cookie)
* `texture` (how it improves the feel of the cookie)
* `calories` (how many calories it adds to the cookie)

You can only measure ingredients in whole-teaspoon amounts accurately, and you
have to be accurate so you can reproduce your results in the future. The total
score of a cookie can be found by adding up each of the properties (negative
totals become `0`) and then multiplying together everything except calories.

For instance, suppose you have these two ingredients:

    Butterscotch: capacity -1, durability -2, flavor 6, texture 3, calories 8
    Cinnamon: capacity 2, durability 3, flavor -2, texture -1, calories 3

Then, choosing to use `44` teaspoons of butterscotch and `56` teaspoons of
cinnamon (because the amounts of each ingredient must add up to `100`) would
result in a cookie with the following properties:

* A `capacity` of `44*-1 + 56*2 = 68`
* A `durability` of `44*-2 + 56*3 = 80`
* A `flavor` of `44*6 + 56*-2 = 152`
* A `texture` of `44*3 + 56*-1 = 7`

Multiplying these together (`68 * 80 * 152 * 76`, ignoring calories for now)
results in a total score of `62842880`, which happens to be the best score
possible given these ingredients. If any properties had produced a negative
total, it would have instead become zero, causing the whole score to multiply to
zero.

The descriptions of each ingredient are in `input.txt`.

##### Part 1

Given the ingredients in your kitchen and their properties, what is the total
score of the highest-scoring cookie you can make?

##### Part 2

Someone asks if you can make another recipe that has exactly `500` calories per
cookie (so they can use it as a meal replacement). Keep the rest of your
award-winning process the same (`100` teaspoons, same ingredients, same scoring
system).

Given the ingredients in your kitchen and their properties, what is the total
score of the highest-scoring cookie you can make with a calorie total of `500`?

#### Solution
I really like my solution to this problem. Admittedly, it isn't amazingly
brilliant in terms of its algorithm nor does it use any snazzy Python tricks,
but I believe I managed to implement it efficiently and succinctly in C. Maybe
I didn't, but I'd like to think I did at least.

I created a system to parse the input file into a singly linked list of
ingredients. Not caring for the order of the ingredients in the list, I simply
prepended each element, as this is O(1) instead of O(n). Of course, there are
only 4 ingredients so this was a useless exercise in truth...

Then, I recursively found the best cookie. Starting with the first ingredient,
I looped from 0 to 100 teaspoons out of the 100. Each time, I recursively found
the best cookie from the remaining ingredients with the remaining teaspoons.

After recursion, I could simply compute the max cookie score. Part 2 required
simply adding a check that the max cookie also had 500 calories.

Check out the **Example** section for a more detailed walkthrough of my solution.

`day15.c` - C code that implements solution

`day15.h` - Header file containing struct definitions and a linked list interface

##### Example
Here is an example of how my solution worked.

Say I start with 4 ingredients. I start by considering the first ingredient. I
check the range from 0 to 100 teaspoons completely, but for this example, say I
am considering 24 teaspoons of this ingredient. This means I have `100-24=76`
teaspoons left for 3 ingredients. I add the appropriate capacity, durability,
etc., counts for these 24 teaspoons.

Then, I recursively find the best cookie that can be created with 3 ingredients
using 76 teaspoons. Looking at the 1st of these 3 ingredients (or the 2nd
overall), say I am considering the cast where this has 36 teaspoons. I compute
the values for this, and then find the max cookie for the remaining 2 ingredients
using `76-36=40` teaspoons.

This recursion continues until I am considering the last ingredient. The last
ingredient must have the remaining teaspoons to add up to 100. This makes looping
for the last ingredient unnecessary, which can significantly reduce the search
space for this brute force algorithm.

By the time the last ingredient has computed its values, then the cookie composed
of all 4 ingredients will have the appropriate values of calories, durability,
etc. for all 4 ingredients. Then, the overall cookie score can be computed and
compared against the max. This is done in each recursion instance so that the
max cookie is returned from each.
