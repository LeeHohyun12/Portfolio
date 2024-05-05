import java.util.Scanner;

public class HW3{
	public static void main(String[] args) {
		Circle cir = new Circle();
		Scanner sc = new Scanner(System.in);
		int r1, r2;
		double ratio;
		
		System.out.print("Enter the first radius: ");
		r1 = sc.nextInt();
		System.out.print("Enter the second radius: ");
		r2 = sc.nextInt();
		
		System.out.println("First circle: The area is " + cir.circleArea(r1)
		+ " and the circumference is " + String.format("%.2f", cir.circleCircum(r1)) + ".");
		System.out.println("Second circle: The area is " + cir.circleArea(r2)
		+ " and the circumference is " + String.format("%.1f", cir.circleCircum(r2)) + ".");
		
		ratio = (cir.circleArea(r1) / cir.circleArea(r2));
		System.out.println("The ratio of the areas is " + String.format("%.2f", ratio) + ".");
		
		sc.close();
	}
}