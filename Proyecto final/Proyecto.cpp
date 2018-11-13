#include <iostream>
#include <string>
#include <cstdio>
#include <cstdlib>
#include <fstream>
using namespace std;

int opcion;
int c;

ifstream archivodatos;

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

	menu();

	system("pause > nul");
}

void menu() {

	system("cls");

	cout << "LISTA DE ALUMNOS" << endl << endl;
	cout << "Men�" << endl << endl;
	cout << "1. Alta de alumnos \n2. Alta de calificaciones \n3. Lista completa \n4. Buscar Matr�cula \n5. Edici�n de alumnos";
	cout << "\n6. Borrar alumnos \n7. Archivo de texto \n8. Manual de usuario \n9. Lista de alumnos y calificaciones";
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
		cout << "Error. Elija una opci�n v�lida." << endl;
		menu();
		break;
	}
}

void AltaDeAlumnos() {

	system("cls");

	cout << "ALTA DE ALUMNOS" << endl << endl;

	cout << "�Desea registrar un alumno?" << endl << endl << "1. Registrar \n2. Cancelar" << endl << endl;
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

				cout << "El correo electr�nico ingresado no contiene @, contiene m�s de un @ o no tiene la finalizaci�n .com." << endl << endl;
				cout << "Presione Enter y vuelva a registrar el correo electr�nico correctamente." << endl << endl;

				system("pause > nul");
			}
		}
				
		bool validar1 = false;
		while (validar1 == false) {
			cout << "\nTel�fono de contacto: ";
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

				cout << "ALTA DE ALUMNOS" << endl << endl;

				cout << "El tel�fono ingresado contiene una cantidad de elementos fuera del rango permitido ";
				cout << "o uno o varios de estos elementos no son n�meros." << endl << endl;
				cout << "Presione Enter y vuelva a registrar el tel�fono correctamente." << endl << endl;

				system("pause > nul");
			}
		}

		cout << "\n�Quiere permitir que el programa autogenere una matr�cula?" << endl;
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
				cout << "\nMatr�cula: ";
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

					cout << "La matr�cula ingresada debe contener 7 elementos." << endl << endl;
					cout << "Presione Enter y vuelva a registrar la matr�cula correctamente." << endl << endl;

					system("pause > nul");
				}
			}
		}
		else {
			system("cls");

			cout << "ALTA DE ALUMNOS" << endl << endl;

			cout << "Error. Presione Enter e ingrese una opcion v�lida." << endl << endl;

			system("pause > nul");

			AltaDeAlumnos();
		}

		cout << "\nDirecci�n: \nCalle y n�mero: ";
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

		cout << "�Quiere registrar otro alumno?" << endl << endl;
		cout << "1. Registrar \n2. Salir" << endl;
		cin >> opcion;

		if (opcion == 1) {
			AltaDeAlumnos();
		}
		else if (opcion == 2) {
			menu();
		}
		else {
			cout << "Error. Elija una opci�n v�lida." << endl;

		system("pause > nul");
		}
	}
	else if (opcion == 2) {
	menu();
			}
	else {
	cout << "Error. Elija una opci�n v�lida." << endl;

	system("pause > nul");

	menu();
	}
}

