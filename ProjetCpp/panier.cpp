#include "panier.h"

panier::panier()
{

}
panier::~panier(){
    for(int i= 0; i<tabEq.size();i++) delete tabEq[i];
}

void panier::Ajouter(Equipement * eq){
    tabEq.push_back(eq);
}
void panier::Supprimer(Equipement * eq){
    for(int i= 0; i<tabEq.size();i++){
        if(tabEq[i]->getid()== eq->getid()) tabEq.remove(i);
    }
}
int panier::rechercher(QString id){
    for(int i=0;i<tabEq.size();i++){
        if(tabEq[i]->getid()== id) return i;
    }
    return -1;
}
