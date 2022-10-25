//By Vinny Dougherty
import java.util.Scanner;
import java.util.regex.Pattern;
import java.util.regex.Matcher;

public class Calculator {

    public static void main(String[] args)
    {
    	//scanner lets you bring in user input
    	
    	Scanner input = new Scanner(System.in);
    	
    	//this string is what the input will be stored in
        String themainstring = "";
        
        //Some intro stuff
        System.out.println("Welcome to Vinny's Scanner/Regex Calculator!");
        System.out.println("Where we only accept 1-2 digit numbers and one operator in between!");
        System.out.println("This is for Assignment 1 in CSIS 3701.");
        System.out.println("Please enter the calculation you would like to perfrom: ");
        
        //open the scanner
        themainstring = input.next();
        
        //close the scanner
        input.close();
        
        //call theregex and pass in the themainstring
        theregex(themainstring);

      }

    
    
    //Write the regex function here and pass themainstring through it
    
    public static void theregex(String themainstring)
    {
    	//the regex
    	
    	//the pattern will look at themainstring and break it up
    	//between it's numbers and the operator symbol
    	Pattern pattern = Pattern.compile("(\\d{1,2})([+-x%/\\\\])(\\d{1,2})");
    	Matcher matcher = pattern.matcher(themainstring);
    	
    	//This boolean will check to see if the matcher was able to match the input to 
    	//either 1 to 2 digit numbers or the operator in between
    	boolean matchFound = matcher.find();
    	
    	//if the match is true..
    	if (matchFound)
    	{
    		//Then parse the digits into an int and set it equal to a variable
    		//The operator can stay a string, but we still need to store it so we can use it
            double numver1 = Integer.parseInt(matcher.group(1));
            String operator = matcher.group(2);
            double numver2 = Integer.parseInt(matcher.group(3));
            
            //Pass the two ints and the operator through the Logicstuff function
            logicstuff(numver1, numver2, operator);
    	}else
    	{
    		System.out.println("Invalid input. Please type the operation in this format: ");
    		System.out.println("##o##, where the ## represents how many digits you have have, ");
    		System.out.println("and the o represents a single operator symbol.");
    		System.out.println("The operators available are +, -, x, /, %, or \\. Thank you.");
    	}
    	
    }
    
    //This determines what operator is being used, then puts the appropriate calculation
    //and displays it
    public static void logicstuff(double numver1, double numver2, String operator)
    {
    
    	System.out.println("Calculation: ");
        

    	//This will look at the "operator" variable and 
    	//determine if it is either +, -, x, or /. and now % and \
    	//and then puts the passed in numbers into the selected calculation
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
            System.out.println("The result after applying the modulus operator: " + mod);
            break;
        
        case "\\":
        	if(numver2 != 0)
            {
                double quot = numver1 / numver2;
                
                int quot2 = (int)quot;
                System.out.println(numver1 + "\\" + numver2 + "=" + quot2);
            }else
            {
                System.out.println("Undefined. Cannot divide by Zero");
            }
            break;

        }
    	
    }

}
