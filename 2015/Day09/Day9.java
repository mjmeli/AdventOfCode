import java.io.File;
import java.io.FileNotFoundException;
import java.util.HashSet;
import java.util.ArrayList;
import java.util.Iterator;
import java.util.Scanner;
import java.util.Collections;

public class Day9 {

    static HashSet<String> cities;  // each possible city assigned an int
    static HashSet<Path> distances; // distances between two cities

    public static void main(String[] args) throws FileNotFoundException {
        cities = new HashSet<>();
        distances = new HashSet<>();
        Scanner s = new Scanner(new File(args[0]));

        // Get all the cities and the distances connecting each pair
        while (s.hasNextLine()) {
            String line = s.nextLine();
            String[] split = line.split(" ");
            cities.add(split[0]);
            cities.add(split[2]);
            distances.add(new Path(split[0], split[2], Integer.parseInt(split[4])));
            distances.add(new Path(split[2], split[0], Integer.parseInt(split[4])));
        }
        s.close();

        // Shuffle the set via a list and randomly try to find least cost path
        int leastCostPath = Integer.MAX_VALUE;
        int mostCostPath = Integer.MIN_VALUE;
        ArrayList<String> cityList = new ArrayList<>();
        cityList.addAll(cities);
        for (int i = 0; i < 100000; i++) {   // i < # iterations
            int path = 0;
            Collections.shuffle(cityList);  // lol this is really inefficient
            // Compute the distance for this path
            for (int j = 1; j < cityList.size(); j++) {
                Iterator<Path> ps = distances.iterator();
                while (ps.hasNext()) {
                    Path p = ps.next();
                    if (p.node1.equals(cityList.get(j)) &&
                        p.node2.equals(cityList.get(j-1)))
                    {
                        path += p.distance;
                        break;
                    }
                }
            }
            // Update minimal and maximal cost path
            if (path < leastCostPath) leastCostPath = path;
            if (path > mostCostPath) mostCostPath = path;
        }
        System.out.println("The distance of the shortest route is " + leastCostPath);
        System.out.println("The distance of the longest route is " + mostCostPath);
    }

    static public class Path {
        String node1;
        String node2;
        int distance;

        public Path(String node1, String node2, int distance) {
            this.node1 = node1;
            this.node2 = node2;
            this.distance = distance;
        }
    }
}
