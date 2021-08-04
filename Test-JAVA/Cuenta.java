import java.io.Serializable;
import java.time.LocalDate;
import java.util.*;

/**
 * clase cuenta en la que almacenan los datos de las cuentas
 * 
 * @author Sebastian orjuela
 * @author Isabella blanco
 * @since 27-05-2021
 * 
 */

public abstract class Cuenta implements Serializable {

    private static int consecutivo = 1;
    private int numconse;
    private double saldo;
    private String estado;
    private LocalDate fechaCreacion;
    private String tipo;
    private List<Titular> titulares = new ArrayList<Titular>();

    /**
     * constructor vacio
     */

    public Cuenta() {

    }

    /**
     * constructor que le asigna toda la informacion a los atributos de la cuenta
     * 
     * @param consecutivo numero con el que se identifica una cuenta de la otra
     * @param saldo       saldo que tiene la cuenta
     * @param tipo        tipo de la cuenta si ahorros o corriente
     * @param estado      estado en el que se encuentra una cuent
     * @param fechaC      fecha de creacion de la cuenta
     */

    public Cuenta(int consecutivo, double saldo, String tipo, String estado, LocalDate fechaC) {
        this.saldo = saldo;
        this.tipo = tipo;
        this.fechaCreacion = fechaC;
        numconse = consecutivo;
        this.estado = estado;

    }

    /**
     * constructor el cual se usa para crear la cuenta manualmente.
     * 
     * @param saldo      Saldo que tiene la cuenta.
     * @param tipo       Tipo de la cuenta si ahorros o corriente.
     * @param estado     Estado en el que se encuentra una cuenta.
     * @param fechaC     Fecha de creacion de la cuenta.
     * @param titualares Lista de titulares con su informacion.
     */

    public Cuenta(double saldo, String tipo, String estado, LocalDate fechaC, List<Titular> titualres) {
        this.saldo = saldo;
        this.tipo = tipo;
        this.fechaCreacion = fechaC;
        this.numconse = consecutivo;
        this.estado = estado;
        this.titulares = titualres;
    }

    /**
     * metodo el cual agrega titulares a la lista de titulares.
     * 
     * @param nombre  nombre completo del titular.
     * @param fn      fecha de nacimiento del titular.
     * @param telfijo telefono fijo del titular.
     * @param cel     telefono celular del titular.
     * @param dir     dirreción del titular.
     * @throws CuentaAhorros_Exception
     * @throws Cuenta_Exception
     * @throws CuentaCorriente_Exception
     */

    public abstract void AgregarTitular(String nombre, LocalDate fn, String telfijo, String cel, String dir)
            throws CuentaAhorros_Exception, CuentaCorriente_Exception;

    /**
     * metodo el cual compara el nombre del titular con los nombres de titualres que
     * tiene la cuenta, en la lista de titualares.
     * 
     * @param nombre nombre del titular a buscar en la lista de titulares
     * @return t retorna si encuentra o no el titular
     */

    public abstract Titular Buscartitular(String nombre);

    /**
     * metodo el cual busca en la lista de titulares el nombre y la edad del titular
     * y lo agrega a la lista nombresTitulares.
     * 
     * @return nombresTitulares lista en la que se encuentran los nombres de los
     *         titulares con respectiva edad.
     */

    public abstract List<String> BuscarnombreEdad();

    /**
     * metodo el cual busca en la lista de titulares la fecha de nacimiento de los
     * titulares y retorna true, si no lo encuentra retorna false.
     * 
     * @return true or false.
     */

    public abstract boolean Buscarfechanacimiento(LocalDate fechabuscar);

    // GETTERS Y SETTERS------------------

    /**
     * @return int
     */

    public static int getConsecutivo() {
        return consecutivo;
    }

    /**
     * @param consecutivo
     */
    public static void setConsecutivo(int consecutivo) {
        Cuenta.consecutivo = consecutivo;
    }

    /**
     * @return int
     */
    public int getNumconse() {
        return numconse;
    }

    /**
     * @param numconse
     */
    public void setNumconse(int numconse) {
        this.numconse = numconse;
    }

    /**
     * @return float
     */
    public double getSaldo() {
        return saldo;
    }

    /**
     * @param saldo
     */
    public void setSaldo(double saldo) {
        this.saldo = saldo;
    }

    /**
     * @return String
     */
    public String getEstado() {
        return estado;
    }

    /**
     * @param estado
     */
    public void setEstado(String estado) {
        this.estado = estado;
    }

    /**
     * @return LocalDate
     */
    public LocalDate getFechaCreacion() {
        return fechaCreacion;
    }

    /**
     * @param fechaCreacion
     */
    public void setFechaCreacion(LocalDate fechaCreacion) {
        this.fechaCreacion = fechaCreacion;
    }

    /**
     * @return String
     */
    public String getTipo() {
        return tipo;
    }

    /**
     * @param tipo
     */
    public void setTipo(String tipo) {
        this.tipo = tipo;
    }

    /**
     * @return List<Titular>
     */
    public List<Titular> getTitulares() {
        return titulares;
    }

    /**
     * @param titulares
     */
    public void setTitulares(List<Titular> titulares) {
        this.titulares = titulares;
    }

    // TO STRING-------------

    /**
     * @return String
     */
    @Override
    public String toString() {
        return "[Consecutivo = " + numconse + ", Saldo = " + saldo + ", Tipo = " + tipo + ", Estado = " + estado
                + ", Fecha de creacion = " + fechaCreacion + " \n" + titulares + "]\n";
    }
}