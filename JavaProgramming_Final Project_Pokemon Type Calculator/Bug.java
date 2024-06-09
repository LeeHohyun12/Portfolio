public class Bug extends Type {
    private double[] weak = {1.0, 0.5, 2.0, 1.0, 0.5, 2.0, 1.0, 1.0, 1.0,
                             2.0, 1.0, 0.5, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0};
    // eigen weakness value of Bug type; please refer GUI class if you confirm the order of type
    @Override
    public double[] getWeak(){
        return weak;
    }   // Function; return weaknesses of Bug type
}
