#include <iostream>
#include <string>
#include <cstdio>
#include <cstdlib>
#include <fstream>
#include <math.h>
#include <sstream>
using namespace std;

int opcion;
int c = 0;

float califaux1;
float califaux2;
float califaux3;

struct alumno {
	string nombre;
	string apellidos;
	string correoelec;
	string telefono;
	string matricula;
	string callenum;
	string colonia;
	float calif1;
	float calif2;
	float calif3;
	float prom;
};

alumno datos[100];

void menu();
void AltaDeAlumnos();
void AltaDeCalificaciones();
void ListaCompleta();
void BuscarAlumno();
void EdicionDeAlumnos();
void BorrarAlumnos();
void ManualDeUsuario();
void Salir();

void main() {

	locale::global(locale("spanish"));

	ifstream archivodatos;

	archivodatos.open("Base de Datos.txt", ios::binary);

	if (archivodatos.fail()) {
		cout << "Error al abrir el archivo. \nPuede que el archivo no exista o se produjo un problema al intentar abrirlo" << endl << endl;
		system("pause > nul");
	}
	else {
		while (!archivodatos.eof()) {
			archivodatos.read((char*)&datos, sizeof(datos));
		}
	}

	archivodatos.close();

	

	menu();
}

void menu() {

	system("cls");

	cout << "LISTA DE ALUMNOS" << endl << endl;
	cout << "Menú" << endl << endl;
	cout << "1. Alta de alumnos \n2. Alta de calificaciones \n3. Lista completa \n4. Buscar Alumno \n5. Edición de alumnos";
	cout << "\n6. Borrar alumnos \n7. Manual de usuario \n8. Salir" << endl << endl;

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
		BuscarAlumno();
		break;

	case 5:
		EdicionDeAlumnos();
		break;

	case 6:
		BorrarAlumnos();
		break;

	case 7:
		ManualDeUsuario();
		break;

	case 8:
		Salir();
		break;

	default:
		cout << "Error. Elija una opción válida." << endl;
		menu();
		break;
	}
}

