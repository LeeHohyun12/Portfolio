public class Circle {
	private double area;
	private double circumference;
	private double pi = 3.14;
	
	public double circleArea(double r) {
		area = (r * r * pi);
		return area;
	}
	
	public double circleCircum(double r) {
		circumference = (2.0 * r * pi);
		return circumference;
	}
}
