#include <iostream>
#include <string>
using namespace std;

int opcion;
int contador;

struct alumno {
	string nombre;
	string apellidos;
	char correoelec;
	char telefono[12];
	char matricula[7];
	string callenum;
	char colonia;
	float calif1;
	float calif2;
	float calif3;
	};

alumno datos[100];

void menu();
void AltaDeAlumnos();
void AltaDeCalificaciones();
void ListaCompleta();
void BuscarMatricula();
void EdicionDeAlumnos();
void BorrarAlumnos();
void ArchivoDeTexto();
void ManualDeUsuario();
void ListaDeCalificaciones();
void Salir();

void main() {

	locale::global(locale("spanish"));

	c = 0;

	menu();

	system("pause");
}

void menu() {

	system("cls");

	cout << "LISTA DE ALUMNOS" << endl << endl;
	cout << "Men�" << endl << endl;
	cout << "1. Alta de alumnos \n2. Alta de calificaciones \n3. Lista completa \n4. Buscar Matr�cula \n5. Edici�n de alumnos \n6. Borrar alumnos";
	cout << "\n7. Archivo de texto \n8. Manual de usuario \n9. Lista de alumnos y calificaciones";
	cout << "\n10. Salir" << endl << endl;

	cin >> opcion;

	switch (opcion) {

	case 1:
		AltaDeAlumnos();
		break;

	case 2:
		AltaDeCalificaciones();
		break;

	case 3:
		ListaCompleta();
		break;

	case 4:
		BuscarMatricula();
		break;

	case 5:
		EdicionDeAlumnos();
		break;

	case 6:
		BorrarAlumnos();
		break;

	case 7:
		ArchivoDeTexto();
		break;

	case 8:
		ManualDeUsuario();
		break;

	case 9:
		ListaDeCalificaciones();
		break;

	case 10:
		Salir();
		break;

	default:
		cout << "Elige una opci�n v�lida." << endl;
		menu();
		break;
	}
}

void AltaDeAlumnos() {

	system("cls");

	cout << "ALTA DE ALUMNOS" << endl << endl;

	cout << "�Desea registrar un alumno?" << endl << endl << "1. Si \n2. Cancelar" << endl << endl;
	cin >> opcion;

	if (opcion == 1) {

		system("cls");

		cout << "ALTA DE ALUMNOS" << endl << endl;

		cout << "Ingrese los datos correspondientes del alumno" << endl << endl;

		cout << "Nombre(s): ";
		getline(cin, datos[c].nombre);
		cin >> ignore();

		cout << "\nApellidos: ";
		getline (cin, datos[c].apellidos);
		cin >> ignore();

		cout << "\nCorreo electronico: ";
		cin >> datos[c].correoelec;

		cout << "\nTel�fono de contacto: ";
		cin >> datos[c].telefono;

		cout << "\nMatr�cula: ";
		cin >> datos[c].matricula;

		datos[c].calif1 = -1;

		datos[c].calif2 = -1;
		
		datos[c].calif3 = -1;

		cout << "\nDirecci�n: ";

		cout << "\nCalle y n�mero: ";
		getline (cin, datos[c].callenum);
		cin >> ignore();

		cout << "\nColonia: ";
		cin >> datos[c].colonia;

		c++;

		system("cls");

		cout << "Los datos han sido registrados exitosamente." << endl << endl;

		cout << "�Quiere registrar otro alumno?" << endl << endl;
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

	cout << "�Desea registrar la calificaci�n de un alumno?" << endl << endl;
	cout << "1. Si \n2. Cancelar" << endl << endl;
	cin >> opcion;

	if (opcion == 1) {

		system("cls");

		cout << "�Qu� calificacion desea registrar?" << endl << endl;
		cout << "1. Calificaci�n 1 \n2. Calificaci�n 2 \n3. Calificaci�n 3" << endl << endl;
		cin >> opcion;

		switch (opcion) {

		case 1:
			if (datos[c].calif1 == -1) {
				cout << "Calificaci�n 1: " << endl;
				cin >> datos[c].calif1;
			}
			else {
				cout << "Esta calificaci�n ya fue registrada. Si desea modificarla acceda a la secci�n de Edicion de Alumnos." << endl;
			}
			break;

		case 2:
			if (datos[c].calif2 == -1) {
				cout << "Calificaci�n 2: " << endl;
				cin >> datos[c].calif2;
			}
			else {
				cout << "Esta calificaci�n ya fue registrada. Si desea modificarla acceda a la secci�n de Edicion de Alumnos." << endl;
			}
			break;

		case 3:
			if (datos[c].calif3 == -1) {
				cout << "Calificaci�n 3: " << endl;
				cin >> datos[c].calif3;
			}
			else {
				cout << "Esta calificaci�n ya fue registrada. Si desea modificarla acceda a la secci�n de Edicion de Alumnos." << endl;
			}
			break;
		}
	}

	system("pause > nul");

	menu();
}

void ListaCompleta() {

	system("cls");

	cout << "LISTA COMPLETA" << endl << endl;
	if (c > 0) {
		for (int i = 0; i < c; i++) {
			cout << "Alumno: " << datos[i].nombre << " " << datos[i].apellidos << endl;
			cout << "Correo electr�nico: " << datos[c].correoelec << endl;
			cout << "Tel�fono: " << datos[i].telefono << endl;
			cout << "Matr�cula" << datos[i].matricula << endl;
			cout << "Calificaciones" << endl << "Calificaci�n 1: " << datos[i].calif1 << endl;
			cout << "Calificaci�n 2: " << datos[i].calif2 << endl << "Calificaci�n 3: " << datos[i].calif3 << endl;
			cout << "Direcci�n: " << datos[i].callenum << " " << datos[i].colonia << endl;
		}
	}
	else {
		cout << "Aun no hay alumnos registrados" << endl;
	}

	system("pause > nul");

	menu();
}

void BuscarMatricula() {

	system("cls");

	cout << "BUSCAR MATRICULA" << endl << endl;

	cout << "�Qu� matr�cula buscas? " << endl;
	char mat;
	cin >> mat;

	bool encontrado = false;
	
	int i = 0;
	while (i < c) {
		if (mat == datos[i].matricula) { 
			system("cls");
			cout << "Se encontr� la siguiente informaci�n." << endl << endl;
			cout << "Altura" << p[i].id << ": " << p[i].altura << endl;
			encontrado = true;
			break;
		}
		i++;
	}

	if (!encontrado) {
		cout << "No hay alumno registrado con esa matr�cula."
	}

	system("pause > nul");

	menu();
}
}

void EdicionDeAlumnos() {

	system("cls");

	cout << "EDICI�N DE ALUMNOS" << endl << endl;
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

	cout << "Estas a punto de salir del programa." << endl << endl << "�Seguro que quieres salir?" << endl << endl;
	cout << "1. Si \n2. Cancelar" << endl << endl;
	cin >> opcion;

	if (opcion == 2) {

		menu();
	}
	else {
		system("cls");
	}
}