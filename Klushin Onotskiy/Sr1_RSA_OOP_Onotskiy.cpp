//Piven Denys K-21
#include <iostream>
#include <cmath>
using namespace std;

int gcd(int a, int b, int & x, int & y);
int inverseMod(int a, int m);

void ASCII();

void Shifer(int c, int p, int q, int e, int n);
unsigned powmod(unsigned base, unsigned exp, unsigned modulo);

void main() {
	//ASCII();
	//Ðîçøèôðóâàòè ôðàçó ç ëàòèíñüêèõ ñèìâîë³â(êîäóâàííÿ ASCII), çàøèôðîâàíó àëãîðèòìîì RSA.
	//var 1

	int e1 = 17257, n1 = 305900099, p1 = 17489, q1 = 17491;
	
	//How many languages you know, so many times you are a man
	int Phrase1[56] = 
	{	
			303218210,	235737614,	12049114,	65976054,	47339400,	162873714,	93971996,	78285016,
			65976054,	199688088,	162873714,	93971996,	94490313,	188004229,	162873714,	94490313,
			65721581,	231894123,	65976054,	78285016,	235737614,	188004229,	65976054,	122655609,
			93971996,	235737614,	12049114,	15620496,	65976054,	231894123,	235737614,	65976054,
			47339400,	162873714,	93971996,	78285016,	65976054,	298936679,	2925556,	47339400,
			65721581,	231894123,	65976054,	78285016,	235737614,	188004229,	65976054,	162873714,
			151170868,	65721581,	65976054,	162873714,	65976054,	47339400,	162873714,	93971996
	};

	for (int i = 0; i < 56; i++) {
		Shifer(Phrase1[i], p1, q1, e1, n1);
	}
	cout << endl;

	//var 2

	int e2 = 17257, n2 = 306005033, q2 = 17489, p2 = 17497, d2 = 115153079;
	
	//What we learn with pleasure we never forget
	int Phrase2[43] =
	{		
			128350614,	6703033,	257174402,	130325230,	176156754,	53707912,	79940138,	176156754,
			153919375,	79940138,	257174402,	209444216,	51176413,	176156754,	53707912,	265505402,
			130325230,	6703033,	176156754,	41983609,	153919375,	79940138,	257174402,	190182858,
			153061207,	209444216,	79940138,	176156754,	53707912,	79940138,	176156754,	51176413,
			79940138,	291259034,	79940138,	209444216,	176156754,	9046462,	117651886,	209444216,
			73486024,	79940138,	130325230
	};

	for (int i = 0; i < 43; i++) {
		Shifer(Phrase2[i], p2, q2, e2, n2);
	}
	cout << endl;

	//var 3

	int e3 = 32657, n3 = 383872193, p3 = 19477, q3 = 19709, d3 = 111351970;

	//Our patience will achieve more than our force
	int Phrase3[45] =
	{		
			12978094,	169899896,	100265847,	41583759,	138093163,	234453534,	308269565,	175631787,
			182062217,	72025863,	169223483,	182062217,	41583759,	6921485,	175631787,	81489883,
			81489883,	41583759,	234453534,	169223483,	169911266,	175631787,	182062217,	158317953,
			182062217,	41583759,	195313862,	282103049,	100265847,	182062217,	41583759,	308269565,
			169911266,	234453534,	72025863,	41583759,	282103049,	169899896,	100265847,	41583759,
			199951051,	282103049,	100265847,	169223483,	182062217
	};

	for (int i = 0; i < 45; i++) {
		Shifer(Phrase3[i], p3, q3, e3, n3);
	}
	cout << endl;

	//var 4

	int e4 = 33721, n4 = 686530157, p4 = 21787, q4 = 31511;

	//You teach best what you most need to learn
	int Phrase4[42] =
	{			
			484531375,	336760179,	509690251,	505258072,	355612286,	676188508,	123505334,	490569067,
			539618080,	505258072,	130404878,	676188508,	409409484,	355612286,	505258072,	13390192,
			539618080,	123505334,	355612286,	505258072,	508868492,	336760179,	509690251,	505258072,
			482789597,	336760179,	409409484,	355612286,	505258072,	534296388,	676188508,	676188508,
			576324693,	505258072,	355612286,	336760179,	505258072,	423266821,	676188508,	123505334,
			644743513,	534296388
	};
	
	for (int i = 0; i < 42; i++) {
		Shifer(Phrase4[i], p4, q4, e4, n4);
	}
	cout << endl;

	system("pause");
}

int gcd(int a, int b, int & x, int & y) {
	if (a == 0) {
		x = 0; y = 1;
		return b;
	}
	int x1, y1;
	int d = gcd(b%a, a, x1, y1);
	x = y1 - (b / a) * x1;
	y = x1;
	return d;
}

int inverseMod(int a, int m) {
	int x, y;
	int g = gcd(a, m, x, y);
	if (g != 1) {
		return -1;
	}
	else {
		x = (x % m + m) % m;
		return x;
	}
}

void ASCII()
{
	cout<<' '<<'	'<<32<<endl;
	for (int i = 0; i < 256; i++) {
		cout << (char)i << '	' << i << endl;
	}
}

void Shifer(int c, int p, int q, int e, int n)
{
	int fi = (p - 1)*(q - 1);
	int d = inverseMod(e, fi);

	int result = powmod(c, d, n);

	cout << (char)result;
}

unsigned powmod(unsigned base, unsigned exp, unsigned modulo)
{
	unsigned res = 1;

	while (exp != 0)
	{
		if ((exp & 1) != 0)
		{
			res = (1ll * res * base) % modulo;
		}

		base = (1ll * base * base) % modulo;
		exp >>= 1;

	}

	return res;
}