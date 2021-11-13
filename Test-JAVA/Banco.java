import java.time.LocalDate;
import java.util.*;
import java.util.concurrent.ThreadLocalRandom;
import java.io.Serializable;

/**
 * Clase Banco que permite asignarle un nombre y agregar cuentas a la lista de
 * cuentas
 * 
 * @author Sebastian Orjuela
 * @author Isabella Blanco
 * @since 27-05-2021
 */

public class Banco implements Serializable {
    private String nombre;
    private List<Cuenta> cuentas;

    /**
     * constructor vacio
     */

    public Banco() {
        
    }

    /**
     * constructor que le asigna el nombre al banco y crea la lista de cuentas
     * 
     * @param string cadena donde se encuentra el nombre del banco
     */

    public Banco(String string) {
        this.nombre = string;
        cuentas = new ArrayList<>();
    }

    /**
     * metodo que adiciona cuentas en la lista de cuentas
     * 
     * @param Ssaldo      Cadena donde se encuentra el saldo de la cuenta para que
     *                    se convierta en double y se le agregue a la cuenta.
     * @param tipo        tipo de cuenta si ahorros o corriente.
     * @param SnumCuenta  Numero de la tarjeta debito en caso de que la cuenta sea
     *                    ahorros y el sobregiro autorizado por el banco en caso que
     *                    sea corriente.
     * @param consecutivo numero con el cual las cuentas se diferencian y no se
     *                    pueden copiar una de otra.
     * @throws Banco_Exception Se encontro la cuenta, no se puede sobre escribir
     * 
     */

    public void adicionarCuenta(String Ssaldo, String tipo, String SnumCuenta, int consecutivo) throws Banco_Exception {
        double saldo = Double.parseDouble(Ssaldo);
        String estado = "ACTIVA";
        LocalDate fechaDeInicio = LocalDate.of(1970, 1, 1);
        long Inicio = fechaDeInicio.toEpochDay();
        LocalDate fechaActual = LocalDate.now();
        long Actual = fechaActual.toEpochDay();
        long fechaAleatoria = ThreadLocalRandom.current().longs(Inicio, Actual).findAny().getAsLong();
        LocalDate fechaC = LocalDate.ofEpochDay(fechaAleatoria);
        Cuenta c = buscarCuenta(consecutivo);
        if (c == null) {
            if (tipo.equalsIgnoreCase("ahorros")) {
                int TarjetaDebito = Integer.parseInt(SnumCuenta);
                cuentas.add(new CuentaAhorros(consecutivo, saldo, tipo, TarjetaDebito, estado, fechaC));
            } else if (tipo.equalsIgnoreCase("corriente")) {
                double Sobregiro = Double.parseDouble(SnumCuenta);
                double sobregiroU = 0;
                cuentas.add(new CuentaCorriente(consecutivo, saldo, tipo, Sobregiro, estado, sobregiroU, fechaC));
            }

        } else
            throw new Banco_Exception("Se encontro la cuenta, no se puede sobre escribir");
    }

    /**
     * metodo que se usa para crear una cuenta manualmente y adiciona esa cuenta a
     * la lista de cuentas.
     * 
     * @param nsaldo      Cadena donde se encuentra el saldo de la cuenta para que
     *                    se convierta en double y se le agregue a la cuenta.
     * @param ntipo       tipo de cuenta si ahorros o corriente.
     * @param NnumCuenta  Numero de la tarjeta debito en caso de que la cuenta sea
     *                    ahorros y el sobregiro autorizado por el banco en caso que
     *                    sea corriente.
     * @param consecutivo numero con el cual las cuentas se diferencian y no se
     *                    pueden copiar una de otra.
     * @throws Banco_Exception Se encontro la cuenta, no se puede sobre escribir
     * 
     */

