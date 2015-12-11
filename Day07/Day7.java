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
            Wire wire = new Wire();

            // ASSIGN will have 3 elements per line
            if (split.length == 3) {
                Operation op = new Operation("ASSIGN", new Driver(split[0]));
                wire.setOperation(op);
                wires.put(split[2], wire);
            }
            // NOT will have 4 elements per line
            else if (split.length == 4){
                Operation op = new Operation("NOT", new Driver(split[1]));
                wire.setOperation(op);
                wires.put(split[3], wire);
            }
            // All other operators will have 5 elements per line
            else {
                Operation op = new Operation(split[1], new Driver(split[0]), new Driver(split[2]));
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

    // Wire is what gets added to the graph.
    static public class Wire {
        Operation op;
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

    // Driver is what drives the input to a Wire via an Operation.
    static public class Driver {
        String name;
        int value;
        boolean isConstant;

        public Driver(String name) {
            if (name.matches("\\d+")) {
                this.value = Integer.parseInt(name);
                this.isConstant = true;
            } else {
                this.name = name;
                this.isConstant = false;
            }
        }

        public int getValue() {
            if (isConstant) return value;
            else return wires.get(name).getValue();
        }
    }

    // An Operation performs an operation based on two input drivers.
    static public class Operation {
        Opcode opcode;
        Driver left, right;

        public Operation(String title, Driver driver) {
            this(title, driver, null);
        }

        public Operation(String title, Driver left, Driver right) {
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