void AltaDeAlumnos() {

	system("cls");

	cout << "ALTA DE ALUMNOS" << endl << endl;

	cout << "¿Desea registrar un alumno?" << endl << endl << "1. Registrar \n2. Cancelar" << endl << endl;
	cin >> opcion;

	if (opcion == 1) {

		system("cls");

		cout << "ALTA DE ALUMNOS" << endl << endl;

		cout << "Ingrese los datos correspondientes del alumno" << endl << endl;

		cin.ignore();

		bool validar4 = false;
		while (validar4 == false) {
			cout << "Nombre(s): ";
			getline(cin, datos[c].nombre);

			string temp = datos[c].nombre;

			int tamano4 = temp.size();

			for (int i = 0; i < tamano4; i++) {
				if (temp[i] >= 65 && temp[i] <= 90 || temp[i] >= 97 && temp[i] <= 122) {
					validar4 = true;
				}
				else if (temp[i] == 32) {
					validar4 = true;
				}
				else {
					validar4 = false;
				}
			}

			if (validar4 == true) {
				break;
			}
			else {
				system("cls");

				cout << "ALTA DE ALUMNOS" << endl << endl;

				cout << "El nombre ingresado contiene elementos que no son letras del alfabeto." << endl << endl;
				cout << "Presione Enter y vuelva a registrar el nombre correctamente." << endl << endl;

				system("pause > nul");
			}
		}

		bool validar5 = false;
		while (validar5 == false) {
			cout << "\nApellidos: ";
			getline(cin, datos[c].apellidos);

			string temp = datos[c].apellidos;

			int tamano5 = temp.size();

			for (int i = 0; i < tamano5; i++) {
				if (temp[i] >= 65 && temp[i] <= 90 || temp[i] >= 97 && temp[i] <= 122) {
					validar5 = true;
				}
				else if (temp[i] == 32) {
					validar5 = true;
				}
				else {
					validar5 = false;
				}
			}

			if (validar5 == true) {
				break;
			}
			else {
				system("cls");

				cout << "ALTA DE ALUMNOS" << endl << endl;

				cout << "Los apellidos ingresados contienen elementos que no son letras del alfabeto." << endl << endl;
				cout << "Presione Enter y vuelva a registrar los apellidos correctamente." << endl << endl;

				system("pause > nul");
			}
		}

		bool validar2 = false;
		while (validar2 == false) {
			cout << "\nCorreo electronico: ";
			getline(cin, datos[c].correoelec);

			string temp = datos[c].correoelec;

			int tamano2 = temp.size();

			int cont = 0;

			for (int i = 0; i < tamano2; i++) {

				if (temp[i] == 64) {
					cont = cont + 1;

					if (cont > 1) {
						validar2 = false;
						break;
					}
					else {
						validar2 = true;
					}
				}
			}

			if (temp[tamano2 - 4] == 46) {
				if (temp[tamano2 - 3] == 99) {
					if (temp[tamano2 - 2] == 111) {
						if (temp[tamano2 - 1] == 109) {
							validar2 = true;
						}
						else {
							validar2 = false;
						}
					}
					else {
						validar2 = false;
					}
				}
				else {
					validar2 = false;
				}
			}
			else {
				validar2 = false;
			}

			if (validar2 == true) {
				break;
			}
			else {
				system("cls");

				cout << "ALTA DE ALUMNOS" << endl << endl;

				cout << "El correo electrónico ingresado no contiene @, contiene más de un @ o no tiene la finalización .com." << endl << endl;
				cout << "Presione Enter y vuelva a registrar el correo electrónico correctamente." << endl << endl;

				system("pause > nul");
			}
		}
				
		bool validar1 = false;
		while (validar1 == false) {
			cout << "\nTeléfono de contacto: ";
			getline(cin, datos[c].telefono);

			string temp = datos[c].telefono;
			
			int tamano1 = temp.size();

			if (tamano1 >= 8 && tamano1 < 12) {

				for (int i = 0; i < tamano1; i++) {
					if (temp[i] >= 48 && temp[i] <= 57) {
						validar1 = true;
					}
					else {
						validar1 = false;
						break;
					}
				}
			}
			else {
				validar1 = false;
			}

			if (validar1 == true) {
				break;
			}
			else {
				system("cls");

				cout << "ALTA DE ALUMNOS" << endl << endl;

				cout << "El teléfono ingresado contiene una cantidad de elementos fuera del rango permitido ";
				cout << "o uno o varios de estos elementos no son números." << endl << endl;
				cout << "Presione Enter y vuelva a registrar el teléfono correctamente." << endl << endl;

				system("pause > nul");
			}
		}

		cout << "\n¿Quiere permitir que el programa autogenere una matrícula?" << endl;
		cout << "1.Autogenerar \n2.Denegar" << endl << endl;
		cin >> opcion;

		if (opcion == 1) {

			for (int i = 0; i < 7; i++) {
				if (i == 0 || i == 6) {
					datos[c].matricula[i] = 49;
				}
				else if (i == 1) {
					datos[c].matricula[i] = 54;
				}
				else {
					datos[c].matricula[i] = 48;
				}
			}

			for (int i = 0; i < c; i++) {
				while (strcmp(datos[c].matricula.c_str(), datos[i].matricula.c_str()) == 0) {

					if (datos[c].matricula[6] < 57) {
						datos[c].matricula[6] = datos[c].matricula[6] + 1;
					}
					else if (datos[c].matricula[5] < 57) {
						datos[c].matricula[6] = 48;
						datos[c].matricula[5] = datos[c].matricula[5] + 1;
					}
					else {
						datos[c].matricula[6] = 48;
						datos[c].matricula[5] = 48;
						datos[c].matricula[4] = 49;
					}
				}
			}
			cin.ignore();
		}
		else if (opcion == 2) {

			cin.ignore();

			bool validar3 = false;
			while (validar3 == false) {
				cout << "\nMatrícula: ";
				getline(cin, datos[c].matricula);

				string temp = datos[c].matricula;

				int tamano3 = temp.size();

				int cont = 0;
				for (int i = 0; i < tamano3; i++) {
					cont = cont + 1;
				}
				if (cont == 7) {
					validar3 = true;
				}
				else {
					validar3 = false;
				}

				if (validar3 == true) {
					break;
				}
				else {
					system("cls");

					cout << "ALTA DE ALUMNOS" << endl << endl;

					cout << "La matrícula ingresada debe contener 7 elementos." << endl << endl;
					cout << "Presione Enter y vuelva a registrar la matrícula correctamente." << endl << endl;

					system("pause > nul");
				}
			}
		}
		else {
			system("cls");

			cout << "ALTA DE ALUMNOS" << endl << endl;

			cout << "Error. Presione Enter e ingrese una opcion válida." << endl << endl;

			system("pause > nul");

			AltaDeAlumnos();
		}

		cout << "\nDirección: \nCalle y número: ";
		getline(cin, datos[c].callenum);

		cout << "\nColonia: ";
		getline(cin, datos[c].colonia);

		datos[c].calif1 = -1;

		datos[c].calif2 = -1;

		datos[c].calif3 = -1;

		c++;

		system("cls");

		cout << "ALTA DE ALUMNOS" << endl << endl;

		cout << "Los datos han sido registrados exitosamente." << endl << endl;

		cout << "¿Quiere registrar otro alumno?" << endl << endl;
		cout << "1. Registrar \n2. Salir" << endl;
		cin >> opcion;

		if (opcion == 1) {
			AltaDeAlumnos();
		}
		else if (opcion == 2) {
			menu();
		}
		else {
			cout << "Error. Elija una opción válida." << endl;

		system("pause > nul");
		}
	}
	else if (opcion == 2) {
	menu();
			}
	else {
	cout << "Error. Elija una opción válida." << endl;

	system("pause > nul");

	menu();
	}
}

