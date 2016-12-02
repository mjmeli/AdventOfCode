import java.io.File;
import java.io.FileNotFoundException;
import java.util.HashMap;
import java.util.Scanner;

public class Day7 {

    static HashMap<String, Wire> wires; // Graph of wire nodes
    static enum Opcode { ASSIGN, AND, OR, NOT, LSHIFT, RSHIFT };

    public static void main(String[] args) throws FileNotFoundException {
        wires = new HashMap<>();
        Scanner s = new Scanner(new File("input.txt"));

        // Construct a graph of wires
        while (s.hasNextLine()) {
            String line = s.nextLine();
            String[] split = line.split(" ");
            Wire wire = getWire(split[split.length-1]);

            // ASSIGN will have 3 elements per line
            if (split.length == 3) {
                Operation op = new Operation("ASSIGN", getWire(split[0]));
                wire.setOperation(op);
                wires.put(split[2], wire);
            }
            // NOT will have 4 elements per line
            else if (split.length == 4){
                Operation op = new Operation("NOT", getWire(split[1]));
                wire.setOperation(op);
                wires.put(split[3], wire);
            }
            // All other operators will have 5 elements per line
            else {
                Operation op = new Operation(split[1], getWire(split[0]), getWire(split[2]));
                wire.setOperation(op);
                wires.put(split[4], wire);
            }
        }
        s.close();

        // Part 1 - Find value of a
        int a = wires.get("a").getValue();
        System.out.println("Part 1: a = " + a);

        // Part 2 - Find new value of a after driving b with value of a from Part 1
        for (Wire wire : wires.values())
            wire.reset();           // reset all wires
        wires.get("b").setValue(a); // drive b with Part 1 value of a
        System.out.println("Part 2: a = " + wires.get("a").getValue());
    }

    // Get the Wire instance from hash map that represents a named wire. If it
    // does not exist yet in the hash map, then add it first.
    static public Wire getWire(String name)
    {
        // If name is a constant, create a wire with a value
        if (name.matches("\\d+")) {
            Wire wire = new Wire();
            wire.setValue(Integer.parseInt(name));
            return wire;
        }
        // If the name is a wire, then either get the wire from the hash table
        // or create a new one.
        else {
            if (!wires.containsKey(name)) {
                Wire wire = new Wire();
                wires.put(name, wire);
            }
            return wires.get(name);
        }
    }

    // Wire is what gets added to the graph.
    static public class Wire {
        Operation op;   // holds parents
        Integer value;

        public void setOperation(Operation op) {
            this.op = op;
        }

        public void setValue(int value) {
            this.value = value;
        }

        public void reset() {
            this.value = null;
        }

        public int getValue() {
            if (value == null) value = op.getValue() & 0xffff;    // 16-bit
            return value;
        }
    }

    // An Operation performs an operation based on two input drivers.
    static public class Operation {
        Opcode opcode;
        Wire left, right;

        public Operation(String title, Wire wire) {
            this(title, wire, null);
        }

        public Operation(String title, Wire left, Wire right) {
            if (title.equals("ASSIGN")) this.opcode = Opcode.ASSIGN;
            else if (title.equals("AND")) this.opcode = Opcode.AND;
            else if (title.equals("OR")) this.opcode = Opcode.OR;
            else if (title.equals("NOT")) this.opcode = Opcode.NOT;
            else if (title.equals("LSHIFT")) this.opcode = Opcode.LSHIFT;
            else if (title.equals("RSHIFT")) this.opcode = Opcode.RSHIFT;
            this.left = left;
            this.right = right;
        }

        public int getValue() {
            switch (this.opcode) {
                case ASSIGN:
                    return left.getValue();
                case AND:
                    return left.getValue() & right.getValue();
                case LSHIFT:
                    return left.getValue() << right.getValue();
                case NOT:
                    return ~left.getValue();
                case OR:
                    return left.getValue() | right.getValue();
                case RSHIFT:
                    return left.getValue() >> right.getValue();
                default:
                    return 0;
            }
        }
    }
}
