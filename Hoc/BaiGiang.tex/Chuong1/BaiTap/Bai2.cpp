// BÀI 2: Áp dụng kỹ thuật cấp phát động cho mảng một chiều
// (Đề bài đánh số 1, 2, 3 rồi nhảy sang 6 nên không có câu 4, 5)
#include <iostream>
#include <cmath>
using namespace std;

// Câu 1: tạo mảng số thực có các giá trị cho sẵn
void khoiTao(double* a, int& n)
{
    n = 10;
    *(a + 0) = 0.8;
    *(a + 1) = 5.6;
    *(a + 2) = 9.1;
    *(a + 3) = 7.3;
    *(a + 4) = 10;
    *(a + 5) = 5.9;
    *(a + 6) = 7.2;
    *(a + 7) = 9.3;
    *(a + 8) = 8.0;
    *(a + 9) = 8.7;
}

// Câu 2: xuất mảng
void xuat(double* a, int n)
{
    for(int i = 0; i < n; i++)
    {
        cout << *(a + i) << "  ";
    }
    cout << endl;
}

// Câu 3: kiểm tra mảng có toàn dương
bool toanDuong(double* a, int n)
{
    for(int i = 0; i < n; i++)
    {
        if(*(a + i) <= 0)
        {
            return false;
        }
    }
    return true;
}

// Câu 6: kiểm tra mảng có đối xứng
bool doiXung(double* a, int n)
{
    for(int i = 0; i < n / 2; i++)
    {
        if(*(a + i) != *(a + n - 1 - i))
        {
            return false;
        }
    }
    return true;
}

// Số thực chỉ xét nguyên tố / chính phương khi nó là số nguyên (vd: 10, 8.0)
bool laSoNguyen(double x)
{
    return x == (int)x;
}

bool laSoNguyenTo(double x)
{
    if(!laSoNguyen(x) || x < 2)
    {
        return false;
    }
    int k = (int)x;
    for(int i = 2; i <= sqrt(k); i++)
    {
        if(k % i == 0)
        {
            return false;
        }
    }
    return true;
}

bool laSoChinhPhuong(double x)
{
    if(!laSoNguyen(x) || x < 0)
    {
        return false;
    }
    int k = (int)x;
    int can = (int)sqrt(k);
    return can * can == k;
}

// Câu 7: kiểm tra mảng có chứa số nguyên tố, số chính phương
bool coSoNguyenTo(double* a, int n)
{
    for(int i = 0; i < n; i++)
    {
        if(laSoNguyenTo(*(a + i)))
        {
            return true;
        }
    }
    return false;
}

bool coSoChinhPhuong(double* a, int n)
{
    for(int i = 0; i < n; i++)
    {
        if(laSoChinhPhuong(*(a + i)))
        {
            return true;
        }
    }
    return false;
}

// Câu 8: tìm một giá trị trong mảng, trả về vị trí (không có thì -1)
int timGiaTri(double* a, int n, double x)
{
    for(int i = 0; i < n; i++)
    {
        if(*(a + i) == x)
        {
            return i;
        }
    }
    return -1;
}

// Câu 9: tìm các số nguyên tố có trong mảng
double* timSoNguyenTo(double* a, int n, int& m)
{
    double* b = new double[n];
    m = 0;
    for(int i = 0; i < n; i++)
    {
        if(laSoNguyenTo(*(a + i)))
        {
            *(b + m) = *(a + i);
            m++;
        }
    }
    return b;
}

// Câu 10: tìm các số chính phương có trong mảng
double* timSoChinhPhuong(double* a, int n, int& m)
{
    double* b = new double[n];
    m = 0;
    for(int i = 0; i < n; i++)
    {
        if(laSoChinhPhuong(*(a + i)))
        {
            *(b + m) = *(a + i);
            m++;
        }
    }
    return b;
}

// Câu 11: trả về các số âm trong mảng
double* soAm(double* a, int n, int& m)
{
    double* b = new double[n];
    m = 0;
    for(int i = 0; i < n; i++)
    {
        if(*(a + i) < 0)
        {
            *(b + m) = *(a + i);
            m++;
        }
    }
    return b;
}

// Câu 12: tìm các số dương và tính tổng của chúng
double* soDuong(double* a, int n, int& m, double& tong)
{
    double* b = new double[n];
    m = 0;
    tong = 0;
    for(int i = 0; i < n; i++)
    {
        if(*(a + i) > 0)
        {
            *(b + m) = *(a + i);
            m++;
            tong = tong + *(a + i);
        }
    }
    return b;
}

// Câu 13: đảo ngược các phần tử ngay trong mảng
void hoan_vi(double* a, double* b)
{
    double temp = *a;
    *a = *b;
    *b = temp;
}

void daoNguoc(double* a, int n)
{
    for(int i = 0; i < n / 2; i++)
    {
        hoan_vi(a + i, a + n - 1 - i);
    }
}

int main()
{
    double* a = new double[100];
    int n = 0;

    if(a == NULL)
    {
        cout << "Cap phat khong thanh cong" << endl;
        return 0;
    }

    khoiTao(a, n);
    cout << "Cau 1-2. Mang: ";
    xuat(a, n);

    cout << "\nCau 3. Mang toan duong? ";
    if(toanDuong(a, n))
    {
        cout << "Co" << endl;
    }
    else
    {
        cout << "Khong" << endl;
    }

    cout << "\nCau 6. Mang doi xung? ";
    if(doiXung(a, n))
    {
        cout << "Co" << endl;
    }
    else
    {
        cout << "Khong" << endl;
    }

    cout << "\nCau 7. Co so nguyen to? ";
    if(coSoNguyenTo(a, n))
    {
        cout << "Co" << endl;
    }
    else
    {
        cout << "Khong" << endl;
    }

    cout << "       Co so chinh phuong? ";
    if(coSoChinhPhuong(a, n))
    {
        cout << "Co" << endl;
    }
    else
    {
        cout << "Khong" << endl;
    }

    double x = 7.3;
    int vt = timGiaTri(a, n, x);
    if(vt != -1)
    {
        cout << "\nCau 8. Tim thay " << x << " tai vi tri " << vt << endl;
    }
    else
    {
        cout << "\nCau 8. Khong tim thay " << x << endl;
    }

    int m = 0;
    double* nt = timSoNguyenTo(a, n, m);
    cout << "\nCau 9. Cac so nguyen to (" << m << "): ";
    xuat(nt, m);
    delete[] nt;
    nt = NULL;

    double* cp = timSoChinhPhuong(a, n, m);
    cout << "\nCau 10. Cac so chinh phuong (" << m << "): ";
    xuat(cp, m);
    delete[] cp;
    cp = NULL;

    double* am = soAm(a, n, m);
    cout << "\nCau 11. Cac so am (" << m << "): ";
    xuat(am, m);
    delete[] am;
    am = NULL;

    double tong = 0;
    double* duong = soDuong(a, n, m, tong);
    cout << "\nCau 12. Cac so duong (" << m << "): ";
    xuat(duong, m);
    cout << "        Tong cac so duong = " << tong << endl;
    delete[] duong;
    duong = NULL;

    daoNguoc(a, n);
    cout << "\nCau 13. Mang sau khi dao nguoc: ";
    xuat(a, n);

    delete[] a;
    a = NULL;
    return 0;
}