void AltaDeCalificaciones() {

	system("cls");

	cout << "ALTA DE CALIFICACIONES" << endl << endl;

	cout << "¿Desea registrar la calificación de un alumno?" << endl << endl;
	cout << "1. Registrar \n2. Cancelar" << endl << endl;
	cin >> opcion;

	if (opcion == 1) {

		system("cls");

		cout << "ALTA DE CALIFICACIONES" << endl << endl;

		cin.ignore();
		cout << "¿Qué matrícula buscas? " << endl;
		string mat;
		getline(cin, mat);

		bool encontrado = false;

		int i = 0;
		while (i < c) {
			if (strcmp(mat.c_str(), datos[i].matricula.c_str()) == 0) {

				system("cls");

				cout << "ALTA DE CALIFICACIONES" << endl << endl;

				encontrado = true;
				cout << "Se encontró el siguiente alumno." << endl << endl;
				cout << "Alumno: " << datos[i].nombre << " " << datos[i].apellidos << endl;

				cout << "¿Qué calificación desea registrar?" << endl << endl;
				cout << "1. Calificación 1 \n2. Calificación 2 \n3. Calificación 3 \n4. Obtener promedio \n5. Cancelar" << endl << endl;
				cin >> opcion;

				if (opcion == 1) {

					bool validar = false;
					if (datos[i].calif1 == -1) {
						
						while (validar == false) {
							cout << "Calificación 1: " << endl;
							cin >> datos[i].calif1;

							if (datos[i].calif1 >= 0.00 && datos[i].calif1 <= 100.00) {

								float calaux1 = (datos[i].calif1);
								float calaux11 = calaux1 * 100;
								int calaux2 = calaux11;
								float calaux3 = calaux11 - calaux2;

								if (calaux3 == 0) {
									validar = true;
								}
								else {
									validar = false;
								}
							}

							if (validar == true) {
								break;
							}
							else {
								system("cls");

								cout << "ALTA DE CALIFICACIONES" << endl << endl;

								cout << "Error. El número ingresado contiene más de dos decimales o esta fuera del rango permitido." << endl << endl;
								cout << "Presione Enter y vuelva a registrar la calificación correctamente." << endl << endl;

								system("pause > nul");
							}
						}

						califaux1 = datos[i].calif1 * 0.3;
					}
					else {
							cout << "Esta calificación ya fue registrada. Si desea modificarla acceda a la sección de Edicion de Alumnos." << endl;
							
							system("pause > nul");
					}
				}
					
				else if (opcion == 2) {

					bool validar = false;
					if (datos[i].calif2 == -1) {
						
						while (validar == false) {
							cout << "Calificación 2: " << endl;
							cin >> datos[i].calif2;

							if (datos[i].calif2 >= 0.00 && datos[i].calif2 <= 100.00) {

								float calaux1 = (datos[i].calif2);
								float calaux11 = calaux1 * 100;
								int calaux2 = calaux11;
								float calaux3 = calaux11 - calaux2;

								if (calaux3 == 0) {
									validar = true;
								}
								else {
									validar = false;
								}
							}

							if (validar == true) {
								break;
							}
							else {
								system("cls");

								cout << "ALTA DE CALIFICACIONES" << endl << endl;

								cout << "Error. El número ingresado contiene más de dos decimales o esta fuera del rango permitido." << endl << endl;
								cout << "Presione Enter y vuelva a registrar la calificación correctamente." << endl << endl;

								system("pause > nul");
							}
						}

						califaux2 = datos[i].calif2 * 0.45;
					}
					else {
						cout << "Esta calificación ya fue registrada. Si desea modificarla acceda a la sección de Edicion de Alumnos." << endl;
						
						system("pause > nul");
					}
				}

				else if (opcion == 3) {

					bool validar = false;
					if (datos[i].calif3 == -1) {
						
						while (validar == false) {	
							cout << "Calificación 3: " << endl;
							cin >> datos[i].calif3;

							if (datos[i].calif3 >= 0.00 && datos[i].calif3 <= 100.00) {

								float calaux1 = (datos[i].calif3);
								float calaux11 = calaux1 * 100;
								int calaux2 = calaux11;
								float calaux3 = calaux11 - calaux2;

								if (calaux3 == 0) {
									validar = true;
								}
								else {
									validar = false;
								}
							}

							if (validar == true) {
								break;
							}
							else {
								system("cls");

								cout << "ALTA DE CALIFICACIONES" << endl << endl;

								cout << "Error. El número ingresado contiene más de dos decimales o esta fuera del rango permitido." << endl << endl;
								cout << "Presione Enter y vuelva a registrar la calificación correctamente." << endl << endl;

								system("pause > nul");
							}
						}

						califaux3 = datos[i].calif3 * 0.25;
					}
					else {
						cout << "Esta calificación ya fue registrada. Si desea modificarla acceda a la sección de Edicion de Alumnos." << endl;
						
						system("pause > nul");
					}
				}

				else if (opcion == 4) {

					if (datos[i].calif1 == -1 || datos[i].calif2 == -1 || datos[i].calif3 == -1) {
						datos[i].prom = 0;
					}
					else {
						datos[i].prom = floor(califaux1 + califaux2 + califaux3);
						cout << "Promedio: " << datos[i].prom << endl << endl;
					}

					system("pause > nul");
				}

				else if (opcion == 5) {
					menu();
				}

				else {
					cout << "Error. Elija una opción válida." << endl;

					system("pause > nul");

					AltaDeCalificaciones();
				}
			}
			else {
				cout << "No hay alumnos registrados con esta matrícula" << endl << endl;
				cout << "Presione Enter y vuelva a ingresar desde el menú." << endl << endl;
				i++;
				system("pause > nul");

				menu();
			}
		}

		if (encontrado == false) {
			cout << "No hay alumno registrado con la matrícula ingresada." << endl;

			system("pause > nul");

			menu();
		}
	}
	else if(opcion == 2) {
		menu();
	}
	else {
		cout << "Error. Elija una opción válida." << endl;
	}
}

