import java.util.Scanner;

public class HW2 {
    public static void main (String[] args){
        String startDate, endDate;
        int result;

        CountDates date = new CountDates();
        Scanner sc = new Scanner(System.in);

        System.out.println("Enter a start date:");
        startDate = sc.next();

        System.out.println("Enter an end date:");
        endDate = sc.next();
        
        result = date.leapYear(endDate) - date.leapYear(startDate);
        System.out.println("D-day: " + result + " days.");
        
        sc.close();
    }
}
