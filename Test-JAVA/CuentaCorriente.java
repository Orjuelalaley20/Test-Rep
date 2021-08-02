import java.time.LocalDate;
import java.util.ArrayList;
import java.util.List;

/**
 * Clase CuentaCorriente que hereda de Cuenta sus metodos y atributos y ademas
 * de eso permite hacer las operaciones necesarias en la cuenta
 * 
 * @author Sebastian Orjuela
 * @author Isabella Blanco
 * @since 27-05-2021
 */

public class CuentaCorriente extends Cuenta {
    double sobregiro;
    double sobregiroUsado;

    /**
     * constructor vacio
     */

    public CuentaCorriente() {

    }

    /**
     * constructor el cual crea la cuenta corriente con su información.
     * 
     * @param consecutivo    Numero de cuenta de identificacion
     * @param saldo          saldo que tiene la cuenta.
     * @param tipo           tipo de la cuenta si ahorros o corriente.
     * @param sobregiro      sobregiro autorizado por el banco en la cuenta
     *                       corriente.
     * @param estado         estado en el que se encuentra una cuenta.
     * @param sobregiroUsado sobregiro usado dentro de la cuenta corriente.
     * @param fechaC         fecha de creacion de la cuenta.
     */

    public CuentaCorriente(int consecutivo, double saldo, String tipo, Double sobregiro, String estado,
            double sobregiroUsado, LocalDate fechaC) {
        super(consecutivo, saldo, tipo, estado, fechaC);
        this.sobregiro = sobregiro;
        this.sobregiroUsado = sobregiroUsado;
    }

    /**
     * constructor el cual se usa para crear la cuenta manualmente.
     * 
     * @param saldo          saldo que tiene la cuenta.
     * @param tipo           tipo de la cuenta si ahorros o corriente.
     * @param sobregiro      sobregiro autorizado por el banco en la cuenta
     *                       corriente.
     * @param estado         estado en el que se encuentra una cuenta.
     * @param sobregiroUsado sobregiro usado dentro de la cuenta corriente.
     */

    public CuentaCorriente(double saldo, String tipo, double sobregiro, String estado, double sobregiroUsado,
            LocalDate fechaC, List<Titular> titulares) {
        super(saldo, tipo, estado, fechaC, titulares);
        this.sobregiro = sobregiro;
        this.sobregiroUsado = sobregiroUsado;
    }

    /**
     * metodo el cual agrega titulares a la lista de titulares.
     * 
     * @param nombre  nombre completo del titular.
     * @param fn      fecha de nacimiento del titular.
     * @param telfijo telefono fijo del titular.
     * @param cel     telefono celular del titular.
     * @param dir     dirreción del titular.
     * @throws CuentaCorriente_Exception hubo un error al agregar un titular.
     */

    @Override
    public void AgregarTitular(String nombre, LocalDate fn, String telfijo, String cel, String dir)
            throws CuentaCorriente_Exception {
        Titular t = Buscartitular(nombre);
        if (t == null) {
            getTitulares().add(new Titular(nombre, fn, telfijo, cel, dir));
        } else
            throw new CuentaCorriente_Exception("hubo un error al agregar un titular");
    }

    /**
     * metodo consignar el cual realiza la consignación en la cuenta.
     * 
     * @param monto cantidad de dinero que se va a consignar en la cuenta.
     * @throws CuentaCorriente_Exception No se puede hacer una consignación de 0.
     */

    public void Consignar(Double monto) throws CuentaCorriente_Exception {
        if (monto > 0) {
            if (getSobregiroUsado() != 0) {
                if (monto >= getSobregiroUsado()) {
                    setSobregiro(getSobregiroUsado() + getSobregiro());
                    setSaldo(monto - getSobregiroUsado());
                    setSobregiroUsado(0);
                }
            } else {
                setSaldo(monto + getSaldo());
            }
        } else
            throw new CuentaCorriente_Exception("No se puede hacer una consignación de 0");
    }

    /**
     * metodo Retirar el cual realiza el retiro de dinero cuenta.
     * 
     * @param monto cantidad de dinero que se va a retirar de la cuenta.
     * @throws CuentaCorriente_Exception No se puede hacer un retiro de 0.
     * @throws CuentaCorriente_Exception No se puede procesar el retiro, el monto
     *                                   excede el saldo y el sobregiro autorizado
     *                                   por el banco
     */

    public void Retirar(Double monto) throws CuentaCorriente_Exception {
        Double MaxRet = (getSaldo() + getSobregiro() - getSobregiroUsado());
        if (monto > 0) {
            if (MaxRet >= monto) {
                if (monto > getSaldo()) {
                    setSobregiroUsado(getSobregiroUsado() + monto - getSaldo());
                    setSaldo(0);
                    setSobregiro(getSobregiro() - getSobregiroUsado());
                } else {
                    setSaldo(getSaldo() - monto);
                }
            } else
                throw new CuentaCorriente_Exception(
                        "No se puede procesar el retiro, el monto excede el saldo y el sobregiro autorizado por el banco");
        } else
            throw new CuentaCorriente_Exception("No se puede hacer un retiro de 0");

    }

    /**
     * metodo Tranferir el cual realiza la tranferencia de dinero de una cuenta a
     * otra.
     * 
     * @param monto cantidad de dinero que se va a tranferir.
     * @param des   Cuenta a la que se le hara al tranferencia del dinero.
     * @throws CuentaCorriente_Exception No se puede hacer una tranferencia de 0
     */

    public void Transferir(Double monto, CuentaCorriente des) throws CuentaCorriente_Exception {
        if (monto > 0) {
            Retirar(monto);
            des.Consignar(monto);
        } else
            throw new CuentaCorriente_Exception("No se puede hacer una tranferencia de 0");

    }

    /**
     * metodo TranferirCa el cual realiza la tranferencia de dinero de una cuenta
     * corriente a una cuenta de ahorros
     * 
     * @param monto cantidad de dinero que se va a tranferir de la cuenta.
     * @param des   cuenta de ahorros a la que se le hara la tranferencia del
     *              dinero.
     * @throws CuentaCorriente_Exception No se puede hacer una tranferencia de 0
     * @throws CuentaAhorros_Exception   No se puede hacer una tranferencia de 0
     */

    public void TransferirCa(Double monto, CuentaAhorros des)
            throws CuentaCorriente_Exception, CuentaAhorros_Exception {
        if (monto > 0) {
            Retirar(monto);
            des.Consignar(monto);
        } else
            throw new CuentaCorriente_Exception("No se puede hacer una tranferencia de 0");
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
     * @return true or false.
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
     * @return double
     */
    public double getSobregiro() {
        return sobregiro;
    }

    /**
     * @param sobregiro
     */
    public void setSobregiro(double sobregiro) {
        this.sobregiro = sobregiro;
    }

    /**
     * @return double
     */
    public double getSobregiroUsado() {
        return sobregiroUsado;
    }

    /**
     * @param sobregiroUsado
     */
    public void setSobregiroUsado(double sobregiroUsado) {
        this.sobregiroUsado = sobregiroUsado;
    }

    // TO STRING-------------

    /**
     * @return String
     */
    @Override
    public String toString() {
        return "Cuenta Corriente [sobregiro = " + sobregiro + ", sobregiro Usado = " + sobregiroUsado + "]\n"
                + super.toString() + "]";
    }

}