void ListaCompleta() {

	system("cls");

	cout << "LISTA COMPLETA" << endl << endl;
	if (c > 0) {
		for (int i = 0; i < c; i++) {

			cout << "Alumno: " << datos[i].nombre << " " << datos[i].apellidos << endl;
			cout << "Correo electrónico: " << datos[i].correoelec << endl;
			cout << "Teléfono: " << datos[i].telefono << endl;
			cout << "Matrícula: " << datos[i].matricula << endl;
			cout << "Dirección: " << datos[i].callenum << " " << datos[i].colonia << endl;
			cout << "Calificaciones" << endl << "Calificación 1: " << datos[i].calif1 << endl;
			cout << "Calificación 2: " << datos[i].calif2 << endl << "Calificación 3: " << datos[i].calif3 << endl;
			cout << "Promedio: " << datos[i].prom << endl << endl;
		}
	}
	else {
		cout << "Aun no hay alumnos registrados" << endl;
	}

	system("pause > nul");

	menu();
}

void BuscarAlumno() {

	system("cls");

	cout << "BUSCAR ALUMNO" << endl << endl;
	
	cin.ignore();

	cout << "¿Qué matrícula buscas? " << endl;
	string mat;
	getline(cin, mat);

	
	bool encontrado = false;

	int i = 0;
	while (i < c) {
		if (strcmp(mat.c_str(), datos[i].matricula.c_str()) == 0) {
			system("cls");
			cout << "Se encontró la siguiente información: " << endl << endl;
			cout << "Alumno: " << datos[i].nombre << " " << datos[i].apellidos << endl;
			cout << "Correo electrónico: " << datos[c].correoelec << endl;
			cout << "Teléfono: " << datos[i].telefono << endl;
			cout << "Matrícula" << datos[i].matricula << endl;
			cout << "Dirección: " << datos[i].callenum << " " << datos[i].colonia << endl;
			cout << "Calificaciones" << endl << "Calificación 1: " << datos[i].calif1 << endl;
			cout << "Calificación 2: " << datos[i].calif2 << endl << "Calificación 3: " << datos[i].calif3 << endl;
			cout << "Promedio: " << datos[i].prom << endl << endl;

			system("pause > nul");

			encontrado = true;
			break;
		}
		else {
			i++;
		}
	}

	if (encontrado == false) {

		system("cls");

		cout << "BUSCAR ALUMNO" << endl << endl;

		cout << "No hay alumno registrado con la matrícula ingresada." << endl;
		
		system("pause > nul");
	}

	menu();
}

