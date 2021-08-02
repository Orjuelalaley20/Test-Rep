public class Ingeniero extends bachiller {

    private String tipo;


    public Ingeniero(String nom, String col, int e, String t) {
        super(nom, col, e);
        this.tipo = t;
    }

    public String Estudiar()
    {
        return "Estudio como Ingeniero";
    }

    public String PrepararClase()
    {
        return "preparo clase como Ingeniero";
    }

    public String PensarenelFuturo()
    {
        return "pienso en el futuro como Ingeniero";
    }

    public String resolverproblemas()
    {
        return "resulvo problemas como un ingeniero";
    }

    public String Descansar()
    {
        return "descanso para comer";
    }



    public String getTipo() {
        return tipo;
    }

    public void setTipo(String tipo) {
        this.tipo = tipo;
    }

    @Override
    public String toString() {
        return "Ingeniero [tipo=" + tipo +" "+ super.toString()+  "]";
    }
    


}
