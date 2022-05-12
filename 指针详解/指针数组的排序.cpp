void sort(char **pa, int n)//ц╟ещеепР
{
    int i, j;
    char *tmp = NULL;

    for(i = 0; i < n-1; i++){
        for(j = 0; j < n-1-i; j++){
            if((strcmp(*pa+j), *(pa+j+1)) > 0){
                tmp = *(pa + j);
                *(pa + j) = *(pa + j + 1);
                *(pa + j + 1) = tmp;
            }
        }
    }
}