void AltaDeCalificaciones() {

	system("cls");

	cout << "ALTA DE CALIFICACIONES" << endl << endl;

	cout << "�Desea registrar la calificaci�n de un alumno?" << endl << endl;
	cout << "1. Registrar \n2. Cancelar" << endl << endl;
	cin >> opcion;

	if (opcion == 1) {

		system("cls");

		cout << "ALTA DE CALIFICACIONES" << endl << endl;

		cin.ignore();
		cout << "�Qu� matr�cula buscas? " << endl;
		string mat;
		getline(cin, mat);

		bool encontrado = false;

		int i = 0;
		while (i < c) {
			if (strcmp(mat.c_str(), datos[i].matricula.c_str()) == 0) {

				system("cls");

				cout << "ALTA DE CALIFICACIONES" << endl << endl;

				cout << "Se encontr� el siguiente alumno." << endl << endl;
				cout << "Alumno: " << datos[i].nombre << " " << datos[i].apellidos << endl;

				cout << "�Qu� calificaci�n desea registrar?" << endl << endl;
				cout << "1. Calificaci�n 1 \n2. Calificaci�n 2 \n3. Calificaci�n 3" << endl << endl;
				cin >> opcion;

				bool validar = false;

				switch (opcion) {

				case 1:
					while (validar = false) {

						if (datos[i].calif1 == -1) {
							cout << "Calificaci�n 1: " << endl;
							cin >> datos[i].calif1;

							string aux = to_string(datos[i].calif1);

							int aux1 = aux.size();

							if (datos[i].calif1 >= 0.0 && datos[i].calif1 <= 100.0) {

								for (int i = 0; i < aux1; i++) {
									if (aux[i] == 46) {
										int cont = 0;
										for (int j = i + 1; j < aux1; j++) {
											cont = cont + 1;
										}

										if (cont > 2) {
											validar = false;
											break;
										}
										else {
											validar = true;
											break;
										}
									}
								}
							}
							else {
								validar = false;
							}

							if (validar == true) {
								break;
							}
							else {
								system("cls");

								cout << "ALTA DE CALIFICACIONES" << endl << endl;

								cout << "Error. El n�mero ingresado contiene m�s de dos decimales o esta fuera del rango permitido." << endl << endl;
								cout << "Presione Enter y vuelva a registrar la calificaci�n correctamente." << endl << endl;

								system("pause > nul");
							}
						}
						else {
							cout << "Esta calificaci�n ya fue registrada. Si desea modificarla acceda a la secci�n de Edicion de Alumnos." << endl;
						}
						break;
					}
					
					
				case 2:
					while (validar = false) {
						if (datos[i].calif2 == -1) {
							cout << "Calificaci�n 2: " << endl;
							cin >> datos[i].calif2;

							string aux = to_string(datos[i].calif2);

							int aux1 = aux.size();
						
							if (datos[i].calif2 >= 0.0 && datos[i].calif2 <= 100.0) {

								for (int i = 0; i < aux1; i++) {
									if (aux[i] == 46) {
										int cont = 0;
										for (int j = i + 1; j < aux1; j++) {
											cont = cont + 1;
										}

										if (cont > 2) {
											validar = false;
											break;
										}
										else {
											validar = true;
											break;
										}
									}
								}
							}
							else {
								validar = false;
							}

							if (validar == true) {
								break;
							}
							else {
								system("cls");

								cout << "ALTA DE CALIFICACIONES" << endl << endl;

								cout << "Error. El n�mero ingresado contiene m�s de dos decimales o esta fuera del rango permitido." << endl << endl;
								cout << "Presione Enter y vuelva a registrar la calificaci�n correctamente." << endl << endl;

								system("pause > nul");
							}
						}
						else {
						cout << "Esta calificaci�n ya fue registrada. Si desea modificarla acceda a la secci�n de Edicion de Alumnos." << endl;
						}
						break;
					}

				case 3:
					while (validar = false) {	
						if (datos[i].calif3 == -1) {
							cout << "Calificaci�n 3: " << endl;
							cin >> datos[i].calif3;

							string aux = to_string(datos[i].calif3);

							int aux1 = aux.size();
						
							if (datos[i].calif3 >= 0.0 && datos[i].calif3 <= 100.0) {

								for (int i = 0; i < aux1; i++) {
									if (aux[i] == 46) {
										int cont = 0;
										for (int j = i + 1; j < aux1; j++) {
											cont = cont + 1;
										}

										if (cont > 2) {
											validar = false;
											break;
										}
										else {
											validar = true;
											break;
										}
									}
								}
							}
							else {
								validar = false;
							}

							if (validar == true) {
								break;
							}
							else {
								system("cls");

								cout << "ALTA DE CALIFICACIONES" << endl << endl;

								cout << "Error. El n�mero ingresado contiene m�s de dos decimales o esta fuera del rango permitido." << endl << endl;
								cout << "Presione Enter y vuelva a registrar la calificaci�n correctamente." << endl << endl;

								system("pause > nul");
							}
						}
						else {
						cout << "Esta calificaci�n ya fue registrada. Si desea modificarla acceda a la secci�n de Edicion de Alumnos." << endl;
						}
						break;
					}
					
				}
			}
			else {
				cout << "No hay alumnos registrados con esta matr�cula" << endl << endl;
				i++;
				system("pause > nul");
			}
		}
	}
	else if(opcion == 2) {
		menu();
	}
	else {
		cout << "Error. Elija una opci�n v�lida." << endl;
	}
}