    public void adicionarNuevaCuenta(String nsaldo, String ntipo, String NnumCuenta, int consecutivo)
            throws Banco_Exception {
        float saldo = Float.parseFloat(nsaldo);
        String estado = "ACTIVA";
        LocalDate fechaC = LocalDate.now();
        Cuenta c = buscarCuenta(consecutivo);
        if (c == null) {
            if (ntipo.equalsIgnoreCase("ahorros")) {
                int TarjetaDebito = Integer.parseInt(NnumCuenta);
                cuentas.add(new CuentaAhorros(consecutivo, saldo, ntipo, TarjetaDebito, estado, fechaC));
            } else if (ntipo.equalsIgnoreCase("corriente")) {
                double Sobregiro = Double.parseDouble(NnumCuenta);
                double sobregiroU = 0;
                cuentas.add(new CuentaCorriente(consecutivo, saldo, ntipo, Sobregiro, estado, sobregiroU, fechaC));
            }

        } else
            throw new Banco_Exception("Se encontro la cuenta, no se puede sobre escribir");
    }

    /**
     * metodo que adiciona titulares a la lista de titualares
     * 
     * @param consecutivo Numero de la cuenta a la que se le agregaran los titulares
     * @param nombre      nombre del titular
     * @param fn          fecha de nacimiento del titular
     * @param telfijo     telefono fijo del titualar
     * @param cel         telefono celular del titular
     * @param dir         dirreción del titular
     * @throws Banco_Exception           No se encontro la cuenta
     * @throws CuentaCorriente_Exception hubo un error al agregar un titular
     * @throws CuentaAhorros_Exception   hubo un error al agregar un titular
     */

    public void AdicionarTitular(int consecutivo, String nombre, String fn, String telfijo, String cel, String dir)
            throws Banco_Exception, CuentaAhorros_Exception, CuentaCorriente_Exception {
        // buscar la cuenta con el consecutivo que es su numero identificador
        Cuenta c = buscarCuenta(consecutivo);
        if (c != null) {
            if (c instanceof CuentaAhorros) {
                LocalDate fechaN = LocalDate.parse(fn);
                ((CuentaAhorros) c).AgregarTitular(nombre, fechaN, telfijo, cel, dir);
            }
            if (c instanceof CuentaCorriente) {
                LocalDate fechaN = LocalDate.parse(fn);
                ((CuentaCorriente) c).AgregarTitular(nombre, fechaN, telfijo, cel, dir);
            }
        } else
            throw new Banco_Exception("No se encontro la cuenta");
    }

    /**
     * metodo que realiza la consignacion de un monto de dinero a la cuenta que el
     * cliente desee
     * 
     * @param numcon numero de cuenta a la que se va a consignar
     * @param monto  cantidad de dinero que se va a consignar en la cuenta
     * @throws Banco_Exception           La cuenta no ha sido encontrada en el
     *                                   sistema
     * @throws CuentaAhorros_Exception   No se puede hacer una consignación de 0
     * @throws CuentaCorriente_Exception No se puede hacer una consignación de 0
     * @return consignar lista en la que se encuentra la informacion de la
     *         consignación
     */

    public List<String> Consignar(int numcon, Double monto)
            throws Banco_Exception, CuentaAhorros_Exception, CuentaCorriente_Exception {
        Cuenta c = buscarCuenta(numcon);
        List<String> consignar = new ArrayList<String>();
        if (c != null) {
            if (c instanceof CuentaAhorros) {
                ((CuentaAhorros) c).Consignar(monto);
                consignar.add(" ");
                consignar.add("consignación realizada con exito !!");
                consignar.add(" ");
                consignar.add("El saldo de la cuenta ahora es: " + ((CuentaAhorros) c).getSaldo());
                consignar.add(" ");
                return consignar;
            }
            if (c instanceof CuentaCorriente) {
                ((CuentaCorriente) c).Consignar(monto);
                consignar.add("consignación realizado con exito !!");
                consignar.add(" ");
                consignar.add("El saldo de la cuenta ahora es de : " + ((CuentaCorriente) c).getSaldo());
                consignar.add("El sobregiro autorizado de la cuenta es de : " + ((CuentaCorriente) c).getSobregiro());
                consignar.add("El sobregiro usado de la cuenta es de : " + ((CuentaCorriente) c).getSobregiroUsado());
                consignar.add(" ");
                return consignar;
            }
        }
        throw new Banco_Exception("La cuenta no ha sido encontrada en el sistema");
    }

