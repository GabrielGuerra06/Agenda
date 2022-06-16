#include <iostream>
#include <time.h>
using namespace std;

struct fecha{
int dia;
int mes;
int anualidad;
};

int cantidad;
fecha *pArregloFechas=new fecha;
void agregarFecha(fecha *pArregloFechas);
bool validarFecha(fecha *pArregloFechas, int i);
void imprimirFecha(fecha *pArregloFechas);


struct agenda{
fecha pArregloFechas;
int No[10];
char actividad[50];
char lugar[30];
int hora;
int minutos;
};
void agregarCita(agenda *pArregloCitas);
void mostrarCita(agenda *pArregloCitas);
void buscarCita(agenda *pArregloCitas);
void editarCita(agenda *pArregloCitas);
void EliminarCita(agenda *pArregloCitas);
void Salir(agenda *pArregloCitas);
////////////////////////////////////////////
int main() {
  int opc;
  bool flag=false;
agenda *pArregloCitas[10];
do{

    cout<<"\n Ingresa la opcion que desees "<<endl;
cout<<"---------MENU--------\n";
  cout<<"1. Agregar citas \n";
  cout<<"2. Mostrar citas \n";
  cout<<"3. Buscar citas\n";
  cout<<"4. Editar citas \n";
  cout<<"5. Eliminar citas \n";
  cout<<"6. Salir \n";
  cin>>opc;

  switch(opc){
    case 1: 
    agregarCita(*pArregloCitas);
      flag=true;
    break;
    case 2:
      if(flag==true){
     mostrarCita(*pArregloCitas);
      }
      else{
        cout<<"ALTO AHÍ, primero debes agregar una cita \n";
      }
    break;
    case 3:
      if(flag==true){
      buscarCita(*pArregloCitas);
      }
      else{
        cout<<"ALTO AHÍ, primero debes agregar una cita \n ";
      }
    break;
    case 4:
      if(flag==true){
      editarCita(*pArregloCitas);
      }
      else{
        cout<<"ALTO AHÍ, primero debes agregar una cita \n ";
      }
       
    break;
    case 5:
      if(flag==true){
       EliminarCita(*pArregloCitas);
      }
      else{
        cout<<"ALTO AHÍ, primero debes agregar una cita \n";
      }
      
    break;
    case 6:
     cout<<"\n PROGRAMA FINALIZADO";
    break;
    default:
    cout<<"INGRESA UNA OPCION VALIDA \n";
     
    break;
  }   
  }while(opc!=6);
  }

//////////////////////////////////////////

void agregarFecha(fecha *pArregloFechas){
  cout<<"-----------Agendar cita------ (ingresa la fecha de tu cita)\n";
 
  cout<<"\n Cuantas fechas quieres ingresar?";
  cin>>cantidad;
  for(int i=0; i<cantidad; i++){
    bool validacion;
    cout<<"\n ---FECHA "<<i+1<<" ---";
     cout<<"\n Año: (AAAA)";
    cin>>pArregloFechas[i].anualidad;
    
  cout<<"\n Mes: (MM)";
  cin>>pArregloFechas[i].mes;
  cout<<"\n Día: (DD)";
  cin>>pArregloFechas[i].dia; 

  
  validacion = validarFecha(pArregloFechas,i);
    while(!validacion){
        cout<<"Fecha incorrecta, vuelva a intentarlo \n";
          cout<<"\n ---FECHA "<<i+1<<" ---";
     cout<<"\n Año: ";
    cin>>pArregloFechas[i].anualidad;
    
  cout<<"\n Mes: ";
  cin>>pArregloFechas[i].mes;
  cout<<"\n Día: ";
  cin>>pArregloFechas[i].dia; 
  
      validacion = validarFecha(pArregloFechas,i);
    }
    
    cout<<"Fecha válida \n";
    
  }
}

bool validarFecha(fecha *pArregloFechas,int i){
   if(pArregloFechas[i].anualidad>=2022){
    if(pArregloFechas[i].mes<=12 && pArregloFechas[i].mes>0){
      if(pArregloFechas[i].mes==4 || pArregloFechas[i].mes==6 || pArregloFechas[i].mes==9 || pArregloFechas[i].mes==11){
        if(pArregloFechas[i].dia<=30 && pArregloFechas[i].dia>0){
          return true;
      }
        else{
    return false; }
      }
        else if(pArregloFechas[i].mes==1 || pArregloFechas[i].mes==3  || pArregloFechas[i].mes==5 || pArregloFechas[i].mes==7 || pArregloFechas[i].mes==10 || pArregloFechas[i].mes==12 || pArregloFechas[i].mes==8){
          if(pArregloFechas[i].dia<=31 && pArregloFechas[i].dia>0){  
            return true;
      }
          else{
    return false;}
        }
        else if(pArregloFechas[i].mes==2){
          if(pArregloFechas[i].dia<=28 && pArregloFechas[i].dia>0){
            return true;
      }
          else{
    return false;}
        }
       else{
    return false;}
     }
    else{
    return false;}
  }
  else{
    return false;} 
  }
  

void imprimirFecha(fecha *pArregloFechas){
  for(int i=0; i<cantidad; i++){
cout<<"Día \t Mes \t Año \n "<<pArregloFechas[i].dia<<"\t \t"<<pArregloFechas[i].mes<<"\t \t"<<pArregloFechas[i].anualidad<<"\n \n";
  
  }
}



