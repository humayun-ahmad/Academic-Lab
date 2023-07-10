import java.io.BufferedReader;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.util.*;


public class Main{
    public static void main(String[] args) throws IOException{
        BufferedReader reader =new BufferedReader(new FileReader("in.txt"));
        FileWriter writer = new FileWriter("out.txt");

        String lines;

        List<String> list = new ArrayList();
        System.out.println("\nOutput: ");
        while((lines = reader.readLine()) != null){
            System.out.println(lines);
            list.add(lines);
        }


        for(String line: list){
            writer.write(line);
            writer.write("\n");
        }

        reader.close();
    }
}