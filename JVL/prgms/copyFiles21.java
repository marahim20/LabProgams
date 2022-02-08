import java.io.*;
public class copyFiles21{
    public static void main(String args[]) throws IOException{
        try{
            FileInputStream fis = new FileInputStream("file1.txt");
            System.out.println("File1 opened successfully");
            FileOutputStream fos = new FileOutputStream("file2.txt", true);
            System.out.println("File2 opened successfully");
            int i = fis.read();
            while(i!=-1){
                fos.write(i);
                i = fis.read();
            }
            fis.close();fos.close();
            System.out.println("File1 copied to file2 successfully");
        }catch(FileNotFoundException fne){
            System.out.println("File not found");
        }
    }
}