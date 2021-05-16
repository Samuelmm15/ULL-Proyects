 /*
 *  GRAFO.CPP - Plantilla para la implementaci�n de la clase GRAFOS
 *
 *
 *  Autor: Samuel Martín Morales
 *  Cursos: 2012-2021
 */

#include "grafo.h"

void GRAFO::destroy() {
	m = 0;
    n = 0;
    dirigido = 0;
    LS.clear();
    LP.clear();
};

void GRAFO::build (char nombrefichero[85], int &errorapertura) { /// COMPROBAR POR QUE LA ACTUALIZACIÓN NO FUNCIONA
    ElementoLista dummy;
	ifstream textfile;
	textfile.open(nombrefichero);

	if (textfile.is_open()) {
        errorapertura = 0; 
		// leemos por conversion implicita el numero de nodos, arcos y el atributo dirigido
		textfile >> (unsigned &) n >> (unsigned &) m >> (unsigned &) dirigido;
		// los nodos internamente se numeran desde 0 a n-1
		// creamos las n listas de sucesores
        if (dirigido) {
            LS.resize(n);
            LP.resize(n);
            int i, j, k;
	        // leemos los m arcos
		    for (k = 0;k < m; k++) {
			    textfile >> (unsigned &) i  >> (unsigned &) j >> (int &) dummy.c; //damos los valores a dummy.j y dummy.c
                dummy.j = j - 1;
                dummy.c = dummy.c;
			    //situamos en la posici�n del nodo i a dummy mediante push_backM
                LS[i - 1].push_back(dummy);

                dummy.j = i - 1;
                dummy.c = dummy.c;
                LP[j - 1].push_back(dummy);
			    //pendiente de hacer un segundo push_back si es no dirigido. O no.
			    //pendiente la construcci�n de LP, si es dirigido
            }
            textfile.close();

        } else if (!dirigido) {
            LS.resize(n);
            int i,j;
            for (int k = 0; k < m; k++) {
                textfile >> (unsigned &) i  >> (unsigned &) j >> (int &) dummy.c;
                dummy.j = j - 1;
                dummy.c = dummy.c;
                LS[i - 1].push_back(dummy);

                dummy.j = i - 1;
                dummy.c = dummy.c;
                LS[j - 1].push_back(dummy);
            }
            textfile.close();
        }

    } else if (!textfile.is_open()){
        errorapertura = 1;
        cout << "<<ERROR>> El archivo introducido no se ha encontrado." << endl;
        }			
};

void GRAFO::ListaPredecesores() {
    ElementoLista dummy;
    LP.resize(n);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < LS[i].size(); j++) {
            dummy.j = i;
            LP[LS[i][j].j].push_back(dummy);
        }
    }
};

GRAFO::~GRAFO() {
	destroy();
};

GRAFO::GRAFO(char nombrefichero[85], int &errorapertura) {
	build (nombrefichero, errorapertura);
};

void GRAFO:: actualizar (char nombrefichero[85], int &errorapertura) {
    //Limpiamos la memoria dinamica asumida en la carga previa, como el destructor
    destroy();
    //Leemos del fichero y actualizamos G con nuevas LS y, en su caso, LP
    build(nombrefichero, errorapertura);
};

unsigned GRAFO::Es_dirigido() {
    return dirigido;
};

void GRAFO::Info_Grafo() {
    if (dirigido == 1) {
        cout << "Grafo dirigido";
    } else {
        cout << "Grafo no dirigido";
    }
    cout << " | nodos " << n << " | ";
    if (dirigido == 1) {
        cout << "arcos ";
    } else {
        cout << "aristas ";
    }
    cout << m << " " << endl;
    cout << endl;
};

void Mostrar_Lista(vector<LA_nodo> L) {
    for (int i = 0; i < L.size(); i++) {
        cout << endl << "[" << i + 1 << "] : {";
        for (int j = 0; j < L[i].size(); j++) {
            if (j != 0) {
                cout << "," << " ";
            }
            cout << L[i][j].j + 1;
        }
        cout << "}";
    }
    cout << endl;
};

void GRAFO :: Mostrar_Listas (int l) {
    if (l == 0 || l == 1) {
        Mostrar_Lista(LS);
    } else if (l == -1) {
        Mostrar_Lista(LP);
    }
};

void GRAFO::Mostrar_Matriz() {//Muestra la matriz de adyacencia, tanto los nodos adyacentes como sus costes

};

