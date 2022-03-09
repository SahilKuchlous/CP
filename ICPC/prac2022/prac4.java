import java.util.Arrays;
import java.util.Scanner;

public class prac4 {

    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        int n = in.nextInt();
        int d = in.nextInt();
        int w = in.nextInt();
        in.nextLine();

        StringBuilder b = new StringBuilder();
        for(int i = 0; i < n; i++) {
            String l = in.nextLine().trim();
            if (i % 2 == 0) {
                b.append(l);
            } else {
                for (int j = l.length() - 1; j >= 0; j--) {
                    b.append(l.charAt(j));
                }
            }
        }
        String[] words = b.toString().split("\\.");
        int width = 0;
        int lines = 0;
        for(String word : words){
            if(width + word.length() > w){
                lines++;
                width = 0;
            }
            width += word.length() + 1;
        }
        if(width > 0) lines++;
        System.out.println(lines);
    }
}
