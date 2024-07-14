//---------------------------------------------------------------------------

#include <vcl.h>
#include <io.h>
#include <stdio.h>
#include <fcntl.h>
#include <sys\stat.h>
#pragma hdrstop

#include "MainUnit.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm1 *Form1;
//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------
void mmx(void * p1, void * p2, int s)
{
asm
{

mov esi, p1
mov edi, p2
mov ecx, s

l1:
movq mm0, [esi] //;загрузить восемь байтов спрайта
movq mm1, [edi] //;загрузить восемь байтов фона
por  mm1, mm0 //;сложить их с байтами спрайта
movq [esi], mm1 //;сохранить их обратно на изображение
add esi, 8
add edi, 8
sub ecx,8
cmp ecx,0
jg l1
emms
}
}

unsigned char *LoadBitmapFile(char *filename, BITMAPINFOHEADER *bitmapInfoHeader, BITMAPFILEHEADER *bitmapFileHeader)
{
FILE *filePtr; //our file pointer
//BITMAPFILEHEADER bitmapFileHeader; //our bitmap file header
unsigned char *bitmapHeader;
unsigned char *bitmapImage;  //store image data
int imageIdx=0;  //image index counter
unsigned char tempRGB;  //our swap variable

//open filename in read binary mode
filePtr = fopen(filename,"rb");
if (filePtr == NULL)
return NULL;

//read the bitmap file header
fread(bitmapFileHeader, sizeof(BITMAPFILEHEADER),1,filePtr);

//verify that this is a bmp file by check bitmap id
if (bitmapFileHeader->bfType !=0x4D42)
{
fclose(filePtr);
return NULL;
}

//read the bitmap info header
fread(bitmapInfoHeader, sizeof(BITMAPINFOHEADER),1,filePtr);

//move file point to the begging of bitmap data
fseek(filePtr, bitmapFileHeader->bfOffBits, SEEK_SET);

//allocate enough memory for the bitmap image data
bitmapImage = (unsigned char*)malloc(bitmapInfoHeader->biSizeImage);

//verify memory allocation
if (!bitmapImage)
{
free(bitmapImage);
fclose(filePtr);
return NULL;
}

//read in the bitmap image data
fread(bitmapImage,bitmapInfoHeader->biSizeImage,1,filePtr);

//make sure bitmap image data was read
if (bitmapImage == NULL)
{
fclose(filePtr);
return NULL;
}

//close file and return bitmap iamge data
fclose(filePtr);
return bitmapImage;
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button2Click(TObject *Sender)
{
BITMAPINFOHEADER bitmapInfoHeader1,bitmapInfoHeader2;
BITMAPFILEHEADER bitmapFileHeader1,bitmapFileHeader2;
unsigned char* p1;
unsigned char* p2;
FILE *file;

p1 = LoadBitmapFile("f1.bmp",&bitmapInfoHeader1,&bitmapFileHeader1);
p2 = LoadBitmapFile("f2.bmp",&bitmapInfoHeader2,&bitmapFileHeader2);

if (p1 == NULL)  ShowMessage("NULL");
mmx(p1, p2, 225*1024);

if ((file = fopen("f3.bmp","w")) == NULL)
	ShowMessage("Файл невозможно создать");
else{
	fwrite (&bitmapFileHeader1, sizeof(BITMAPFILEHEADER),1, file );
	fwrite (&bitmapInfoHeader1, sizeof(BITMAPINFOHEADER),1, file );
	fwrite (p1, 225*1024,1, file );   //225*1024
}
fclose(file);
Image3->Picture->LoadFromFile("f3.bmp");
}
//---------------------------------------------------------------------------

