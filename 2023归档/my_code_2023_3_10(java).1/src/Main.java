public class Main {
    public static void main(String[] args) {
        String[] pets = {"Fido", "Zeus", "Bin"};
        int x = pets.length;
        int rand1 = (int)(Math.random() * x);
        System.out.println(pets[rand1]);
    }
}
