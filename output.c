/* EL2208 Praktikum Pemecahan Masalah dengan C 2019/2020  
* MODUL 9 – TUGAS BESAR  
* Kelompok   		: B6  
* Hari dan Tanggal 	: Jumat, 17 April 2020  
* Asisten (NIM)  	: Ryan Dharma Chandra (13217018)  
* Nama File   		: output.c  
* Deskripsi   		: Mencetak ngram dari tabel ke layar sesuai dengan jumlah kata dari input pengguna 
*/

#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <time.h>

/*
struct node {
	char *key;
    char value[20][100];
	struct node* go;
};
*/


void display(struct node *start,int N,int Ngram)
{
	struct node *ptrls;
	srand(time(0));
    struct node *current;
    int count;
    int k;

    int jumlahkata= Ngram;
	int modkata;
	int sisakata;

    //tempvalue digunakan untuk menyiman value dari key yang digunakan
    char *tempvalue;
    //tmpkey digunakan untuk menyimpan kata pertama dari key saat menggunakan strtok
    char tempkey[100];
    int nvalue;
    char *token;

	//menghitung banyaknya node yang ada
	ptrls = start;
		count =0;
		while(ptrls != NULL)
		{
			ptrls = ptrls->go;
			count++;
		}
		

	current = start;

	//untuk mengakses key secara random
	k = rand()%count;
	int i=0;
	int j;

	//coval untuk menghitung value yang ada setiap node untuk random
	int coval;
	//menampilkan key pertama jika i sama dengan node yang di random
	printf("...");
    while (current!=NULL)
    {
    	if (i==k)
    	{
    		coval =0;
    		j=0;
    		printf("%s ", current->key);
    		//menghitung banyaknya value dalam satu node
    		while(strlen(current->value[j]) && (j<20))
    		{
    			coval++;
    			j++;
			}
			//mengambil vaue secara random
			nvalue = rand()%coval;
			tempvalue = current->value[nvalue];

		}
		else
		{
			current = current->go;
		}
		i++;
	}
    //mencari kata apabila jumlah kata yang diinginkan
	modkata = N%Ngram;
	sisakata = N-modkata;

    while ((jumlahkata<N))
    {
        //sisa kata jika Ngram bukan kelipatan dari jumlah kata yang ingin ditampilkan
    	if((current!=NULL)&&(jumlahkata == sisakata))
    	{
    		int m=0;
    		token = strtok((current->key), " ");
			while((current!=NULL) && (m<modkata))
			{
				printf("%s ", token);
				token = strtok(NULL, " ");
				m++;
			}
			jumlahkata+= modkata;
		}
    	else if ((current!=NULL))
    	{
    		strcpy(tempkey,"\0");
    		//mengambil kata pertama dari key
    		strcpy(tempkey,(current->key));
    		token = strtok(tempkey, " ");
    		//melakukan pengecekan antara value dengan kata pertama key
    		if (strcmp(tempvalue,token)==0)
    		{
    			printf("%s ", current->key);
    			coval =0;
    			j=0;
    			while(strlen(current->value[j]) && (j<20))
    			{
    				coval++;
    				j++;
				}
                    nvalue = rand()%coval;
                    tempvalue = current->value[nvalue];
                    jumlahkata += Ngram;
			}
			else
			{
				current = current->go;
			}
		}
		else
		{
            current = start;
		}
	}
	printf("...");
	return;
}
