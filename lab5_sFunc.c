//#include <files.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
//#include <image.h>

int sFunc (finalB1L1, finalB1L2, finalW1L1, finalW1L2, finaSoftmaxTheta)
{
  int level = 0.65; // thresholding constant
  int width, height = 0;''
  int locx = -1;
  int locy;
  int flag = 0;
  int i, j, l = 1;
  int z1, z2, z3, z4, total = 0;
  int digits = round(width/height);

  float Image[640][480];
  float oImage[640][480];
  float oImage1[640][480];
  float image[640][480];
  float image1[640][480];

  ////////////////////////////
  // ALL DONE IN VERILOG?!?!//
  ////////////////////////////

  // Img_in(??); //LOAD IMAGE????
  //Img_out(??) if we need/want to ourput the image
  //oImage = tograyscale (Image); // convert to gray scale ?
  //Threshold (oImage, oImage1, level); // convert to binary ?
  // oImage = ~oImage1;

    while (locx = -1)
      {
	i = i++;
	for (j=1; j<=3180; j++)
	  {
	    if(image[i][j]=0)
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
      
      while (oImage(locy + height, locx)== 0)
      		height = height + 1;

     oImage2 = image(locy: locy+height, locx;locx+ width);

    for (l = 1; l<=digits; l++)
    {
      total = total *10;

//WEIGHT STUFF: DO IN VERILOG?
    /*z1 = 1/(1+exp(-(finalW1L1*image1+finalB1L1))); 
      z2 = 1/(1+exp(-(finalW1L2*z1+finalB1L2)));
      z3 = finalSoftmaxTheta *z2;
      z4 = mod(find(z3 == max(z3)), 10);

      total = total + z4;*/
    }
} 

// SCALING ALGORITHM
#define FLT_MAX 99999999
#define FLT_MIN -99999999

void Scale(struct Image *In, struct Image *Out)
{
  float min, max, *InD, *OuD;
  long ImSize, i;

  min = FLT_MAX;
  max = FLT_MIN;
  InD = (float *)In->Data;
  ImSize = In->Rows * In->Cols;

  //Scan input for min/max values
  for(i=0; i<ImSize; ++i)
    {
      if(*InD<min)
	min = *InD;
      if(*InD>max)
	max = *InD;
      ++InD;
    }

  InD = (float *)In->Data;
  OuD = (float *)Out->Data;

  //scale the output
  for(i=0; i<ImSize; ++i)
    *OuD = (255/(max-min))*(*InD-min);
}

// GOT TO DO TOMORROW
// Parse through and get each W1L1 weight for the nural network
const int* getWeight_wW1L1 (input)
{
 int i, j = 1;
 float weight[640][480] = 0;

 while (i= 1; i <= 640; i++)
 {
 	while (j=1; j <=480; j++)
 	{
 		weight[i][j] = strtok(imput, ",");
 	}
 }
}


////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//                                           Stuff We Might Not need                                              //
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/*array tograyscale(img)
{
   unsigned int x, y;
   grayimage timg;// undeclared
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

// Attempt to load image
    void Img_IO (struct *IO[],char *filename[],char dir)

{
	FILE *fp;
	int i, sz_pix;
	
	if(dir)
	  // open (or create) a file for read 
		fp = fopen(filename, "rb");
	
	else
	  // open (or create) a file for write
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
	
	// process the image by rows
	for (i=0; i<IO->Rows;  ++i)
		if(dir)
			fread(IO->Data + i*IO->Cols, IO->Cols,  sz_pix, fp);
		
		else
			fwrite(IO->Data + i*IO->Cols, IO->Cols, sz_pix, fp);
	
	fclose(fp);
}

//GOT TO DO THIS
void column_sum (image)
{
	int j, i = 1;
	float sum [640] = 0;
	float image[640][480];

	while (i<=640)
	{
		for (j = 1, j<=480, j++)
		{
			sum[i] = sum[i] + image[i][j];

			if (sum[i] = 0) // whole column is white
			{}
			if(sum[i] = 640) // whole column is black
			{}
			if (sum[i] = 160) //region of interest is probably in this column
			{}
		}
		i++
	}
	return(sum);
}*/
