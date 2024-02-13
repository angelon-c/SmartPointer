#include <iostream>
#include "my_shared_ptr.h"

using namespace std;
class Persona{
public:
    Persona() {cout<<"persona creada"<<endl;}
    ~Persona() {cout<<"persona eliminada"<<endl;}
    void saludar(){cout<<"Hola"<<endl;}




};

using namespace std;
int main() {

    my_shared_ptr<Persona> persona1(new Persona());
    cout<<"Referencias:"<<persona1.get_count()<<endl;
    persona1->saludar();

    my_shared_ptr<Persona> persona2=persona1;
    cout<<"Referencias:"<<persona2.get_count()<<endl;
    {
        my_shared_ptr<Persona> persona3=persona1;
        cout<<"referencias:"<<persona3  .get_count()<<endl;

    }
    cout<<"Referencias:"<<persona1.get_count()<<endl;






    return 0;
}
