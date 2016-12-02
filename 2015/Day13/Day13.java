import java.io.File;
import java.io.FileNotFoundException;
import java.util.HashMap;
import java.util.ArrayList;
import java.util.Iterator;
import java.util.Scanner;
import java.util.Collections;

public class Day13 {

    public static void main(String[] args) throws FileNotFoundException {
        HashMap<String, Attendee> attendees = new HashMap<>();
        Scanner s = new Scanner(new File(args[0]));

        // Get all the attendees and the happiness between each pair
        while (s.hasNextLine()) {
            String line = s.nextLine();
            String[] split = line.split(" ");
            Attendee src = addOrGetAttendee(attendees, split[0]);
            Attendee dest = addOrGetAttendee(attendees, split[10].replaceAll("\\.", ""));
            int gainOrLose = split[2].equals("gain") ? 1 : -1;
            src.setHappiness(dest, gainOrLose * Integer.parseInt(split[3]));
        }
        s.close();

        // Part 1 - Get the optimal seating arrangement of input file
        System.out.println("The optimal arrangement has value " +
                            getOptimalArrangment(attendees));

        // Part 2 - Get the optimal seating after adding myself
        Attendee me = addOrGetAttendee(attendees, "Michael");
        for (Attendee other : attendees.values()) {
            me.setHappiness(other, 0);
            other.setHappiness(me, 0);
        }
        System.out.println("The optimal arrangement after I join has value " +
                            getOptimalArrangment(attendees));
    }

    static public class Attendee {
        private String name;
        private HashMap <Attendee,Integer> happiness;

        public Attendee (String name) {
            this.name = name;
            this.happiness = new HashMap<>();
        }

        public boolean hasHappiness(Attendee neighbor) {
            return happiness.containsKey(neighbor);
        }

        public void setHappiness(Attendee neighbor, int happy) {
            happiness.put(neighbor, happy);
        }

        public int getHappiness(Attendee neighbor) {
            return happiness.get(neighbor);
        }
    }

    static public Attendee addOrGetAttendee(HashMap<String, Attendee> attendees, String name) {
        if (attendees.containsKey(name)) {
            return attendees.get(name);
        }
        else {
            Attendee a = new Attendee(name);
            attendees.put(name, a);
            return a;
        }
    }

    static public int getOptimalArrangment(HashMap<String, Attendee> attendees) {
        // Shuffle the list of attendees to randomly find the optimal arrangement
        int optimal = Integer.MIN_VALUE;
        ArrayList<Attendee> arrangement = new ArrayList<>();
        arrangement.addAll(attendees.values());
        for (int i = 0; i < 100000; i++) {     // i < (# iterations)
            int arrangementValue = 0;
            Collections.shuffle(arrangement);  // lol this is really inefficient
            // Compute happiness for this arrangment
            for (int j = 0; j < arrangement.size(); j++) {
                Attendee a1 = arrangement.get(j);
                Attendee a2 = arrangement.get((j+1) % arrangement.size());
                arrangementValue += a1.getHappiness(a2);
                arrangementValue += a2.getHappiness(a1);
            }
            if (arrangementValue > optimal) optimal = arrangementValue;
        }
        return optimal;
    }
}
