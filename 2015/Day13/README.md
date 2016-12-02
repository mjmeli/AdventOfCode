## Day 13

#### Problem

You are trying to make sure the holiday feast with your family goes well this
year by finding the **optimal seating arrangement**. You have a list of everyone
invited and the amount their happiness would increase or decrease if they were
to find themselves sitting next to every other person. Assume the following:

* The attendees and their relative happiness is given in `input.txt`.
* The table is circular, so each person will have exactly two neighbors.
* The table is just big enough to fit everyone.

##### Part 1

What is the **total change in happiness** for the optimal seating arrangement
of the guest list?

##### Part 2

You realize you forgot to seat yourself at the table. Because you are tired, you
simply assume that everyone will be apathetic to sitting next to you, and you
are apathetic to sitting next to anyone else. In other words, all happiness
relationships involving you involve a score of '0'.

After adding yourself, what is the **total change in happiness** for the optimal
seating arrangement?

#### Solution

This is a similar problem to the Day 9 problem, although it is slightly
different in that it is a cycle and that the costs of each link differ depending
on the direction, and both directions must be taken into account.

Since the problem is so similar to Day 9, I simply decided to reuse my Day 9
solution. I did some modifications to make it a bit cleaner (things I should
have done to day 9), but in general the code is the same.

The solution is just as inefficient as Day 9's :)

Java code: `Day13.java`
