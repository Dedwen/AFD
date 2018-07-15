#include <iostream>
#include <cstring>
#include <fstream>
using namespace std;


int main()
{
    ifstream in("date.in");
    int f[100][100] = {-1}; // f-Functia de tranzitie
    bool Fin[100] = {0};
    int k = 0, i, nrQ, nrFin,nrS,nrTranz;

    char *cuvant = new char[50];
    in.getline(cuvant,50); // Citim cuvantul din fisier
    cout<<" Cuvantul este= "<<cuvant<<endl;

    in >> nrS; // Citim nr de simboluri din alfabet
    char* alfabet = new char [nrS];
    cout << " Simbolurile din alfabet sunt : {";
    for(int i = 0; i < nrS; ++i)
    {
        in >> alfabet[i]; // Citim simbolurile alfabetului respectiv
        cout <<" "<<alfabet[i];
    }
    cout<<" }"<< endl;

    int ok;
    if(cuvant[0] != '&') // & o sa fie in cazul nostru cuvantul vid
    for(int j = 0; j < strlen(cuvant); ++j)
    {
        ok=0;
        for(int i = 0; i < nrS; ++i)      // Verific daca toate literele cuvantului apartin in alfabet
            if(cuvant[j] == alfabet[i])
                ok = 1;
        if(ok == 0)
        {
            cout << " Cuvantul nu exista in limbaj";
            return -1;
        }
    }

    in >> nrQ; // Citim nr de stari din fisier
    cout << " Nr. stari= "<<nrQ<<endl;
    cout << " Starile sunt: {";
    for(int i = 0; i < nrQ; ++i)
        cout << " q" << i;
    cout << " }" << endl;

    in >> nrFin; // Citim nr de stari finale din fisier
    cout << " Starile finale: ";
    for(int i = 0; i < nrFin; ++i)
    {
        in >> k;  // citim indicele starilor finale
        cout <<" q"<< k;
        Fin[k] = 1;
    }
    cout << endl;

    if(cuvant[0] == '&')
      {
        if(Fin[0] == 1)  // Verificam daca prima stare este finala pentru a apartine sau nu cuvantul vid
        cout << " Cuvantul exista in limbaj ! " << endl;
        else cout << " Cuvantul nu exista in limbaj ! " << endl;
        return 1;
        }


    in >> nrTranz; // citesc numarul de tranzitii
    if(nrTranz != nrQ*nrS)
        cout << " Cuvantul nu exista in limbaj ! " << endl;

    int s1,s2;
    char *caracter = new char [nrTranz];
    cout << " Tranzitiile sunt: " << endl;
    for(int i = 0; i < nrTranz; ++i)    // Functia de tranzitie <=> Matrice : primul indice= starea curenta ,al doilea indice= directia ,si valoare matrice= starea unde se duce.
    {
        in >> s1 >> caracter[i] >> s2; // s1-starea curenta ,iar s2 starea urmatoare
        cout << " f("<<s1<<","<<caracter[i]<<")=" << s2 << endl;
        f[s1][caracter[i]] = s2; // matricea care realizeaza tranzitia
    }
    cout << endl;

    s1 = 0; // resetez valoarea lui s1 pentru a incepe de la prima stare
    for(int i = 0; i < strlen(cuvant); ++i)  // Verific daca cuvantul apartine limbajului
    {
        s2 = f[s1][cuvant[i]];
        s1 = s2;
    }

    if(Fin[s1] == 1) // Se verifica daca ultima stare curenta este finala
        cout << " Cuvantul exista in limbaj ! " << endl;
    else
        cout << " Cuvantul nu exista in limbaj ! " << endl;


    in.close();
    return 0;
}
