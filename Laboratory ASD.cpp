#include <iostream>
#include <cmath>
#include <bits/stdc++.h>

using namespace std;
// structura pentru lista simplu inlantuita
typedef struct numar
{
    int v;
    numar *urm; //adresarea catre urmatorul element din lista
} numar;
// structura pentru lista dublu inlantuita
typedef struct numar2
{
    int v;
    numar2 *urm;
    numar2 *prec;
} numar2;
typedef struct lista2
{
    numar2 *prim;
    numar2 *ultim;
} lista2;
typedef struct punct
{
    float x;
    punct *urm;
} punct;
struct monom
{
    float coef;
    int grad;
    monom *urm;
};
typedef struct lista
{
    int val;
    lista *next;
} lista;
typedef struct muchie
{
    int nod1;
    int nod2;
    muchie *urm;
} muchie;

struct nod
{
    int v;
    nod *urm;
};

struct muchie2
{
    int v1,v2;
    muchie2 *urm;
};
// functii
void rezolva_ec2(float a, float b, float c) //functia pentru calculul ecuatiei de gradul 2
{
    cout << endl << "Solutia ecuatiei:" << endl;

    float delta = 0;
    delta = b * b - 4 * a * c; //calculez delta
    if (a == 0 && b == 0)
    {
        cout << endl << "Nu este ecuatie" << endl; //verifica daca a*x^2+b*x+c este ecuatie
        return;
    }

    if (a == 0)
    {
        cout << endl << "Ecuatie de grad 1, cu solutia: " << endl; //verifica daca a*x^2+b*x+c este ecuatie de gradul 1
        float x1 = -c / b;
        cout << x1 << endl;
        return;
    }

    cout << endl << "Ecuatie de grad 2, " << endl; //verifica daca a*x^2+b*x+c este ecuatie de gradul 2

    if (delta > 0)
    {
        float x1, x2;
        float RadicalDinDelta = sqrt(delta);
        cout << "Solutiile sunt: " << endl;
        x1 = (-b + RadicalDinDelta) / 2 * a;
        x2 = (-b - RadicalDinDelta) / 2 * a;
        cout << "x1=" << x1 << ", x2=" << x2 << endl;
    }
    if (delta == 0)
    {
        cout << "Solutia este dubla " << endl;
        float x = -b / (2 * a);
        cout << "x1=x2=" << x << endl;
    }
    if (delta < 0)
    {
        cout << "Solutiile sunte imaginare " << endl;
        float Parte_Imaginara = sqrt(-delta) / (2 * a);
        float Parte_Reala = -b / (2 * a);
        cout << Parte_Reala << " + i * " << Parte_Imaginara << endl;
        cout << Parte_Reala << " + i * " << -Parte_Imaginara << endl;
    }


}


void inmultire_matricilor(int AL, int AC, int BL, int BC) //functia pentru citire+afisare+inmultire
{
    int A[10][10], B[10][10], C[10][10], i, j, k;

    if (AC != BL) //Verific daca matricile se pot inmulti
        cout << "Nu se poate realiza inmultirea matricilor" << endl;
    else
    {
        cout << endl << "Introduceti elementele matricei A " << endl; //Citesc matricea A
        for (i = 1; i <= AL; i++)
            for (j = 1; j <= AC; j++)
                cin >> A[i][j];
        cout << "Introduceti elementele matricei B " << endl; //Citesc matricea B
        for (i = 1; i <= BL; i++)
            for (j = 1; j <= BC; j++)
                cin >> B[i][j];
        cout << "Matricile A si B sunt: " << endl;
        cout << "Matricea A: " << endl; //Afisez matricea A
        for (i = 1; i <= AL; i++)
        {
            for (j = 1; j <= AC; j++)
            {
                cout << A[i][j] << " ";
            }
            cout << endl;
        }
        cout << endl;
        cout << "Matricea B: " << endl;//Afisez matricea B
        for (i = 1; i <= BL; i++)
        {
            for (j = 1; j <= BC; j++)
            {
                cout << B[i][j] << " ";
            }
            cout << endl;
        }
        cout << endl;
        for (i = 1; i <= AL; i++) //Initializez matricea C cu 0
            for (j = 1; j <= BC; j++)
                C[i][j] = 0;
        cout << "Se poate realiza inmultirea matricilor " << endl << "Rezulta urmatoarea matrice C: " << endl; //Calculez A*B si afisez
        for (i = 1; i <= AL; i++)
            for (j = 1; j <= BC; j++)
                for (k = 1; k <= AC; k++)
                    C[i][j] += A[i][k] * B[k][j];
        cout << endl;
        for (i = 1; i <= AL; i++)
        {
            for (j = 1; j <= BC; j++)
            {
                cout << C[i][j] << " ";
            }
            cout << endl;
        }
        cout << endl;
    }
}
bool prim(int nr) //functia de verificare a primalitatii
{
    if (nr == 0)
        return false;
    if (nr == 1 || nr == 2)
        return true;
    if (nr >= 3)
    {
        for (int d = 2; d <= sqrt(nr); d++)
            if (nr % d == 0)
                return false;
    }
}

void schimba_baza(int numar, int baza)
{
    int nr = numar;
    int noua_baza = 0, P10 = 1;
    while (numar != 0)
    {
        noua_baza += P10 * (numar % baza);
        P10 *= 10;
        numar = numar / baza;
    }
    cout << endl << "Numarul " << nr << " scris in baza " << baza << " este : " << noua_baza << endl;
}
//Algoritmi de sortare si cautare
void Bubble_Sort(int n, int v[20])
{
    int ind, i, b;
    float aux;

    b = 0; //numara parcurgerile sirului
    do
    {
        b++;
        ind = 1; // nu s-a facut inca nicio interschimbare intre elementele sirului
        for (i = 0; i <= n - 2; i++)
        {
            if (v[i] > v[i + 1])
            {
                aux = v[i];
                v[i] = v[i + 1];
                v[i + 1] = aux;
                ind = 0; // s-a facut o interschimbare
            }
        }
    }
    while (ind == 0);
    cout << endl << "Sirul ordonat dupa " << b << " parcugeri, este:" << endl;
    for (i = 0; i <= n - 1; i++)
        cout << v[i] << ' ';
    cout << endl;
}