void EdicionDeAlumnos() {

	system("cls");

	cout << "EDICIÓN DE ALUMNOS" << endl << endl;

	cin.ignore();

	cout << "¿Qué matrícula buscas? " << endl;
	string mat;
	getline(cin, mat);

	bool encontrado = false;

	int i = 0;
	while (i < c) {
		if (strcmp(mat.c_str(), datos[i].matricula.c_str()) == 0) {

			system("cls");

			cout << "EDICIÓN DE ALUMNOS" << endl << endl;

			cout << "Se encontró la siguiente información." << endl << endl;
			cout << "Alumno: " << datos[i].nombre << " " << datos[i].apellidos << endl;
			cout << "Correo electrónico: " << datos[i].correoelec << endl;
			cout << "Teléfono: " << datos[i].telefono << endl;
			cout << "Matrícula" << datos[i].matricula << endl;
			cout << "Dirección: " << datos[i].callenum << " " << datos[i].colonia << endl;
			cout << "Calificaciones" << endl << "Calificación 1: " << datos[i].calif1 << endl;
			cout << "Calificación 2: " << datos[i].calif2 << endl << "Calificación 3: " << datos[i].calif3 << endl;
			cout << "Promedio: " << datos[i].prom << endl << endl;
			encontrado = true;

			cout << "¿Quiere modificar los datos de este alumno?" << endl << endl;
			cout << "1. Modificar \n2. Cancelar" << endl;
			cin >> opcion;

			if (opcion == 1) {

				system("cls");

				cout << "EDICIÓN DE ALUMNOS" << endl << endl;

				cout << "¿Qué dato quiere modificar?" << endl << endl;
				cout << "1. Nombre \n2. Apellidos \n3. Correo electrónico \n4. Teléfono \n5. Matrícula";
				cout << "\n6. Calle y número \n7. Colonia \n8. Calificación 1 \n9. Calificación 2 \n10. Calificación 3 " << endl << endl;
				cin >> opcion;

				if (opcion == 1) {

					system("cls");

					cout << "EDICIÓN DE ALUMNOS" << endl << endl;

					bool validar4 = false;
					while (validar4 == false) {
						cout << "Nombre(s): ";
						getline(cin, datos[c].nombre);

						string temp = datos[c].nombre;

						int tamano4 = temp.size();

						for (int i = 0; i < tamano4; i++) {
							if (temp[i] >= 65 && temp[i] <= 90 || temp[i] >= 97 && temp[i] <= 122) {
								validar4 = true;
							}
							else if (temp[i] == 32) {
								validar4 = true;
							}
							else {
								validar4 = false;
							}
						}

						if (validar4 == true) {
							break;
						}
						else {
							system("cls");

							cout << "EDICIÓN DE ALUMNOS" << endl << endl;

							cout << "El nombre ingresado contiene elementos que no son letras del alfabeto." << endl << endl;
							cout << "Presione Enter y vuelva a registrar el nombre correctamente." << endl << endl;

							system("pause > nul");
						}
					}
					
				}

				if (opcion == 2) {

					system("cls");

					cout << "EDICIÓN DE ALUMNOS" << endl << endl;

					bool validar5 = false;
					while (validar5 == false) {
						cout << "\nApellidos: ";
						getline(cin, datos[c].apellidos);

						string temp = datos[c].apellidos;

						int tamano5 = temp.size();

						for (int i = 0; i < tamano5; i++) {
							if (temp[i] >= 65 && temp[i] <= 90 || temp[i] >= 97 && temp[i] <= 122) {
								validar5 = true;
							}
							else if (temp[i] == 32) {
								validar5 = true;
							}
							else {
								validar5 = false;
							}
						}

						if (validar5 == true) {
							break;
						}
						else {
							system("cls");

							cout << "EDICIÓN DE ALUMNOS" << endl << endl;

							cout << "Los apellidos ingresados contienen elementos que no son letras del alfabeto." << endl << endl;
							cout << "Presione Enter y vuelva a registrar los apellidos correctamente." << endl << endl;

							system("pause > nul");
						}
					}

				}

				if (opcion == 3) {

					system("cls");

					cout << "EDICIÓN DE ALUMNOS" << endl << endl;

					bool validar2 = false;
					while (validar2 == false) {
						cout << "\nCorreo electronico: ";
						getline(cin, datos[c].correoelec);

						string temp = datos[c].correoelec;

						int tamano2 = temp.size();

						int cont = 0;

						for (int i = 0; i < tamano2; i++) {

							if (temp[i] == 64) {
								cont = cont + 1;

								if (cont > 1) {
									validar2 = false;
									break;
								}
								else {
									validar2 = true;
								}
							}
						}

						if (temp[tamano2 - 4] == 46) {
							if (temp[tamano2 - 3] == 99) {
								if (temp[tamano2 - 2] == 111) {
									if (temp[tamano2 - 1] == 109) {
										validar2 = true;
									}
									else {
										validar2 = false;
									}
								}
								else {
									validar2 = false;
								}
							}
							else {
								validar2 = false;
							}
						}
						else {
							validar2 = false;
						}

						if (validar2 == true) {
							break;
						}
						else {
							system("cls");

							cout << "EDICIÓN DE ALUMNOS" << endl << endl;

							cout << "El correo electrónico ingresado no contiene @, contiene más de un @ o no tiene la finalización .com." << endl << endl;
							cout << "Presione Enter y vuelva a registrar el correo electrónico correctamente." << endl << endl;

							system("pause > nul");
						}
					}

				}

				if (opcion == 4) {

					system("cls");

					cout << "EDICIÓN DE ALUMNOS" << endl << endl;

					bool validar1 = false;
					while (validar1 == false) {
						cout << "\nTeléfono de contacto: ";
						getline(cin, datos[c].telefono);

						string temp = datos[c].telefono;

						int tamano1 = temp.size();

						if (tamano1 >= 8 && tamano1 < 12) {

							for (int i = 0; i < tamano1; i++) {
								if (temp[i] != 32) {
									if (temp[i] >= 48 && temp[i] <= 57) {
										validar1 = true;
									}
									else {
										validar1 = false;
										break;
									}
								}
								else {
									validar1 = false;
								}
							}
						}
						else {
							validar1 = false;
						}

						if (validar1 == true) {
							break;
						}
						else {
							system("cls");

							cout << "EDICIÓN DE ALUMNOS" << endl << endl;

							cout << "El teléfono ingresado contiene una cantidad de elementos fuera del rango permitido ";
							cout << "o uno o varios de estos elementos no son números." << endl << endl;
							cout << "Presione Enter y vuelva a registrar el teléfono correctamente." << endl << endl;

							system("pause > nul");
						}
					}

				}

				if (opcion == 5) {

					system("cls");

					cout << "EDICIÓN DE ALUMNOS" << endl << endl;

					cout << "\n¿Quiere permitir que el programa autogenere una matrícula?" << endl;
					cout << "1.Autogenerar \n2.Denegar" << endl << endl;
					cin >> opcion;

					if (opcion == 1) {
						datos[c].matricula = 0000001;
						for (int i = 0; i < c; i++) {
							if (strcmp(datos[c].matricula.c_str(), datos[i].matricula.c_str()) == 0) {
								datos[c].matricula = stoi(datos[c].matricula) + 1;
							}
							else {
								break;
							}
						}
						cin.ignore();
					}
					else if (opcion == 2) {

						cin.ignore();

						bool validar3 = false;
						while (validar3 == false) {
							cout << "\nMatrícula: ";
							getline(cin, datos[c].matricula);

							string temp = datos[c].matricula;

							int tamano3 = temp.size();

							int cont = 0;
							for (int i = 0; i < tamano3; i++) {
								cont = cont + 1;
							}
							if (cont == 7) {
								validar3 = true;
							}
							else {
								validar3 = false;
							}

							if (validar3 == true) {
								break;
							}
							else {
								system("cls");

								cout << "EDICIÓN DE ALUMNOS" << endl << endl;

								cout << "La matrícula ingresada debe contener 7 elementos." << endl << endl;
								cout << "Presione Enter y vuelva a registrar la matrícula correctamente." << endl << endl;

								system("pause > nul");
							}
						}
					}
					else {
						system("cls");

						cout << "EDICIÓN DE ALUMNOS" << endl << endl;

						cout << "Error. Presione Enter e ingrese una opcion válida." << endl << endl;

						system("pause > nul");

						AltaDeAlumnos();
					}

				}

				if (opcion == 6) {

					system("cls");

					cout << "EDICIÓN DE ALUMNOS" << endl << endl;

					cout << "\nDirección: \nCalle y número: ";
					getline(cin, datos[c].callenum);

				}

				if (opcion == 7) {

					system("cls");

					cout << "EDICIÓN DE ALUMNOS" << endl << endl;

					cout << "\nColonia: ";
					getline(cin, datos[c].colonia);

				}

				if (opcion == 8) {

					system("cls");

					cout << "EDICIÓN DE ALUMNOS" << endl << endl;

					bool validar = false;
					while (validar == false) {
						cout << "Calificación 1: " << endl;
						cin >> datos[i].calif1;

						if (datos[i].calif1 >= 0.00 && datos[i].calif1 <= 100.00) {

							float calaux1 = (datos[i].calif1);
							float calaux11 = calaux1 * 100;
							int calaux2 = calaux11;
							float calaux3 = calaux11 - calaux2;

							if (calaux3 == 0) {
								validar = true;
							}
							else {
								validar = false;
							}
						}

						if (validar == true) {
							break;
						}
						else {
							system("cls");

							cout << "EDICIÓN DE ALUMNOS" << endl << endl;

							cout << "Error. El número ingresado contiene más de dos decimales o esta fuera del rango permitido." << endl << endl;
							cout << "Presione Enter y vuelva a registrar la calificación correctamente." << endl << endl;

							system("pause > nul");
						}
					}

					califaux1 = datos[i].calif1 * 0.3;

					if (datos[i].calif1 == -1 || datos[i].calif2 == -1 || datos[i].calif3 == -1) {
						datos[i].prom = 0;
					}
					else {
						datos[i].prom = floor(califaux1 + califaux2 + califaux3);
					}
				}

				if (opcion == 9) {

					system("cls");

					cout << "EDICIÓN DE ALUMNOS" << endl << endl;

					bool validar = false;
					while (validar == false) {
						cout << "Calificación 2: " << endl;
						cin >> datos[i].calif2;

						if (datos[i].calif2 >= 0.00 && datos[i].calif2 <= 100.00) {

							float calaux1 = (datos[i].calif2);
							float calaux11 = calaux1 * 100;
							int calaux2 = calaux11;
							float calaux3 = calaux11 - calaux2;

							if (calaux3 == 0) {
								validar = true;
							}
							else {
								validar = false;
							}
						}

						if (validar == true) {
							break;
						}
						else {
							system("cls");

							cout << "EDICIÓN DE ALUMNOS" << endl << endl;

							cout << "Error. El número ingresado contiene más de dos decimales o esta fuera del rango permitido." << endl << endl;
							cout << "Presione Enter y vuelva a registrar la calificación correctamente." << endl << endl;

							system("pause > nul");
						}
					}

					califaux2 = datos[i].calif2 * 0.45;

					if (datos[i].calif1 == -1 || datos[i].calif2 == -1 || datos[i].calif3 == -1) {
						datos[i].prom = 0;
					}
					else {
						datos[i].prom = floor(califaux1 + califaux2 + califaux3);
					}
				}

				if (opcion == 10) {

					system("cls");

					cout << "EDICIÓN DE ALUMNOS" << endl << endl;

					bool validar = false;
					while (validar == false) {
						cout << "Calificación 3: " << endl;
						cin >> datos[i].calif3;

						if (datos[i].calif3 >= 0.00 && datos[i].calif3 <= 100.00) {

							float calaux1 = (datos[i].calif3);
							float calaux11 = calaux1 * 100;
							int calaux2 = calaux11;
							float calaux3 = calaux11 - calaux2;

							if (calaux3 == 0) {
								validar = true;
							}
							else {
								validar = false;
							}
						}

						if (validar == true) {
							break;
						}
						else {
							system("cls");

							cout << "EDICIÓN DE ALUMNOS" << endl << endl;

							cout << "Error. El número ingresado contiene más de dos decimales o esta fuera del rango permitido." << endl << endl;
							cout << "Presione Enter y vuelva a registrar la calificación correctamente." << endl << endl;

							system("pause > nul");
						}
					}

					califaux3 = datos[i].calif3 * 0.25;

					if (datos[i].calif1 == -1 || datos[i].calif2 == -1 || datos[i].calif3 == -1) {
						datos[i].prom = 0;
					}
					else {
						datos[i].prom = floor(califaux1 + califaux2 + califaux3);
					}
				}
			}

			menu();
		}
		i++;
	}

	if (encontrado == false) {

		system("cls");

		cout << "EDICIÓN DE ALUMNOS" << endl << endl;

		cout << "No hay alumno registrado con la matrícula ingresada." << endl;
		
		system("pause > nul");
	}

	menu();
}

