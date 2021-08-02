import java.io.*;
import java.util.List;

/**
 * clase en la que se hacen modificaciones en el archivo.
 * 
 * @author Sebastian orjuela
 * @author Isabella blanco
 * @since 27-05-2021
 */

public class ManejadorDeArchivos {

    /**
     * Metodo que escribe en un archivo de texto las cuentas nuevas creadas por
     * consola.
     * 
     * @param nomarchivo nombre del archivo, donde se escriben las nuevas cuentas
     * @param Ncuenta    lista de la clase Cuenta que contiene las cuentas nuevas
     * @exception IOException Error de archivo
     * @exception Exception   Ocurrio un problema al cargar el archivo de texto
     */

    public static void escribirNuevasC(String nomarchivo, List<Cuenta> Ncuenta) {
        try {
            OutputStreamWriter out = new OutputStreamWriter(new FileOutputStream(nomarchivo));
            for (Cuenta cu : Ncuenta) {
                if (cu instanceof CuentaAhorros) {
                    out.write("#Cuenta\n");
                    out.write("#Saldo------Tipo---------Tarjeta/Sobregiro\n");
                    out.write(cu.getSaldo() + "-------" + cu.getTipo() + "-------"
                            + ((CuentaAhorros) cu).getTarjetaDebito() + "\n");
                    out.write("#Titulares\n");
                    out.write("#Nombre----------fecha Nacimiento----TelFijo-----Celular---Direccion\n");
                    for (Titular titu : cu.getTitulares()) {
                        out.write(titu.getNombre() + " *" + titu.getFechaNac() + " *" + titu.getTelefonof() + " *"
                                + titu.getTelefonoC() + " *" + titu.getDirr() + "\n");
                    }
                    out.write("0\n");
                }
                if (cu instanceof CuentaCorriente) {
                    out.write("#Cuenta\n");
                    out.write("#Saldo------Tipo---------Tarjeta/Sobregiro\n");
                    out.write(cu.getSaldo() + "-------" + cu.getTipo() + "-------"
                            + ((CuentaCorriente) cu).getSobregiro() + "\n");
                    out.write("#Titulares\n");
                    out.write("#Nombre----------fecha Nacimiento----TelFijo-----Celular---Direccion\n");
                    for (Titular titu : cu.getTitulares()) {
                        out.write(titu.getNombre() + " *" + titu.getFechaNac() + " *" + titu.getTelefonof() + " *"
                                + titu.getTelefonoC() + " *" + titu.getDirr() + "\n");
                    }
                    out.write("0\n");
                }
            }
            out.write("#FIN");
            out.close();

        } catch (FileNotFoundException e) {
            System.out.println("El archivo de texto no se pudo crear " + e);
        } catch (IOException e) { // Manejo de excepciones de archivos
            System.out.println("Error de archivo " + e);
        }
    }

