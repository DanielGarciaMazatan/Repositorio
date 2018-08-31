#include <iostream>
using namespace std;

int opcion;

void entrada();
void porche();
void jardin();
void recibidor();
void videojuego();
void sala();
void comedor();
void cocina();
void patio();


void main() {
	
	locale::global(locale("spanish"));

	entrada();

	system("pause");
	
}

void entrada() {

	cout << "Hola. Esta es mi casa." << endl;
	cout << "¿Te gustaría entrar a ver?" << endl << "1. Si \n2. No" << endl;
	cin >> opcion;

	if (opcion == 1) {
		
		porche();
	}
	else {
		
		cout << "Hasta luego. Que te vaya bien." << endl;
	}
}

void porche() {

	cout << "Pasa\n¿Quieres ver mi jardin o entramos a la casa? \n1. Jardin \n2. Casa \n3. Ningna de las dos." << endl;
	cin >> opcion;

	if (opcion == 1) {

		jardin();
	}
	else if (opcion == 2) {

		recibidor();
	}
	else {

		cout << "Okey, entonces regresemos." << endl;
		entrada();
	}
}

void jardin() {

	cout << "Bien. Este es mi jardín. \n¿Que quieres hacer? \n1. Regar las plantas \n2. Podar el pasto \n3. Nada" << endl;
	cin >> opcion;

	if (opcion == 1) {

		cout << "Te lo agradezco mucho :)" << endl;
	}
	else if (opcion == 2) {

		cout << "Okay, pero no le voy a pagar joven :v" << endl;
	}
	else {

		cout << "Bueno. Entonces ¿a dónde vamos? \n1. Al porche \n2. Al patio \n3. Ninguno de los dos" << endl;
		cin >> opcion;

		if (opcion == 1) {

			porche();
		}
		else if (opcion == 2) {

			patio();
		}
		else {

			cout << "Pues nos quedamos en el jardin." << endl;
			jardin();
		}
	}
}

void recibidor() {

	cout << "Adelante. \n¿Te gustaría realizar alguna actividad en la televisión? \n1. Si \n2. No" << endl;
	cin >> opcion;

	if (opcion == 1) {

		cout << "Tengo cable, DVD y consolas de videojuegos. \n¿Que te gustaria hacer?" << endl;
		cout << "1. Ver algun programa en el cable. \n2. Ver una pelicula en el DVD. \n3. Jugar videojuegos. \n4. Mejor nada" << endl;
		cin >> opcion;

		if (opcion == 1) {

			cout << "Bien, vamos a verlo." << endl;
		}
		else if (opcion == 2) {

			cout << "Muy bien, elige la que tu quieras, hay una gran variedad." << endl;
		}
		else if (opcion == 3) {

			videojuego();

		}
		else {

			cout << "¿No quieres eso?¿Entonces?" << endl;
			recibidor();
		}
	}
	else {

		cout << "Okey. Por la izquierda se encuentra el baño, enfrente esta la sala y a la derecha esta mi recámara." << endl;
		cout << "¿A dónde quieres ir? \n1. Baño \n2. Sala \n3. Recámara \n4. Ninguna de las tres" << endl;
		cin >> opcion;

		if (opcion == 1) {

			cout << "¡Andale! Correle." << endl;
			recibidor();
		}
		else if (opcion == 2) {

			sala();
		}
		else if (opcion == 3) {

			cout << "No no no, este cuarto es mio y es privado :p" << endl;
			recibidor();
		}
		else {

			cout << "Bueno, volvamos." << endl;
			porche();
		}
	}


}

void videojuego() {

	cout << "¿En qué consola quieres jugar?" << endl;
	cout << "1. PlayStation 4 \n2. Nintendo Switch \n3. Wii U" << endl;
	cin >> opcion;

	switch (opcion) {

	case 1:
		cout << "Perdon, pero es de mi hermano y no me lo presta :(" << endl;
		videojuego();
		break;

	case 2:
		cout << "Ya quisiera tener una :(" << endl;
		videojuego();
		break;

	case 3:
		cout << "¿Qué videojuego te gustaría jugar?" << endl;
		cout << "1. Mario Kart 8 \n2. Super Smash Bros Wii U \n3. Pokken Tournament" << endl;
		cin >> opcion;

		switch (opcion) {

		case 1:
			cout << "A correr se ha dicho." << endl;
			break;

		case 2:
			cout << "A pelear se ha dicho" << endl;
			break;

		case 3:
			cout << "No tengo ese juego, lo siento :(" << endl;
			videojuego();
			break;

		default:
			cout << "¿No quieres jugar? ¿Entonces?" << endl;
			recibidor();
		}
		break;

	default:
		cout << "¿No quieres jugar? ¿Entonces?" << endl;
		recibidor();
	}
}

void sala() {

	cout << "Esta es la sala. ¿Quieres reposar o seguimos el recorrido? \n1. Reposar \n2. Seguir el recorrido \n3. Nada" << endl;
	cin >> opcion;

	if (opcion == 1) {

		cout << "Adelante, descansa un rato." << endl;
	}
	else if (opcion == 2) {

		cout << "Bien, sigamos." << endl;
		comedor();
	}
	else {

		cout << "Bueno, regresemos." << endl;
		recibidor();
	}
}

void comedor() {

	cout << "Este es el comedor, usado generalmente para hacer tarea. \n¿Te gustaría repasar un rato los temas?" << endl;
	cout << "1. Si \n2. No" << endl;
	cin >> opcion;

	if (opcion == 1) {

		cout << "Vamos a estudiar :D" << endl;
	}
	else {

		cout << "Bueno \n¿Seguimos con el recorrido? \n1. Si \n2. No" << endl;
		cin >> opcion;

		if (opcion == 1) {

			cocina();
		}
		else {

			cout << "Okey, entonces volvamos." << endl;
			sala();
		}
	}
}

void cocina() {

	cout << "Ahora estamos en la cocina. \n¿Que quieres hacer? \n1. Cocinar un platillo exquisito. \n2. Nada" << endl;
	cin >> opcion;

	if (opcion == 1) {

		cout << "Excelente, ojala prepares algo delicioso." << endl;
	}
	else {

		cout << "Entonces ¿vamos al último lugar de mi casa? \n1. Si \n2. No" << endl;
		cin >> opcion;

		if (opcion == 1) {

			patio();
		}
		else {

			cout << "Entonces regresemos" << endl;
			comedor();
		}
	}
}

void patio() {

	cout << "Estás en el patio. \n¿Qué deseas hacer? \n1. Barrer las hojas. \n2. Cosechar la fruta. \n3. Nada" << endl;
	cin >> opcion;

	if (opcion == 1) {

		cout << "Gracias, me ahorras el trabajo de fin de semana." << endl;
	}
	else if (opcion == 2) {

		cout << "Genial, te lo compensare con parte de la cosecha." << endl;
	}
	else {

		cout << "¿Estas seguro que no quieres hacer nada? \n1. Si \n2. No" << endl;
		cin >> opcion;

		if (opcion == 1) {

			cout << "Bueno, gracias por acompañarme un rato y haber prestado atencion a los detalles de mi casa." << endl;
		}
		else {

			cout << "¡¿Entonces?! \nVolvamos a empezar." << endl;
			entrada();
		}
	}
}





