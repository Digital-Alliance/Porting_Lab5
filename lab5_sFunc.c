#include <file.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <image.h>

int sFunc (finalB1L1, finalB1L2, finalW1L1, finalW1L2, finaSoftmaxTheta)
{
  int level = 0.65; // thresholding constant
  int width = 0;
  int locx = -1;
  int flag = 0;
  int i, j = 0;
  int z1, z2, z3, z4, total = 0;
  int digits = round(width/175);
  
// Attempt to load image
void Img_IO (struct Image *IO, char *filename, char dir)

{
	FILE *fp;
	int i, sz_pix;
	
	if(dir)
		/* open (or create) a file for read */
		fp = fopen(filename, "rb");
	
	else
		/* open (or create) a file for write */
		fp = fopen(filename, "wb");
	
	switch (IO->Type)
	{
		case BASIC:
			sz_pix = sizeof(unsigned char);
			break;
		
		case UINT:
			sz_pix = sizeof(unsigned int);
			break;
		
		case REAL:
			sz_pix = sizeof(float);
			break;
		
		case CMPLX:
			sz_pix = 2*sizeof(float);
			break;
	}
	
	/* process the image by rows */
	for (i=0; i<IO->Rows;  ++i)
		if(dir)
			fread(IO->Data + i*IO->Cols, IO->Cols,  sz_pix, fp);
		
		else
			fwrite(IO->Data + i*IO->Cols, IO->Cols, sz_pix, fp);
	
	fclose(fp);
}
  

  Img_in(??); //LOAD IMAGE????
  //Img_out(??) if we need/want to ourput the image
  oImage = tograyscale (Image); // convert to gray scale ?
  Threshold (oImage, oImage1, level); // convert to binary ?
  oImage = ~oImage1;

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

Threshold(strict Image *IMAGE, stuct Image *IMAGE1, int THRES) //Converts to binary image??
{
	int X, Y, GO, GB;
	GO = 225;
	GB = 0;
	
	for (Y=0; y<=IMAGE->Rows; Y++)
	{
		for(X = 0; X <= IMAGE->Cols; X++)
		{
			if (*(IMAGE1->Data+X+(long)Y*IMAGE->Cols)>THRES)
				*(IMAGE1->Data+X+(long)Y*IMAGE->Cols)= GO;
			else
				*(IMAGE1->Data+X+(long)Y*IMAGE->Cols)= GB;
		}
	}
	
	
}

