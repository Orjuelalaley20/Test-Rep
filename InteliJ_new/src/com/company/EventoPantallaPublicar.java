public class EventoPantallaPublicar {
    private  Object _textoMensaje;
    public PantallaPublicarMensaje _conoce;
    public NegocioPublicarMensaje _n;

    public EventoPantallaPublicar() {
    }

    public void crearmensaje()
    {
        String tx = getTextoMensaje();
        if(tx != null)
        {
            Mensaje m = new Mensaje(tx);
            Respuesta rta = _n.crearMensaje(m);
        }
        else
        {

        }
    }


}