void agregarCita(agenda *pArregloCitas){
    agregarFecha(pArregloFechas);
  for(int i=0; i<cantidad; i++){
  cout<<"\n-----------Cita"<<i+1<<":-----------";
  cout<<"\n Actividad a realizar de la cita "<<i+1<<":";
    cin.ignore();
    cin.getline(pArregloCitas[i].actividad,50); 
  cout<<"\n Hora de la actividad "<<i+1<<" (24-11 am y 12-23 pm):";
    cin>>pArregloCitas[i].hora;
  cout<<"\n Minutos  (00-59): ";
    cin>>pArregloCitas[i].minutos;
    if(pArregloCitas[i].minutos>60){
      cout<<"Error en los minutos \n";
      cout<<"Nuevos minutos:\n";
      cin>>pArregloCitas[i].minutos;
    }
  cout<<"\n En donde se realizará la actividad "<<i+1<<":";
    cin.ignore();
    cin.getline(pArregloCitas[i].lugar,30);
  }
}


void mostrarCita(agenda *pArregloCitas){
     for(int i=0; i<cantidad; i++){
    cout<<endl;
cout<<" ---------------fecha "<<i+1<<" :----------\n";
cout<<"Día de la cita: "<<pArregloFechas[i].dia<<"/"<<pArregloFechas[i].mes<<"/"<<pArregloFechas[i].anualidad<<" \n";
cout<<"Actividad a realizar: "<<pArregloCitas[i].actividad<<" \n";
cout<<"Horario: "<<pArregloCitas[i].hora<<":"<<pArregloCitas[i].minutos<<"\n";
cout<<"lugar: "<<pArregloCitas[i].lugar<<" \n \n";
    
      }
}
void buscarCita(agenda *pArregloCitas){
float filtro;
bool encontro=false;
  
cout<<"\n Ingresa el numero de cita: ";
cin>>filtro;

for(int i=0; i<cantidad;i++){
  if(filtro==i+1) {
    
  encontro=true;
cout<<"\n -----------------CITA  "<<i+1<<"------------------";
cout<<"\nDía de la cita: "<<pArregloFechas[i].dia<<"/"<<pArregloFechas[i].mes<<"/"<<pArregloFechas[i].anualidad;
cout<<"\nActividad a realizar: "<<pArregloCitas[i].actividad;
cout<<"\n Horario: "<<pArregloCitas[i].hora<<":"<<pArregloCitas[i].minutos;
cout<<"\n lugar: "<<pArregloCitas[i].lugar;
    }
else if(encontro==false){
cout<<" ";}
}
  
if(encontro==false){
  cout<<"\n No. de cita inexistente, ingrese otro \n";}
  
}
void editarCita(agenda *pArregloCitas){
  float filtro;
  bool encontro=false;
  string dato;
  string cambiofecha;
  
  cout<<"Ingresa la cita que quieres modificar";
  cin>>filtro;
    for(int i=0; i<cantidad;i++){
    if(filtro==i+1) {
  encontro=true;
  cout<<"\n Que dato quieres modificar? (Fecha, Actividad, Hora, Lugar)";
  cin>>dato;
     
    if(dato=="fecha" || dato=="Fecha" || dato=="FECHA"){
  cout<<"\n/////////////MODIFICACION DE FECHA/////////\n Que dato deseas modificar Año(A)/Mes(M)/Día(D)";
  cin>>cambiofecha;
    if(cambiofecha=="A" || cambiofecha=="a"){
  cout<<"Ingresa el nuevo año de tu cita: ";
  cin>>pArregloFechas[i].anualidad; 
  cout<<"\n Su nuevo año es: "<<pArregloFechas[i].anualidad<<"\n";
  }
    else if(cambiofecha=="M" || cambiofecha=="m"){
  cout<<"Ingresa el nuevo mes de tu cita: ";
  cin>>pArregloFechas[i].mes; 
  cout<<"\n Su nuevo mes es: "<<pArregloFechas[i].mes<<"\n";
  } 
    else if(cambiofecha=="D" || cambiofecha=="d"){
  cout<<"Ingresa el nuevo día de tu cita: ";
  cin>>pArregloFechas[i].dia; 
  cout<<"\n Su nuevo día es: "<<pArregloFechas[i].dia<<"\n";
  }  
    else{
  cout<<"Lo sentimos, opción inválida";
  }
  }
  
      else if(dato=="actividad" || dato=="Actividad" || dato=="ACTIVIDAD"){
  cout<<"Ingresa la nueva actividad de tu cita";
      cin.ignore();
  cin.getline(pArregloCitas[i].actividad,50);
  cout<<"\n Su nueva actividad es: "<<pArregloCitas[i].actividad;}
  
    else if(dato=="hora" || dato=="Hora" || dato=="HORA"){
  cout<<"Ingresa la nueva hora de tu cita: ";
  cin>>pArregloCitas[i].hora;   
  cout<<"\n Su nueva hora es: "<<pArregloCitas[i].hora;}
        
    else if(dato=="lugar" || dato=="Lugar" ||   dato=="LUGAR"){
  cout<<"ingresa el nuevo lugar de su cita: ";
      cin.ignore();
 cin.getline(pArregloCitas[i].lugar,50);  
  cout<<"\n El nuevo lugar de su cita es: "<<pArregloCitas[i].lugar;}
  
    else if(encontro==false){
  cout<<" ";}
  }
  }
}

void EliminarCita(agenda *pArregloCitas){
float filtro;
bool encontro=false;
string dato;

  cout<<"Ingresa el numero de cita que quieras eliminar";
cin>>filtro;
for(int i=0; i<cantidad;i++){
  if(filtro==i+1) {
  encontro=true;
    cout<<"\n Cita eliminada  *____*";
    pArregloFechas[i].anualidad=0;
    pArregloFechas[i].mes=0;
    pArregloFechas[i].dia=0;
    *pArregloCitas[i].actividad=0;
    pArregloCitas[i].hora=0;
    pArregloCitas[i].minutos=0;
    *pArregloCitas[i].lugar=0;
    }
}
}
void Salir(agenda *pArregloCitas){
exit;  
}

