#include <stdio.h>
#include <stdlib.h>
#include <omp.h>

int main()
{
    FILE *image, *outputImage, *lecturas;
    image = fopen("sample5.bmp","rb");          //Imagen original a transformar
    outputImage = fopen("img3.bmp","wb");    //Imagen transformada
    long ancho;
    long alto;
    unsigned char r, g, b;               //Pixel
    unsigned char* ptr;

    unsigned char xx[54];
    int cuenta = 0;
    for(int i=0; i<54; i++) {
      xx[i] = fgetc(image);
      fputc(xx[i], outputImage);   //Copia cabecera a nueva imagen
    }
    ancho = (long)xx[20]*65536+(long)xx[19]*256+(long)xx[18];
    alto = (long)xx[24]*65536+(long)xx[23]*256+(long)xx[22];

    printf("largo img %li\n",alto);
    printf("ancho img %li\n",ancho);

    ptr = (unsigned char*)malloc(alto*ancho*3* sizeof(unsigned char));

    while(!feof(image)){
      b = fgetc(image);
      g = fgetc(image);
      r = fgetc(image);

      unsigned char pixel = 0.21*r+0.72*g+0.07*b;

      ptr[cuenta] = pixel; //b
      ptr[cuenta+1] = pixel; //g
      ptr[cuenta+2] = pixel; //r

      cuenta +=3;

    }

    for(int i=0; i<alto-1; i++){
      for(int j=(ancho*3); j>2; j-=3){
        fputc(ptr[(ancho*i*3)+j+1+162], outputImage);
        fputc(ptr[(ancho*i*3)+j+2+162], outputImage);
        fputc(ptr[(ancho*i*3)+j+3+162], outputImage);
      }
    }

    free(ptr);
    fclose(image);
    fclose(outputImage);

    return 0;
}