void GRAFO::dfs_num(unsigned i, vector<LA_nodo>  L, vector<bool> &visitado, vector<unsigned> &prenum, unsigned &prenum_ind, vector<unsigned> &postnum, unsigned &postnum_ind) { //Recorrido en profundidad recursivo con recorridos enum y postnum 
	visitado[i] = true;
    prenum[prenum_ind++] = i;//asignamos el orden de visita prenum que corresponde el nodo i
     for (unsigned j = 0; j < L[i].size(); j++) {
        if (!visitado[L[i][j].j]) {
            dfs_num(L[i][j].j, L, visitado, prenum, prenum_ind, postnum, postnum_ind);
        }
        postnum[postnum_ind++] = i;//asignamos el orden de visita posnum que corresponde al nodo i
    } 
};

void GRAFO::RecorridoProfundidad() {
    /// creación e inicialización de variables y vectores
    unsigned i = 0;
    vector<bool> visitado;
    vector<unsigned> prenum;
    prenum.resize(n); 
    unsigned prenum_ind;
    vector<unsigned> postnum;
    postnum.resize(n);
    unsigned postnum_ind;
    /// solicitud al usuario del nodo inicial del recorrido en profundidad
    cout << "Introduzca el nodo inicial para la realización del recorrido en profundidad: ";
    cin >> i;


    for (int v = 0; v < n; v++) {
        visitado.push_back(false);
        prenum_ind = 0;
        postnum_ind = 0;
    }
    for (int v = i; v <= n; v++) {
        if (visitado[v] == false) {
           dfs_num(v, LS, visitado, prenum, prenum_ind, postnum, postnum_ind);
        } 
    }
    
    /// mostrar en pantalla el preorden
    cout << endl;
    cout << "El pre-orden es: " << endl;
    for (int i = 0; i < prenum.size(); i++) {
        cout << prenum.at(i) << " ";
    }
    cout << endl;
    /// mostrar en pantalla el postorden
    cout << endl;
    cout << "El post-orden es: " << endl;
    for (int i = 0; i < postnum.size(); i++) {
        cout << postnum.at(i) << " ";
    }
    cout << endl; 
};

void GRAFO::bfs_num( unsigned i, /*nodo desde el que realizamos el recorrido en amplitud */ vector<LA_nodo>  L, /*lista que recorremos, LS o LP; por defecto LS */ vector<unsigned> &pred, /*vector de predecesores en el recorrido */ vector<unsigned> &d) { /*vector de distancias a nodo i+1 */
//Recorrido en amplitud con la construcci�n de pred y d: usamos la cola
    vector<bool> visitado; //creamos e iniciamos el vector visitado
    visitado.resize(n, false);  
    visitado[i] = true;
 
    pred.resize(n, 0); //creamos e inicializamos pred y d
    d.resize(n, 0);
    pred[i] = i;
    d[i] = 0;

    queue<unsigned> cola; //creamos e inicializamos la cola
    cola.push(i);//iniciamos el recorrido desde el nodo i+1
 
    while (!cola.empty()) { //al menos entra una vez al visitar el nodo i+1 y contin�a hasta que la cola se vac�e
       unsigned k = cola.front(); //cogemos el nodo k+1 de la cola
        cola.pop(); //lo sacamos de la cola
        //Hacemos el recorrido sobre L desde el nodo k+1
        for (unsigned j=0;j<L[k].size();j++) {
            //Recorremos todos los nodos u adyacentes al nodo k+1
            //Si el nodo u no est� visitado
            //Lo visitamos
            //Lo metemos en la cola
            //le asignamos el predecesor
            //le calculamos su etiqueta distancia
            }
        //Hemos terminado pues la cola est� vac�a
    }
};

void RecorridoAmplitud() { //Construye un recorrido en amplitud desde un nodo inicial


};

void GRAFO::FloydWarshall() {
    vector<LA_nodo> P;

    /// Creamos P
    P.resize(n);
    for (unsigned i = 0; i < n; i++)
        P[i].resize(n);
    for (unsigned i = 0; i < n; i++)
        for (unsigned j = 0; j < n; j++) {
            if (i != j) {
                P[i][j].j = 0;
                P[i][j].c = maxint;
            }
            else {
                P[i][j].c = 0;
                P[i][j].j = i;
            }
        }
    
    for (unsigned i = 0; i < n; i++) {
        for (unsigned j = 0; j < LS[i].size(); j++) {
            P[i][LS[i][j].j].j = i;
            P[i][LS[i][j].j].c = LS[i][j].c;
        }
    }

    /// monstrar las matrices y los caminos mínimos
    
};








