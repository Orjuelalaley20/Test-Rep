
public class bachiller {
   private String nombre;
   private String colegio;
   private int edad;

    public bachiller(String nom, String col, int edad) {
        this.nombre = nom;
        this.colegio = col;
        this.edad = edad;
    }

    public String Estudiar()
    {
        return "Estudio como bachiller";
    }

    public String PrepararClase()
    {
        return "preparo clase como bachiller";
    }

    public String PensarenelFuturo()
    {
        return "pienso en el futuro como bachiller";
    }

    public String Descansar()
    {
        return "descanso para comer";
    }
    


    public String getNombre() {
        return nombre;
    }


    public void setNombre(String nombre) {
        this.nombre = nombre;
    }

    public String getColegio() {
        return colegio;
    }

    public void setColegio(String colegio) {
        this.colegio = colegio;
    }

    public int getEdad() {
        return edad;
    }

    public void setEdad(int edad) {
        this.edad = edad;
    }

    @Override
    public String toString() {
        return "bachiller [colegio=" + colegio + ", nombre=" + nombre  + ", edad=" + edad + "]";
    }
    
    
   
}