void BorrarAlumnos() {

	system("cls");

	cout << "BORRAR ALUMNOS" << endl << endl;

	cin.ignore();

	cout << "¿Qué matrícula buscas? " << endl;
	string mat;
	getline(cin, mat);

	bool encontrado = false;

	int i = 0;
	while (i < c) {
		if (strcmp(mat.c_str(), datos[i].matricula.c_str()) == 0) {
			system("cls");
			cout << "Se encontró la siguiente información." << endl << endl;
			cout << "Alumno: " << datos[i].nombre << " " << datos[i].apellidos << endl;
			cout << "Correo electrónico: " << datos[c].correoelec << endl;
			cout << "Teléfono: " << datos[i].telefono << endl;
			cout << "Matrícula" << datos[i].matricula << endl;
			cout << "Dirección: " << datos[i].callenum << " " << datos[i].colonia << endl;
			cout << "Calificaciones" << endl << "Calificación 1: " << datos[i].calif1 << endl;
			cout << "Calificación 2: " << datos[i].calif2 << endl << "Calificación 3: " << datos[i].calif3 << endl;
			cout << "Promedio: " << datos[i].prom << endl << endl;
			encontrado = true;

			cout << "¿Deseas eliminar a " << datos[i].nombre << "de la lista?" << endl << endl;
			cout << "1. Eliminar \n2. Cancelar" << endl;
			cin >> opcion;

			if (opcion == 1) {
				for (int j = i; j < 100; j++) {
					datos[j] = datos[j + 1];
				}

				c--;
			}
		}
		i++;
	}

	if (encontrado == false) {

		system("cls");

		cout << "BORRAR ALUMNOS" << endl << endl;

		cout << "No hay alumno registrado con la matrícula ingresada." << endl;
		
		system("pause > nul");
	}

	menu();
}

void ManualDeUsuario() {

	system("cls");

	cout << "MANUAL DE USUARIO" << endl << endl;

	system("pause > nul");

	menu();
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

		ofstream archivodatosF;

		archivodatosF.open("Base de Datos.txt", ios::binary);

		archivodatosF.write((char*)&datos, sizeof(datos));

		archivodatosF.close();

		system("cls");
	}
}