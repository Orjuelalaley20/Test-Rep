import java.io.Serializable;
import java.time.LocalDate;
import java.time.LocalDateTime;
import java.time.Month;
import java.time.Period;
import java.time.format.DateTimeFormatter;

/**
 * clase titular en la que almacenan los datos de los titulares
 * 
 * @author Sebastian orjuela
 * @author Isabella blanco
 * @since 27-05-2021
 */

public class Titular implements Serializable {
    private String nombre;
    private LocalDate fechaNac;
    private String telefonof;
    private String telefonoC;
    private String dirr;
    private int years;

    /**
     * constructor vacio
     */

    public Titular() {

    }

    /**
     * constructor que le asigna toda la informacion a los atributos de los
     * titulares.
     * 
     * @param nombre    nombre completo del titular.
     * @param fechaNac  fecha de nacimiento del titular.
     * @param telefonof telefono fijo del titular.
     * @param telefonoC telefono celular del titular.
     * @param dirr      dirreción del titular.
     */

    public Titular(String nombre, LocalDate fechaNac, String telefonof, String telefonoC, String dirr) {

        this.nombre = nombre;
        this.fechaNac = fechaNac;
        this.telefonof = telefonof;
        this.telefonoC = telefonoC;
        this.dirr = dirr;
    }

    /**
     * metodo el cual calcula la edad de los titulares.
     */

    public void calcularedad() {
        String fechan = getFechaNac().toString();
        DateTimeFormatter dtf = DateTimeFormatter.ofPattern("yyyy/MM/dd");
        String fechahoy = dtf.format(LocalDateTime.now());
        String partes[] = fechan.split("-");
        String partes2[] = fechahoy.split("/");
        int dia = Integer.parseInt(partes[2]);
        int mes = Integer.parseInt(partes[1]);
        Month Mes = Month.of(mes);
        int año = Integer.parseInt(partes[0]);
        LocalDate primerafecha = LocalDate.of(año, Mes, dia);
        dia = Integer.parseInt(partes2[2]);
        mes = Integer.parseInt(partes2[1]);
        Mes = Month.of(mes);
        año = Integer.parseInt(partes2[0]);
        LocalDate segundafecha = LocalDate.of(año, Mes, dia);
        Period diferencia = Period.between(primerafecha, segundafecha);
        setYears(diferencia.getYears());
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

    /**
     * @return String
     */
    public LocalDate getFechaNac() {
        return fechaNac;
    }

    /**
     * @param fechaNac
     */
    public void setFechaNac(LocalDate fechaNac) {
        this.fechaNac = fechaNac;
    }

    /**
     * @return String
     */
    public String getTelefonof() {
        return telefonof;
    }

    /**
     * @param telefonof
     */
    public void setTelefonof(String telefonof) {
        this.telefonof = telefonof;
    }

    /**
     * @return String
     */
    public String getTelefonoC() {
        return telefonoC;
    }

    /**
     * @param telefonoC
     */
    public void setTelefonoC(String telefonoC) {
        this.telefonoC = telefonoC;
    }

    /**
     * @return String
     */
    public String getDirr() {
        return dirr;
    }

    /**
     * @param dir
     */
    public void setDirr(String dir) {
        this.dirr = dir;
    }

    /**
     * @return int
     */
    public int getYears() {
        return years;
    }

    /**
     * @param years
     */
    public void setYears(int years) {
        this.years = years;
    }

    // TO STRING-------------

    /**
     * @return String
     */

    @Override
    public String toString() {
        return "Titulares [nombre = " + nombre + ", fecha de nacimiento = " + fechaNac + ", telefono fijo = "
                + telefonof + ", telefono celular = " + telefonoC + ", dirr = " + dirr + "]\n";
    }
}