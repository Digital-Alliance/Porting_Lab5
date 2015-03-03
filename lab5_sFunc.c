#include <file.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int sFunc (finalB1L1, finalB1L2, finalW1L1, finalW1L2, finaSoftmaxTheta)
{
  int level = 0.65; // thresh holding constant
  int width = 0;
  int locx = -1;
  int flag = 0;
  int i, j = 0;
  int z1, z2, z3, z4, total = 0;
  int digits = round(width/175);
  

  //LOAD IMAGE????
  oImage = tograyscale (Image); // convert to gray scale ?
 //oImage = mmbinary(oImage, level); // convert to binary ?
  

    while (locx = -1)
      {
	i = i++;
	for (j=1; j<=3180; j++)
	  {
	    if(image[i,j]=0)
	      width++;
	    if (width > 200 && flag <1)
	      {
		i = i+3;
		flag = 1;
	      }
	    else
	      {
		if(width>200)
		  {
		    locx = j-width;
		    locy = i;
		    break;
		  }
		else
		  {
		    width = 0;
		  }
	      }
	  }
   
      }
  for (l = 1, l<=digits, l++)
    {
      total = total *10;

      z1 = 1/(1+exp(-(finalW1L1*image1+finalB1L1))); 
      z2 = 1/(1+exp(-(finalW1L2*z1+finalB1L2)));
      z3 = finalSoftmaxTheta *z2;
      z4 = mod(find(z3 == max(z3)), 10);

      total = total + z4;
    }
}

grayimage tograyscale(image img)
{
   unsigned int x, y;
   grayimage timg;
   double rc, gc, bc, l;
   unsigned int ofs;
 
   timg = alloc_grayimg(img->width, img->height);
 
   for(x=0; x < img->width; x++)
   {
      for(y=0; y < img->height; y++)
      {
        ofs = (y * img->width) + x;
        rc = (double) img->buf[ofs][0];
        gc = (double) img->buf[ofs][1];
        bc = (double) img->buf[ofs][2];
        l = 0.2126*rc + 0.7152*gc + 0.0722*bc;
        timg->buf[ofs][0] = (luminance) (l+0.5);
      }
   }
   return timg;
}
