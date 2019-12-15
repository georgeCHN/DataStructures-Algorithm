#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>

//返回int型的数的二进制位数
int blen(int num)
{

    char buff[32];
    memset(buff, 0, sizeof(buff) / sizeof(char));
    sprintf(buff, "%x", num);
    int len = (strlen(buff) - 1) * 4;
    if (buff[0] < '2')
	len += 1;
    else if (buff[0] < '4')
	len += 2;
    else if (buff[0] < '8')
	len += 3;
    else
	len += 4;
    return len;
}

int mod2div(int dividend, int divisor)
{
    int dsor_len = blen(divisor);
    //首先进行左移补0
    dividend = dividend << (dsor_len - 1);
    //除数的副本
    int div_copy = dividend;
    printf("first:%d\n", dividend);
    //取得divisor的2进制位数的最大值，例如divisor是8(1000),那么threshold=7(111)
    int threshold = pow(2, dsor_len - 1) - 1;

    while (dividend > threshold) {
	int len = blen(dividend);
	int t_divisor = divisor << (len - dsor_len);
	dividend = dividend ^ t_divisor;
	printf("the dividend is:%d\n", dividend);
    }
    div_copy += dividend;
    printf("the dividend is:%d\n", div_copy);
    return div_copy;
}

int main(void)
{
    //CRC-32测试长数据通过失败，原因int型的数值不够<<19位
    //int dividend=111325,divisor=98309;
    //用计算机网络-第六版中的例子来测试
    int dividend = 41, divisor = 13;
    int res = mod2div(dividend, divisor);
    printf("----check---\n");
    //res用crc检验过的余数是0，则表示传输过程正确
    int check = mod2div(res, divisor);
    return 0;
}
