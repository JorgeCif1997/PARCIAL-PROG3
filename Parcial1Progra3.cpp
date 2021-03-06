#include<iostream>
using namespace std;

struct nodo{
    int dato;
    nodo *sig=NULL;
};

void apilar(nodo *&inicio,int x);
void desapilar(nodo *&inicio,int x);
void mostrar(nodo *&inicio);
void menu();
int pedirop();

int main(){
    int op,n;
    char nomb;
    nodo *lista=NULL;
    do{
        menu();
        op=pedirop();
        switch(op){
            case 1:
                cout<<"\n\t->Ingrese el registro a apilar: ";
                cin>>n;
            
                apilar(lista,n);
                break;
            case 2:
                cout<<"\n\t->Ingrese el registro desapilar: ";
                cin>>n;
                desapilar(lista,n);
                break;
            case 3:
                mostrar(lista);
                break;

            case 4:
                cout<<"\n\t->Nos vemos vuelve pronto!!! T_T";
          }

        }while(op!=4);

        return 0;
}

int pedirop(){
    int opcion;
    do{
        cout<<"\n\t--->Digite lo deseado (1-4): ";
        cin>>opcion;
        if(opcion<1||opcion>4)
            cout<<"\t--->Error reingrese!!!";
    }while(opcion<1||opcion>4);
    return opcion;
}

void menu(){
    cout<<"\n\t*************MENU****************";
    cout<<"\n\t1-> Apilar registro ";
    cout<<"\n\t2-> Desapilar el registro ";
    cout<<"\n\t3-> Mostrar registros ";
    cout<<"\n\t4-> Exit ";
}

void apilar(nodo *&inicio,int x){
    nodo *nuevo = new nodo;
    nuevo->dato = x;
    nuevo->sig = inicio;
    inicio = nuevo;
}

void desapilar(nodo *&inicio,int x){
    nodo *a=NULL,*p=inicio;
    if(p!=NULL){
        while(p->dato!=x && p->sig!=NULL){
            a=p;
            p=p->sig;
        }
        if(p->dato==x){
            if(a==NULL)
                inicio=p->sig;
            else
                a->sig=p->sig;
            p->sig=NULL;
            delete p;
            cout<<"Se elimino el dato "<<x<<"\n";
            p=NULL; 
        }
        else
            cout<<"No se encontro el dato "<<x<<"\n";
    }
    else
        cout<<"Pila vac??a"<<endl;
}

void mostrar(nodo *&inicio){
    cout<<"\nLISTA: ";
    nodo *p = inicio;
    if(p!=NULL){
        while(p!=NULL){
            cout<<p->dato<<" -> ";
            p = p->sig;
        }
        cout<<"NULL"<<endl;
    }
    else
        cout<<"Pila vac??a"<<endl;
}