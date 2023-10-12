#include<stdio.h>
#include<stdlib.h>
#include"Sinhvien.h"
#include<string.h>
 
 void nhap_dl(SV sv[], int n){
 	int i;
 	printf("\n	*Nhap thong tin sinh vien :");
 	for(i=0;i<n;i++){
 	
		printf("\n *Sinh vien thu %d : ",i+1);
			
		do{
		fflush(stdin);
		printf("\n Nhap ma sinh vien (5 ky tu) : ");
		gets(sv[i].ma);
		if(strlen(sv[i].ma)!= 5){
		
		printf("\n Ma SV phai dung 5 ky tu! Moi nhap lai!");
		}
		} while (strlen(sv[i].ma)!= 5 );
			
		
		
			fflush(stdin);
		printf("\n Nhap ten sinh vien : ");
		gets(sv[i].hoten);
	
		printf("\n Nhap lop sinh vien : ");
		gets(sv[i].lop);
		do{
	
		printf("\n Nhap diem toan (0->10) : ");
		scanf("%d",&sv[i].toan);
		if(sv[i].toan < 0 || sv[i].toan > 10){
		
		printf("\n Diem chi co trong khoang tu 0 - 10! Moi nhap lai!");}
	} while (sv[i].toan<0 || sv[i].toan>10);
	do{

		printf("\nNhap diem ly (0->10) : ");
		scanf("%d",&sv[i].ly);
		if(sv[i].ly < 0 || sv[i].ly > 10){
		
		printf("\n Diem chi co trong khoang tu 0 - 10! Moi nhap lai!");}
	} while (sv[i].ly<0 || sv[i].ly>10);	
	do{
		printf("\nNhap diem hoa (0->10): ");
		scanf("%d",&sv[i].hoa);
		if(sv[i].hoa < 0 || sv[i].hoa > 10){
		
		printf("\n Diem chi co trong khoang tu 0 - 10! Moi nhap lai!");}
	} while (sv[i].hoa<0 || sv[i].hoa>10);
	 sv[i].dtb = ( sv[i].toan + sv[i].ly + sv[i].hoa )/3;
	 }
	 
 }
 
 void hien_thi(SV sv[],int n){
 	int i;
 	printf("\n *Thong tin sinh vien : ");
 	printf("\n Hien co %d sinh vien\n",n);
	for(i=0;i<n;i++){
 		printf("|%-8s|%-30s|%-10s|%-3d|%-3d|%-3d|%-3.2f|\n",sv[i].ma,sv[i].hoten,sv[i].lop,sv[i].toan,sv[i].ly,sv[i].hoa,sv[i].dtb);
	 }
 }
 
 void luu(SV sv[],int n){
 	FILE *tt;
 	tt = fopen("TTSinhVien.dat","ab");
 	fwrite(sv,sizeof(SV),n,tt);
 	fclose(tt);
 }
 
 void luu_moi(SV sv[], int n){
 	FILE *tt;
 	tt = fopen("TTSinhVien.dat","wb");
 	fwrite(sv,sizeof(SV),n,tt);
 	fclose(tt);
 }
 
 void doc_dl(SV sv[],int *n){
 	FILE *tt;
 	tt = fopen("TTSinhVien.dat","rb");
 	fseek(tt,0,SEEK_END);
 	*n = (ftell(tt)+1)/sizeof(SV);
 	fseek(tt,0,SEEK_SET);
 	fread(sv,sizeof(SV),*n,tt);
 	fclose(tt);
 	
 }
 
 int tim(SV sv[],int n){
	int i;
	char code[5];
	fflush(stdin);
	printf("\nNhap ma sinh vien : ");
	gets(code);
	for(i = 0; i < n; i++){
		if(strcmp(sv[i].ma, code) == 0){
			return i;
		}
	}
	
	return -1;
}

 int tim_lop(SV sv[],int n){
	int i;
	char code[5];
	fflush(stdin);
	printf("\nNhap lop : ");
	gets(code);
	for(i = 0; i < n; i++){
		if(strcmp(sv[i].lop, code) == 0){
			return i;
		}
	}
	
	return -1;
}


