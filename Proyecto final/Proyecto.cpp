#include <iostream>
#include <string>
#include <cstdio>
#include <cstdlib>
#include <fstream>
#include <math.h>
using namespace std;

int opcion;
int c = 0;
int matemp = 1;

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

	archivodatos.open("BasedeDatos.txt", ios::binary);

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

	for (int i = 0; i < 100; i++){
		if (datos[i].matricula.size() != 0) {
			c++;
		}
	}

	menu();
}

void menu() {

	system("cls");

	cout << "LISTA DE ALUMNOS" << endl << endl;
	cout << "Men�" << endl << endl;
	cout << "1. Alta de alumnos \n2. Alta de calificaciones \n3. Lista completa \n4. Buscar Alumno \n5. Edici�n de alumnos";
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
					break;
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
					break;
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
		bool validar22 = false;
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

			if (temp[tamano2 - 4] == 46 && temp[tamano2 - 3] == 99 && temp[tamano2 - 2] == 111 && temp[tamano2 - 1] == 109) {
				validar22 = true;
			}
			else {
				validar22 = false;
			}

			if (validar2 == true && validar22 == true) {
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
					if (temp[i] >= 48 && temp[i] <= 57) {
						validar1 = true;
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

			datos[c].matricula = to_string(matemp);

			for (int i = 0; i < c; i++) {
				while (strcmp(datos[c].matricula.c_str(), datos[i].matricula.c_str()) == 0) {

					matemp = matemp + 1;

					datos[c].matricula = to_string(matemp);

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
				if (cont >= 1 && cont <= 7) {
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

					cout << "La matr�cula ingresada debe contener m�ximo 7 elementos." << endl << endl;
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

				encontrado = true;
				cout << "Se encontr� el siguiente alumno." << endl << endl;
				cout << "Alumno: " << datos[i].nombre << " " << datos[i].apellidos << endl;

				cout << "�Qu� calificaci�n desea registrar?" << endl << endl;
				cout << "1. Calificaci�n 1 \n2. Calificaci�n 2 \n3. Calificaci�n 3 \n4. Obtener promedio \n5. Cancelar" << endl << endl;
				cin >> opcion;

				if (opcion == 1) {

					bool validar = false;
					if (datos[i].calif1 == -1) {
						
						while (validar == false) {
							cout << "Calificaci�n 1: " << endl;
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

								cout << "Error. El n�mero ingresado contiene m�s de dos decimales o esta fuera del rango permitido." << endl << endl;
								cout << "Presione Enter y vuelva a registrar la calificaci�n correctamente." << endl << endl;

								system("pause > nul");
							}
						}

						califaux1 = datos[i].calif1 * 0.3;
					}
					else {
							cout << "Esta calificaci�n ya fue registrada. Si desea modificarla acceda a la secci�n de Edicion de Alumnos." << endl;
							
							system("pause > nul");
					}
				}
					
				else if (opcion == 2) {

					bool validar = false;
					if (datos[i].calif2 == -1) {
						
						while (validar == false) {
							cout << "Calificaci�n 2: " << endl;
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

								cout << "Error. El n�mero ingresado contiene m�s de dos decimales o esta fuera del rango permitido." << endl << endl;
								cout << "Presione Enter y vuelva a registrar la calificaci�n correctamente." << endl << endl;

								system("pause > nul");
							}
						}

						califaux2 = datos[i].calif2 * 0.45;
					}
					else {
						cout << "Esta calificaci�n ya fue registrada. Si desea modificarla acceda a la secci�n de Edicion de Alumnos." << endl;
						
						system("pause > nul");
					}
				}

				else if (opcion == 3) {

					bool validar = false;
					if (datos[i].calif3 == -1) {
						
						while (validar == false) {	
							cout << "Calificaci�n 3: " << endl;
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

								cout << "Error. El n�mero ingresado contiene m�s de dos decimales o esta fuera del rango permitido." << endl << endl;
								cout << "Presione Enter y vuelva a registrar la calificaci�n correctamente." << endl << endl;

								system("pause > nul");
							}
						}

						califaux3 = datos[i].calif3 * 0.25;
					}
					else {
						cout << "Esta calificaci�n ya fue registrada. Si desea modificarla acceda a la secci�n de Edicion de Alumnos." << endl;

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
					cout << "Error. Elija una opci�n v�lida." << endl;

					system("pause > nul");

					AltaDeCalificaciones();
				}
			}
			else {
				i++;
			}
		}

		if (encontrado == false) {
			cout << "No hay alumno registrado con la matr�cula ingresada." << endl;

			system("pause > nul");

			menu();
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

	cout << "LISTA COMPLETA" << endl << endl;
	if (c > 0) {
		for (int i = 0; i < c; i++) {

			cout << "Alumno: " << datos[i].nombre << " " << datos[i].apellidos << endl;
			cout << "Correo electr�nico: " << datos[i].correoelec << endl;
			cout << "Tel�fono: " << datos[i].telefono << endl;
			cout << "Matr�cula: " << datos[i].matricula << endl;
			cout << "Direcci�n: " << datos[i].callenum << " " << datos[i].colonia << endl;
			cout << "Calificaciones" << endl << "Calificaci�n 1: " << datos[i].calif1 << endl;
			cout << "Calificaci�n 2: " << datos[i].calif2 << endl << "Calificaci�n 3: " << datos[i].calif3 << endl;
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

	cout << "�Qu� matr�cula buscas? " << endl;
	string mat;
	getline(cin, mat);
	
	bool encontrado = false;

	int i = 0;
	while (i < c) {
		if (strcmp(mat.c_str(), datos[i].matricula.c_str()) == 0) {
			system("cls");
			cout << "Se encontr� la siguiente informaci�n: " << endl << endl;
			cout << "Alumno: " << datos[i].nombre << " " << datos[i].apellidos << endl;
			cout << "Correo electr�nico: " << datos[c].correoelec << endl;
			cout << "Tel�fono: " << datos[i].telefono << endl;
			cout << "Matr�cula: " << datos[i].matricula << endl;
			cout << "Direcci�n: " << datos[i].callenum << " " << datos[i].colonia << endl;
			cout << "Calificaciones" << endl << "Calificaci�n 1: " << datos[i].calif1 << endl;
			cout << "Calificaci�n 2: " << datos[i].calif2 << endl << "Calificaci�n 3: " << datos[i].calif3 << endl;
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

		cout << "No hay alumno registrado con la matr�cula ingresada." << endl;
		
		system("pause > nul");
	}

	menu();
}

void EdicionDeAlumnos() {

	system("cls");

	cout << "EDICI�N DE ALUMNOS" << endl << endl;

	cin.ignore();

	cout << "�Qu� matr�cula buscas? " << endl;
	string mat;
	getline(cin, mat);

	bool encontrado = false;

	int i = 0;
	while (i < c) {
		if (strcmp(mat.c_str(), datos[i].matricula.c_str()) == 0) {

			system("cls");

			cout << "EDICI�N DE ALUMNOS" << endl << endl;

			cout << "Se encontr� la siguiente informaci�n." << endl << endl;
			cout << "Alumno: " << datos[i].nombre << " " << datos[i].apellidos << endl;
			cout << "Correo electr�nico: " << datos[i].correoelec << endl;
			cout << "Tel�fono: " << datos[i].telefono << endl;
			cout << "Matr�cula: " << datos[i].matricula << endl;
			cout << "Direcci�n: " << datos[i].callenum << " " << datos[i].colonia << endl;
			cout << "Calificaciones" << endl << "Calificaci�n 1: " << datos[i].calif1 << endl;
			cout << "Calificaci�n 2: " << datos[i].calif2 << endl << "Calificaci�n 3: " << datos[i].calif3 << endl;
			cout << "Promedio: " << datos[i].prom << endl << endl;
			encontrado = true;

			cout << "�Quiere modificar los datos de este alumno?" << endl << endl;
			cout << "1. Modificar \n2. Cancelar" << endl;
			cin >> opcion;

			if (opcion == 1) {

				cout << "\n�Qu� dato quiere modificar?" << endl << endl;
				cout << "1. Nombre \n2. Apellidos \n3. Correo electr�nico \n4. Tel�fono \n5. Matr�cula";
				cout << "\n6. Calle y n�mero \n7. Colonia \n8. Calificaci�n 1 \n9. Calificaci�n 2 \n10. Calificaci�n 3 " << endl << endl;
				cin >> opcion;

				if (opcion == 1) {

					system("cls");

					cout << "EDICI�N DE ALUMNOS" << endl << endl;

					bool validar4 = false;
					while (validar4 == false) {

						cin.ignore();
						cout << "Nombre(s): ";
						getline(cin, datos[i].nombre);

						string temp = datos[i].nombre;

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
								break;
							}
						}

						if (validar4 == true) {
							break;
						}
						else {
							system("cls");

							cout << "EDICI�N DE ALUMNOS" << endl << endl;

							cout << "El nombre ingresado contiene elementos que no son letras del alfabeto." << endl << endl;
							cout << "Presione Enter y vuelva a registrar el nombre correctamente." << endl << endl;

							system("pause > nul");
						}
					}
					
				}

				if (opcion == 2) {

					system("cls");

					cout << "EDICI�N DE ALUMNOS" << endl << endl;

					bool validar5 = false;
					while (validar5 == false) {

						cin.ignore();
						cout << "\nApellidos: ";
						getline(cin, datos[i].apellidos);

						string temp = datos[i].apellidos;

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
								break;
							}
						}

						if (validar5 == true) {
							break;
						}
						else {
							system("cls");

							cout << "EDICI�N DE ALUMNOS" << endl << endl;

							cout << "Los apellidos ingresados contienen elementos que no son letras del alfabeto." << endl << endl;
							cout << "Presione Enter y vuelva a registrar los apellidos correctamente." << endl << endl;

							system("pause > nul");
						}
					}

				}

				if (opcion == 3) {

					system("cls");

					cout << "EDICI�N DE ALUMNOS" << endl << endl;

					bool validar2 = false;
					bool validar22 = false;
					while (validar2 == false) {

						cin.ignore();
						cout << "\nCorreo electronico: ";
						getline(cin, datos[i].correoelec);

						string temp = datos[i].correoelec;

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

						if (temp[tamano2 - 4] == 46 && temp[tamano2 - 3] == 99 && temp[tamano2 - 2] == 111 && temp[tamano2 - 1] == 109) {
							validar22 = true;
						}
						else {
							validar22 = false;
						}

						if (validar2 == true && validar22 == true) {
							break;
						}
						else {
							system("cls");

							cout << "EDICI�N DE ALUMNOS" << endl << endl;

							cout << "El correo electr�nico ingresado no contiene @, contiene m�s de un @ o no tiene la finalizaci�n .com." << endl << endl;
							cout << "Presione Enter y vuelva a registrar el correo electr�nico correctamente." << endl << endl;

							system("pause > nul");
						}
					}

				}

				if (opcion == 4) {

					system("cls");

					cout << "EDICI�N DE ALUMNOS" << endl << endl;

					bool validar1 = false;
					while (validar1 == false) {

						cin.ignore();
						cout << "\nTel�fono de contacto: ";
						getline(cin, datos[i].telefono);

						string temp = datos[i].telefono;

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

							cout << "EDICI�N DE ALUMNOS" << endl << endl;

							cout << "El tel�fono ingresado contiene una cantidad de elementos fuera del rango permitido ";
							cout << "o uno o varios de estos elementos no son n�meros." << endl << endl;
							cout << "Presione Enter y vuelva a registrar el tel�fono correctamente." << endl << endl;

							system("pause > nul");
						}
					}

				}

				if (opcion == 5) {

					system("cls");

					cout << "EDICI�N DE ALUMNOS" << endl << endl;

					cout << "\n�Quiere permitir que el programa autogenere una matr�cula?" << endl;
					cout << "1.Autogenerar \n2.Denegar" << endl << endl;
					cin >> opcion;

					if (opcion == 1) {

						datos[i].matricula = to_string(matemp);

						for (int i = 0; i < c; i++) {
							while (strcmp(datos[c].matricula.c_str(), datos[i].matricula.c_str()) == 0) {

								matemp = matemp + 1;

								datos[i].matricula = to_string(matemp);

							}
						}
						cin.ignore();
					}
					else if (opcion == 2) {

						cin.ignore();

						bool validar3 = false;
						while (validar3 == false) {
							cout << "\nMatr�cula: ";
							getline(cin, datos[i].matricula);

							string temp = datos[i].matricula;

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

								cout << "EDICI�N DE ALUMNOS" << endl << endl;

								cout << "La matr�cula ingresada debe contener 7 elementos." << endl << endl;
								cout << "Presione Enter y vuelva a registrar la matr�cula correctamente." << endl << endl;

								system("pause > nul");
							}
						}
					}
					else {
						system("cls");

						cout << "EDICI�N DE ALUMNOS" << endl << endl;

						cout << "Error. Presione Enter e ingrese una opcion v�lida." << endl << endl;

						system("pause > nul");

						AltaDeAlumnos();
					}

				}

				if (opcion == 6) {

					system("cls");

					cout << "EDICI�N DE ALUMNOS" << endl << endl;

					cin.ignore();
					cout << "\nDirecci�n: \nCalle y n�mero: ";
					getline(cin, datos[i].callenum);

				}

				if (opcion == 7) {

					system("cls");

					cout << "EDICI�N DE ALUMNOS" << endl << endl;

					cin.ignore();
					cout << "\nColonia: ";
					getline(cin, datos[i].colonia);

				}

				if (opcion == 8) {

					system("cls");

					cout << "EDICI�N DE ALUMNOS" << endl << endl;

					bool validar = false;
					while (validar == false) {

						cin.ignore();
						cout << "Calificaci�n 1: " << endl;
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

							cout << "EDICI�N DE ALUMNOS" << endl << endl;

							cout << "Error. El n�mero ingresado contiene m�s de dos decimales o esta fuera del rango permitido." << endl << endl;
							cout << "Presione Enter y vuelva a registrar la calificaci�n correctamente." << endl << endl;

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

					cout << "EDICI�N DE ALUMNOS" << endl << endl;

					bool validar = false;
					while (validar == false) {

						cin.ignore();
						cout << "Calificaci�n 2: " << endl;
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

							cout << "EDICI�N DE ALUMNOS" << endl << endl;

							cout << "Error. El n�mero ingresado contiene m�s de dos decimales o esta fuera del rango permitido." << endl << endl;
							cout << "Presione Enter y vuelva a registrar la calificaci�n correctamente." << endl << endl;

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

					cout << "EDICI�N DE ALUMNOS" << endl << endl;

					bool validar = false;
					while (validar == false) {

						cin.ignore();
						cout << "Calificaci�n 3: " << endl;
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

							cout << "EDICI�N DE ALUMNOS" << endl << endl;

							cout << "Error. El n�mero ingresado contiene m�s de dos decimales o esta fuera del rango permitido." << endl << endl;
							cout << "Presione Enter y vuelva a registrar la calificaci�n correctamente." << endl << endl;

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

		cout << "EDICI�N DE ALUMNOS" << endl << endl;

		cout << "No hay alumno registrado con la matr�cula ingresada." << endl;
		
		system("pause > nul");
	}

	menu();
}

void BorrarAlumnos() {

	system("cls");

	cout << "BORRAR ALUMNOS" << endl << endl;

	cin.ignore();

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
			cout << "Matr�cula: " << datos[i].matricula << endl;
			cout << "Direcci�n: " << datos[i].callenum << " " << datos[i].colonia << endl;
			cout << "Calificaciones" << endl << "Calificaci�n 1: " << datos[i].calif1 << endl;
			cout << "Calificaci�n 2: " << datos[i].calif2 << endl << "Calificaci�n 3: " << datos[i].calif3 << endl;
			cout << "Promedio: " << datos[i].prom << endl << endl;
			encontrado = true;

			cout << "�Deseas eliminar a " << datos[i].nombre << "de la lista?" << endl << endl;
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

		cout << "No hay alumno registrado con la matr�cula ingresada." << endl;
		
		system("pause > nul");
	}

	menu();
}

void ManualDeUsuario() {

	system("cls");

	cout << "MANUAL DE USUARIO" << endl << endl;

	cout << "Requisitos: \nCualquier computadora con la capacidad de ejecutar Microsoft Visual Studio ";
	cout << "(se recomienda que ejecute Microsoft Visual Studio 2017)." << endl << endl;

	cout << "Introducci�n: " << endl << endl;
	cout << "Este programa fue creado con el prop�sito de brindar una herramienta a cualquier  ";
	cout << "profesor que requiera agendar los datos de sus alumnos asi como sus calificaciones obtenidas en ciertas ";
	cout << "actividades de forma pr�ctica y sencilla, para realizar el c�lculo de promedios, buscar contactar a un ";
	cout << "alumno, entre muchas otras cosas." << endl << endl;

	cout << "Instrucciones generales: " << endl << endl;

	cout << "Al iniciar el programa por primera vez aparecer� un mensaje que dice Error al abrir el archivo. ";
	cout << "Puede que el archivo no exista o se produjo un problema al intentar abrirlo, esto es normal, solo se ";
	cout << "debe presionar Enter para continuar." << endl << endl;
	cout << "Si dicho mensaje sigue apareciendo despu�s de la primera vez, debi� haber ocurrido alg�n error." << endl << endl;
	
	cout << "Cada vez que aparezca una lista de opciones enumeradas, se debe elegir ingresando el n�mero desde teclado ";
	cout << "y enseguida presionar Enter." << endl << endl;
	cout << "Si se ingresa un n�mero diferente de los disponibles en la lista, el programa lo marcar� como Error ";
	cout << "y se tendr� que ingresar de nuevo la opci�n, o, en el peor de los casos, se tendr� que ingresar desde el men�." << endl << endl;

	cout << "Cada vez que se deba ingresar un dato mediante el teclado, se debe presionar Enter una vez que se escriba ";
	cout << "el dato completo." << endl << endl;

	cout << "Instrucciones: " << endl << endl;
	
	cout << "Men�: " << endl << endl;
	cout << "En esta secci�n se puede elegir cualquiera de las opciones que se muestran en pantalla para proceder a ";
	cout << "realizar sus respectivas funciones." << endl << endl;
	
	cout << "Alta de alumnos: " << endl << endl;
	cout << "En esta secci�n se solicitar� confirmaci�n de registro." << endl;
	cout << "Si se ingresa la opci�n 1, se proceder� al llenado de los datos de alumno, para los cuales se debe ";
	cout << "tener en cuenta las siguientes indicaciones: " << endl << endl;
	cout << "- Todos los datos a ingresar pueden tener la cantidad de espacios que el usuario desee utilizar, ";
	cout << "queda a criterio de �ste el manejo de los espacios en cada dato." << endl;
	cout << "- Ning�n dato cambiar� letras min�sculas a may�sculas ni viceversa, queda a criterio ";
	cout << "del usuario el manejo del tipo de letras." << endl;
	cout << "- Los datos Nombre(s) y Apellidos solo aceptan letras al momento de ingresarlos." << endl;
	cout << "- El correo electr�nico debe tener un solo @ y debe terminar con .com ." << endl;
	cout << "- El tel�fono de contacto solo acepta n�meros al momento de ingresarlo, y debe ser de al menos 8 ";
	cout << "d�gitos y menor que 12 d�gitos." << endl;
	cout << "- Para la matr�cula tendr� 2 opciones: autogenerarla o ingresarla. Si se desea ingresarla, la matr�cula ";
	cout << "debe ser de al menos 1 elemento y acepta un m�ximo de 7 elementos." << endl << endl;
	cout << "Al finalizar el registro, se tiene la opci�n de registrar a otro alumno. Si elige Salir regresar� a Men�." << endl << endl;
	
	cout << "Alta de calificaciones: " << endl << endl;
	cout << "En esta secci�n se solicitar� confirmaci�n de registro." << endl;
	cout << "Si se ingresa la opci�n 1, se proceder� a la b�squeda de un alumno, para lo cual el usuario debe ";
	cout << "ingresar la matr�cula del alumno a quien se le dar� de alta una o varias calificaciones." << endl;
	cout << "Una vez encontrado el alumno, el usuario puede elegir la calificaci�n que quiera registrar, asi como ";
	cout << "obtener el promedio de dicho alumno. Aqui algunas indicaciones respecto al registro de calificaciones: " << endl << endl;
	cout << "- Cualquier calificaci�n solo acepta n�meros al momento de ingresarlas." << endl;
	cout << "- Dichos n�meros tienen que estar dentro del rango de 0 a 100, y pueden tener un m�ximo de 2 decimales." << endl << endl;
	cout << "- Evite ingresar una gran cantidad de ceros como decimales, pues podr�a traer problemas al programa." << endl << endl;
	cout << "- Si no registra una calificaci�n, el promedio ser� de cero. Este programa fue creado para que ";
	cout << "calcule un promedio basado en tres calificaciones. El usuario no puede hacer nada para modificarlo." << endl << endl;
	cout << "Para salir de esta secci�n se debe ingresar la opci�n Cancelar." << endl << endl;

	cout << "Lista completa: " << endl << endl;
	cout << "Al seleccionar esta opci�n se muestra una lista de todos los alumnos que est�n registrados en el programa." << endl << endl;
	cout << "Para salir de esta secci�n se debe presionar Enter." << endl << endl;

	cout << "Buscar alumno: " << endl << endl;
	cout << "En esta secci�n el usuario puede buscar los datos de un solo alumno ingresando su matr�cula correspondiente." << endl << endl;
	cout << "Para salir de esta secci�n se debe presionar Enter." << endl << endl;

	cout << "Edici�n de alumnos" << endl << endl;
	cout << "En esta secci�n el usuario puede modificar los datos de los alumnos que fueron ingresados durante el ";
	cout << "registro. Para ello deber� ingresar la matr�cula del alumno que desea modificar y enseguida visualizar� ";
	cout << "los datos de dicho alumno, as� como dos opciones: Modificar y Cancelar." << endl;
	cout << "Si se ingresa la opci�n 1, se abrir� una lista de opciones con los datos que se pueden modificar. ";
	cout << "Dependiendo de la opci�n que se elija, se proceder� a ingresar el nuevo dato correspondiente.";
	cout << "Se deben tomar en cuenta las indicaciones ya mencionadas en las secciones anteriores." << endl << endl;

	cout << "Borrar alumnos: " << endl << endl;
	cout << "En esta secci�n el usuario puede borrar alumnos del programa para un fin determinado. Deber� ingresar la ";
	cout << "matr�cula del alumno que desea eliminar y despu�s se solicitar� confirmaci�n de eliminaci�n." << endl;
	cout << "Si se elije la opci�n de Eliminar, el programa borrar� todos los datos del alumno eliminado del programa." << endl << endl;

	cout << "La secci�n Manual de Usuario muestra las indicaciones que debe conocer el usuario antes de ejecutar el ";
	cout << "programa. As� no tendr� dificultad para manejarlo." << endl << endl;

	cout << "Salir: " << endl << endl;
	cout << "Con esta opci�n se guardan todos los cambios que se hayan realizado en el programa durante su ejecuci�n." << endl;
	cout << "Primero se solicitar� confirmaci�n de salida del programa y despu�s se cerrar�." << endl << endl;

	cout << "Para salir de esta secci�n presione Enter.";

	system("pause > nul");
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

		ofstream archivodatos;

		archivodatos.open("BasedeDatos.txt", ios::binary);

		archivodatos.write((char*)&datos, sizeof(datos));

		archivodatos.close();

		system("cls");
	}
}