## Day 14

#### Problem
This year is the Reindeer Olympics! Reindeer can fly at high speeds, but must
rest occasionally to recover their energy. Santa would like to know which of his
reindeer is fastest, and so he has them race.

Reindeer can only either be `flying` (always at their top speed) or `resting`
(not moving at all), and always spend whole seconds in either state.

For example, suppose you have the following Reindeer:

* Comet can fly 14 km/s for 10 seconds, but then must rest for 127 seconds.
* Dancer can fly 16 km/s for 11 seconds, but then must rest for 162 seconds.

After one second, Comet has gone 14 km, while Dancer has gone 16 km. After ten
seconds, Comet has gone 140 km, while Dancer has gone 160 km. On the eleventh
second, Comet begins resting (staying at 140 km), and Dancer continues on for a
total distance of 176 km. On the 12th second, both reindeer are resting. They
continue to rest until the 138th second, when Comet flies for another ten
seconds. On the 174th second, Dancer flies for another 11 seconds.

The descriptions of each reindeer are in `input.txt`.

##### Part 1

Given the descriptions of each reindeer, after exactly `2503` seconds, what
distance has the winning reindeer traveled?

##### Part 2

Seeing how reindeer move in bursts, Santa decides he's not pleased with the old
scoring system. Instead, at the end of each second, he awards one point to the
reindeer currently in the lead.

Again given the descriptions of each reindeer (in your puzzle input), after
exactly 2503 seconds, how many points does the winning reindeer have?

#### Solution
The solution to this problem isn't too exciting. I implemented a Python script
that would create a list of the `Reindeer`. I then simulated 2503 ticks, where
in each tick I would move the reindeer or keep it at rest, depending on its
state. Scoring is a simple task of finding the reindeer with the max distance
after each tick.

Python was chosen because it has a lot of easy to use tools for quickly
comparing the fields of each object in a list, which is useful for this problem.

`day14.py` - Python script that implements solution
