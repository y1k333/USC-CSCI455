/* 
 * Contains hasPeak method and
 * tests it on a bunch of hardcoded test cases, printing out test
 * data, actual results, and a FAILED message if actual results don't
 * match expected results.
 */

import java.util.LinkedList;
import java.util.ListIterator;
import java.util.Scanner;

public class PeakTester {


    /*
     * see lab assgt for specification of hasPeak method.
     */
    public static boolean hasPeak(LinkedList<Integer> list) {

    	ListIterator<Integer> it1 = list.listIterator();
    	ListIterator<Integer> it2 = list.listIterator();

    	if (it2.hasNext()) {
    		it2.next();
    	}
    	if (it1.hasNext() && it2.hasNext()) {
    		int i = it1.next();
    		int j = it2.next();
    		if (i > j) {
    			return false;
    		}
    	}
    	int peak = 0;
    	while (it1.hasNext() && it2.hasNext()) {
    		int i = it1.next();
    		int j = it2.next();
    		if (i < j) {
    			if (peak == 1) {
    				return false;
    			}
    			continue;
    		}else {
    			peak = 1;
    		}
    	}

     	return peak == 1 ? true : false;
     }
    // public static boolean hasPeak(LinkedList<Integer> list) {

    //     ListIterator<Integer> it1 = list.listIterator();
    //     ListIterator<Integer> it2 = list.listIterator(list.size());

    //     if (list.size() == 0 || list.size() == 1) {
    //         return false;
    //     }

    //     while (it1.hasNext() && it2.hasPrevious()) {
    //         int pre1 = it1.next();
    //         int pre2 = it2.previous();
    //         int i = 0, j = 0;
    //         if (it1.hasNext() && it2.hasPrevious()) {
    //             i = it1.next();
    //             j = it2.previous();
    //             if (i < pre1 || j < pre2) {
    //                 return false;
    //             }
    //             if (i == j) {
    //                 return true;
    //             }
    //         }
    //         else if (i != j) {
    //             return true;
    //         }
    //         if (pre1 == pre2 && (pre1 < i || pre1 < j)) {
    //             return false;
    //         }
    //     }
    //     return false;
    // }


    public static void main(String args[]) {

    	testPeak("", false);
    	testPeak("3", false);
    	testPeak("3 4", false);
    	testPeak("4 2", false);
    	testPeak("3 4 5", false);
    	testPeak("5 4 3", false);
    	testPeak("3 4 5 3", true);
    	testPeak("3 4 5 3 2", true);
    	testPeak("3 7 9 11 8 4 3 1", true);
    	testPeak("3 5 4", true);
    	testPeak("4 3 5", false);
    	testPeak("2 4 3 5", false);
    	testPeak("5 2 4 3 5", false);
    	testPeak("5 2 4 3", false);
		testPeak("2 4 3 5 2", false);  // 2 peaks
}



    /*  Assumes the following format for list strings (first one
     *     is empty list):
     *   "", "3", "3 4", "3 4 5", etc.
     */
    public static LinkedList<Integer> makeList(String listString) {
    	Scanner strscan = new Scanner(listString);

    	LinkedList<Integer> list = new LinkedList<Integer>();

	// strscan.skip("\\[");  // consume the "["
    	while (strscan.hasNextInt()) {
    		list.add(strscan.nextInt());
    	}

    	return list;
    }


    /* Test hasPeak method on a list form of input given in listString
     * Prints test data, result, and whether result matched expectedResult
     *
     * listString is a string form of a list given as a space separated
     * sequence of ints.  E.g.,
     *  "" (empty string), "3" (1 elmt string), "2 4" (2 elmt string), etc.
     *
     */
    public static void testPeak(String listString, boolean expectedResult) {

    	LinkedList<Integer> list = makeList(listString);

    	boolean result = hasPeak(list);
    	System.out.print("List: " + list
    		+ " hasPeak? " + result);
    	if (result != expectedResult) {
    		System.out.print("...hasPeak FAILED");
    	}
    	System.out.println();
    }
}