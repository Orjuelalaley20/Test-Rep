/**
 * clase CuentaCorriente_Exception la cual se usa para imprimir los posibles
 * errores que puedan ocurrir en la compilación.
 * 
 * @author Sebastian orjuela
 * @author Isabella blanco
 * @since 27-05-2021
 */
public class CuentaCorriente_Exception extends Exception {

    private static final long serialVersionUID = 1L;
    private String detalle;

    /**
     * @param string cadena en la cual esta el error para posterior mente ser
     *               impreso
     */

    public CuentaCorriente_Exception(String string) {
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
        return "CuentaCorriente_Exception [detalle=" + detalle + "]";
    }
}
