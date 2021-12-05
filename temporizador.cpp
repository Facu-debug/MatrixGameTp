
#include<iostream>
using namespace std;

int main()
{
    int n, t0, t1;
    int v[10];
    int v1[10];
    int v2[10];

    cout << "\nINICIO:\n\n";
    t0 = time(NULL);
    t1 = time(NULL)*2;
    printf("Espere unos segundos mientras se genera una semilla Para el vector 0 (?\n");
    while(t0 != t1)
    {
        t0 ++;
    }
    cargaVector(v,10);
    system("pause");
    cout << endl;
    t0 = time(NULL);
    t1 = time(NULL)*2;
    printf("Espere unos segundos mientras se genera una semilla Para el vector 1 :D\n");
    while(t0 != t1)
    {
        t0 ++;
    }
    cargaVector(v1,10);
    system("pause");
    cout << endl;
    t0 = time(NULL);
    t1 = time(NULL)*2;
    printf("Espere unos segundos mientras se genera una semilla Para el vector 2 =)\n");
    while(t0 != t1)
    {
        t0 ++;
    }
    cargaVector(v2,10);
    system("pause");
    system("cls");

    cout << "Hello world!" << endl;
    cout << "----------------\n";
    cout << "|" <<v[0]<<" | "<<v[1]<<" | "<<v[2]<<" | "<<v[3]<< " |"<<endl;
    cout << "----------------\n";
    cout << "|" <<v1[0]<<" | "<<v1[1]<<" | "<<v1[2]<<" | "<<v1[3]<< " |"<<endl;
    cout << "----------------\n";
    cout << "|" <<v2[0]<<" | "<<v2[1]<<" | "<<v2[2]<<" | "<<v2[3]<< " |"<<endl;
    cout << "----------------\n";

    return 0;
};
