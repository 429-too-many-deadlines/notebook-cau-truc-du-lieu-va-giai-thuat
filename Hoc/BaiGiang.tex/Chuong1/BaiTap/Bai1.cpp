// BÀI 1: Áp dụng con trỏ cho mảng 1 chiều (số thực)
#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

// Câu 1: tạo giá trị ngẫu nhiên thuộc (-268; 339), 2 chữ số sau dấu chấm
// số lượng thuộc đoạn [10; 20]
void khoiTao(double* a, int& n)
{
    n = rand() % 11 + 10;
    for(int i = 0; i < n; i++)
    {
        double x;
        do
        {
            // phần nguyên từ -268 đến 338, phần lẻ từ .00 đến .99
            x = (rand() % 607 - 268) + (rand() % 100) / 100.0;
        } while(x <= -268); // khoảng mở nên bỏ -268.00
        *(a + i) = x;
    }
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

// Câu 3: tính tổng
double tinhTong(double* a, int n)
{
    double t = 0;
    for(int i = 0; i < n; i++)
    {
        t = t + *(a + i);
    }
    return t;
}

// Câu 4: tính tổng, tích trong 1 hàm => trả kết quả qua con trỏ
void tongTich(double* a, int n, double* tong, double* tich)
{
    *tong = 0;
    *tich = 1;
    for(int i = 0; i < n; i++)
    {
        *tong = *tong + *(a + i);
        *tich = *tich * *(a + i);
    }
}

// Câu 5: đếm số lần xuất hiện của x
int demX(double* a, int n, double x)
{
    int dem = 0;
    for(int i = 0; i < n; i++)
    {
        if(*(a + i) == x)
        {
            dem++;
        }
    }
    return dem;
}

// Câu 6: trả về các phần tử chẵn (xét phần nguyên của số thực)
// m là số lượng phần tử của mảng kết quả
double* phanTuChan(double* a, int n, int& m)
{
    double* b = new double[n];
    m = 0;
    for(int i = 0; i < n; i++)
    {
        int phanNguyen = (int)*(a + i);
        if(phanNguyen % 2 == 0)
        {
            *(b + m) = *(a + i);
            m++;
        }
    }
    return b;
}

// Câu 7: tìm vị trí phần tử nhỏ nhất
int viTriMin(double* a, int n)
{
    int vt = 0;
    for(int i = 1; i < n; i++)
    {
        if(*(a + i) < *(a + vt))
        {
            vt = i;
        }
    }
    return vt;
}

// Câu 8: tạo một mảng đảo ngược (mảng mới, không sửa mảng cũ)
double* daoNguoc(double* a, int n)
{
    double* b = new double[n];
    for(int i = 0; i < n; i++)
    {
        *(b + i) = *(a + n - 1 - i);
    }
    return b;
}

// Câu 9: trả về các số âm
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

// Câu 10: đếm số lượng giá trị thuộc đoạn [x, y]
int demDoan(double* a, int n, double x, double y)
{
    int dem = 0;
    for(int i = 0; i < n; i++)
    {
        if(*(a + i) >= x && *(a + i) <= y)
        {
            dem++;
        }
    }
    return dem;
}

// Câu 11: trả về các giá trị thuộc đoạn [x, y]
double* giaTriDoan(double* a, int n, double x, double y, int& m)
{
    double* b = new double[n];
    m = 0;
    for(int i = 0; i < n; i++)
    {
        if(*(a + i) >= x && *(a + i) <= y)
        {
            *(b + m) = *(a + i);
            m++;
        }
    }
    return b;
}

int main()
{
    srand(time(0));

    double* a = new double[100];
    int n = 0;

    if(a == NULL)
    {
        cout << "Cap phat khong thanh cong" << endl;
        return 0;
    }

    // Câu 1 + 2
    khoiTao(a, n);
    cout << "Cau 1-2. Mang vua tao (" << n << " phan tu):" << endl;
    xuat(a, n);

    // Câu 3
    cout << "\nCau 3. Tong = " << tinhTong(a, n) << endl;

    // Câu 4
    double tong, tich;
    tongTich(a, n, &tong, &tich);
    cout << "\nCau 4. Tong = " << tong << "   Tich = " << tich << endl;

    // Câu 5: lấy phần tử đầu tiên làm x cho dễ kiểm tra
    double x = *(a + 0);
    cout << "\nCau 5. So lan xuat hien cua " << x << " la: " << demX(a, n, x) << endl;

    // Câu 6
    int m = 0;
    double* chan = phanTuChan(a, n, m);
    cout << "\nCau 6. Cac phan tu chan (" << m << "): ";
    xuat(chan, m);
    delete[] chan;
    chan = NULL;

    // Câu 7
    int vt = viTriMin(a, n);
    cout << "\nCau 7. Phan tu nho nhat la a[" << vt << "] = " << *(a + vt) << endl;

    // Câu 8
    double* dn = daoNguoc(a, n);
    cout << "\nCau 8. Mang dao nguoc: ";
    xuat(dn, n);
    delete[] dn;
    dn = NULL;

    // Câu 9
    double* am = soAm(a, n, m);
    cout << "\nCau 9. Cac so am (" << m << "): ";
    xuat(am, m);
    delete[] am;
    am = NULL;

    // Câu 10 + 11
    double dau = -100, cuoi = 100;
    cout << "\nCau 10. So luong gia tri thuoc [" << dau << ", " << cuoi << "]: "
         << demDoan(a, n, dau, cuoi) << endl;

    double* doan = giaTriDoan(a, n, dau, cuoi, m);
    cout << "\nCau 11. Cac gia tri thuoc [" << dau << ", " << cuoi << "]: ";
    xuat(doan, m);
    delete[] doan;
    doan = NULL;

    delete[] a;
    a = NULL;
    return 0;
}