void Selection_Sort(int n,int v[20])
{
    int i,j,poz;
    float minim, aux;

    for(i=0; i<=n-2; i++)
    {
        minim=v[i];
        poz=i;
        for(j=i+1; j<=n-1; j++)
        {
            if (minim > v[j])
            {
                minim=v[j];
                poz=j;
            }
        }
        if (i!=poz)
        {
            aux=v[i];
            v[i]=v[poz];
            v[poz]=aux;
        }
    }
    cout<<endl<<"Sirul ordonat este:"<<endl;
    for(i=0; i<=n-1; i++)
        cout<<v[i]<<' ';
    cout<<endl;
}


void Counting_Sort(int n,int v[20] )
{
    //cautam max din v
    int max=v[0];
    for(int i=1; i<n; i++)
    {
        if(v[i]>max)
        {
            max=v[i];
        }
    }
    //initializam vectorul counting
    int c[max+1] = {0};

    //numaram aparitiile
    for(int i=0; i<n; i++)
    {
        c[v[i]]++;
    }

    int k=0;

    //actualizam v
    for(int i=0; i<max+1; i++)
    {
        while(c[i])
        {
            v[k]=i;
            k++;
            c[i]--;

        }
    }
    cout<<endl<<"Sirul ordonat este:"<<endl;
    for(int i=0; i<n; i++)
        cout<<v[i]<<' ';
    cout<<endl;
}

void Merge(int v[20], int s, int m, int d)
{
    int vec[d + 1];
    int i = s;
    int j = m + 1;
    int k = 0;

    while (i <= m && j <= d)
    {
        if (v[i] <= v[j])
            vec[k++] = v[i++];
        else
            vec[k++] = v[j++];
    }
    while (i <= m)
        vec[k++] = v[i++];
    while (j <= d)
        vec[k++] = v[j++];
    k--;
    while (k >= 0)
    {
        v[k + s] = vec[k];
        k--;
    }
}

void Merge_Sort(int v[20], int s, int d)
{
    int m;

    if (s < d)
    {
        m = (s + d) / 2;
        Merge_Sort(v, s, m);
        Merge_Sort(v, m + 1, d);
        Merge(v, s, m, d);
    }

}

int Divide(int v[20],int s,int d)
{
    int pivot=v[d];
    int j=s;
    for(int i=s; i<d; i++)
    {
        if(v[i]<= pivot)
        {
            int aux=v[i];
            v[i]=v[j];
            v[j]=aux;
            j++;
        }

    }
    int aux=v[j];
    v[j]=v[d];
    v[d]=aux;

    return j;
}

void Quick_Sort(int v[20], int s, int d)
{
    int pivot;
    if(s<d)
    {
        pivot=Divide(v,s,d);
        Quick_Sort(v,s, pivot-1);
        Quick_Sort(v, pivot+1,d);
    }
}

void Insertion_Sort(int n,int v[20])
{
    for(int i=1; i<n; i++)
    {
        int aux=v[i];
        int j=i-1;
        while(v[j]>aux && j>=0)
        {
            v[j+1]=v[j];
            j--;
        }
        v[j+1]=aux;
    }
}

void Shell_Sort(int n, int v[20])
{
    int pas = n/2;
    while(pas >=1)
    {
        int i=0;
        while(i+pas <=n-1)
        {
            int j=i;
            int aux = v[i+pas];
            while( (v[j]>aux) && j>=0 )
            {
                v[j+pas]=v[j];
                j-=pas;
            }
            v[j+pas]=aux;
            i++;
        }
        pas = pas/2;
    }
}

int Numar_Cifre(int num)
{
    int k=0;
    while(num)
    {
        k++;
        num=num/10;
    }

    return k;
}

void Descompunere(int* v1, int nr, int M)
{
    int v2[M];
    int k=0;
    while(nr)
    {
        v2[k]=nr%10;
        k++;
        nr=nr/10;
    }
    for(int i=k; i<M; i++)
        v2[i]=0;
    for(int i=0; i<M; i++)
        v1[i]=v2[M-1-i];
}

int Recompunere(int* v1, int M)
{
    int nr=0;
    for(int i=0; i<M; i++)
        nr=nr*10+v1[i];
    return nr;
}

void Radix_Sort(int n, int v[20])
{

    int M=0;
    for(int i=0; i<n; i++)
    {
        int aux=Numar_Cifre(v[i]);
        if(aux>M)
            M=aux;
    }

    int a[n][M];
    int b[n][M];

    for(int i=0; i<n; i++)
        Descompunere(a[i], v[i], M);
    for(int j=M-1; j>=0; j--)
    {
        int i=0;
        for(int k=0; k<=9; k++)
        {
            for(int s=0; s<n; s++)
            {
                if(a[s][j]==k)
                {
                    for(int i1=0 ; i1<M ; i1++)
                        b[i][i1] = a[s][i1];
                    i++;
                }
            }


        }

        cout<<"Variabila j este: "<<j<<endl;
        for(int i1 = 0; i1<n ; i1++)
        {
            for(int j1 = 0; j1<M; j1++)
            {
                a[i1][j1] = b[i1][j1];
                cout<<a[i1][j1]<<" ";
            }
            cout<<endl;
        }
    }

    for(int i=0; i<n; i++)
        v[i]=Recompunere(a[i],M);


}

void Cautare_Secventiala(int n, int v[20], int y)
{
    int c=0;
    for(int i=0; i<n ; i++)
    {
        if(y==v[i])
            c++;
    }
    if(c==0)
        cout<<"Elementul y = "<<y<<" nu se afla in sirul v."<<endl;
    else
        cout<<"Elementul y = "<<y<<" se afla in sirul v. Si apare de "<<c<<" ori."<<endl;;
}