    /**
     * Metodo que lee el nuevo archivo creado con las nuevas cuentas. Divide cadenas
     * de caracteres dado por ("-" y "\\*") la informacion de las cuentas y los
     * titulares.
     * 
     * @param nuevas  nombre del archivo que contiene las nuevas cuentas
     * @param cuentas
     * @exception IOException               Error de archivo
     * @exception Banco_Exception           Ocurrio un problema en el Banco
     * @exception CuentaAhorros_Exception
     * @exception CuentaCorriente_Exception
     * @exception Exception                 Ocurrio un problema al cargar el archivo
     *                                      de texto
     * @return el objeto banco
     */
    public static Banco leerNuevoArch(String nuevas, String cuentas) {
        Banco banc = new Banco("JaviBank");
        try {

            InputStreamReader input = new InputStreamReader(new FileInputStream(nuevas));
            BufferedReader fa = new BufferedReader(input);
            String cad = fa.readLine();
            int consecutivo = 1;
            while (!cad.equalsIgnoreCase("#FIN")) {
                // Se le quita los espacios a la cadena. Se invoca el metodo estatico de
                // AuxiliarCadenas
                cad = fa.readLine();
                cad = fa.readLine();
                cad = ManejadorCadenas.limpiarCaracteres(cad);
                cad = ManejadorCadenas.limpiarCadena(cad);
                String[] tokens = ManejadorCadenas.tokenizador(cad, "-");
                banc.adicionarNuevaCuenta(tokens[0], tokens[1], tokens[2], consecutivo);
                // agregar info cuenta
                fa.readLine(); // "\n"
                fa.readLine(); // "\n"
                cad = fa.readLine();
                while (!cad.equals("0")) {
                    // agregar info de titulares
                    cad = ManejadorCadenas.limpiarCadena(cad);
                    String[] tokenes = ManejadorCadenas.tokenizador(cad, " \\*");
                    banc.AdicionarTitular(consecutivo, tokenes[0], tokenes[1], tokenes[2], tokenes[3], tokenes[4]);
                    cad = fa.readLine();
                }
                consecutivo++;
                cad = fa.readLine();
            }
            fa.close();
            InputStreamReader inputaux = new InputStreamReader(new FileInputStream(cuentas));
            BufferedReader ca = new BufferedReader(inputaux);
            cad = ca.readLine();
            while (!cad.equalsIgnoreCase("#FIN")) {
                // Se le quita los espacios a la cadena. Se invoca el metodo estatico de
                // AuxiliarCadenas
                cad = ca.readLine();
                cad = ca.readLine();
                cad = ManejadorCadenas.limpiarCaracteres(cad);
                String[] tokens = ManejadorCadenas.tokenizador(cad, "-");
                banc.adicionarCuenta(tokens[0], tokens[1], tokens[2], consecutivo);
                // agregar info cuenta
                ca.readLine(); // "\n"
                ca.readLine(); // "\n"
                cad = ca.readLine();
                while (!cad.equals("0")) {
                    // agregar info de titulares
                    String[] tokenes = ManejadorCadenas.tokenizador(cad, " \\*");
                    banc.AdicionarTitular(consecutivo, tokenes[0], tokenes[1], tokenes[2], tokenes[3], tokenes[4]);
                    cad = ca.readLine();
                }
                consecutivo++;
                cad = ca.readLine();
            }
            ca.close();

        } catch (FileNotFoundException e) {
            System.out.println("Ocurrio un problema al cargar el archivo de texto " + e);
        } catch (IOException e) { // Manejo de excepciones de archivos
            System.out.println("Error de archivo " + e);
        } catch (Banco_Exception e) {
            System.out.println("Ocurrio un problema en el Banco " + e);
        } catch (CuentaAhorros_Exception e) {
            System.out.println(e.getLocalizedMessage());
        } catch (CuentaCorriente_Exception e) {
            System.out.println(e.getLocalizedMessage());
        } catch (Exception e) {
            System.out.println(e.getLocalizedMessage() + "Ocurrio un problema al cargar el archivo de texto");
        }
        return banc;
    }

    /**
     * Metodo que lee de un archivo de texto. Divide cadenas de caracteres dado por
     * ("-" y " \\*") la informacion del profesor y los estudiantes.
     * 
     * @param nomarchivo
     * @exception IOException               Error de archivo
     * @exception Banco_Exception           Ocurrio un problema en el Banco
     * @exception CuentaAhorros_Exception
     * @exception CuentaCorriente_Exception
     * @exception Exception                 Ocurrio un problema al cargar el archivo
     *                                      de texto
     * @return banco
     */

