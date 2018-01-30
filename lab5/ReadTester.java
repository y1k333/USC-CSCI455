import java.util.Scanner;
import java.util.ArrayList;

class ReadTester {
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        ArrayList<Integer> res = new ArrayList<>();
        String input = new String();
        while (true) {
            res.clear();
            System.out.println("Enter a space separated list of numbers:");
            input = in.nextLine();
            input = input.replaceAll("[^\\w\\s\\.]", " ");
            Scanner div = new Scanner(input);
            System.out.println("The numbers were");
            while (div.hasNextInt()) {
                res.add(div.nextInt());
            }
            System.out.println(res);
        }

    }
}
