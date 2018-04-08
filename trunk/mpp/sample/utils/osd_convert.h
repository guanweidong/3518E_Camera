#ifndef OSD_CONVERT_H
#define OSD_CONVERT_H

#pragma pack(1)
typedef struct {
	unsigned short 	bfType; 	  //λͼ�ļ������ͣ�����ΪBM 
	unsigned int	bfSize; 	  //�ļ���С�����ֽ�Ϊ��λ
	unsigned short 	bfReserved1; //λͼ�ļ������֣�����Ϊ0 
	unsigned short 	bfReserved2; //λͼ�ļ������֣�����Ϊ0 
	unsigned int	bfOffBits;  //λͼ�ļ�ͷ�����ݵ�ƫ���������ֽ�Ϊ��λ
} BMPFILEHEADER_T;

typedef struct{
	unsigned int 	biSize;						//�ýṹ��С���ֽ�Ϊ��λ
	unsigned int  	biWidth;					   //ͼ�ο���������Ϊ��λ
	unsigned int  	biHeight; 					//ͼ�θ߶�������Ϊ��λ
	unsigned short 	biPlanes;			   //Ŀ���豸�ļ��𣬱���Ϊ1 
	unsigned short  biBitCount;			   //��ɫ��ȣ�ÿ����������Ҫ��λ��
	unsigned int  	biCompression;		 //λͼ��ѹ������
	unsigned int  	biSizeImage;				//λͼ�Ĵ�С�����ֽ�Ϊ��λ
	unsigned int  	biXPelsPerMeter;		 //λͼˮƽ�ֱ��ʣ�ÿ��������
	unsigned int  	biYPelsPerMeter;		 //λͼ��ֱ�ֱ��ʣ�ÿ��������
	unsigned int  	biClrUsed;			//λͼʵ��ʹ�õ���ɫ���е���ɫ��
	unsigned int  	biClrImportant;		//λͼ��ʾ��������Ҫ����ɫ��
} BMPINFOHEADER_T;

typedef struct{
	unsigned short b:5;
	unsigned short g:5;
	unsigned short r:5;
	unsigned short a:1;
}RGB1555_T;

#pragma pack()

typedef struct{
	int width;
	int height;
	char* pRGB;
}BITMAP_INFO_T;

int hzk_bitmap_create(int b2feild, unsigned short font, int space, char *text, 
					  unsigned short fcolor, unsigned short bcolor, unsigned short edgecolor, BITMAP_INFO_T* info);
void hzk_bitmap_destory(BITMAP_INFO_T info);
int hzk_bitmap_save(char* name, BITMAP_INFO_T info);
	
int hzk_bitmap_charbit(unsigned char *in, unsigned short qu, unsigned short wei, unsigned short font);

int hzk_bitmap_draw32(int x_pos, unsigned char* bitmap, unsigned short fcolor
		, unsigned short bcolor, unsigned short edgecolor, unsigned char *bmp_buffer
		, unsigned short bmp_width, unsigned short font);
int hzk_bitmap_draw(int x_pos, unsigned char* bitmap, unsigned short fcolor
		, unsigned short bcolor, unsigned short edgecolor, unsigned char *bmp_buffer
		, unsigned short bmp_width, unsigned short font);
#endif