    public static Banco leerDeArchivoTexto(String nomarchivo) {
        Banco banc = new Banco("JaviBank");
        try {

            InputStreamReader input = new InputStreamReader(new FileInputStream(nomarchivo));
            BufferedReader fa = new BufferedReader(input);
            String cad = fa.readLine();
            int consecutivo = 1;
            while (!cad.equalsIgnoreCase("#FIN")) {
                // Se le quita los espacios a la cadena. Se invoca el metodo estatico de
                // AuxiliarCadenas
                cad = fa.readLine();
                cad = fa.readLine();
                cad = ManejadorCadenas.limpiarCaracteres(cad);
                String[] tokens = ManejadorCadenas.tokenizador(cad, "-");
                banc.adicionarCuenta(tokens[0], tokens[1], tokens[2], consecutivo);
                // agregar info cuenta
                fa.readLine(); // "\n"
                fa.readLine(); // "\n"
                cad = fa.readLine();
                while (!cad.equals("0")) {
                    // agregar info de titulares
                    String[] tokenes = ManejadorCadenas.tokenizador(cad, " \\*");
                    banc.AdicionarTitular(consecutivo, tokenes[0], tokenes[1], tokenes[2], tokenes[3], tokenes[4]);
                    cad = fa.readLine();
                }
                consecutivo++;
                cad = fa.readLine();
            }
            fa.close();
        } catch (FileNotFoundException e) {
            System.out.println("El archivo de texto no ha sido encontrado" + e);
        } catch (IOException e) {// Manejo de excepciones de archivos
            System.out.println("Error de archivo " + e);
        } catch (Banco_Exception e) {
            System.out.println("Ocurrio un problema en el Banco " + e);
        } catch (CuentaAhorros_Exception e) {
            System.out.println(e.getLocalizedMessage());
        } catch (CuentaCorriente_Exception e) {
            System.out.println(e.getLocalizedMessage());
        }
        return banc;
    }

    /**
     * Metodo que genera un nuevo archivo y por consola toda la informacion basica
     * de cada una de las cuentas.
     * 
     * @param b              objeto que contiene las cuentas del banco con su
     *                       nombre.
     * @param informeGeneral Archivo al cual se le va a escribir el informe general
     *                       del banco.
     * @return b
     */

    public static Banco generarInforme(Banco b, String informeGeneral) throws Banco_Exception {
        try {
            OutputStreamWriter out = new OutputStreamWriter(new FileOutputStream(informeGeneral));
            out.write(b.ImprimirInforme() + "\n");
            out.close();
        } catch (IOException e) { // Manejo de excepciones de archivos
            System.out.println("Error de archivo " + e);
        } catch (Exception e) {
            System.out.println("Ocurrio un error escribiendo el archivo de reporte: " + e);
        }
        return b;
    }

    /**
     * Metodo que salva a un archivo de nombre nomarch un objeto de tipo Banco b.
     * 
     * @param nomarch string que contiene el nombre del archivo al cual se va a
     *                hacer la serializacion.
     * @param b       objeto el cual se va a serializar.
     * @return Un string el cual contiene el aviso de que la serializacion se hizo
     *         correctamente y no se presentaron errores.
     */

    public static String salvarArchivo(String nomarch, Banco b) {
        try {
            FileOutputStream fileOut = new FileOutputStream(nomarch);
            ObjectOutputStream out = new ObjectOutputStream(fileOut);
            out.writeObject(b);
            out.close();
            String completado = "Serializacion realizada correctamente";
            return completado;
        } catch (FileNotFoundException e) {// Manejo de excepciones de archivos
            System.out.println("No se encontro el archivo " + e.getLocalizedMessage());
        } catch (IOException e) {
            System.out.println("El archivo no existe: " + e.getLocalizedMessage());
        }
        return null;
    }

    /**
     * Metodo que cargar de un archivo el cual deserializa un string llamado nomarch
     * donde esta la informacion del objeto
     * 
     * @param nomarch string que contiene el nombre del archivo al cual se va a
     *                hacer la serializacion
     * @return Banc Objeto deserializado.
     */

    public Banco cargarDeArchivo(String nomarch) {
        Banco banc = null;
        try {
            FileInputStream FileIn = new FileInputStream("JaviBank.dat");
            ObjectInputStream In = new ObjectInputStream(FileIn);
            banc = (Banco) In.readObject();
            In.close();
        } catch (FileNotFoundException e) {// Manejo de excepciones de archivos
            System.out.println("No se encontro el archivo " + e.getLocalizedMessage());
        } catch (IOException e) {
            System.out.println("El archivo no existe: " + e.getLocalizedMessage());
        } catch (ClassNotFoundException c) {
            System.out.println("Class not found" + c.getLocalizedMessage());
        }
        return banc;
    }
}