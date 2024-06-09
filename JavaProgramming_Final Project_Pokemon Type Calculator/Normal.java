public class Normal extends Type {
    private final double[] weak = {1.0, 2.0, 1.0, 1.0, 1.0, 1.0, 1.0, 0.0, 1.0,
                                   1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0};
    // eigen weakness value of Normal type; please refer GUI class if you confirm the order of type
    @Override
    public double[] getWeak(){
        return weak;
    }   // Function; return weaknesses of Normal type
}
