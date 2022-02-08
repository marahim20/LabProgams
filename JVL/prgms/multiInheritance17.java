import java.util.*;
public class multiInheritance17{
    public static void main(String[] args){
        Result obj = new Result();
        obj.getno();
        obj.getMarks();
        obj.putwt();
        obj.putno();
        obj.putmarks();
        obj.display();
    }
}
interface Sport{
    final int sportwt = 0;
    abstract void putwt();
}
class Student{
    Scanner sc = new Scanner(System.in);
    int rollno;
    void getno(){
        System.out.println("Enter the roll number : ");
        rollno = sc.nextInt();

    }
    void putno(){
        System.out.println("Roll number is : " + rollno);
    }
}
class test1 extends Student{
    float part1, part2;
    void getMarks(){
        System.out.println("Enter the marks of part 1 : ");
        part1 = sc.nextFloat();
        System.out.println("Enter the marks of part 2 : ");
        part2 = sc.nextFloat();
    }
    void putmarks(){
        System.out.println("Part 1 marks : " + part1);
        System.out.println("Part 2 marks : " + part2);
    }
}
class Result extends test1 implements Sport{
    public void putwt(){
        System.out.println("Sports Weightage: " + sportwt);
    }
    void display(){
        System.out.println("Total marks : " + (part1 + part2 + sportwt));
    }
}