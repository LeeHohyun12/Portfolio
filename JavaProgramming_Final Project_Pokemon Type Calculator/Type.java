public class Type {
    public final static int theNumberOfType = 18;
    // constant; the number of type
    private final static String[] typeName = {"normal","fighting","flying","poison","ground"
    ,"rock","bug","ghost","steel","fire","water","grass","electric","psychic"
    ,"ice","dragon","dark","fairy"};
    private final double[] weak = new double[theNumberOfType];
    public double[] getWeak(){
        return weak;
    }   // Function; it allows for users to get each type's weaknesses

    // weakness values are specified differently for each type
    // eighteen type classes(normal, grass, etc.) have their own weakness compatibility values

    public static String[] getTypeName(){
        return typeName;
    }
}