void Cautare_Binara(int s, int d, int v[20], int y)
{
    int m;
    if(s<d)
    {
        m=(s+d)/2;
        if(y==v[m])
            cout<<"Elementul y = "<<y<<" se afla in sir pe pozitia "<<m<<"."<<endl;
        else
        {
            if(y<v[m])
                Cautare_Binara(s,m-1,v,y);
            else
                Cautare_Binara(m+1,d,v,y);
        }
    }
    else
    {
        if(s==d)
            cout<<"Sirul are un singur elemnt."<<endl;
        if(y==v[s])
            cout<<y<<" se afla in sirul v pe pozitia "<<s<<endl;
    }


}
// functii pentru liste simplu inlantuite

numar *creare_lista()
{
    numar *prim, *u, *p;
    int x;
    char a;
    // creeaza capatul de lista
    prim=new numar;
    cout<<"valoare prim lista x=";
    cin>>x;
    prim->v=x;
    prim->urm=NULL;
    // u =ultimul element din lista, dupa care adaugam pe urmatoarele
    u=prim;
    do
    {
        cout<<"Adauga elemente in lista [D/N]? ";
        cin>>a;
        if ((a=='d') || (a=='D'))
        {
            p=new numar;
            cout<<"valoare de adaugat x=";
            cin>>x;
            p->v=x;
            p->urm=NULL;
            u->urm=p;
            u=p;
        }
    }
    while((a=='d') || (a=='D'));
    return prim;
}

void parcurgere_lista (numar *prim)
{
    numar *p;
    int n=0;

    if (prim==NULL)
        cout<<"Lista este vida! "<<endl;
    else
    {

        cout<<"Lista de puncte este:"<<endl;
        for(p=prim; p ; p=p->urm)
        {
            n++;
            cout<<p->v<<" ";
        }
        cout<<endl<<"Numarul de puncte din lista este n="<<n<<endl;
    }
}

numar *stergere(numar *prim, int s)
{
    numar *p, *r;
    int c=0;
    while(prim->v==s)
    {
        c++;
        if(prim->urm != NULL)
            prim=prim->urm;
        else
        {
            prim=prim->urm;
            break;
        }
    }
    p=prim->urm;
    r=prim;
    while(p!=NULL)
    {
        if(p->v == s)
        {
            c++;
            r->urm=p->urm;
            p=p->urm;

        }
        else
        {
            r=p;
            p=p->urm;
        }
    }
    cout<<"Elementul de sters "<<s<<" a aparut de "<<c<<" ori"<<endl;
    return prim;

}

numar *adaugare_in_lista(numar *prim, int xa)
{
    numar *p;
    int op=1;
    cout<<"element de adaugat xa="<<xa<<endl;
    do
    {
        cout<<"1. Adauga xa la inceput" <<endl;
        cout<<"2.Adauga xa dupa un element din lista"<<endl;
        cout<<"3.Adauga xa la sfarsit"<<endl;
        cout<<"0. A terminat adaugarea!!!"<<endl;
        cout<<"Alege optiune op_liste=";
        cin>>op;
        switch(op)
        {
        case 1:

            p=new numar;
            p->v=xa;
            p->urm=prim;
            prim=p;
            cout<<"Lista dupa adaug la inceput ete:"<<endl;
            parcurgere_lista(prim);
            break;

        case 2:
            numar *p,*u;
            int x;
            cout<<"elementul dupa care adaugam x=";
            cin>>x;
            p=prim;
            while(p)
            {
                if(p->v==x)
                {
                    u=new numar;
                    u->v=xa;
                    u->urm=p->urm;
                    p->urm=u;
                    p=u;

                }
                p=p->urm;
            }
            parcurgere_lista(prim);
            break;

        case 3:
            p=prim;
            while(p)
            {
                u=p;
                p=p->urm;
            }
            p=new numar;
            p->v=xa;
            p->urm=NULL;
            u->urm=p;
            parcurgere_lista(prim);
            break;

        case 0:
            break;
        default:
            cout<<"optiune incorecta"<<endl;
            break;

        }
    }
    while(op!=0);
    return prim;
}
numar *modificare_elem(numar *prim,int m,int n)
{
    numar *c;
    int count;
    for(c=prim; c!=NULL; c=c->urm)
    {
        if(c->v==m)
        {
            c->v=n;
            count++;
        }
    }
    return prim;
}
numar *stergere_lista(numar *prim)
{
    numar *c;

    while(prim)
    {
        c=prim;
        prim=prim->urm;
        delete  c;
    }
    return prim;
}

//functii pentru liste dublu inlantuite


lista2 *creare_lista_dublu_inlantuita()
{
    int x,n;
    lista2 *cap;
    numar2 *c;
    cout<<"Primul element este x=";
    cin>>x;
    c=new numar2;
    c->v=x;
    c->prec=NULL;
    c->urm=NULL;
    cap=new lista2;
    cap->prim=c;
    cap->ultim=c;
    cout<<"Cate elemente scriem in lista n=";
    cin>>n;
    for(int i=1; i<=n; i++)
    {
        //citeste o valoare si o adauga in lista dupa ultimul element
        cout<<"Elementul al "<<i+1<<"-lea este x=";
        cin>>x;
        c=new numar2;
        c->v=x;
        c->prec=cap->ultim;
        c->urm=NULL;
        (cap->ultim)->urm=c;
        cap->ultim=c;
    }
    return cap;
}

void parcurgere_inainte(lista2 *cap)
{
    numar2 *c;
    // parcurgere prim catre ultim
    c=cap->prim;
    while(c!=NULL)
    {
        cout<<c->v<<" ";
        c=c->urm;
    }
    cout<<endl;
}

