/**
 * clase Cuenta_Exception la cual se usa para imprimir los posibles errores que puedan ocurrir en la compilación.
 * @author  Sebastian orjuela - Isabella blanco 
 * @since   07-05-2021
*/
public class Cuenta_Exception extends Exception{

    private static final long serialVersionUID = 1L;
    private String detalle;

    /**
     *@param string cadena en la cual esta el error para posterior mente ser impreso
    */

    public Cuenta_Exception(String string) {
        detalle = string;
    }
    
    public static long getSerialversionuid() {
        return serialVersionUID;
    }

    public String getDetalle() {
        return detalle;
    }

    public void setDetalle(String detalle) {
        this.detalle = detalle;
    }

    @Override
    public String toString() {
        return "Cuenta_Exception [detalle=" + detalle + "]";
    }
}