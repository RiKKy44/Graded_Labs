#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char *data;
    int length;
}wishlist;



int main(void){

}


wishlist create_wishlist(const char *l){
    wishlist wl;
    if (l==NULL||*l=='\0'){
        wl.data = NULL;
        wl.length =0;
    }
    int size = (sizeof(l)/sizeof(char)) - 1;
    wl.length = size;
    wl.data = malloc(sizeof(char)*size);
    memcpy(wl.data,l,wl.length);
    return wl;
}   
void print_wishlist(const wishlist* w){
    if (w==NULL||w->data == NULL||w->length == 0){
        printf("Empty\n");
        return;
    }
    for (int i=0;i<w->length;i++){
        if(w->data[i] == ' '){
            putchar('\n');
            continue;
        }
        putchar(w->data[i]);
        
    }
}
void destroy_wishlist(wishlist *w){
        if (w != NULL && w->data != NULL) {
            free(w->data);
            w->data = NULL;
            w->length = 0;
}
int append_presents(wishlist *w, const char *l){
    
}