void ListaCompleta() {

	system("cls");

	archivodatos.open("Base de datos.txt", ios::binary);

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

	cout << "LISTA COMPLETA" << endl << endl;
	if (c > 0) {
		for (int i = 0; i < c; i++) {
			cout << "Alumno: " << datos[i].nombre << " " << datos[i].apellidos << endl;
			cout << "Correo electr�nico: " << datos[i].correoelec << endl;
			cout << "Tel�fono: " << datos[i].telefono << endl;
			cout << "Matr�cula: " << datos[i].matricula << endl;
			cout << "Calificaciones" << endl << "Calificaci�n 1: " << datos[i].calif1 << endl;
			cout << "Calificaci�n 2: " << datos[i].calif2 << endl << "Calificaci�n 3: " << datos[i].calif3 << endl;
			cout << "Direcci�n: " << datos[i].callenum << " " << datos[i].colonia << endl << endl;
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
	string mat;
	getline(cin, mat);

	
	bool encontrado = false;

	int i = 0;
	while (i < c) {
		if (strcmp(mat.c_str(), datos[i].matricula.c_str()) == 0) {
			system("cls");
			cout << "Se encontr� la siguiente informaci�n." << endl << endl;
			cout << "Alumno: " << datos[i].nombre << " " << datos[i].apellidos << endl;
			cout << "Correo electr�nico: " << datos[c].correoelec << endl;
			cout << "Tel�fono: " << datos[i].telefono << endl;
			cout << "Matr�cula" << datos[i].matricula << endl;
			cout << "Calificaciones" << endl << "Calificaci�n 1: " << datos[i].calif1 << endl;
			cout << "Calificaci�n 2: " << datos[i].calif2 << endl << "Calificaci�n 3: " << datos[i].calif3 << endl;
			cout << "Direcci�n: " << datos[i].callenum << " " << datos[i].colonia << endl;
			encontrado = true;
			break;
		}
		else {
			i++;
		}
	}

	if (!encontrado) {
		cout << "No hay alumno registrado con esa matr�cula." << endl;
	}

	system("pause > nul");

	menu();
}

void EdicionDeAlumnos() {

	system("cls");

	cout << "EDICI�N DE ALUMNOS" << endl << endl;

	cout << "�Qu� matr�cula buscas? " << endl;
	string mat;
	getline(cin, mat);

	bool encontrado = false;

	int i = 0;
	while (i < c) {
		if (strcmp(mat.c_str(), datos[i].matricula.c_str()) == 0) {
			system("cls");
			cout << "Se encontr� la siguiente informaci�n." << endl << endl;
			cout << "Alumno: " << datos[i].nombre << " " << datos[i].apellidos << endl;
			cout << "Correo electr�nico: " << datos[i].correoelec << endl;
			cout << "Tel�fono: " << datos[i].telefono << endl;
			cout << "Matr�cula" << datos[i].matricula << endl;
			cout << "Calificaciones" << endl << "Calificaci�n 1: " << datos[i].calif1 << endl;
			cout << "Calificaci�n 2: " << datos[i].calif2 << endl << "Calificaci�n 3: " << datos[i].calif3 << endl;
			cout << "Direcci�n: " << datos[i].callenum << " " << datos[i].colonia << endl;
			encontrado = true;

			cout << "�Quiere modificar los datos de este alumno?" << endl << endl;
			cout << "1. Modificar \n2. Cancelar" << endl;
			cin >> opcion;

			if (opcion == 1) {
				cout << "�Qu� dato quiere modificar?" << endl;
				cout << "1. Nombre \n2. Apellidos \n3. Correo electr�nico \n4. Tel�fono \n5. Matr�cula";
				cout << "\n6. Calificaci�n 1 \n7. Calificaci�n 2 \n8. Calificaci�n 3 \n9. Calle y n�mero \n10. Colonia" << endl << endl;
				cin >> opcion;

				cout << "Ingrese el nuevo dato: ";
				switch (opcion) {
				case 1:
					getline(cin, datos[i].nombre);
					break;

				case 2:
					getline(cin, datos[i].apellidos);
					break;

				case 3:
					cin >> datos[i].correoelec;
					break;

				case 4:
					cin >> datos[i].telefono;
					break;

				case 5:
					cin >> datos[i].matricula;
					break;

				case 6:
					cin >> datos[i].calif1;
					break;

				case 7:
					cin >> datos[i].calif2;
					break;

				case 8:
					cin >> datos[i].calif3;
					break;

				case 9:
					cin >> datos[i].callenum;
					break;

				case 10:
					cin >> datos[i].colonia;
					break;
				}
			}
			break;
		}
		i++;
	}

	if (!encontrado) {
		cout << "No hay alumno registrado con esa matr�cula." << endl;
	}

	system("pause > nul");

	menu();
}

void BorrarAlumnos() {

	system("cls");

	cout << "BORRAR ALUMNOS" << endl << endl;

	cout << "�Qu� matr�cula buscas? " << endl;
	string mat;
	getline(cin, mat);

	bool encontrado = false;

	int i = 0;
	while (i < c) {
		if (strcmp(mat.c_str(), datos[i].matricula.c_str()) == 0) {
			system("cls");
			cout << "Se encontr� la siguiente informaci�n." << endl << endl;
			cout << "Alumno: " << datos[i].nombre << " " << datos[i].apellidos << endl;
			cout << "Correo electr�nico: " << datos[c].correoelec << endl;
			cout << "Tel�fono: " << datos[i].telefono << endl;
			cout << "Matr�cula" << datos[i].matricula << endl;
			cout << "Calificaciones" << endl << "Calificaci�n 1: " << datos[i].calif1 << endl;
			cout << "Calificaci�n 2: " << datos[i].calif2 << endl << "Calificaci�n 3: " << datos[i].calif3 << endl;
			cout << "Direcci�n: " << datos[i].callenum << " " << datos[i].colonia << endl;

			cout << "�Deseas eliminar a " << datos[i].nombre << "de la lista?" << endl << endl;
			cout << "1. Eliminar \n2. Cancelar" << endl;
			cin >> opcion;

			if (opcion == 1) {
				for (int j = i; j < 100; j++) {
					datos[j] = datos[j + 1];
				}
			}
			break;
		}
		encontrado = true;
		break;
		}
		i++;

	if (!encontrado) {
		cout << "No hay alumno registrado con esa matr�cula." << endl;
	}

	system("pause > nul");

	menu();

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

		ofstream archivo;

		archivo.open("Base de datos.txt", ios::binary);

		archivo.write((char*)&archivodatos, sizeof(archivodatos));

		archivo.close();

		system("cls");
		system("pause > nul");
	}
}