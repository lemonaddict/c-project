//Muhammad Rafie Kurnia - 2602166722 - LB20
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

//struct data pokemon
struct pokemon{
	char nama[20];
	char jenis[10];
	int power;
}mon[100];
int data = 0;

//input data
void insert()
{	
	//membuka file
	FILE *fp;
	if ((fp = fopen("pokedex.txt","a")) == NULL)//membuka file dalam mode append/tambah karena akan menambahkan, bukan menulis ulang
	{
		printf ("Error! opening file");
		exit(1);
	}
	
	//menerima input dari user untuk data dari pokemon
	printf("Masukkan nama pokemon: ");
	scanf("%[^\n]", mon[data].nama); getchar();
	
	printf("Masukkan jenis pokemon: ");
	scanf("%[^\n]", mon[data].jenis); getchar();
	
	printf("Masukkan base power pokemon: ");
	scanf("%d", &mon[data].power); getchar();
	
	//melakukan print pada file
	fprintf(fp, "%s;%s;%d\n", mon[data].nama, mon[data].jenis, mon[data].power);
    data++; //menambah hitungan jumlah baris/index/record
	fclose(fp);
}

//menampilkan data dengan ketentuan user
void display()
{
	bool ketemu = false; //deklarasi boolean sebagai penanda
	int pil, base;
	char line[200];
	//pencarian berdasarkan keinginan user
	printf("<1> Tampilkan berdasarkan kekuatan\n");
	printf("<2> Tampilkan berdasarkan base power\n");
	printf("Choose: "); scanf("%d", &pil); getchar();
	switch(pil){//menu dalam pencarian
		case 1://mencari berdasarkan jenis kekuatan
			ketemu = false;
			printf("Masukkan kekuatan yang dicari: "); scanf("%s", line); getchar();
			for(int i = 0; i < data; i++)//perulangan sampai banyaknya record
			{
				if(strcmp(line, mon[i].jenis) == 0) //pembanding apabila kata kunci sudah ketemu
				{
					printf("============================================\n");
					printf("NAMA POKEMON\tJENIS KEKUATAN\tBASE POWER");
					printf("\n============================================\n");
					
					if(strlen(mon[i].nama)>=9)//pembanding panjangnya nama pokemon untuk menentukan format tampilan
					{
						printf("\n%s\t%s\t\t%d\n", mon[i].nama, mon[i].jenis, mon[i].power);
					}
					else
					{
						printf("\n%s\t\t%s\t\t%d\n", mon[i].nama, mon[i].jenis, mon[i].power);
					}
					ketemu = true;
				}
			}
			if(ketemu == false) //fail tester
			{
				printf("Jenis kekuatan tidak ditemukan!\n");
			}
			break;
			
		case 2://mencari berdasarkan base power
			ketemu = false;
			printf("Masukkan base power yang dicari: "); scanf("%d", &base); getchar(); //pengambilan data base power yang diinginkan user
			for(int i = 0;i < data;i++)
			{
				if(mon[i].power >= base) //membandingkan base power yang tertera dengan base power yang diinput user, apabila lebih besar maka akan ditampilkan
				{
					printf("============================================\n");
					printf("NAMA POKEMON\tJENIS KEKUATAN\tBASE POWER");
					printf("\n============================================\n");
					
					if(strlen(mon[i].nama)>=9)//pembanding panjangnya nama pokemon untuk menentukan format tampilan
					{
						printf("\n%s\t%s\t\t%d\n", mon[i].nama, mon[i].jenis, mon[i].power);
					}
					else
					{
						printf("\n%s\t\t%s\t\t%d\n", mon[i].nama, mon[i].jenis, mon[i].power);
					}
					ketemu = true;
				}
			}
			if(ketemu == false) //fail tester
			{
				printf("Base power %d tidak ditemukan!\n",base);
			}
			break;
		default:
			printf("Masukkan menu yang benar.");
			
		}
}

