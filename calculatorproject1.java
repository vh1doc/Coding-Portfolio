import java.util.Scanner;

import java.util.regex.Pattern;
import java.util.regex.Matcher;

public class Calculator {

    public static void main(String[] args)
    {
    	
    	Scanner input = new Scanner(System.in);
    	
    	
        String themainstring = "  ";
        
        System.out.println("Welcome to my Scanner/Regex Calculator!");
        System.out.println("Where we only accept 1-2 digit numbers and one operator!");
        System.out.println("Please enter the calculation you would like to perfrom: ");
        themainstring = input.next();
        
        input.close();
        
        theregex(themainstring);

      }

    
    
    //Write the regex function here and pass themainString through it
    
    public static void theregex(String themainstring)
    {
    	//the regex
    	
    	Pattern pattern = Pattern.compile("(\\d{1,2})([+-x/])(\\d{1,2})");
    	Matcher matcher = pattern.matcher(themainstring);
    	boolean matchFound = matcher.find();
    	if (matchFound)
    	{
            double numver1 = Integer.parseInt(matcher.group(1));
            String operator = matcher.group(2);
            double numver2 = Integer.parseInt(matcher.group(3));
            
            logicstuff(numver1, numver2, operator);
    	}
    	
    }
    
    public static void logicstuff(double numver1, double numver2, String operator)
    {
    
    	System.out.println("Calculation: ");
        

        switch (operator)
        {
        case "+":
            double sum = numver1 + numver2;
            System.out.printf("%.2f + %.2f = %.2f", numver1, numver2, sum);
            break;

        case "-":
            double diff = numver1 - numver2;
            System.out.printf("%.2f - %.2f = %.2f", numver1, numver2, diff);
            break;

        case "x":
            double product = numver1 * numver2;
            System.out.printf("%.2f * %.2f = %.2f", numver1, numver2, product);
            break;

        case "/":
            if(numver2 != 0)
            {
                double quot = numver1 / numver2;
                System.out.printf("%.2f / %.2f = %.2f", numver1, numver2, quot);
            }else
            {
                System.out.println("Undefined. Cannot divide by Zero");
            }
            break;

        case "%":
            double mod = numver1 % numver2;
            System.out.printf("%.2f % %.2f = %.2f", numver1, numver2, mod);
            break;

        }
    	
    }

}