void xoa(SV sv[],int n, int key){
	int i,j = 0;
	SV svm[100];
	for(i = 0; i < n; i++){
		if(key == i){
			continue;
		}
		strcpy(svm[j].ma, sv[i].ma);
		strcpy(svm[j].hoten, sv[i].hoten);
		strcpy(svm[j].lop, sv[i].lop);
		svm[j].toan=svm[i].toan;
		svm[j].ly=svm[i].ly;
		svm[j].hoa=svm[i].hoa;
		j++;
	}
	
	luu_moi(svm, j);
}

void luu_sua(SV sv[],int n){
	luu_moi(sv, n);
}

void sua(SV sv[],int n,int key){
	SV ttm;
	strcpy(ttm.ma,sv[key].ma);
	strcpy(ttm.hoten,sv[key].hoten);
	strcpy(ttm.lop,sv[key].lop);
	ttm.toan=sv[key].toan;
	ttm.ly=sv[key].ly;
	ttm.hoa=sv[key].hoa;
	printf("\n Ma : "); 
	gets(sv[key].ma);
	if(strcmp(sv[key].ma, "") == 0){
		strcpy(sv[key].ma, ttm.ma);
	}

	printf("\n Ten : "); 
	gets(sv[key].hoten);
	if(strcmp(sv[key].hoten, "") == 0){
		strcpy(sv[key].hoten, ttm.hoten);
	}
	printf("\n Lop : ");
	gets(sv[key].lop);
	if(strcmp(sv[key].lop, "") == 0){
		strcpy(sv[key].lop, ttm.lop);
	}
	
	printf("\n Toan : "); 
	scanf("%d",&sv[key].toan);
	if(sv[key].toan == 0){
		sv[key].toan =  ttm.toan;
	}
	
	printf("\n Ly : "); 
	scanf("%d",&sv[key].ly);
	if(sv[key].ly == 0){
		sv[key].ly =  ttm.ly;
	}
	
	printf("\n Hoa : "); 
	scanf("%d",&sv[key].hoa);
	if(sv[key].hoa == 0){
		sv[key].hoa =  ttm.hoa;
	}
	
	luu_sua(sv,n);
}

void sap_xep_giam_dan(SV sv[],int n){
	int i, j;
	SV ttsx;
	for(i=0 ; i<n-1 ; i++){
		for (j=i+1 ; j<n ; j++)	{
			if (sv[i].dtb<sv[j].dtb)	{
			strcpy(ttsx.ma,sv[i].ma);
			strcpy(ttsx.hoten,sv[i].hoten);
			strcpy(ttsx.lop,sv[i].lop);
			ttsx.toan=sv[i].toan;
			ttsx.ly=sv[i].ly;
			ttsx.hoa=sv[i].hoa;
			ttsx.dtb=sv[i].dtb;
	
		
			strcpy(sv[i].ma,sv[j].ma);
			strcpy(sv[i].hoten,sv[j].hoten);
			strcpy(sv[i].lop,sv[j].lop);
			sv[i].toan=sv[j].toan;
			sv[i].ly=sv[j].ly;
			sv[i].hoa=sv[j].hoa;
			sv[i].dtb=sv[j].dtb;
			
						
			strcpy(sv[j].ma,ttsx.ma);
			strcpy(sv[j].hoten,ttsx.hoten);
			strcpy(sv[j].lop,ttsx.lop);
			sv[j].toan=ttsx.toan;
			sv[j].ly=ttsx.ly;
			sv[j].hoa=ttsx.hoa;
			sv[j].dtb=ttsx.dtb;
	
		
	}}}
	hien_thi(sv,n);
}

