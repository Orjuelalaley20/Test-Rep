public class Interfaz {
    public static void main(String[] args) throws Exception {
        bachiller b;
        Ingeniero i;

        b = new bachiller("carlos" , "champagnant",19);
        i = new Ingeniero("edward" , "san pedro " , 21, "electronica");
        System.out.println("esta monda parece que ya corre java sisis señoooor xd");
        System.out.println(b);
        System.out.println(i);

        System.out.println(b.Estudiar());
        System.out.println(b.PrepararClase());
        System.out.println(b.PensarenelFuturo());
        b = i;
        System.out.println(b);
        System.out.println(((Ingeniero) b).resolverproblemas());
    }
    
}