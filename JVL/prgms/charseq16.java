public class charseq16 {
    public static void main(String[] args) {
        java.util.Scanner sc = new java.util.Scanner(System.in);
        System.out.println("Enter a string : ");
        Test obj = new Test(sc.nextLine());
        int flag = 1;
        while (flag != 0) {
            System.out.println("\n1. CharAt \n2.Length\n3.SubSequence\n4.Reverse");
            flag = sc.nextInt();
            switch (flag) {
                case 1:
                    System.out.println("Enter the position: ");
                    int pos = sc.nextInt();
                    System.out.println("The character at position " + pos + " is " + obj.charAt(pos));
                    break;
                case 2:
                    System.out.println("The length of the string is " + obj.length());
                    break;
                case 3:
                    System.out.println("Enter the starting position: ");
                    int start = sc.nextInt();
                    System.out.println("Enter the ending position: ");
                    int end = sc.nextInt();
                    System.out.println("The sub-sequence is " + obj.subSequence(start, end));
                    break;
                case 4:
                    System.out.println("The reverse of the string is " + obj.reverse());
                    break;

                default:
                    break;
            }

        }
        sc.close();
    }
}

class Test implements java.lang.CharSequence {
    private String str;

    public Test(String str) {
        this.str = str;
    }

    public char charAt(int index) {
        return str.charAt(index);
    }

    public int length() {
        return str.length();
    }

    public java.lang.CharSequence subSequence(int start, int end) {
        return str.subSequence(start, end);
    }

    public String reverse() {
        String rev = "";
        for (int i = str.length() - 1; i >= 0; i--) {
            rev = rev + str.charAt(i);
        }
        return rev;
    }
}