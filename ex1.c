#include <stdio.h>
#include <string.h>
#define MAX 50

struct Playlists {
    char nomePlaylist[40];
    char nomeCriador[40];
    int numMusicas;
    double tempoPlaylist;
};

void menu(struct Playlists playlist[MAX]);
void criarNovaPlaylist(struct Playlists playlist[MAX], int *numeroPlaylists);
void excluirPlaylist(struct Playlists playlist[MAX]);
void adicionarMusica(struct Playlists playlist[MAX]);

int main(){
    struct Playlists playlist[MAX];

    menu(playlist);

}

void menu(struct Playlists playlist[MAX]){
    int opcao;
    int numeroPlaylists = 0;

    
    do
    {
        printf("-----------------\n");
        printf("[1]-Criar Nova Playlist\n");
        printf("[2]-Excluir Playlist\n");
        printf("[3]-Adicionar Música\n");
        printf("[4]-Remover Música\n");
        printf("[5]-Exibir Playlists\n");
        printf("[6]-Sair\n");
        printf("-----------------\n");
        scanf("%d", &opcao);
        switch (opcao)
        {
        case 1:
            criarNovaPlaylist(playlist, &numeroPlaylists);
            break;
        case 2:
            excluirPlaylist(playlist);
            break;
        case 3:
            adicionarMusica(playlist);
            break;
        }

    } while (opcao != 6);
}

void criarNovaPlaylist(struct Playlists playlist[MAX], int *numeroPlaylists){
    int existe = 0;

    printf("digite o nome da Playlist:");
    do
    {
        scanf("%s", &playlist[*numeroPlaylists].nomePlaylist);
        for(int i = 0; i < MAX; i++){
            if(strcmp(playlist[*numeroPlaylists].nomePlaylist, playlist[i].nomePlaylist) == 1){
                printf("já existe uma playlist com esse nome\n");
                printf("por favor digite outro nome");
                existe = 1;
            }else{
                existe = 0;
            }
        }   
    } while(existe == 1);

    printf("digite o nome do criador da playlist:");
    scanf("%s", &playlist[*numeroPlaylists].nomeCriador);
    printf("digite o número de músicas ");
    scanf("%d", &playlist[*numeroPlaylists].numMusicas);
    printf("digite o tempo total da playlist(em minutos):");
    scanf("%f", &playlist[*numeroPlaylists].tempoPlaylist);

    *numeroPlaylists += 1;
}

void excluirPlaylist(struct Playlists playlist[MAX]){
    char nome[MAX];

    printf("digite o nome da playlist que deseja excluir: ");
    scanf("%s", &nome);

    for(int i = 0; i < MAX; i++){
        if(strcmp(nome, playlist[i].nomePlaylist) == 0 ){
            for(int j = i; j < MAX; j++){
                playlist[j] = playlist[j + 1];
            }
        }
    }
    
}

void adicionarMusica(struct Playlists playlist[MAX]){
    char nomePlaylist[40];
    double tempo = 0;

    printf("digite o nome da playlist que deseja adicionar a música:");
    scanf("%s", &nomePlaylist);
    printf("digite quanto tempo tem essa música(em minutos):");
    scanf("%f", &tempo);

    for(int i = 0; i < MAX; i++){
        if(strcmp(nomePlaylist, playlist[i].nomePlaylist  == 1)){
            playlist[i].numMusicas += 1;
            playlist[i].tempoPlaylist += tempo;
        }
    }
}

