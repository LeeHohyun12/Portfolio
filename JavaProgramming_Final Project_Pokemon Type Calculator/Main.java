public class Main {
    private static String str1, str2;
    public static void main(String[] args) {
        new GUI("Pokemon Type Calculator");
    }

    static void setStr1(String s){
        str1=s;
    }
    static void setStr2(String s){
        str2=s;
    }

    static String getStr1(){
        return str1;
    }

    static String getStr2(){
        return str2;
    }


    static double[] typeMatch(String str){
        if(str.equals("normal")){
            Type t = new Normal();
            return t.getWeak();
        }
        if(str.equals("fighting")){
            Type t = new Fighting();
            return t.getWeak();
        }
        if(str.equals("poison")){
            Type t = new Poison();
            return t.getWeak();
        }
        if(str.equals("ground")){
            Type t = new Ground();
            return t.getWeak();
        }
        if(str.equals("rock")){
            Type t = new Rock();
            return t.getWeak();
        }
        if(str.equals("bug")){
            Type t = new Bug();
            return t.getWeak();
        }
        if(str.equals("ghost")){
            Type t = new Ghost();
            return t.getWeak();
        }
        if(str.equals("steel")){
            Type t = new Steel();
            return t.getWeak();
        }
        if(str.equals("psychic")){
            Type t = new Psychic();
            return t.getWeak();
        }
        if(str.equals("ice")){
            Type t = new Ice();
            return t.getWeak();
        }
        if(str.equals("dragon")){
            Type t = new Dragon();
            return t.getWeak();
        }
        if(str.equals("dark")){
            Type t = new Dark();
            return t.getWeak();
        }
        if(str.equals("fairy")){
            Type t = new Fairy();
            return t.getWeak();
        }
        if(str.equals("water")){
            Type t = new Water();
            return t.getWeak();
        }
        if(str.equals("grass")){
            Type t = new Grass();
            return t.getWeak();
        }
        if(str.equals("fire")){
            Type t = new Fire();
            return t.getWeak();
        }
        if(str.equals("flying")){
            Type t = new Flying();
            return t.getWeak();
        }
        if(str.equals("electric")){
            Type t = new Electric();
            return t.getWeak();
        }
        Type t = new Type();
        return t.getWeak();
    }

    static void print(double[] arr){
        int count=0;
        GUI.getLabArray(1).setText("| ");
        GUI.getLabArray(5).setText("| ");
        GUI.getLabArray(2).setText("| ");
        for(int i=0;i<18;i++){
            if(arr[i]==2.0){
                GUI.getLabArray(2).setText(GUI.getLabArray(2).getText()+Type.getTypeName()[i]+" | ");
            }
        }
        GUI.getLabArray(3).setText("| ");
        for(int i=0;i<18;i++){
            if(arr[i]==1.0){
                if(count==8){
                    GUI.getLabArray(3).setText("<html>"+ GUI.getLabArray(3).getText()+"<br>| ");
                }
                GUI.getLabArray(3).setText(GUI.getLabArray(3).getText()+Type.getTypeName()[i]+" | ");
                count++;
            }
        }
        GUI.getLabArray(4).setText("| ");
        for(int i=0;i<18;i++){
            if(arr[i]==0.5){
                GUI.getLabArray(4).setText(GUI.getLabArray(4).getText()+Type.getTypeName()[i]+" | ");
            }
        }
        GUI.getLabArray(6).setText("| ");
        for(int i=0;i<18;i++){
            if(arr[i]==0.0){
                GUI.getLabArray(6).setText(GUI.getLabArray(6).getText()+Type.getTypeName()[i]+" | ");
            }
        }
    }


    static void print(double[] arr1, double[] arr2){
        int count =0;
        double[] mulArr =new double[18];
        for(int i=0;i<18;i++){
            mulArr[i]=arr1[i]*arr2[i];
        }
        GUI.getLabArray(1).setText("| ");
        for(int i=0;i<18;i++){
            if(mulArr[i]==4.0){
                GUI.getLabArray(1).setText(GUI.getLabArray(1).getText()+Type.getTypeName()[i]+" | ");
            }
        }
        GUI.getLabArray(2).setText("| ");
        for(int i=0;i<18;i++){
            if(mulArr[i]==2.0){
                GUI.getLabArray(2).setText(GUI.getLabArray(2).getText()+Type.getTypeName()[i]+" | ");
            }
        }
        GUI.getLabArray(3).setText("| ");
        for(int i=0;i<18;i++){
            if(mulArr[i]==1.0){
                if(count==8){
                    GUI.getLabArray(3).setText("<html>"+ GUI.getLabArray(3).getText()+"<br>| ");
                }
                GUI.getLabArray(3).setText(GUI.getLabArray(3).getText()+Type.getTypeName()[i]+" | ");
                count++;
            }
        }
        GUI.getLabArray(4).setText("| ");
        for(int i=0;i<18;i++){
            if(mulArr[i]==0.5){
                GUI.getLabArray(4).setText(GUI.getLabArray(4).getText()+Type.getTypeName()[i]+" | ");
            }
        }
        GUI.getLabArray(5).setText("| ");
        for(int i=0;i<18;i++){
            if(mulArr[i]==0.25){
                GUI.getLabArray(5).setText(GUI.getLabArray(5).getText()+Type.getTypeName()[i]+" | ");
            }
        }
        GUI.getLabArray(6).setText("| ");
        for(int i=0;i<18;i++){
            if(mulArr[i]==0.0){
                GUI.getLabArray(6).setText(GUI.getLabArray(6).getText()+Type.getTypeName()[i]+" | ");
            }
        }
    }
}
