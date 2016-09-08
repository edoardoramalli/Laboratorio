//
// Created by Edoardo Ramalli on 26/07/16.
//

int cifraIndex(int n,int index){
    int cifra=0;
    int k=0;
    for(int i=n ;i>0 && k!=index;i=i/10){
        k++;
        cifra=i%10;
    }
    return cifra;
}