public class CountDates {
	private String yearStr;
    private String monthStr;
    private String dayStr;
    
    public int leapYear(String startDate){
        int year, month, day;
        yearStr = "";
        monthStr = "";
        dayStr = "";

        // change startDate; string type to integer type
        for (int i=0; i<4; i++)     yearStr += startDate.charAt(i);
        for (int i=4; i<6; i++)     monthStr += startDate.charAt(i);
        for (int i=6; i<8; i++)     dayStr += startDate.charAt(i);

        year = Integer.parseInt(yearStr);
        month = Integer.parseInt(monthStr);
        day = Integer.parseInt(dayStr);

        int countleapYear = 0;			
        int yearToDays, monthToDays = 0;	// change year and month to days
        int sumDays;						// sum every days after changing
        int[] month_days = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30};


        for (int i=0; i<year; i++) {
            if (i % 4 == 0) {
                if (i % 100 == 0) {
                    if (i % 400 == 0) {
                        countleapYear++;
                    }
                } else {
                    countleapYear++;
                }
            }
        }	// find leap year from AD.0 to Now; count leap years

        if (year % 4 == 0) {
            if (year % 100 == 0) {
                if (year % 400 == 0) {
                    month_days[1] = 29;
                }
            } else {
                month_days[1] = 29;
            }
        }	// change the February days when input year is leap year
        
        yearToDays = (365 * (year-1)) + countleapYear;

        for (int i=0; i<12; i++){
            if ((i+1) == month){
                for (int j=0; j<i; j++)
                    monthToDays += month_days[j];
            }
        }	// change month unit to day unit; accumulate month days
        sumDays = yearToDays + monthToDays + day;
        return sumDays;
    }
}