    /**
     * metodo que realiza el retiro de un monto de dinero de la cuenta que el
     * cliente desee
     * 
     * @param numret numero de la cuenta a la que se va a retirar dinero
     * @param monto  cantidad de dinero que se va a retirar de la cuenta
     * @throws Banco_Exception           La cuenta no ha sido encontrada en el
     *                                   sistema
     * @throws CuentaAhorros_Exception
     * @throws CuentaCorriente_Exception
     * @return retirar lista en la que se encuentra la información del retiro
     */

    public List<String> Retirar(int numret, Double monto)
            throws Banco_Exception, CuentaAhorros_Exception, CuentaCorriente_Exception {
        Cuenta c = buscarCuenta(numret);
        List<String> retirar = new ArrayList<String>();
        if (c != null) {
            if (c instanceof CuentaAhorros) {
                ((CuentaAhorros) c).Retirar(monto);
                retirar.add(" ");
                retirar.add("Retiro realizado con exito !!");
                retirar.add(" ");
                retirar.add("El saldo de la cuenta ahora es: " + ((CuentaAhorros) c).getSaldo());
                return retirar;
            }
            if (c instanceof CuentaCorriente) {
                ((CuentaCorriente) c).Retirar(monto);
                retirar.add("Retiro realizada con exito !!");
                retirar.add(" ");
                retirar.add("El nuevo saldo de la cuenta es de : " + ((CuentaCorriente) c).getSaldo());
                retirar.add("El nuevo Sobregiro autorizado es de : " + ((CuentaCorriente) c).getSobregiro());
                retirar.add("El nuevo sobregiro Usado es de : " + ((CuentaCorriente) c).getSobregiroUsado());
                retirar.add(" ");
                return retirar;
            }
        }
        throw new Banco_Exception("La cuenta no ha sido encontrada en el sistema");
    }

    /**
     * metodo que permite hacer una tranferencia de una cuenta a otra
     * 
     * @param cuorigin numero de la cuenta origen
     * @param cuedesti numero de la cuenta destino
     * @param monto    monto a tranferir
     * @throws Banco_Exception           No se puede hacer una tranferencia a la
     *                                   misma cuenta
     * @throws Banco_Exception           La cuenta destino esta mal escrita o no
     *                                   existe en el sistema
     * @throws CuentaAhorros_Exception
     * @throws CuentaCorriente_Exception
     * @return lista de strings en la cual se guarda toda la informacion de la
     *         tranferencia
     * 
     */