void parcurgere_inapoi(lista2 *cap)
{
    numar2 *c;
    c=cap->ultim;
    while(c!=NULL)
    {
        cout<<c->v<<" ";
        c=c->prec;
    }
    cout<<endl;
}

lista2 *adaugare_in_lista_dublu_inlantuita(lista2 *cap)
{
    int optiune=1,xa,y;
    numar2 *c, *p;
    int nrl=0;

    do
    {
        cout<<"1. Adauga la inceput."<<endl;
        cout<<"2. Adauga dupa element."<<endl;
        cout<<"3. Adauga la sfarsit."<<endl;
        cout<<"0. A terminat adaugarea"<<endl;
        cout<<"Optiunea este: ";
        cin>>optiune;
        switch (optiune)
        {
        case 1:
            cout<<"Valoare de adaugat xa = ";
            cin>>xa;
            c=new numar2;
            c->v=xa;
            c->prec=NULL;
            c->urm=cap->prim;
            (cap->prim)->prec=c;
            cap->prim=c;
            parcurgere_inainte(cap);
            break;

        case 2:
            cout<<"Valoare de adaugat xa = ";
            cin>>xa;
            cout<<"Valoare dupa care adaugam y = ";
            cin>>y;
            p=cap->prim;
            while (p!=NULL)
            {
                if (p->v == y)
                {
                    nrl++;
                    c=new numar2;
                    c->v=xa;
                    c->urm=NULL;
                    if (p->urm != NULL)
                    {
                        c->urm=p->urm;
                        (p->urm)->prec=c;
                    }
                    else cap->ultim=c;
                    c->prec=p;
                    p->urm=c;
                    p=c->urm;
                }
                else
                    p=p->urm;
            }
            cout<<"A adaugat "<<nrl<<"  elemente in lista"<<endl;
            parcurgere_inainte(cap);
            break;

        case 3:
            cout<<"Valoare de adaugat xa = ";
            cin>>xa;
            c=new numar2;
            c->v=xa;
            c->urm=NULL;
            c->prec=cap->ultim;
            (cap->ultim)->urm=c;
            cap->ultim=c;
            parcurgere_inainte(cap);
            break;
        case 0:
            cout<<"Am terminat de adaugat!"<<endl;
            break;
        default:
            cout<<"Optiune gresita!"<<endl;
            break;
        }
    }
    while(optiune!=0);
    return cap;
}

lista2 *stergere_din_lista_dublu_inlantuita(lista2 *cap)
{
    int s;
    numar2 *p, *desters;
    cout<<"Elementul de sters este s = ";
    cin>>s;
    // sterge elemente din capatul prim al listei daca au valoarea s
    // presupunem ca nu stergem dintr-o lista vida: cap->prim != NULL
    while ((cap->prim)->v == s)
    {
        desters=cap->prim;
        cap->prim=(cap->prim)->urm;
        (cap->prim)->prec=NULL;
        delete desters;
    }
    // nu mai este in capatul prim al listei valoarea s
    // parcurge lista dublu inlantuita si sterge elemente care contin valoarea s
    p=(cap->prim)->urm;
    while (p!=NULL)
    {
        if (p->v == s)//sterge elementul p din lista
        {
            if (p->urm == NULL)
            {
                desters=p;
                (p->prec)->urm=NULL;
                cap->ultim=p->prec;
                delete desters;
                p=(cap->ultim)->urm;
            }
            else
            {
                desters=p;
                (p->prec)->urm=p->urm;
                (p->urm)->prec=p->prec;
                p=p->urm;
                delete desters;
            }
        }
        else
            p=p->urm;
    }
    return cap;
}
//functii pentru stive
punct *creare_stiva()
{
    punct *prim, *p;
    float v;
    char a;

    prim=new punct;
    cout<<"Valoarea primului punct din stiva v= ";
    cin>>v;
    prim->x=v;
    prim->urm=NULL;
    do
    {
        cout<<"Adaugam element nou in stiva (d/n)? ";
        cin>>a;
        if ((a=='d') || (a=='D'))
        {
            cout<<"Valoare punct v= ";
            cin>>v;
            p=new punct;
            p->x=v;
            p->urm=prim;
            prim=p;
        }
    }
    while((a=='d') || (a=='D'));
    return prim;
}
void parcurgere_stiva(punct *prim)
{
    punct *c;
    c=prim;
    while(c)
    {
        cout<<c->x<<endl;
        c=c->urm;
    }

}
punct *adaugare_in_stiva(punct *prim)
{
    punct *p;
    p = new punct;
    float xa;
    cout<<"valoare de adaugat xa=";
    cin>>xa;
    p->x=xa;
    p->urm=prim;
    prim=p;

    return prim;
}
punct *stergere_din_stiva(punct *prim)
{
    punct *p;
    p=prim;
    prim=prim->urm;
    delete p;
    return prim;
}
// functii pentru coada
lista2 *creare_coada()
{
    lista2 *c;
    c=creare_lista_dublu_inlantuita();
    return c;
}
lista2 *adaugare_coada(lista2 *c)
{
    numar2 *p;
    int va;
    cout<<"valoare de adaugat este va=" <<endl;
    cin>>va;
    p=new numar2;
    p->v=va;
    p->prec=c->ultim;
    p->urm=NULL;
    (c->ultim)->urm=p;
    c->ultim=p;
    return c;
}
lista2 *stergere_coada(lista2 *c)
{
    numar2 *s;
    s=c->prim;
    ((c->prim)->urm)->prec=NULL;
    c->prim=(c->prim)->urm;
    delete s;

    return c;
}
// aplicatii liste
// // Crearea unei liste ordonate crescator
numar *creare_ordonata()
{
    int x,i;
    numar *cap,*u,*c,*p,*r;
    cout<<"Valoarea in capat de lista: ";
    cin>>x;
    cap=new numar;
    cap->v=x;
    cap->urm=NULL;
    u=cap;
    int n;
    cout<<"Numarul de elemente de adaugat este: ";
    cin>>n;
    for (i=0; i<n; i++)
    {
        cout<<"Valoarea de adaugat x= ";
        cin>>x;
        if(x<(cap->v))
        {
            c=new numar;
            c->v=x;
            c->urm=cap;
            cap=c;
        }
        if (x>(u -> v))
        {
            c=new numar;
            c->v=x;
            c->urm=NULL;
            u->urm=c;
            u=c;
        }
        if(x>(cap->v) && x<(u->v))
        {
            p=cap;
            r=NULL;
            while(p->v<=x)
            {
                r=p;
                p=p->urm;
            }
            c=new numar;
            c->v=x;
            c->urm=p;
            r->urm=c;
        }
    }
    return cap;
}
// Interclasarea a doua liste ordonate crescator
numar *interclasare_2liste(numar *L1, numar *L2)
{
    numar *L;
    numar *p1,*p2,*p3,*u,*c;
    L=new numar;
    if ((L1->v) < (L2->v))
    {
        L->v=L1->v;
        L->urm=NULL;
        p1=L1->urm;
        p2=L2;
    }
    else
    {
        L->v=L2->v;
        L->urm=NULL;
        p1=L1;
        p2=L2->urm;
    }
    u=L;
    while ((p1!=NULL) && (p2!=NULL))
    {
        if ((p1->v) < (p2->v))
        {
            c=new numar;
            c->v=p1->v;
            c->urm=NULL;
            u->urm=c;
            u=c;
            p1=p1->urm;
        }
        else
        {
            c=new numar;
            c->v=p2->v;
            c->urm=NULL;
            u->urm=c;
            u=c;
            p2=p2->urm;
        }
    }
    if(p1!=NULL)
    {
        while (p1!=NULL)
        {
            c=new numar;
            c->v=p1->v;
            c->urm=NULL;
            u->urm=c;
            u=c;
            p1=p1->urm;
        }
    }
    if (p2!=NULL)
    {
        while (p2!=NULL)
        {
            c=new numar;
            c->v=p2->v;
            c->urm=NULL;
            u->urm=c;
            u=c;
            p2=p2->urm;
        }
    }
    return L;
}
//functii pentru polinoame
monom *creare()
{
    monom *p, *q, *r;
    float c;
    int g;
    char dn;
    cout<<"Coeficientul primului monom din polinom coef = ";
    cin>>c;
    cout<<"Gradul primului monom din polinom grad = ";
    cin>>g;
    p=new monom;
    p->coef=c;
    p->grad=g;
    p->urm=NULL;
    q=p;
    do
    {
        cout<<"Adauga monoame in polinom [d/n]? ";
        cin>>dn;
        if ((dn == 'd') || (dn=='D'))
        {
            cout<<"Coeficientul monomului din polinom coef = ";
            cin>>c;
            cout<<"Gradul monomului din polinom grad = ";
            cin>>g;
            r=new monom;
            r->coef=c;
            r->grad=g;
            r->urm=NULL;
            q->urm=r;
            q=r;
        }
    }
    while((dn == 'd') || (dn=='D'));
    return p;
}

