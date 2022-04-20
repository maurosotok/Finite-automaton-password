#include <iostream>
#include <cctype>
using namespace std;
enum class Estado{INICIO, E1, E2, VALIDO, INVALIDO};
bool validar(string pass){
	
	Estado actual = Estado::INICIO;
	int pos = 0;
	int cont = 0;
	int temp = 0;
	while (pos < pass.length()){
		if(pass[pos] == '#'){
			temp = pos;
			cont++;
		}
		pos++;
	}
	if(temp != pass.length()-1) {
		actual = Estado::INVALIDO;
	}else{
		if(pass.length()<6){
			actual = Estado::INVALIDO;		
		}else{
			pos = 0;
			while(pos<pass.length()){
				switch(actual){
					case Estado::INICIO:
						if(isdigit(pass[pos])){
							actual = Estado::E1;
						}else{
							actual =Estado::INVALIDO;
						}
					break;
					case Estado::E1:
						if(isupper(pass[pos])){
							actual = Estado::E2;
						}else{
							actual = Estado::INVALIDO;	
						}	
					break;
					case Estado::E2:
						if(pos<= 4){
							if(isupper(pass[pos])){
								actual = Estado::E2;
							}else{
								actual = Estado::INVALIDO;
							}
						}else if(pos>5 && isupper(pass[pos])){
							actual = Estado::E2;
						}else if(pass[pos] == '#' || pass[pos] == '*'){
							actual = Estado::VALIDO;
						}
					break;
					default: actual = Estado::INVALIDO;
				}
				pos++;
			}
		}
	}	
	if(cont >= 2) {
		actual = Estado::INVALIDO;
	}
	if (actual == Estado::VALIDO){
		return true;
	}else{
		return false;
	}
}
int main(){
	string password = "";
	
	cout<<"Ingrese la clave a utilizar"<<endl;
	cout<<"Minimo 6 caracteres"<<endl;
	cout<<"Debe comenzar con un numero entre 0 y 9"<<endl;
	cout<<"Luego llevara solo letras mayusculas, la cantidad que desee (nada de numeros o simbolos)"<<endl;
	cout<<"Ultimo caracter debe ser '# *' "<<endl;
	cin>>password;
	
	if(validar(password)){
		cout << "Password valido"<< endl;
	}else{
		cout << "Password no valido"<< endl;
	}
	
	return 0;
}