void sap_xep_tang_dan(SV sv[],int n){
	int i, j;
	SV ttsx;
	for(i=0 ; i<n-1 ; i++){
		for (j=i+1 ; j<n ; j++)	{
			if (sv[i].dtb>sv[j].dtb)	{
			strcpy(ttsx.ma,sv[i].ma);
			strcpy(ttsx.hoten,sv[i].hoten);
			strcpy(ttsx.lop,sv[i].lop);
			ttsx.toan=sv[i].toan;
			ttsx.ly=sv[i].ly;
			ttsx.hoa=sv[i].hoa;
			ttsx.dtb=sv[i].dtb;
	
		
			strcpy(sv[i].ma,sv[j].ma);
			strcpy(sv[i].hoten,sv[j].hoten);
			strcpy(sv[i].lop,sv[j].lop);
			sv[i].toan=sv[j].toan;
			sv[i].ly=sv[j].ly;
			sv[i].hoa=sv[j].hoa;
			sv[i].dtb=sv[j].dtb;
			
						
			strcpy(sv[j].ma,ttsx.ma);
			strcpy(sv[j].hoten,ttsx.hoten);
			strcpy(sv[j].lop,ttsx.lop);
			sv[j].toan=ttsx.toan;
			sv[j].ly=ttsx.ly;
			sv[j].hoa=ttsx.hoa;
			sv[j].dtb=ttsx.dtb;
	
		
	}}}
	hien_thi(sv,n);
}

void tim_diem(SV sv[],int n){
	float diem1,diem2;
	int i ,t=0;
	SV dsv[20];
	printf(" *Nhap khoang diem : ");
	scanf("%f %f",&diem1,&diem2);
	for(i=0;i<n;i++){
		if(sv[i].dtb >= diem1 && sv[i].dtb <= diem2){
			strcpy(dsv[t].ma,sv[i].ma);
			strcpy(dsv[t].hoten,sv[i].hoten);
			strcpy(dsv[t].lop,sv[i].lop);
			dsv[t].toan=sv[i].toan;
			dsv[t].ly=sv[i].ly;
			dsv[t].hoa=sv[i].hoa;
			dsv[t].dtb=sv[i].dtb;
			t++;
		}
	}
	hien_thi(dsv,t);
}

void tim_diem_toan(SV sv[],int n){
	float t1,t2;
	int i ,t=0;
	SV dsv[20];
	printf(" *Nhap khoang diem : ");
	scanf("%f %f",&t1,&t2);
	for(i=0;i<n;i++){
		if(sv[i].toan >= t1 && sv[i].toan <= t2){
			strcpy(dsv[t].ma,sv[i].ma);
			strcpy(dsv[t].hoten,sv[i].hoten);
			strcpy(dsv[t].lop,sv[i].lop);
			dsv[t].toan=sv[i].toan;
			dsv[t].ly=sv[i].ly;
			dsv[t].hoa=sv[i].hoa;
			dsv[t].dtb=sv[i].dtb;
			t++;
		}
	}
	hien_thi(dsv,t);
}

void tim_diem_ly(SV sv[],int n){
	float l1,l2;
	int i ,t=0;
	SV dsv[20];
	printf(" *Nhap khoang diem : ");
	scanf("%f %f",&l1,&l2);
	for(i=0;i<n;i++){
		if(sv[i].ly >= l1 && sv[i].ly <= l2){
			strcpy(dsv[t].ma,sv[i].ma);
			strcpy(dsv[t].hoten,sv[i].hoten);
			strcpy(dsv[t].lop,sv[i].lop);
			dsv[t].toan=sv[i].toan;
			dsv[t].ly=sv[i].ly;
			dsv[t].hoa=sv[i].hoa;
			dsv[t].dtb=sv[i].dtb;
			t++;
		}
	}
	hien_thi(dsv,t);
}

void tim_diem_hoa(SV sv[],int n){
	float h1,h2;
	int i ,t=0;
	SV dsv[20];
	printf(" *Nhap khoang diem : ");
	scanf("%f %f",&h1,&h2);
	for(i=0;i<n;i++){
		if(sv[i].hoa >= h1 && sv[i].hoa <= h2){
			strcpy(dsv[t].ma,sv[i].ma);
			strcpy(dsv[t].hoten,sv[i].hoten);
			strcpy(dsv[t].lop,sv[i].lop);
			dsv[t].toan=sv[i].toan;
			dsv[t].ly=sv[i].ly;
			dsv[t].hoa=sv[i].hoa;
			dsv[t].dtb=sv[i].dtb;
			t++;
		}
	}
	hien_thi(dsv,t);
}