void parcurgere(monom *cap)
{
    monom *p;
    int semn=0;

    if (!cap)
        cout<<"Polinomul este vid! "<<endl;
    else
    {
        for(p=cap; p ; p=p->urm)
        {
            if ((semn == 1) && (p->coef > 0))
                cout<<"+";
            cout<<p->coef<<"*X^"<<p->grad;
            semn=1;
        }
    }
    cout<<endl;
}

monom *concatenare(monom *p1, monom *p2)
{
    monom *s, *p, *q, *u;

    s=new monom;
    s->coef=p1->coef;
    s->grad=p1->grad;
    s->urm=NULL;
    u=s;
    for(p=p1->urm; p; p=p->urm)
    {
        q=new monom;
        q->coef=p->coef;
        q->grad=p->grad;
        q->urm=NULL;
        u->urm=q;
        u=q;
    }
    for(p=p2; p; p=p->urm)
    {
        q=new monom;
        q->coef=p->coef;
        q->grad=p->grad;
        q->urm=NULL;
        u->urm=q;
        u=q;
    }
    return s;
}

monom *inmultire(monom *p1,monom *p2)
{
    monom *s, *p, *q, *u, *r;
    s= new monom;
    s->coef=0;
    s->grad=0;
    s->urm=NULL;
    u=s;
    for(p=p1; p; p=p->urm)
    {
        for(r=p2; r; r=r->urm)
        {
            q=new monom;
            q->coef=p->coef*r->coef;
            q->grad=p->grad+r->grad;
            q->urm=NULL;
            u->urm=q;
            u=q;
        }
    }
    p=s;
    s=s->urm;
    delete p;

    return s;
}

monom *reducere(monom *s)
{
    monom *p, *q, *u;

    for(p=s; p; p=p->urm)
    {
        u=p;
        for(q=p->urm; q ; q=q->urm)
        {
            if (p->grad == q->grad)
            {
                p->coef=p->coef + q->coef;
                u->urm=q->urm;
                delete q;
                q=u;
            }
            u=q;
        }
    }
    return s;
}
bool Validare_paranteze(char E[20])  //functia este de tip bool- returneaza 1- A sau 0- F
{

    char x; //caracterul intermediar
    int n;  //dimensiunea expresiei/sirului

    cout<<"Dim. expresie: ";
    cin>>n;

    stack<char> sta; //declar stack-ul cu tipul char
    //Stack-ul este in acest caz o stiva/container

    cout<<"Expresia este: ";
    //citim Expresia E(combinatie de simboluri)
    for(int i=0; i<n; i++)
        cin>>E[i];

    for(int i = 0; i < n; i++)
    {

        if(E[i] == '(' || E[i] == '[' || E[i] == '{')  //daca Expresia are paranteze deschise la inceput
        {
            // pune parantezele deschise(daca ele exista) pe stack
            sta.push(E[i]); //push(x) este functia care adauga elementul aferent x in capul Stack-ului
            continue; //contiuna iteratia
        }

        // caracterul curent este obligatoriu o paranteza inchisa/deschisa... sau un alt char
        //Stack-ul nu poate fi gol!

        if(sta.empty()) // empty() verifica daca lista este goala
            return 0; //returneaza 0(fals)

        switch(E[i])
        {

        case ')':

            x = sta.top(); //lui x atribuim valoarea din capul Stack-ului(top)
            sta.pop(); //trebuie precizat ca functia pop() sterge elementul din capul Stack-ului

            if (x == '{' || x == '[') //{) sau [) nu sunt expresii valide
                return 0;
            break;

        //aceeasi logica la restul!

        case ']':

            x = sta.top();
            sta.pop();

            if (x == '(' || x == '{')
                return 0;
            break;


        case '}':

            x = sta.top();
            sta.pop();

            if (x == '(' || x == '[')
                return 0;
            break;

        }
    }

    // verifica si returneaza valoarea
    return(sta.empty());
}

