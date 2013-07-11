import java.io.*;
import java.lang.*;

public class Calc {
    public static void main(String args[])
    {
        System.out.print("Enter your an integer: ");
        //  open up standard input
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        String number = null;
        //  readLine() method
        try {
            number = br.readLine();
        }catch (IOException ioe) {
            System.out.println("IO error trying to read the number!");
            System.exit(1);
        }
        int n = Integer.parseInt(number);

        Calc c = new Calc();
        c.func(n, 0);
        System.out.println(c.count);
    }

    public Calc()
    {}

    public int count = 0;

    public void func(int n, int p)
    {
        count++;
        if (p > n) return;
        for (int i = 0; i < n; i++) {
            func(n, p + 1);
        }
    }
}
