#include<stdio.h>
#include<string.h>
#include<malloc.h>
typedef struct{
	char TenDV[20];
	float TL, GT, DG;
	int PA;
}DoVat;
DoVat *ReadFromFile(float *W,int *n){
	FILE *f;
	f = fopen("CaiBalo1.inp", "r");
	fscanf(f, "%f", W);
	DoVat *dsdv;
	dsdv=(DoVat*)malloc(sizeof(DoVat));
	int i = 0;
	while (!feof(f)){
	fscanf(f, "%f%f%[^\n]",&dsdv[i].TL,&dsdv[i].GT,&dsdv[i].TenDV);
	dsdv[i].DG=dsdv[i].GT/dsdv[i].TL; 
	dsdv[i].PA=0;
	i++;
	dsdv=(DoVat*)realloc(dsdv, sizeof(DoVat)*(i+1)); 
	}
	*n=i;
	fclose(f);
	return dsdv; 
}
void Swap(DoVat *x, DoVat *y){
	DoVat Temp;
	Temp = *x;
	*x = *y;
	*y = Temp;
	
}
void BubbleSort(DoVat *dsdv, int n){
	int i,j;
	for(i=0; i<=n-2; i++)
		for (j=n-1; j>=i+1; j--){
			if (dsdv[j].DG>dsdv[j-1].DG)
				Swap(&dsdv[j],&dsdv[j-1]);
		}
}
void InDSDV(DoVat *dsdv, int n, float w){
	int i;
	float TongTL=0.0, TongGT=0.0;
	printf("\nPhuong an Cai Ba lo 1 dung thuat toan THAM AN nhu sau:\n");
	printf("|---|------------------|---------|---------|---------|-----------|\n");
	printf("|STT| Ten Do Vat       | T Luong | Gia Tri | Don Gia | Phuong an |\n");
	printf("|---|------------------|---------|---------|---------|-----------|\n");
	for(i=0;i<n;i++){
		printf("|%2d |%-18s|%9.2f|%9.2f|%9.2f|%6d     |\n",i+1,dsdv[i].TenDV,dsdv[i].TL,dsdv[i].GT,dsdv[i].DG,dsdv[i].PA);
		TongTL=TongTL+dsdv[i].PA * dsdv[i].TL;
		TongGT=TongGT+dsdv[i].PA * dsdv[i].GT;
	}
	printf("|---|------------------|---------|---------|---------|-----------|\n");
	printf("Trong luong cua ba lo = %-9.2f\n",w);
	printf("Tong trong luong = %-9.2f\n",TongTL);
	printf("Tong gia tri = %-9.2f\n",TongGT);
	printf("Phuong an X (");
	for(int i = 0; i < n; i++){
		printf("%d",dsdv[i].PA);
		if(i != (n - 1))	printf(",");
	}
	printf(")");
}
 void Greedy(DoVat *dsdv,int n, float W){
 	for(int i = 0; i < n; i++){
 		dsdv[i].PA = (W/dsdv[i].TL); 
 		W = W-dsdv[i].PA * dsdv[i].TL;
 	}

}
int main(){
	int n;
	float W;
	DoVat *dsdv;
	dsdv=ReadFromFile(&W, &n);
	BubbleSort(dsdv,n);
	Greedy(dsdv,n,W);
	InDSDV(dsdv,n,W);

	free(dsdv);
	return 0;
 }



