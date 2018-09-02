#include <iostream>
#include <string>
using namespace std;

int opcion;

string nombre;
string apellidos;
char correoelec;
char telefono[12];
char matricula;
string callenum;
char colonia;
float calif1;
float calif2;
float calif3;

void menu();
void AltaDeAlumnos();
void AltaDeCalificaciones();
void EdicionDeAlumnos();
void BorrarAlumnos();
void ArchivoDeTexto();
void ManualDeUsuario();
void ListaDeCalificaciones();
void Salir();

void main() {

	locale::global(locale("spanish"));
	
	menu();

	system("pause");
}

void menu() {

	system("cls");

	cout << "LISTA DE ALUMNOS" << endl << endl;
	cout << "Bienvenido. Seleccione una opcion del menú." << endl << endl;
	cout << "Menú" << endl << endl;
	cout << "1. Alta de alumnos \n2. Alta de calificaciones \n3. Edición de alumnos \n4. Borrar alumnos";
	cout << "\n5. Archivo de texto \n6. Manual de usuario \n7. Lista de alumnos y calificaciones";
	cout << "\n8. Salir" << endl << endl;

	cin >> opcion;

	switch (opcion) {

	case 1:
		AltaDeAlumnos();
		break;

	case 2:
		AltaDeCalificaciones();
		break;

	case 3:
		EdicionDeAlumnos();
		break;

	case 4:
		BorrarAlumnos();
		break;

	case 5:
		ArchivoDeTexto();
		break;

	case 6:
		ManualDeUsuario();
		break;

	case 7:
		ListaDeCalificaciones();
		break;

	case 8:
		Salir();
		break;

	default:
		cout << "Elige una opción válida." << endl;
		menu();
		break;
	}
}

void AltaDeAlumnos() {

	system("cls");

	cout << "ALTA DE ALUMNOS" << endl << endl;

	cout << "¿Desea registrar un alumno?" << endl << endl << "1. Si \n2. Cancelar" << endl << endl;
	cin >> opcion;

	if (opcion == 1) {

		system("cls");

		cout << "ALTA DE ALUMNOS" << endl << endl;

		cout << "Ingrese los datos correspondientes del alumno" << endl << endl;

		cout << "Nombre(s): " << endl;
		cin >> nombre;

		cout << endl << "Apellidos: " << endl;
		cin >> apellidos;

		cout << "Correo electronico: " << endl;
		cin >> correoelec;

		cout << "Teléfono de contacto: " << endl;
		cin >> telefono;

		cout << "Matrícula: " << endl;
		cin >> matricula;

		cout << "Calificaciones" << endl;
		cout << "Calificación 1: \nCalificación 2: \nCalificación 3: " << endl;

		cout << "Dirección: " << endl;
		cout << "Calle y número: " << endl;
		cin >> callenum;
		cout << endl << "Colonia: " << endl;
		cin >> colonia;

		system("cls");

		cout << "Los datos han sido registrados exitosamente." << endl << endl;

		cout << "¿Quiere registrar otro alumno?" << endl << endl;
		cout << "1. Si \n2. No" << endl;
		cin >> opcion;

		if (opcion == 1) {
			AltaDeAlumnos();
		}
		else {
			menu();
		}
	}
	else {
		menu();
	}
}

void AltaDeCalificaciones() {

	system("cls");

	cout << "ALTA DE CALIFICACIONES" << endl << endl;

	cout << "¿Desea registrar la calificación de un alumno?" << endl << endl;
	cout << "1. Si \n2. Cancelar" << endl << endl;
	cin >> opcion;

	if (opcion == 1) {

		system("cls");

		cout << "Calificación 1: " << endl;
		cin >> calif1;
		cout << "Calificación 2: " << endl;
		cin >> calif2;
		cout << "Calificación 3: " << endl;
		cin >> calif3;
	}
	else {
		menu();
	}
}

void EdicionDeAlumnos() {

	system("cls");

	cout << "EDICIÓN DE ALUMNOS" << endl << endl;
}

void BorrarAlumnos() {

	system("cls");

	cout << "BORRAR ALUMNOS" << endl << endl;
}

void ArchivoDeTexto() {

	system("cls");

	cout << "ARCHIVO DE TEXTO" << endl << endl;
}

void ManualDeUsuario() {

	system("cls");

	cout << "MANUAL DE USUARIO" << endl << endl;
}

void ListaDeCalificaciones() {

	system("cls");

	cout << "LISTA DE ALUMNOS Y CALIFICACIONES" << endl << endl;
}

void Salir() {

	system("cls");

	cout << "SALIR" << endl << endl;

	cout << "Estas a punto de salir del programa." << endl << endl << "¿Seguro que quieres salir?" << endl << endl;
	cout << "1. Si \n2. Cancelar" << endl << endl;
	cin >> opcion;

	if (opcion == 2) {

		menu();
	}
	else {
		system("cls");
	}
}