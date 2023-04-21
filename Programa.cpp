
const char *archivo = "notas.dat";
struct Estudiante{
	int codigo;
	char nombres[50];
	char apellidos[50];
	int telefono;
};
void Leer();
void Crear();
void Actualizar();
void Borrar();
main() {
	Leer();
  	Crear();
  	Borrar();
	Actualizar();
  	
	system("pause");
}
void Leer(){
	system("cls");
	FILE* archivos = fopen(archivo,"rb");
	if (!archivos){
		archivos = fopen(archivo,"w+b");
	}
	Estudiante estudiante;
	int id=0; // indice o pocision del registro(fila) dentro del archivo
	fread(&estudiante,sizeof(Estudiante),1,archivos);
	cout<<"___________________________________________________"<<endl;
	cout<<"ID"<<"|"<<"Codigo"<<"|"<<"   Nombres  "<<"|"<<"   Apellidos   "<<"|"<<" Telefono"<<endl;
	do{
		cout<<id<<"|"<<estudiante.codigo<<"|"<<estudiante.nombres<<"|"<<estudiante.apellidos<<"|"<<estudiante.telefono<<endl;
		fread(&estudiante,sizeof(Estudiante),1,archivos);
		id+=1;
	}while(feof(archivos)==0);
	fclose(archivos);
}
void Crear(){
	
	FILE* archivos = fopen(archivo,"a+b");
	char res;
	Estudiante estudiante;
	do{
		fflush(stdin);
		cout<<"Ingrese Codigo:";
		cin>>estudiante.codigo;
		cin.ignore();
		
		cout<<"Ingrese Nombres:";
		cin.getline(estudiante.nombres,50);
		
		cout<<"Ingrese Apellidos:";
		cin.getline(estudiante.apellidos,50);
		
		cout<<"Ingrese Telefono:";
		cin>>estudiante.telefono;
		
		fwrite(&estudiante,sizeof(Estudiante),1,archivos);
		cout<<"Desea ingresar otro estudiante(s/n):";
		cin>>res;
	}while(res=='s' || res=='S');
	fclose(archivos);
	Leer();
}
void Actualizar(){
	
	FILE* archivos = fopen(archivo,"r+b"); 
	Estudiante estudiante;
	int id=0;
	cout<<"Ingrese el ID que desea Modificar:";
	cin>>id;
	fseek(archivos,id * sizeof(Estudiante),SEEK_SET);
		cout<<"Ingrese Codigo:";
		cin>>estudiante.codigo;
		cin.ignore();
		
		cout<<"Ingrese Nombres:";
		cin.getline(estudiante.nombres,50);
		
		cout<<"Ingrese Apellidos:";
		cin.getline(estudiante.apellidos,50);
		
		cout<<"Ingrese Telefono:";
		cin>>estudiante.telefono;
		
		fwrite(&estudiante,sizeof(Estudiante),1,archivos);
	
	
	fclose(archivos);
	Leer();
}
void Borrar(){
	const char *archivo_temp = "archivo_temp.dat";
	FILE* archivos_temp = fopen(archivo_temp,"w+b");
	FILE* archivos = fopen(archivo,"rb");
	Estudiante estudiante;
	int id=0,id_n=0;
	cout<<"Ingrese el ID a eliminar:";
	cin>>id;
	while(fread(&estudiante,sizeof(Estudiante),1,archivos)){
		if (id_n !=id ){
			fwrite(&estudiante,sizeof(Estudiante),1,archivos_temp);
		}
		id_n++;
	}
	fclose(archivos);
	fclose(archivos_temp);
	
	archivos_temp = fopen(archivo_temp,"rb");
	archivos = fopen(archivo,"wb");
	while(fread(&estudiante,sizeof(Estudiante),1,archivos_temp)){
		fwrite(&estudiante,sizeof(Estudiante),1,archivos);
		
	}
		fclose(archivos);
	fclose(archivos_temp);
	Leer();

	
}