//menampilkan seluruh data
void list()
{
	printf("============================================\n");
	printf("NAMA POKEMON\tJENIS KEKUATAN\tBASE POWER");
	printf("\n============================================\n");
	
	//menampilkan seluruh data
	for(int i= 0; i<data; i++)//berulang hingga banyaknya record
	{
		if(strlen(mon[i].nama)>=9)//cek apabila panjang nama lebih dari 9 karakter
		{
		printf("\n%s\t%s\t\t%d\n", mon[i].nama, mon[i].jenis, mon[i].power);
		}
		else
		{
			printf("\n%s\t\t%s\t\t%d\n", mon[i].nama, mon[i].jenis, mon[i].power);
		}
	}

}

//menyunting data
void update()
{
	FILE *fp;
    fp = fopen("pokedex.txt", "w");//membuka file dalam mode write/tulis karena akan menulis ulang data dalam file

    int x;
    printf("\nChoose index of the data you want to update : ");
    scanf("%d", &x); getchar();
	
	//mengambil data baru untuk index/recird yg dipilih
    printf("\nMasukan nama pokemon : ");
    scanf("%[^\n]", &mon[x-1].nama); getchar();

    printf("\nMasukan jenis pokemon : ");
    scanf("%[^\n]", &mon[x-1].jenis);getchar();

    printf("\nMasukan base power : ");
    scanf("%d", &mon[x-1].power); getchar();
    
    //rewrite data dalam record
    for (int i = 0; i < data; i++)
	{
    	fprintf(fp, "%s;%s;%d\n", mon[i].nama, mon[i].jenis, mon[i].power);
	}
    fclose(fp);
}

//menghapus data
void del()
{
	int x;

    FILE *fp;
    fp = fopen("pokedex.txt", "w");//membuka file dalam mode write/tulis karena akan menulis ulang file
	
    printf("Pilih index/urutan data pokemon yang ingin dihapus: ");
    scanf("%d", &x);
    //menggeser index data agar data yang tidak terpilih tidak terhapus
    for (int i = x-1; i < data; i++)
    {
        mon[i] = mon[i+1];
    }
    data--;
	
	//rewrite data dalam record
    for (int i = 0; i < data; i++)
    {
        fprintf(fp, "%s;%s;%d\n", mon[i].nama, mon[i].jenis, mon[i].power);
    }
    fclose(fp);
}

//main function
int main()
{
	//ambil nama user
	char nama[20]; 
	int pilihan;
	printf("Enter your name: ");scanf("%s", nama);getchar();
	system("cls");
	
	//hitung jumlah line/record
	FILE *fp;
	fp = fopen("pokedex.txt", "r");//membuka file dan dalam mode read/baca
    data = 0;
    while(fscanf(fp, "%[^;];%[^;];%d\r\n", mon[data].nama, mon[data].jenis, &mon[data].power) != EOF) //melakukan scan pada file, dengan constraint akhir file
	{
        data += 1;
	}
	fclose(fp);
	
	//main loop, akan berulang selama user belum exit
	do{
		
	printf("\t~MAIN MENU~");
	printf("\n\n========== %s Pokedex ==========\n", nama);
	printf("<1> Input new pokemon");
	printf("\n<2> Update pokemon status");
	printf("\n<3> Display pokemon per category");
	printf("\n<4> Delete pokemon data");
	printf("\n<5> List all pokemon data");
	printf("\n<0> Exit");
	
	printf("\n\nChoose : ");
	scanf("%d", &pilihan); fflush(stdin);
	system("cls");
	
	//menu driven case, akan memanggil function sesuai input dari user
	switch (pilihan){
		case 1: //input function
			insert();
			system("cls");
			printf("Data saved!\n"); system("pause");
			break;
		case 2: //update function
			list();
			update();
			system("cls");
			printf("Data updated!\n");
			break;
		case 3: //display function
			display();
			system("pause");
			system("cls");
			break;
		case 4: //delete function
			list();
			del();
			system("cls");
			printf("Data deleted\n");
			break;
		case 5: //show list function
			list();
			system("pause");
			system("cls");
			break;
		case 0:
			break;
		default: 
			printf("You inputted the wrong menu!\n");
			break;
		
		}	
	}while (pilihan != 0); //constraint
	printf("Pokedex closed.");
	
	return 0;
}