import java.util.*;
import java.lang.*;
import java.io.*;

public class Main {
	public static void main (String[] args) throws java.lang.Exception {
	    Scanner in = new Scanner(System.in);
	    int kase = in.nextInt();
	    for (int i = 1; i<=kase; ++i)
	    {
	        long a = in.nextLong(), b = in.nextLong(), c = in.nextLong();
	        System.out.println("Case #" + i + ": " + (a + b > c ? "true" : "false"));
	    }
	}
}