    public List<String> Tranferir(int cuorigin, int cuedesti, double monto)
            throws Banco_Exception, CuentaAhorros_Exception, CuentaCorriente_Exception {
        Cuenta co = buscarCuenta(cuorigin);
        Cuenta cd = buscarCuenta(cuedesti);
        List<String> transferir = new ArrayList<String>();
        if (co != null) {
            if (cd != null) {
                if (co != cd) {
                    if (co instanceof CuentaAhorros && cd instanceof CuentaAhorros) {
                        ((CuentaAhorros) co).Transferir(monto, ((CuentaAhorros) cd));
                        transferir.add(" ");
                        transferir.add("El nuevo saldo de la cuenta origen es de : " + ((CuentaAhorros) co).getSaldo());
                        transferir
                                .add("El nuevo saldo de la cuenta destino es de : " + ((CuentaAhorros) cd).getSaldo());
                        transferir.add(" ");
                        return transferir;
                    }
                    if (co instanceof CuentaAhorros && cd instanceof CuentaCorriente) {
                        ((CuentaAhorros) co).TransferirCo(monto, ((CuentaCorriente) cd));
                        transferir.add(" ");
                        transferir.add("El nuevo saldo de la cuenta origen es de : " + ((CuentaAhorros) co).getSaldo());
                        transferir.add(
                                "El nuevo saldo de la cuenta destino es de : " + ((CuentaCorriente) cd).getSaldo());
                        transferir
                                .add("El nuevo Sobregiro autorizado es de : " + ((CuentaCorriente) cd).getSobregiro());
                        transferir
                                .add("El nuevo sobregiro Usado es de : " + ((CuentaCorriente) cd).getSobregiroUsado());
                        transferir.add(" ");
                        return transferir;
                    }
                    if (co instanceof CuentaCorriente && cd instanceof CuentaCorriente) {
                        ((CuentaCorriente) co).Transferir(monto, ((CuentaCorriente) cd));
                        transferir.add(" ");
                        transferir
                                .add("El nuevo saldo de la cuenta origen es de :" + ((CuentaCorriente) co).getSaldo());
                        transferir.add("El nuevo Sobregiro autorizado de la cuenta origen es de : "
                                + ((CuentaCorriente) co).getSobregiro());
                        transferir.add("El nuevo sobregiro Usado de la cuenta origen es de : "
                                + ((CuentaCorriente) co).getSobregiroUsado());
                        transferir.add(
                                "El nuevo saldo de la cuenta destino es de : " + ((CuentaCorriente) cd).getSaldo());
                        transferir.add("El nuevo Sobregiro autorizado de la cuenta destino es de : "
                                + ((CuentaCorriente) cd).getSobregiro());
                        transferir.add("El nuevo sobregiro Usado de la cuenta destino es de : "
                                + ((CuentaCorriente) cd).getSobregiroUsado());
                        transferir.add(" ");
                        return transferir;
                    }
                    if (co instanceof CuentaCorriente && cd instanceof CuentaAhorros) {
                        ((CuentaCorriente) co).TransferirCa(monto, ((CuentaAhorros) cd));
                        transferir.add(" ");
                        transferir
                                .add("El nuevo saldo de la cuenta origen es de :" + ((CuentaCorriente) co).getSaldo());
                        transferir.add("El nuevo Sobregiro autorizado de la cuenta origen es de : "
                                + ((CuentaCorriente) co).getSobregiro());
                        transferir.add("El nuevo sobregiro Usado de la cuenta origen es de : "
                                + ((CuentaCorriente) co).getSobregiroUsado());
                        transferir
                                .add("El nuevo saldo de la cuenta destino es de : " + ((CuentaAhorros) cd).getSaldo());
                        transferir.add(" ");
                        return transferir;
                    }

                }
                throw new Banco_Exception("No se puede hacer una tranferencia a la misma cuenta");

            } else
                throw new Banco_Exception("La cuenta destino esta mal escrita o no existe en el sistema");
        }
        return null;
    }

    /**
     * metodo que utiliza para obtener el saldo de la cuenta
     * 
     * @param cuorigin numero de la cuenta el cual se va a buscar y posterior se
     *                 obtendra el saldo de la misma
     * @return retorna el saldo de la cuenta
     * @exception Banco_Exception si la cuenta esta mal escrita informara la
     *                            excepcion
     * 
     */

    public List<String> obtenersaldo(int cuorigin) throws Banco_Exception {
        Cuenta co = buscarCuenta(cuorigin);
        List<String> obs = new ArrayList<String>();
        if (co != null) {
            if (co instanceof CuentaAhorros) {
                obs.add("Saldo maximo :" + co.getSaldo());
                return obs;
            }
            if (co instanceof CuentaCorriente) {
                obs.add("Saldo maximo : " + ((CuentaCorriente) co).getSaldo());
                obs.add("Con un sobregiro autorizado maximo de : " + ((CuentaCorriente) co).getSobregiro());
                return obs;
            }
        }
        throw new Banco_Exception("La cuenta esta mal escrita o no esta en el sistema");
    }

    /**
     * metodo que utiliza para obtener la informacion de los titulares y sus edades
     * 
     * @param numCue numero de la cuenta donde se debe buscar sus titulares.
     * @exception Banco_Exception No se encontro la cuenta
     * @return retorna una lista de strings con el nombre y la edad del titular.
     * 
     */

    public List<String> obtenernombretitu(int numCue) throws Banco_Exception {
        Cuenta cnt = buscarCuenta(numCue);
        if (cnt != null) {
            return cnt.BuscarnombreEdad();
        } else
            throw new Banco_Exception("No se encontro la cuenta");
    }

    /**
     * metodo que se usa para buscar la cuenta en la lista de cuentas
     * 
     * @param consecutivo numero donde esta la cuenta para que se busque en la lista
     *                    de cuentas
     * 
     */

