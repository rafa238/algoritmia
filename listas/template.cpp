#include <iostream>

using namespace std;

void printLinkedList(SinglyLinkedListNode* head) {
     while(head!=nullptr){
         cout <<head->data<<endl;
         head=head->next;
     }
}
class Nodo{
    public:
        int dato=0;
        Nodo * siguiente;
        Nodo * anterior;
        Nodo(int dato){
            this->dato = dato;
            siguiente = nullptr;
            anterior = nullptr;
        }
};

class Lista{
    public:
        void insertar(int dato){
            //Creamos el punterto a un nodo
            Nodo * nuevoNodo;
            //Creamos el nodo como tal
            nuevoNodo = new Nodo(dato);

            // delete destruye una referencia

            //Si la lista esta vacia
            if(iniLista == nullptr){
              iniLista = nuevoNodo; // puntero = puntero
              finLista = nuevoNodo;
            } else {
              //El ultimo elemento de la lista en su next, va a apuntar
              //al nuevo nodo
              finLista->siguiente = nuevoNodo;

              // (*finLista).siguiente = nuevoNodo;  <->  finLista->siguiente = nuevoNodo;

              //Y actualizamos el fin
              finLista = nuevoNodo;
            }
            this->tamLista++;
            return;
        }
        void modificarPorPos(int dato, int pos){
          if(pos <= 0 || pos > tamLista){
              cout << "Posicion invalida" << endl;
              //mensaje, tirar una except
              return;
          } else {
              //-1 3
              Nodo * it = iniLista;
              //3 4 1 8

              for(int i = 1; i < pos; i++, it = it->siguiente);
              it->dato = dato;
              return;
          }
        }
        void reversa(){
            int arr[tamLista+1];
            int i = 0;

            for(Nodo * it = iniLista; it != nullptr; it = it->siguiente, i++){
                arr[i] = it->dato;
            }

            for(int i = 1; i < tamLista; i++){
                modificarPorPos(arr[tamLista-i], i);
            }

            return;
        }
        void imprimirLista(){
            for(Nodo * it = iniLista; it != nullptr; it = it->siguiente){
                cout << it->dato << " -> ";
            }
        }
    private:
        Nodo * iniLista = nullptr;
        Nodo * finLista = nullptr;
        int tamLista = 0;
};


int main()
{
    Lista l;
    int n;
    cin>>n;
    for(int i=0; i<n; i++){
        int num;
        cin>>num;
        l.insertar(num);
    }
    return 0;
}

SinglyLinkedListNode* mergeLists(SinglyLinkedListNode* head1, SinglyLinkedListNode* head2) {
    SinglyLinkedList nuevaLista;
    while(head1 != nullptr || head2 != nullptr){
        if(head1 == nullptr) {
            nuevaLista.insert_node(head2->data);
            head2=head2->next;
        }
        if(head2 == nullptr) {
            nuevaLista.insert_node(head1->data);
            head1=head1->next;
        }
        if(head1 < head2){
            nuevaLista.insert_node(head1->data);
            head1=head1->next;
        } else if(head2 < head1){
            nuevaLista.insert_node(head2->data);
            head2=head2->next;
        } else if(head1 == head2){
            nuevaLista.insert_node(head1->data);
            head1=head1->next;
            nuevaLista.insert_node(head2->data);
            head2=head2->next;
        }
    }
    return nuevaLista.head;
}
