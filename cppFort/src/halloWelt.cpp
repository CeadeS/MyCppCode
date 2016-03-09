# include <stdio.h>
int  main(int argc, char* argv[]){
int a=6;
int b=5;
#ifdef mal5
a=5;
#endif
for (int i=0;i<argc;i++){
	printf("argv[%d] = %s \n",i,argv[i]);
}
printf("hallo welt!, ich heiße "__FILE__"\n das Ergebnis lautet: \n %d \n",a+b);
return a+b;
}
