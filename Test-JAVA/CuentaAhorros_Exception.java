/**
 * clase CuentaAhorros_Exception la cual se usa para imprimir los posibles
 * errores que puedan ocurrir en la compilación.
 * 
 * @author Sebastian orjuela
 * @author Isabella blanco
 * @since 27-05-2021
 */
public class CuentaAhorros_Exception extends Exception {

    private static final long serialVersionUID = 1L;
    private String detalle;

    /**
     * @param string cadena en la cual esta el error para posterior mente ser
     *               impreso
     */

    public CuentaAhorros_Exception(String string) {
        detalle = string;
    }

    /**
     * @return long
     */
    public static long getSerialversionuid() {
        return serialVersionUID;
    }

    /**
     * @return String
     */
    public String getDetalle() {
        return detalle;
    }

    /**
     * @param detalle
     */
    public void setDetalle(String detalle) {
        this.detalle = detalle;
    }

    /**
     * @return String
     */
    @Override
    public String toString() {
        return "CuentaAhorros_Exception [detalle=" + detalle + "]";
    }
}
