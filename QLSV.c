#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include"menu.h"
#include"function.h"
#include<string.h>
void main(){
int chon;
	SV sv[100];
	
	int c,n,d,e,g,key;
	do{menu();
	printf("\n	*Moi ban chon chuc nang : ");
	scanf("%d",&c);
		
		switch(c){
			case 1:
				printf("\n 1 - Them thong tin sinh vien");
				printf("\n 2 - Sua thong tin sinh vien");
				printf("\n 3 - Xoa thong tin sinh vien");
				printf("\n *Hay chon thao tac : ");
				scanf("%d",&d);
				switch(d){
			
					case 1:
						system("cls");
						doc_dl(sv,&n);
						SV svt[100];
						printf("	*Moi nhap so luong sinh vien : ");
						scanf("%d",&n);
						nhap_dl(svt,n);
						luu(svt,n);
						break;
					case 2:
						system("cls");
						doc_dl(sv,&n);
						key = tim(sv,n);
						printf("%d",key);
						if (key !=-1){
							
							printf("\n *Thong tin sinh vien can sua la : \n");
							printf("\n Ma: %s | Ho&Ten: %s |  Lop: %s | Toan: %d | Ly: %d | Hoa: %d | Trung binh: %.2f\n",sv[key].ma,sv[key].hoten,sv[key].lop,sv[key].toan,sv[key].ly,sv[key].hoa,sv[key].dtb);	
							printf("\n *Nhap cac thong tin can sua : ");
							sua(sv,n,key);
						} else { 
							printf(" Khong co sinh vien vua nhap ");
						}
						break;
				
					
					case 3:
						system("cls");
						doc_dl(sv,&n);
						key = tim(sv,n);
						if(key != -1){
							xoa(sv, n,key);
						} else { 
							printf(" Khong co sinh vien vua nhap ");
						}
						break;
				}
					
			case 2:
				system("cls");
				doc_dl(sv,&n);
				
				hien_thi(sv,n);
				break;
		
			case 3:
				system("cls");
				printf("\n 1 - Sap xep thu tu giam dan");
				printf("\n 2 - Sap xep thu tu tang dan");
				printf("\n *Hay chon thao tac : ");
				scanf("%d",&e);
				switch(e){
					case 1:
						doc_dl(sv,&n);
						sap_xep_giam_dan(sv,n);
						break;
					case 2:
						doc_dl(sv,&n);
						sap_xep_tang_dan(sv,n);
						break;	
				
				}break;
				
			case 4:
				system("cls");
				doc_dl(sv,&n);
				key = tim_lop(sv,n);
				if(key != -1){
					hien_thi(sv,n);
				} else{
					printf(" Lop vua nhap khong ton tai");
				}
				break;	
				
			case 5:
				system("cls");
				printf("\n 1 - Tim sinh vien theo diem trung binh");
				printf("\n 2 - Tim sinh vien theo diem toan");
				printf("\n 3 - Tim sinh vien theo diem ly");
				printf("\n 4 - Tim sinh vien theo diem hoa");
				printf("\n *Hay chon thao tac : ");
				scanf("%d",&g);
				switch(g){
				case 1:
					doc_dl(sv,&n);
					tim_diem(sv,n);
					fflush(stdin);
					break;
				
				case 2:
					doc_dl(sv,&n);
					tim_diem_toan(sv,n);
					fflush(stdin);
					break;
				
				case 3:
					doc_dl(sv,&n);
					tim_diem_ly(sv,n);
					fflush(stdin);
					break;
					
				case 4:
					doc_dl(sv,&n);
					tim_diem_hoa(sv,n);
					fflush(stdin);
					break;			
		}break;
		}
	}
	while (c>0 && c<6);
	


}
