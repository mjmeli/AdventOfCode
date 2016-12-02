## Day 7

#### Problem
This year, Santa brought little Bobby Tables a set of wires and bitwise logic
gates! Unfortunately, little Bobby is a little under the recommended age range,
and he needs help assembling the circuit. Important information:

* Each wire has an identifier of lowercase letters.
* Each wire can carry a 16-bit signal.
* A signal is provided to each wire by a gate, another wire, or some specific
value.
* Each wire can only get a signal from one source, but can provide its signal to
multiple destinations.
* A gate provides no signal until all of its inputs have a signal.
* You may not assume that the instructions define wires before using them.

The instructions in `input.txt` explain how to connect the parts together. For
example, `x AND y -> z` means to connect `x` and `y` via an AND gate and assign
this value to the wire `z`.

Possible operations are:

* Assign (`x -> y`)
* `AND` (`x AND y -> z`)
* `OR` (`x AND y -> z`)
* `NOT` (`NOT x -> y`)
* `LSHIFT` (`x LSHIFT 2 -> z`)
* `RSHIFT` (`x RSHIFT 2 -> z`)

##### Part 1
In Bobby's kit's instruction booklet, what signal is ultimately provided to
**wire `a`**?

##### Part 2
Now, take the signal that you found on wire `a` for Part 1 and drive wire `b`
with that signal, resetting the other wires.

What new signal is ultimately
provided to **wire `a`**?

#### Solution
To solve this solution, I made extensive use of recursion through a graph. I
developed this solution in Java.

To begin, I constructed a graph where each node in the graph is a `Wire`. Each
`Wire` gets it's value from a specific `Operation` on two inputs `Wire`s. The
graph structure should be clear; each wire has one or two parent wire(s) and is
defined by an operation on these parent wire(s).

After scanning through the text file, the graph is fully constructed. Then, to
get a value of a `Wire`, I could recursively find the value of each of the
`Wire`'s input `Wire`s. Eventually, the recursion would reach the initial inputs
to the overall system, which means that a value could be determined for the
signal.

Java code: `Day7.java`

##### Example
To give a quick example, consider the following instructions:

    x AND y -> z
    w OR y -> x
    w -> 54
    y -> 1242

Naively parsing through these instructions and calculating values as you go does
not work because the gates are used before they are defined. Instead, I create
a graph with nodes `w`, `x`, `y`, and `z`. `z` is specified as being formed
based on the `AND` of inputs `x` and `y`. `x` is specified as being formed
based on the `OR` of inputs `w` and `y`. `w` and `y` can simply be identified
as constants.

To find the value of `z`, I attempt to do `x AND y`. While `y` is a known
constant, I do not know what the value of `x` is. As such, I recursively compute
`x` by looking at its inputs `w` and `y`. In this case, both inputs are known,
so `x` can be computed. Once `x` is computed, `z` itself can finally be
computed.