int main()
{

    int op; // optiunea pentru capitol sau iesire din program
    int op1; // optiune capitol 1
    int op2;// optiune capitol 2
    int op3; // optiune capitol 3
    float a,b,c; //coeficienti ecuatie
    int n,i;
    int v[100];
    float x[20];
    int AL, AC, BL, BC;
    int nr;
    int numarul,baza;
    int y,p;
    char E[20]; //expresia este un sir de caractere!
    do
    {
        cout<<"PROGRAME ASD"<<endl<<endl;
        cout<<"Copaceanu Vlad-Constantin"<<endl;
        cout<<"1. Probleme simple de programare"<<endl;
        cout<<"2. Algoritmi de sortare"<<endl;
        cout<<"3. Liste, stive, cozi,polinoame"<<endl;
        cout<<"4. Grafuri"<<endl;
        cout<<"0.Incheiere program! "<<endl;

        //citeste optiune
        cout<<"Citeste optiune op = ";
        cin>>op;
        cout<<endl<<endl;

        switch (op)
        {
        case 1:
            do
            {
                cout<<"1. PROBLEME SIMPLE DE PROGRAMARE"<<endl;
                cout<<"1.1. Rezolvare completa ecuatie de gradul al doilea"<<endl;
                cout<<"1.2. Inmultire de matrici"<<endl;
                cout<<"1.3. Verificare numar prim"<<endl;
                cout<<"1.4. Trecerea unui numar din baza 10 in baza b=2,...,9"<<endl;
                cout<<"1.0. Incheiere capitol 1"<<endl;
                cout<<"Optiune capitol 1 op1 =  ";
                cin>>op1;

                switch (op1)
                {
                case 1:
                    cout << endl << "Rezolva ecuatie a*x^2+b*x+c=0" << endl;
                    cout << "a= ";
                    cin >> a;
                    cout << endl;
                    cout << "b= ";
                    cin >> b;
                    cout << endl;
                    cout << "c= ";
                    cin >> c;
                    cout << endl;
                    rezolva_ec2(a, b, c);
                    break;

                case 2:
                    cout << endl << "Rezolva inmultirea matricilor A si B" << endl;
                    cout << "Numarul de linii pentru A = ";
                    cin >> AL;
                    cout << "Numarul de coloane pentru A = ";
                    cin >> AC;
                    cout << "Numarul de linii pentru B = ";
                    cin >> BL;
                    cout << "Numarul de coloane pentru B = ";
                    cin >> BC;
                    cout << endl;
                    inmultire_matricilor(AL, AC, BL, BC);
                    break;

                case 3:
                    cout << endl << "Verificare de primalitate: ";
                    cout << endl << "Introduceti numarul: ";
                    cin >> nr;
                    cout << endl;
                    if (prim(nr) == true)
                        cout << "Numarul " << nr << " este prim. " << endl;
                    else
                        cout << "Numarul " << nr << " nu este prim. " << endl;
                    break;

                case 4:
                    cout << endl << "Schimbarea din baza 10 in alta baza din intervalul [2; 9]" << endl;
                    cout << "Introduceti numarul pe care doriti sa il schimbati: ";
                    cin >> numarul;
                    cout <<
                         "Introduceti baza dorita: ";
                    cin >> baza;
                    schimba_baza(numarul, baza);
                    break;

                case 0:
                    cout<<
                        "Iesire din capitol 1."<<endl;
                    break;

                default:
                    cout<<"Optiune invalida capitol 1."<<endl;
                    break;
                }

            }
            while(op1 != 0);
            cout<<endl<<endl;
            break;

        case 2: // Algoritmi de sortare

            do
            {
                cout<<endl<<"2. Algoritmi de sortare"<<endl;
                cout<<"      2.1. Algoritmul Bubble Sort"<<endl;
                cout<<"      2.2. Algoritmul Selection Sort"<<endl;
                cout<<"      2.3. Algoritmul Counting Sort"<<endl;
                cout<<"      2.4. Algoritmul Merge Sort"<<endl;
                cout<<"      2.5. Algoritmul QuickSort"<<endl;
                cout<<"      2.6. Algoritmul Insertion Sort"<<endl;
                cout<<"      2.7. Algoritmul Shell Sort"<<endl;
                cout<<"      2.8. Algoritmul Radix Sort"<<endl;
                cout<<"      2.9. Cautare secventiala"<<endl;
                cout<<"      2.10. Cautare binara"<<endl;
                cout<<"      2.0. Iesire meniu Algoritmi de sortare!"<<endl;

                cout<<"Optiune algoritmi de sortare: ";
                cin>>op2;

                switch (op2)
                {
                case 1: //Bubble Sort
                    cout <<
                         "Dimensiune sir n= ";
                    cin >> n;
                    for (i = 0; i <= n - 1; i++)
                    {
                        cout << "v[" << i << "]= ";
                        cin >> v[i];
                    }
                    Bubble_Sort(n, v);
                    break;

                case 2: //Selection Sort
                    cout<<"Dimensiune sir n= ";
                    cin>>n;
                    for(i=0; i<=n-1; i++)
                    {
                        cout<<"v["<<i<<"]= ";
                        cin>>v[i];
                    }
                    Selection_Sort(n,v);
                    break;

                case 3: //Counting Sort
                    cout<<"Dimensiune sir n= ";
                    cin>>n;
                    for(i=0; i<=n-1; i++)
                    {
                        cout<<"v["<<i<<"]= ";
                        cin>>v[i];
                    }
                    Counting_Sort(n,v);
                    break;

                case 4: //Merge Sort
                    cout<<"Dimensiune sir n= ";
                    cin>>n;
                    for(i=0; i<=n-1; i++)
                    {
                        cout<<"v["<<i<<"]= ";
                        cin>>v[i];
                    }
                    Merge_Sort(v,0,n-1);
                    cout<<endl<<"Sirul ordonat este:"<<endl;
                    for(i=0; i<n; i++)
                        cout<<v[i]<<' ';
                    cout<<endl;
                    break;

                case 5: //Quick Sort
                    cout<<
                        "Dimensiune sir n= ";
                    cin>>n;
                    for(i=0; i<=n-1; i++)
                    {
                        cout<<"v["<<i<<"]= ";
                        cin>>v[i];
                    }
                    Quick_Sort(v,0,n-1);
                    cout<<endl<<"Sirul ordonat este:"<<endl;
                    for(i=0; i<n; i++)
                        cout<<v[i]<<' ';
                    cout<<endl;
                    break;

                case 6: //Insertion Sort
                    cout<<
                        "Dimensiune sir n= ";
                    cin>>n;
                    for(i=0; i<=n-1; i++)
                    {
                        cout<<"v["<<i<<"]= ";
                        cin>>v[i];
                    }
                    Insertion_Sort(n,v);
                    cout<<endl<<"Sirul ordonat este:"<<endl;
                    for(i=0; i<n; i++)
                        cout<<v[i]<<' ';
                    cout<<endl;
                    break;

                case 7: //Shell Sort
                    cout<<
                        "Dimensiune sir n= ";
                    cin>>n;
                    for(i=0; i<=n-1; i++)
                    {
                        cout<<"v["<<i<<"]= ";
                        cin>>v[i];
                    }
                    Shell_Sort(n,v);
                    cout<<endl<<"Sirul ordonat este:"<<endl;
                    for(i=0; i<n; i++)
                        cout<<v[i]<<' ';
                    cout<<endl;
                    break;

                case 8: //Radix Sort
                    cout<<
                        "Dimensiune sir n= ";
                    cin>>n;
                    for(i=0; i<=n-1; i++)
                    {
                        cout<<"v["<<i<<"]= ";
                        cin>>v[i];
                    }
                    Radix_Sort(n,v);
                    cout<<endl<<"Sirul ordonat este:"<<endl;
                    for(i=0; i<n; i++)
                        cout<<v[i]<<' ';
                    cout<<endl;
                    break;
                case 9: //Cautare Secventiala
                    cout<<
                        "Dimensiune sir n= ";
                    cin>>n;
                    for(i=0; i<=n-1; i++)
                    {
                        cout<<"v["<<i<<"]= ";
                        cin>>v[i];
                    }
                    cout<<"Introduceti elementul pe care doriti sa il cautati: ";
                    cin>>y;
                    Cautare_Secventiala(n,v,y);
                    break;

                case 10: //Cautare Binara
                    cout<<
                        "Dimensiune sir n= ";
                    cin>>n;
                    for(i=0; i<=n-1; i++)
                    {
                        cout<<"v["<<i<<"]= ";
                        cin>>v[i];
                    }
                    cout<<"Introduceti elementul pe care doriti sa il cautati: ";
                    cin>>y;
                    Quick_Sort(v,0,n);
                    cout<<endl<<
                        "Sirul ordonat este:"<<endl;
                    for(i=0; i<n; i++)
                        cout<<v[i]<<' ';
                    cout<<endl;
                    Cautare_Binara(0,n-1,v,y);
                    break;


                case 0:
                    cout<<
                        "Incheiere capitol 2!"<<endl;
                    break;

                default:
                    cout<<endl<<"Optiune invalida!"<<endl<<endl;
                    break;
                } // end switch op2
            }
            while(op2);
            break;

        case 3: //liste dinamice
            do
            {
                cout<<endl<<"3. Liste dinamice. Aplicatii"<<endl<<endl;
                cout<<"   3.1. Liste simplu inlantuite"<<endl;
                cout<<"   3.2. Liste dublu inlantuite"<<endl;
                cout<<"   3.3. Stive"<<endl;
                cout<<"   3.4. Cozi"<<endl;
                cout<<"   3.5. Creearea unei liste ordonata crescator.   "<<endl;
                cout<<"   3.6.Interclasarea a doua liste ordonate crescator.  "<<endl;
                cout<<"   3.7. Operatii cu polinoame: creare, parcurgere, concatenare, inmultire,suma,reducere."<<endl;
                cout<<"   3.8. Verificarea corectitudinii parantezelor intr-o expresie aritmetica."<<endl;
                cout<<"   3.0. Inchidere capitol 3"<<endl;

                cout<<endl<<"Optiune capitol 3: ";
                cin>>op3;
                switch (op3)
                {
                case 1: // Liste simplu inlantuite
                    numar *prim_lista;

                    // creare lista
                    prim_lista=creare_lista();
                    //pargurgere lista
                    cout<<
                        "Lista dupa creare este: ";
                    parcurgere_lista(prim_lista);
                    cout<<endl;
                    // adaugare in lista
                    int xa;
                    // adaugare la  lista
                    cout<<
                        "Valoare de adaugat in lista xa= ";
                    cin>>xa;
                    prim_lista=adaugare_in_lista(prim_lista,xa);
                    cout<<"Lista dupa adaugare este :"<<endl;
                    parcurgere_lista(prim_lista);
                    // stergere din lista
                    int s;
                    cout<<
                        "Sterge elementele cu valoarea s=";
                    cin>>s;
                    prim_lista=stergere(prim_lista,s);

                    // parcurgere lista dupa stergere
                    cout<<"Lista dupa stergere este: "<<endl;
                    parcurgere_lista(prim_lista);
                    cout<<endl;
                    //modificare element
                    int n,m;
                    cout<<
                        "elementul de modificat este n=";
                    cin>>n;
                    cout<<"se modifica cu elementul m=";
                    cin>>m;
                    prim_lista=modificare_elem(prim_lista,n,m);
                    cout<<"lista dupa modificare este: "<<endl;
                    parcurgere_lista(prim_lista);
                    cout<<endl;

                    //stergere lista


                    prim_lista=stergere_lista(prim_lista);
                    parcurgere_lista(prim_lista);
                    break;



                case 2: // Liste dublu inlantuite
                    lista2 *l2;

                    // creare lista dublu inlantuita
                    l2=creare_lista_dublu_inlantuita();
                    cout<<
                        "Lista inainte este: ";
                    parcurgere_inainte(l2);
                    cout<<
                        "Lista inapoi este: ";
                    parcurgere_inapoi(l2);

                    //adaugare elemente in lista dublu inlantuita

                    l2=adaugare_in_lista_dublu_inlantuita(l2);
                    cout<<
                        "Dupa adaugare:"<<endl;
                    cout<<
                        "Lista inainte este: ";
                    parcurgere_inainte(l2);
                    cout<<
                        "Lista inapoi este: ";
                    parcurgere_inapoi(l2);

                    // stergere elemente cu valoare data din lista dublu inlantuita

                    l2=stergere_din_lista_dublu_inlantuita(l2);
                    cout<<
                        "Dupa stergere:"<<endl;
                    cout<<
                        "Lista inainte este: ";
                    parcurgere_inainte(l2);
                    cout<<
                        "Lista inapoi este: ";
                    parcurgere_inapoi(l2);

                    break;
                case 3: //stive
                    punct *stiva;
                    stiva=creare_stiva();
                    cout<<
                        "Stiva este: "<<endl;
                    parcurgere_stiva(stiva);
                    //adaugare stiva
                    stiva=adaugare_in_stiva(stiva);
                    cout<<
                        "Stiva dupa adaugare este: "<<endl;
                    parcurgere_stiva(stiva);
                    //stergere din stiva
                    stiva=stergere_din_stiva(stiva);
                    cout<<
                        "Stiva dupa stergere este: "<<endl;
                    parcurgere_stiva(stiva);


                    break;
                case 4: //cozi
                    lista2 *coada;
                    coada=creare_coada();
                    cout<<
                        "coada este :"<<endl;
                    parcurgere_inainte(coada);
                    //adaugare in coada
                    coada=adaugare_coada(coada);
                    cout<<
                        "coada dupa adaugare este: "<<endl;
                    parcurgere_inainte(coada);
                    //stergere din coada
                    coada=stergere_coada(coada);
                    cout<<
                        "coada dupa stergere este:"<<endl;
                    parcurgere_inainte(coada);

                    break;
                case 5: // creare de lista ordonata

                {
                    numar *a;
                    a=creare_ordonata();
                    while (a!=NULL)
                    {
                        cout<<a->v;
                        a=a->urm;
                        cout<<" ";
                    }
                }

                break;
                case 6: //interclasarea

                {
                    numar *a,*b,*c;
                    a=creare_ordonata();
                    b=creare_ordonata();
                    c=interclasare_2liste(a,b);
                    while (c!=NULL)
                    {
                        cout<<c->v;
                        c=c->urm;
                        cout<<" ";
                    }
                }

                break;
                case 7: //polinoame
                    monom *p1, *p2; // listele pentru cele doua polinoame
                    monom *suma;
                    monom *produs;

                    // Creaza cele doua polinoame
                    cout<<"Primul polinom"<<endl;
                    p1=creare();
                    cout<<"Al doilea polinom"<<endl;
                    p2=creare();
                    cout<<"Primul polinom : ";
                    parcurgere(p1);
                    cout<<endl;
                    cout<<"Al doilea polinom :";
                    parcurgere(p2);

                    // adunarea polinoamelor date;
                    // concatenam listele date intr-o singura lista

                    suma=concatenare(p1,p2);
                    cout<<endl<<"Suma fara reducerea termenilor este s = ";
                    parcurgere(suma);

                    // reducem termenii asemenea

                    suma=reducere(suma);
                    cout<<endl<<"Suma polinoamelor este s = ";
                    parcurgere(suma);

                    // inmultirea polinoamelor

                    produs=inmultire(p1,p2);
                    cout<<endl<<"Produsul fara reducerea termenilor este p = ";
                    parcurgere(produs);

                    // reducem termenii asemenea in produs:

                    produs=reducere(produs);
                    cout<<endl<<"Produsul polinoamelor este p = ";
                    parcurgere(produs);

                    break;
                case 8:
                    if(Validare_paranteze(E)==1) //daca expresia este valida!
                        cout << "Expresie valida!";
                    else
                        cout << "Expresie invalida-trebuie sa contina paranteze plasate corect!";

                case 0: //incheiere capitol 3
                    cout<<
                        "Incheiere capitol 3!"<<endl<<endl;
                    break;
                default :
                    cout<<"Optiune invalida capitol 3!"<<endl<<endl;
                    break;
                }//end switch capitol 3
            }
            while(op3);
            break;
            while(op!=0);
            break;
        case 0:
            // iesire din programul principal
            cout<<"La revedere!"<<endl;
            break;

        default:
            cout<<"Optiune invalida meniu principal!"<<endl;
            break;
        } // end switch principal (capitole)
    }
    while (op !=0 );
    return 0;
}