    public Cuenta buscarCuenta(int consecutivo) {
        for (Cuenta c : cuentas) {
            if (c != null && c.getNumconse() == (consecutivo)) {
                return c;
            }
        }
        return null;
    }

    /**
     * metodo que se usa para buscar la fecha de nacimiento de los titulares en la
     * lista de titulares y compararla con la fecha ingresada, Si la fecha ingresada
     * es despues de la fecha de nacimiento del titular agregue la cuenta a la lista
     * de "cuentasfecha" para ser retornada.
     * 
     * @param fechab Fecha la cual se va a buscar.
     * @throws Banco_Exception no hay cuentas creadas antes de la fecha.
     * @return cuentasfecha lista en la cual se encuentran las cuentas con la fecha
     *         de nacimiento de los titulares antes que la fecha introducida.
     */

    public List<String> buscarFecha(LocalDate fechab) throws Banco_Exception {
        List<String> cuentasfecha = new ArrayList<String>();
        for (Cuenta c : cuentas) {
            if (c != null) {
                if (c instanceof CuentaAhorros) {
                    if (c.Buscarfechanacimiento(fechab)) {
                        cuentasfecha.add(String.valueOf(c));
                    }
                }
                if (c instanceof CuentaCorriente) {
                    if (c.Buscarfechanacimiento(fechab)) {
                        cuentasfecha.add(String.valueOf(c));
                    }
                }
            }
        }
        if (cuentasfecha.size() == 0) {
            throw new Banco_Exception("no hay cuentas con titulares que hayan nacido antes de : " + fechab);
        }
        return cuentasfecha;
    }

    /**
     * metodo que se usa para imprimir el informe general de las cuentas en el banco
     * 
     * @return imprimircuentas lista de strings en el cual se guarda la información
     *         de las cuentas
     */

    public List<String> ImprimirInforme() {
        List<String> imprimircuentas = new ArrayList<String>();
        for (Cuenta c : cuentas) {
            if (c instanceof CuentaAhorros) {
                imprimircuentas.add("--------/#CUENTA " + c.getNumconse() + "/-----\n");
                imprimircuentas.add("Saldo--------Tipo-------Tarjeta------Estado------Fecha de creación \n");
                imprimircuentas.add(String.valueOf(c.getSaldo()) + " --- " + c.getTipo() + " ---- "
                        + ((CuentaAhorros) c).getTarjetaDebito() + " ---- " + c.getEstado() + " ----- "
                        + c.getFechaCreacion() + "\n");
                imprimircuentas.add(String.valueOf(c.getTitulares()));
                imprimircuentas.add("\n");
            }
            if (c instanceof CuentaCorriente) {
                imprimircuentas.add("--------/#CUENTA " + c.getNumconse() + "/-----\n");
                imprimircuentas.add(
                        "Saldo---------Tipo-------Sobregiro--------Sobregiro Usado---------Estado-----Fecha de creación \n");
                imprimircuentas.add(String.valueOf(c.getSaldo()) + " - " + c.getTipo() + " --- "
                        + ((CuentaCorriente) c).getSobregiro() + " ---------------- "
                        + ((CuentaCorriente) c).getSobregiroUsado() + " ------------- " + c.getEstado() + " ------ "
                        + c.getFechaCreacion() + "\n");
                imprimircuentas.add(String.valueOf(c.getTitulares()));
                imprimircuentas.add("\n");
            }
        }
        return imprimircuentas;
    }

    // GETTERS Y SETTERS------------------

    /**
     * @return String
     */
    public String getNombre() {
        return nombre;
    }

    /**
     * @param nombre
     */
    public void setNombre(String nombre) {
        this.nombre = nombre;
    }

    public List<Cuenta> getCuentas() {
        return cuentas;
    }

    public void setCuentas(List<Cuenta> cuentas) {
        this.cuentas = cuentas;
    }

    // TO STRING-------------

    /**
     * @return String
     */
    @Override
    public String toString() {
        return "Banco : nombre = " + nombre + "\n" + cuentas + "]";
    }
}