#include "Grafo.h"


Grafo::Grafo(){
	
}

Grafo::~Grafo(){
	
}


bool Grafo::vacio(){
    if (this->adyasencia.lista_vacia()){
        return true;
    }
    return false;
}

Vertice *Grafo::getVertice(string nombre){
	unsigned pos;
	Vertice<Vuelos> *aux;
    for( pos=0; pos<this->adyasencia.get_tam(); pos++){
    	aux=*adyasencia.get_dato(pos);
        if ( *aux.get_nombre()== nombre){
            return aux;
        }
        aux = aux->get_sig_vertice();
    }
    return NULL;
}

void Grafo::inserta_vertice(string nombre){
    Vertice<Vuelos> *nuevo = new Vertice(nombre);
    this->adyasencia.insert(nuevo);
}

void Grafo::insertaArista(Arista *arisata){
	Vertice<Vuelos> *aux;
	aux=this->getVertice(*arista.get_origin);
	*aux.aristas.insert(arista);
}


void Grafo::listaAdyacencia(){
	
    Vertice<Vuelos> *vertAux;
    Vertice<Vuelos> *ady;
    Aristas<Vuelos> *arisAux;
    
    unsigned pos=1;
    
    vertAux = this->adyasencia.get_dato(pos);
    
	while(vertAux != NULL){
    	
        cout<<*vertAux->get_nombre()<<"->";
        unsigned pos2=1;
        
        while(pos2<*vertAux.aristas.get_tam()){
        	
        	arisAux=vertAux.aristas.get_dato(pos2);
        	ady=*arisAux.get_adyacente();
            cout<<*ady.get_nombre()<<"->";
            pos2++
        }
        cout<<endl;
        pos++;
    }
}


Lista<Etiqueta<Vuelos>> Grafo::camino_minimo(string origen, string destino, char t){
	
	Lista<Etiqueta<Vuelos>> camino_minimo;
    Lista<Etiqueta<Vuelos>> etiquetas;
    
    Etiqueta<Vuelos> *cargaEt;    
    Arista<Vuelos> *cargaAri;
    Vertice<Vuelos> *cargaVert;
    
    Vertice<Vuelos> *auxV; 
    Etiqueta<Vuelos> auxcargv;
    Vuelos auxVue;
    
    unsigned posOr, posFin;
    unsigned  posAr, posEt, posVer;
    
	
    
    for( posVer=1; posVer<this->adyasencia.get_tam(); posVer++){
    	
    	*cargaVert=this->adyasencia.get_nodo(posVer);
    	
    	*cargaEt.invariante=false;
    	if(*cargaVert.get_nombre()==origen){
    		posOr=posVer;
    		*cargaEt.invariante=true;
		}
		
		if(*cargaVert.get_nombre()==destino){
			posFin=posVer;
		}
		*cargaEt.nombre_vertice=cargaVert.get_nombre();
		etiquetas.insert(cargaEt);
		
	}
    
    posEt=0;
    auxVue.set_precio(0);
    auxVue.set_tiempo(0);
    cargaEt.peso_llegada=auxVue;
    posVer=posOr;
    
    cargaVert=this->adyasencia.get_dato(posVer);
    
    while( cargaVert!=this->adyasencia.get_dato(posFin)){
    	
		cargaVert=this->adyasencia.get_dato(posVer);
		
    	for( posAr=1; posAr<(cargaVert->aristas.get_tam()); posAr++){
    		
    		cargaAri=cargaVert->aristas.get_dato(posAr);
    		auxV=cargaAri.get_adyacente();
    		
    		posEt=0;
    		while(auxV->get_nombre()!=cargaEt->nombre_vertic){
    			posEt++;
        	    cargaEt=etiquetas.get_dato(posEt);
    	    }
    	    
    	    auxVue=cargaAri->get_vuelo();
    	    cargaEt->peso_llegada=(cargaEt->peso_llegada+auxVue);
    	    if(((auxcargv->get_tiempo() < cargaEt->peso_llegada.get_tiempo()) && (t =='t'))&&(!cargaEt.invariante)) etiquetas.set_dato(posEt,*cargaEt);
    	    if(((auxcargv->get_precio() < cargaEt->peso_llegada.get_precio()) && (t =='p'))&&(!cargaEt.invariante)) etiquetas.set_dato(posEt,*cargaEt);
		}
    	 for(posEt=1;posEt<(etiquetas.get_tam()-1);posEt++){
        	cargaEt=etiquetas.get_dato(posEt);
        	auxcargv=cargaEt;
        	if(((auxcargv->get_tiempo() < cargaEt->peso_llegada.get_tiempo()) && (t =='t'))&&(!cargaEt.invariante)){
        		auxcargv=cargaEt;
        		posVer=posEt;
        	}
    	    if(((auxcargv->get_precio() < cargaEt->peso_llegada.get_precio()) && (t =='p'))&&(!cargaEt.invariante)){
    	    	auxcargv=cargaEt;
        		posVer=posEt;
    	    }
		}
	    auxcargv->invariante=true;
	    camino_minimo.insert(auxcargv);
    }
    
    return camino_minimo;
}
