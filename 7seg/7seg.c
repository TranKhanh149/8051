	#include <REGX51.H>
	#define Bt2 P1_0
	#define Bt3 P1_1
	#define port P2
	void delay (int time)
	{
		int i, j;
		for(i = 0; i < time; i++)
		for(j = 0; j < 125; j++);
	}
	void main (void) 
	{
		signed char mang[10] = {0xC0, 0xF9, 0xA4, 0xB0, 0x99, 0x92, 0x82, 0xF8, 0x80, 0x90};
		int num = 0;
		while(1)
		{
			if(Bt2 == 0)
			{
				num++;
				if (num == 10) 
					num = 0;
			}
			if(Bt3 == 0)
			{
				num--;
				if (num == -1) 
					num = 9;
			}
				port = mang[num];
				delay(1000);
		}
	}