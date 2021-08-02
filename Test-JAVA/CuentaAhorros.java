import java.time.LocalDate;
import java.util.ArrayList;
import java.util.List;

/**
 * Clase CuentaAhorros que hereda de Cuenta sus metodos y atributos y ademas de
 * eso permite hacer las operaciones necesarias en la cuenta
 * 
 * @author Sebastian Orjuela
 * @author Isabella Blanco
 * @since 27-05-2021
 */

public class CuentaAhorros extends Cuenta {

    private int tarjetaDebito;

    /**
     * constructor vacio
     */

    public CuentaAhorros() {

    }

    /**
     * constructor el cual crea la cuenta ahorros con su información.
     * 
     * @param consecutivo   Numero de cuenta de identificacion
     * @param saldo         saldo que tiene la cuenta.
     * @param tipo          tipo de la cuenta si ahorros o corriente.
     * @param tarjetaDebito Numero de la tarjeta debito de la cuenta de ahorros.
     * @param estado        estado en el que se encuentra una cuenta.
     * @param fechaC        fecha de creacion de la cuenta.
     */

    public CuentaAhorros(int consecutivo, double saldo, String tipo, int tarjetaDebito, String estado,
            LocalDate fechaC) {
        super(consecutivo, saldo, tipo, estado, fechaC);
        this.tarjetaDebito = tarjetaDebito;
    }

    /**
     * constructor el cual se usa para crear la cuenta manualmente.
     * 
     * @param saldo         saldo que tiene la cuenta.
     * @param tipo          tipo de la cuenta si ahorros o corriente.
     * @param tarjetaDebito Numero de la tarjeta debito de la cuenta de ahorros.
     * @param estado        estado en el que se encuentra una cuenta.
     * @param fechaC        fecha de creacion de la cuenta.
     * @param titulares     Lista de titulares de la cuenta.
     */

    public CuentaAhorros(double saldo, String tipo, int tarjetaDebito, String estado, LocalDate fechaC,
            List<Titular> titulares) {
        super(saldo, tipo, estado, fechaC, titulares);
        this.tarjetaDebito = tarjetaDebito;
    }

    /**
     * metodo el cual agrega titulares a la lista de titulares.
     * 
     * @param nombre  nombre completo del titular.
     * @param fn      fecha de nacimiento del titular.
     * @param telfijo telefono fijo del titular.
     * @param cel     telefono celular del titular.
     * @param dir     dirreción del titular.
     * @throws CuentaAhorros_Exception hubo un error al agregar un titular
     */

    public void AgregarTitular(String nombre, LocalDate fn, String telfijo, String cel, String dir)
            throws CuentaAhorros_Exception {
        Titular t = Buscartitular(nombre);
        if (t == null) {
            getTitulares().add(new Titular(nombre, fn, telfijo, cel, dir));
        } else
            throw new CuentaAhorros_Exception("hubo un error al agregar un titular");
    }

    /**
     * metodo consignar el cual realiza la consignación en la cuenta.
     * 
     * @param monto cantidad de dinero que se va a consignar en la cuenta.
     * @throws CuentaAhorros_Exception No se puede hacer una consignación de 0.
     */

    public void Consignar(double monto) throws CuentaAhorros_Exception {
        if (monto > 0) {
            setSaldo(monto + getSaldo());
        } else
            throw new CuentaAhorros_Exception("No se puede hacer una consignación de 0");
    }

    /**
     * metodo Retirar el cual realiza el retiro de dinero cuenta.
     * 
     * @param monto cantidad de dinero que se va a retirar de la cuenta.
     * @throws CuentaAhorros_Exception No tiene los fondos suficientes para el
     *                                 retiro.
     * @throws CuentaAhorros_Exception No se puede hacer un retiro de 0
     */

    public void Retirar(double monto) throws CuentaAhorros_Exception {
        if (monto > 0) {
            if (getSaldo() >= monto) {
                setSaldo(getSaldo() - monto);
            } else
                throw new CuentaAhorros_Exception("No tiene los fondos suficientes para el retiro");
        } else
            throw new CuentaAhorros_Exception("No se puede hacer un retiro de 0");

    }

    /**
     * metodo Tranferir el cual realiza la tranferencia de dinero de una cuenta a
     * otra.
     * 
     * @param monto cantidad de dinero que se va a tranferir.
     * @param des   Cuenta a la que se le hara al tranferencia del dinero.
     * @throws CuentaAhorros_Exception No se puede hacer una tranferencia de 0
     */

    public void Transferir(double monto, CuentaAhorros des) throws CuentaAhorros_Exception {
        if (monto > 0) {
            Retirar(monto);
            des.Consignar(monto);
        } else
            throw new CuentaAhorros_Exception("No se puede hacer una tranferencia de 0");
    }

    /**
     * metodo Tranferir el cual realiza la tranferencia de dinero de una cuenta
     * ahorros a una cuenta corriente.
     * 
     * @param monto cantidad de dinero que se va a tranferir.
     * @param des   Cuenta corriente a la que se le hara al tranferencia del dinero.
     * @throws CuentaAhorros_Exception No se puede hacer una tranferencia de 0
     */

    public void TransferirCo(double monto, CuentaCorriente des)
            throws CuentaAhorros_Exception, CuentaCorriente_Exception {
        if (monto > 0) {
            Retirar(monto);
            des.Consignar(monto);
        } else
            throw new CuentaAhorros_Exception("No se puede hacer una tranferencia de 0");
    }

    /**
     * metodo el cual compara el nombre del titular con los nombres de titulares que
     * tiene la cuenta, en la lista de titulares.
     * 
     * @param nombre nombre del titular a buscar en la lista de titulares
     * @return t or null, si encuentra o no el titular
     */

    @Override
    public Titular Buscartitular(String nombre) {
        for (Titular t : getTitulares()) {
            if (t != null && (t.getNombre().equalsIgnoreCase(nombre))) {
                return t;
            }
        }
        return null;
    }

    /**
     * metodo el cual busca en la lista de titulares el nombre y la edad del titular
     * y lo agrega a la lista nombresTitulares.
     * 
     * @return nombresTitulares lista en la que se encuentran los nombres de los
     *         titulares con respectiva edad.
     */

    public List<String> BuscarnombreEdad() {
        List<String> nombresTitulares = new ArrayList<String>();
        for (Titular t : getTitulares()) {
            if (t != null) {
                t.calcularedad();
                nombresTitulares.add(t.getNombre() + " : " + t.getYears() + " años");
            }
        }
        return nombresTitulares;
    }

    /**
     * metodo el cual busca en la lista de titulares la fecha de nacimiento de los
     * titulares.
     * 
     * @param fechabuscar la fecha a la cual se le va a comparar la fecha de
     *                    nacimiento de los titulares.
     * @return true or false 
     */

    public boolean Buscarfechanacimiento(LocalDate fechabuscar) {
        for (Titular t : getTitulares()) {
            if (t != null) {
                if (t.getFechaNac().isBefore(fechabuscar)) {
                    return true;
                }
            }
        }
        return false;
    }

    // GETTERS Y SETTERS------------------

    /**
     * @return int
     */
    public int getTarjetaDebito() {
        return tarjetaDebito;
    }

    /**
     * @param tarjetaDebito
     */
    public void setTarjetaDebito(int tarjetaDebito) {
        this.tarjetaDebito = tarjetaDebito;
    }

    // TO STRING-------------

    /**
     * @return String
     */

    @Override
    public String toString() {
        return "Cuenta de Ahorros [Tarjeta Debito = " + tarjetaDebito + "]\n " + super.toString() + "]";
    }
}
