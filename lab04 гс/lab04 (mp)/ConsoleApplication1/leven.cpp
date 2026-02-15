//#include <iomanip>
//#include <algorithm>
//#include "leven.h"
//#define DD(i,j) d[(i)*(ly+1)+(j)] 
//
//int min3(int x1, int x2, int x3)
//{
//	return std::min(std::min(x1, x2), x3);
//}
//
//int levenshtein(int lx, const char x[], int ly, const char y[])
//{
//	int* d = new int[(lx + 1) * (ly + 1)];
//	for (int i = 0; i <= lx; i++) DD(i, 0) = i;
//	for (int j = 0; j <= ly; j++) DD(0, j) = j;
//	for (int i = 1; i <= lx; i++)
//		for (int j = 1; j <= ly; j++)
//		{
//			DD(i, j) = min3(DD(i - 1, j) + 1, DD(i, j - 1) + 1,
//				DD(i - 1, j - 1) + (x[i - 1] == y[j - 1] ? 0 : 1));
//		}
//	return DD(lx, ly);
//}
//
//int levenshtein_recursive(int lx, const char x[], int ly, const char y[]) {
//    if (lx == 0) return ly;
//    if (ly == 0) return lx;
//
//    int cost = (x[lx - 1] == y[ly - 1]) ? 0 : 1;
//
//    return min3(
//        levenshtein_recursive(lx - 1, x, ly, y) + 1,      // удаление
//        levenshtein_recursive(lx, x, ly - 1, y) + 1,      // вставка
//        levenshtein_recursive(lx - 1, x, ly - 1, y) + cost // замена
//    );
//}
//
//int levenshtein_r(
//	int lx, const char x[],
//	int ly, const char y[]
//)
//{
//	int rc = 0;
//	if (lx == 0) rc = ly;
//	else  if (ly == 0) rc = lx;
//	else  if (lx == 1 && ly == 1 && x[0] == y[0]) rc = 0;
//	else  if (lx == 1 && ly == 1 && x[0] != y[0]) rc = 1;
//	else  rc = min3(
//		levenshtein_r(lx - 1, x, ly, y) + 1,
//		levenshtein_r(lx, x, ly - 1, y) + 1,
//		levenshtein_r(lx - 1, x, ly - 1, y) + (x[lx - 1] == y[ly - 1] ? 0 : 1)
//	);
//	return rc;
//};
