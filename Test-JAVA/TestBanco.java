import java.time.LocalDate;
import java.time.format.DateTimeFormatter;
import java.time.format.DateTimeParseException;
import java.util.*;

/**
 * Clase TestBanco en la que se imprimen los datos en pantalla
 * 
 * @author Sebastian orjuela
 * @author Isabella blanco
 * @since 27-05-2021
 */
public class TestBanco {

    private static Banco banc;
    

    /**
     * constructor vacio
     */

    public TestBanco() {

    }

    /**
     * @param args
     */
    public static void main(String[] args) {
        Scanner s = new Scanner(System.in);
        String opcion;
        do {
            System.out.println("------------------------/MENU DE JAVIBANK/------------------------");
            System.out.println(" ");
            System.out.println("1. Crear cuentas y titulares");
            System.out.println("2. Consignar en una cuenta");
            System.out.println("3. Retirar de la cuenta");
            System.out.println("4. Transferir de una cuenta a otra");
            System.out.println("5. Mostrar titulares con su edad");
            System.out.println("6. Mostrar todas las cuentas de los titulares que nacieron antes de esa fecha");
            System.out.println("7. Mostrar toda la informacion de cada una de las cuentas del banco");
            System.out.println("8. Serializar");
            System.out.println("9. Deserializar");
            System.out.println("10. Terminar programa ");
            System.out.println("Digite su Opcion a elegir: ");
            opcion = s.nextLine();
            switch (opcion) {
                case "1":
                    // Crear cuentas y titulares
                    System.out.println("----------/MENU DE CUENTAS/--------------");
                    System.out.println(" ");
                    System.out.println("1. Crear cuenta manualmente");
                    System.out.println("2. leer archivo con cuentas");
                    opcion = s.nextLine();
                    switch (opcion) {
                        case "1":
                            // Crear cuenta manualmente
                            List<Cuenta> Ncuenta = new ArrayList<Cuenta>();
                            int opcionc = 0;
                            int numtitu;
                            try {
                                do {
                                    System.out.println("Ingrese el tipo de cuenta que desea crear:");
                                    System.out.println("1. Corriente");
                                    System.out.println("2. Ahorros");
                                    opcion = s.nextLine();
                                    switch (opcion) {
                                        case "1":
                                            List<Titular> titularc = new ArrayList<Titular>();
                                            String tipoc = "corriente";
                                            String estadoc = "ACTIVA";
                                            double Sobregiro = (Math.floor(Math.random() * (555555 - 111111) + 111111));
                                            double sobregiroUsado = 0;
                                            System.out
                                                    .println("Ingrese la cantidad de saldo con el que desea iniciar: ");
                                            double saldoc = s.nextFloat();
                                            LocalDate fechaCo = LocalDate.now();
                                            System.out.println("Cuantos titulares desea que tenga la cuenta: ");
                                            numtitu = s.nextInt();
                                            s.nextLine();
                                            for (int i = 0; i < numtitu; i++) {
                                                System.out.println("Ingrese el nombre del titular: ");
                                                String nom = s.nextLine();
                                                System.out.println("Ingrese la fecha de nacimiento (aaaa-mm-dd): ");
                                                String fecha = s.next();
                                                s.nextLine();
                                                final DateTimeFormatter dateTimeFormatter = DateTimeFormatter
                                                        .ofPattern("yyyy-MM-dd");
                                                LocalDate fechaN = LocalDate.parse(fecha, dateTimeFormatter);
                                                System.out.println("Ingrese el telefono fijo: ");
                                                String fijo = s.nextLine();
                                                System.out.println("Ingrese el celular: ");
                                                String cel = s.nextLine();
                                                System.out.println("Ingrese la direccion: ");
                                                String dir = s.nextLine();
                                                titularc.add(new Titular(nom, fechaN, fijo, cel, dir));
                                            }
                                            Ncuenta.add(new CuentaCorriente(saldoc, tipoc, Sobregiro, estadoc,
                                                    sobregiroUsado, fechaCo, titularc));
                                            ManejadorDeArchivos.escribirNuevasC("Nuevas.txt", Ncuenta);
                                            break;
                                        case "2":
                                            List<Titular> titulara = new ArrayList<Titular>();
                                            String tipoa = "ahorros";
                                            String estadoa = "ACTIVA";
                                            int TarjetaDebito = ((int) Math
                                                    .floor(Math.random() * (999999 - 111111) + 111111));
                                            System.out
                                                    .println("Ingrese la cantidad de saldo con el que desea iniciar: ");
                                            float saldoa = s.nextFloat();
                                            LocalDate fechaCa = LocalDate.now();

                                            System.out.println("Cuantos titulares desea que tenga la cuenta: ");
                                            numtitu = s.nextInt();
                                            s.nextLine();
                                            for (int i = 0; i < numtitu; i++) {
                                                System.out.println("Ingrese el nombre del titular: ");
                                                String nom = s.nextLine();
                                                System.out.println("Ingrese la fecha de nacimiento (aaaa-mm-dd): ");
                                                String naci = s.nextLine();
                                                LocalDate fechaN = LocalDate.parse(naci);
                                                System.out.println("Ingrese el telefono fijo: ");
                                                String fijo = s.nextLine();
                                                System.out.println("Ingrese el celular: ");
                                                String cel = s.nextLine();
                                                System.out.println("Ingrese la direccion: ");
                                                String dir = s.nextLine();
                                                titulara.add(new Titular(nom, fechaN, fijo, cel, dir));
                                            }
                                            Ncuenta.add(new CuentaAhorros(saldoa, tipoa, TarjetaDebito, estadoa,
                                                    fechaCa, titulara));
                                            ManejadorDeArchivos.escribirNuevasC("Nuevas.txt", Ncuenta);
                                    }
                                    do {
                                        System.out.println("Desea seguir creando cuentas ?");
                                        System.out.println("1. Si");
                                        System.out.println("2. No");
                                        System.out.println("Digite su Opcion a elegir: ");
                                        opcionc = s.nextInt();
                                        s.nextLine();
                                        if (opcionc == 2 && Ncuenta.size() != 0) {
                                            banc = ManejadorDeArchivos.leerNuevoArch("Nuevas.txt", "Cuentas.txt");
                                            System.out.println(banc);
                                        }
                                        if (opcionc == 2) {
                                            break;
                                        } else if (opcionc != 1) {
                                            System.out.println(" ");
                                            System.out.println("Opcion no valida");
                                            System.out.println(" ");
                                        }
                                    } while (opcionc != 2);
                                } while (opcionc != 2);
                            } catch (DateTimeParseException e) {
                                System.err.println(" ");
                                System.out.println(e.getLocalizedMessage()
                                        + "\nSin una fecha de nacimiento en el formato aaaa-MM-dd\nNo se puede crear la cuenta manualmente\nIntentelo nuevamente");
                                System.out.println(" ");
                            }
                            break;
                        case "2":
                            //leer archivo con cuentas
                            banc = ManejadorDeArchivos.leerDeArchivoTexto("Cuentas.txt");
                            System.out.println(banc);
                            break;
                        default:
                            System.out.println("Opcion no valida");
                            break;
                    }
                    break;
                case "2":
                    // Consignar en una cuenta
                    System.out.println("Escriba el numero de la cuenta : ");
                    int numcon = s.nextInt();
                    System.out.println("Escriba el monto a consignar :");
                    Double monto = s.nextDouble();
                    s.nextLine();
                    try {
                        List<String> consi = banc.Consignar(numcon, monto);
                        for (String co : consi) {
                            System.out.println(co);
                        }
                    } catch (Banco_Exception e) {
                        System.out.println(" ");
                        System.out.println(e.getDetalle() + "\nIntentelo nuevamente\n");
                    } catch (CuentaAhorros_Exception e) {
                        System.out.println(e.getDetalle() + "\nIntentelo nuevamente\n");
                    } catch (CuentaCorriente_Exception e) {
                        System.out.println(e.getDetalle() + "\nIntentelo nuevamente\n");
                    }
                    break;
                case "3":
                    // Retirar de la cuenta
                    System.out.println("Escriba el numero de la cuenta : ");
                    int numret = s.nextInt();
                    s.nextLine();
                    try {
                        System.out.println(" ");
                        List<String> maxsal = banc.obtenersaldo(numret);
                        if (maxsal != null) {
                            for (String r : maxsal) {
                                System.out.println(r);
                            }
                        }
                        System.out.println(" ");
                        System.out.println("Escriba el monto a retirar :");
                        Double mont = s.nextDouble();
                        s.nextLine();
                        List<String> retirar = banc.Retirar(numret, mont);
                        if (retirar != null) {
                            for (String r : retirar) {
                                System.out.println(r);
                            }
                        }
                    } catch (Banco_Exception e) {
                        System.out.println(e.getDetalle() + "\nIntentelo nuevamente\n");
                    } catch (CuentaAhorros_Exception e) {
                        System.out.println(e.getDetalle() + " nIntentelo nuevamente\n");
                    } catch (CuentaCorriente_Exception e) {
                        System.out.println(e.getDetalle() + "\nIntentelo nuevamente\n");
                    }
                    break;
                case "4":
                    // Transferir de una cuenta a otra
                    System.out.println("Escriba el numero de la cuenta origen :");
                    int cuorigin = s.nextInt();
                    s.nextLine();
                    try {
                        System.out.println(" ");
                        List<String> maxtransf = banc.obtenersaldo(cuorigin);
                        if (maxtransf != null) {
                            for (String r : maxtransf) {
                                System.out.println(r);
                            }
                        }
                        System.out.println(" ");
                        System.out.println("Escriba el numero de la cuenta destino :");
                        int cuedesti = s.nextInt();
                        System.out.println("Escriba el monto a transferir : ");
                        int montra = s.nextInt();
                        s.nextLine();
                        List<String> tranf = (banc.Tranferir(cuorigin, cuedesti, montra));
                        if (tranf != null) {
                            for (String cad : tranf) {
                                System.out.println(cad);
                            }
                        }
                    } catch (Banco_Exception e) {
                        System.out.println(e.getDetalle() + "\nIntentelo nuevamente\n");
                    } catch (CuentaAhorros_Exception e) {
                        System.out.println(e.getDetalle() + "\nIntentelo nuevamente\n");
                    } catch (CuentaCorriente_Exception e) {
                        System.out.println(e.getDetalle() + "\nIntentelo nuevamente\n");
                    }
                    break;
                case "5":
                    // Mostrar titulares con su edad
                    System.out.println("Escriba el numero de cuenta :");
                    int numCue = s.nextInt();
                    s.nextLine();
                    try {
                        List<String> nombreTitulares = banc.obtenernombretitu(numCue);
                        if (nombreTitulares != null) {
                            System.out.println(" ");
                            for (String cad : nombreTitulares) {
                                System.out.println(cad);
                                System.out.println(" ");
                            }
                        }
                    } catch (Banco_Exception e) {
                        System.out.println(e.getDetalle() + "\nIntentelo nuevamente\n");
                    }
                    break;
                case "6":
                    // mostrar todas las cuentas de los titulares que nacieron antes de esa fecha
                    System.out.println("Escriba la fecha que desea consultar la informacion en formato aaaa-MM-dd : ");
                    try {
                        String fecha = s.next();
                        s.nextLine();
                        final DateTimeFormatter dateTimeFormatter = DateTimeFormatter.ofPattern("yyyy-MM-dd");
                        LocalDate fechab = LocalDate.parse(fecha, dateTimeFormatter);
                        List<String> cuentasf = banc.buscarFecha(fechab);
                        System.out.println("Las cuentas con los titualares que nacieron antes de la fecha son :  "
                                + fechab + " son : ");
                        System.out.println(" ");
                        if (cuentasf != null) {
                            for (String c : cuentasf) {
                                System.out.println(c);
                            }
                        }
                    } catch (Banco_Exception e) {
                        System.out.println(" ");
                        System.out.println(e.getDetalle());
                        System.out.println(" ");
                    } catch (DateTimeParseException e) {
                        System.out.println(e.getMessage() + "\nFecha en formato incorrecto\nIntentelo nuevamente");
                    }
                    break;
                case "7":
                    // Generar un archivo y consola la informacion basica de cada una de las cuentas
                    // del banco
                    try {
                        banc = ManejadorDeArchivos.generarInforme(banc, "informeGeneral.txt");
                        System.out.println(banc.ImprimirInforme());
                    } catch (Banco_Exception e) {
                        System.out.println(e.getDetalle());
                    }
                    break;
                case "8":
                    // Serializar
                    System.out.println(ManejadorDeArchivos.salvarArchivo("JaviBank.dat", banc));
                    break;
                case "9":
                    // Deserializar
                    ManejadorDeArchivos Ma = new ManejadorDeArchivos();
                    banc = Ma.cargarDeArchivo("JaviBank.dat");
                    if(banc != null)
                    {
                        System.out.println("Deserializacion realizada correctamente");
                        System.out.println(banc);
                    }
                    break;
                case "10":
                    System.out.println(" ");
                    System.out.println("Usted va a salir del Programa");
                    System.out.println(" ");
                    System.exit(1);
                    break;
                default:
                    System.out.println(" ");
                    System.out.println("Opcion no valida");
                    break;
            }
        } while (opcion != "10");
        s.close();
    }
}