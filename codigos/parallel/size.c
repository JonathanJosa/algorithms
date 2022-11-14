#include <stdio.h>
#include <stdlib.h>

int main()
{
    FILE *image, *outputImage, *lecturas;
    image = fopen("sample.bmp","rb");          //Imagen original a transformar
    outputImage = fopen("img2_dd.bmp","wb");    //Imagen transformada

    unsigned char r, g, b;               //Pixel
    unsigned char xx[54];
    long ancho, alto;

    for(int i=0; i<54; i++){
      xx[i] = fgetc(image);
      fputc(xx[i], outputImage);   //Copia cabecera a nueva imagen
    }

    ancho=(long)xx[20]*65536+(long)xx[19]*256+(long)xx[18];
    alto=(long)xx[24]*65536+(long)xx[23]*256+(long)xx[22];
    printf("largo img %li\n", alto);
    printf("ancho img %li\n", ancho);

    while(!feof(image)){                                        //Grises
       b = fgetc(image);
       g = fgetc(image);
       r = fgetc(image);

       unsigned char pixel = 0.21*r+0.72*g+0.07*b;
       fputc(pixel, outputImage);
       fputc(pixel, outputImage);
       fputc(pixel, outputImage);
    }

    fclose(image);
    fclose(outputImage);
    return 0;
}
