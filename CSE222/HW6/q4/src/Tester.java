/**
 * General tests for KWHashMap data structure
 */
public class Tester {
    
    public static void runTests(KWHashMap<String, Integer> map) {
        t_addKV(map);
        t_removeKV(map);
        t_getKV(map);
        t_size(map);
    }

    private static void t_addKV(KWHashMap<String, Integer> map) {
        System.out.println("Adding key/value pairs to map.");
        map.put("Apple", 5);
        map.put("Banana", 12);
        map.put("Orange", 0);
        map.put("Cherry", 43);
        map.put("Citrus", 64);
        map.put("Grapes", 21);
        System.out.println("Add done.");
        map.print();
    }

    private static void t_removeKV(KWHashMap<String, Integer> map) {
        System.out.println("Removing key/value pairs (Apple, Citrus) from map.");
        map.remove("Apple");
        map.remove("Citrus");
        System.out.println("Remove done.");
        map.print();
    }

    private static void t_getKV(KWHashMap<String, Integer> map) {
        System.out.println("Get key Orange from map.");
        int value = map.get("Banana");
        System.out.println("Get done: " + value);
    }

    private static void t_size(KWHashMap<String, Integer> map) {
        System.out.println("Get size of map.");
        int size = map.size();
        System.out.println("Size: " + size);
    } 

}