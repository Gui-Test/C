//buscando as funções do vetores.c
void gera_valores(int v[], int n,int limite);
void gera_valores_ordem(int v[], int n,int limite);
int busca_binaria (int v[], int n, int chave);
void mostra_vetor(int v[], int n);

//funções com matriz 
void gera_matriz(int lin, int col,int x[lin][col],int limite);
void mostra_matriz(int lin, int col,int x[lin][col]);
float media_pares(int l, int c,int x[l][c]);
void gera_transposta(int l, int c,int x[l][c], int t[c][l]);
void soma_matriz(int l, int c,int x[l][c], int y[l][c],int t[l][c]);
void multiplica_matriz(int la, int ca, int a[la][ca], int lb, int cb, int b[lb][cb], int c[la][cb]);
