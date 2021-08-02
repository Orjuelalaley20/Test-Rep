/**
 * clase ManejadorCadenas el cual ayuda a editar la cadena de texto del archivo
 * 
 * @author Sebastian orjuela
 * @author Isabella blanco
 * @since 27-05-2021
 */

public class ManejadorCadenas {

	/**
	 * Metodo para limpiar la cadena de espacios.
	 * 
	 * @param cad cadena a la que se le va a eliminar los espacios iniciales y
	 *            adicionales. Ademas solo deja un espacio entre las palabras
	 * @return cad
	 */

	public static String limpiarCadena(String cad) {
		cad = eliminarEspaciosAdicionales(cad);
		cad = cad.trim();
		return cad;
	}

	/**
	 * Metodo para quitarle a la cadena espacios adicionales que tenga.
	 * 
	 * @param cad: cadena a la que se le va a eliminar espacios
	 * @return la cadena con solo un espacio entre las palabras
	 */

	public static String eliminarEspaciosAdicionales(String cad) {
		return cad.replaceAll("\\s+", " ");

	}

	/**
	 * @param cadena cadena la cual hay que partir
	 * @param tok    expresion por la cual se puede partir una cadena
	 * @return un conjunto de subcadenas "partidas por el token dado"
	 */

	public static String[] tokenizador(String cadena, String tok) {
		String[] tokens = cadena.split(tok);
		return tokens;
	}

	/**
	 * Metodo para limpiar caracteres adicionales en la cadena.
	 * 
	 * @param cad cadena la cual hay que limpiar
	 * @return la cadena anterior sin - adicionales.
	 */

	public static String limpiarCaracteres(String cad) {
		return cad.replaceAll("\\-+", "-");
	}
}