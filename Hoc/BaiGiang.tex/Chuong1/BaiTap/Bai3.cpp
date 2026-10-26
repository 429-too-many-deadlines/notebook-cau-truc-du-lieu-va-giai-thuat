// BÀI 3: Quản lý và tính tiền lương nhân viên (cấp phát động mảng cấu trúc)
#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

struct NhanVien
{
    string maNV;
    string hoTen;
    double luongCoBan;
    int soNgayLam;
    double luongThang;
};

// Câu 1: tạo dữ liệu kiểm thử (10 nhân viên)
void khoiTao(NhanVien* ds, int& n)
{
    n = 10;
    *(ds + 0) = {"NV01", "Nguyen Van An",  4500000, 22, 0};
    *(ds + 1) = {"NV02", "Tran Thi Binh",  6000000, 20, 0};
    *(ds + 2) = {"NV03", "Le Van Cuong",   3500000, 18, 0};
    *(ds + 3) = {"NV04", "Pham Thi Dung",  7000000, 25, 0};
    *(ds + 4) = {"NV05", "Hoang Van Em",   3500000, 18, 0};
    *(ds + 5) = {"NV06", "Vo Thi Phuong",  5000000, 15, 0};
    *(ds + 6) = {"NV07", "Dang Van Giang", 8000000, 26, 0};
    *(ds + 7) = {"NV08", "Bui Thi Hoa",    4000000, 24, 0};
    *(ds + 8) = {"NV09", "Do Van Hung",    8000000, 22, 0};
    *(ds + 9) = {"NV10", "Ngo Thi Kim",    5500000, 21, 0};
}

void xuat(NhanVien nv)
{
    cout << nv.maNV << " | " << nv.hoTen << " | " << nv.luongCoBan << " | "
         << nv.soNgayLam << " | " << nv.luongThang << endl;
}

// Câu 2: xuất danh sách nhân viên
void xuatMang(NhanVien* ds, int n)
{
    cout << "Ma | Ho ten | Luong CB | So ngay lam | Luong thang" << endl;
    for(int i = 0; i < n; i++)
    {
        xuat(*(ds + i));
    }
}

// Lương hằng tháng = lương căn bản + số ngày làm * 180.000
// Nếu lương hằng tháng > 8.000.000 thì thưởng thêm 5%
// Nếu lương cơ bản < 5.000.000 thì phụ cấp thêm 10%
// (thưởng và phụ cấp đều tính trên lương hằng tháng ban đầu)
void tinhLuong(NhanVien* nv)
{
    double luong = nv->luongCoBan + nv->soNgayLam * 180000;
    nv->luongThang = luong;
    if(luong > 8000000)
    {
        nv->luongThang = nv->luongThang + luong * 0.05;
    }
    if(nv->luongCoBan < 5000000)
    {
        nv->luongThang = nv->luongThang + luong * 0.1;
    }
}

// Câu 3: tính và cập nhật tiền lương cho các nhân viên
void capNhatLuong(NhanVien* ds, int n)
{
    for(int i = 0; i < n; i++)
    {
        tinhLuong(ds + i);
    }
}

// Câu 4: tổng lương công ty phải trả
double tongLuong(NhanVien* ds, int n)
{
    double t = 0;
    for(int i = 0; i < n; i++)
    {
        t = t + (ds + i)->luongThang;
    }
    return t;
}

// Câu 5: tổng lương các nhân viên có lương cơ bản < 5 triệu
double tongLuongDuoi5Trieu(NhanVien* ds, int n)
{
    double t = 0;
    for(int i = 0; i < n; i++)
    {
        if((ds + i)->luongCoBan < 5000000)
        {
            t = t + (ds + i)->luongThang;
        }
    }
    return t;
}

// Câu 6: tìm nhân viên theo mã, không có thì trả về NULL
NhanVien* timTheoMa(NhanVien* ds, int n, string ma)
{
    for(int i = 0; i < n; i++)
    {
        if((ds + i)->maNV == ma)
        {
            return ds + i;
        }
    }
    return NULL;
}

// Câu 7: các nhân viên có lương hằng tháng thấp nhất (có thể nhiều người bằng nhau)
void xuatLuongThapNhat(NhanVien* ds, int n)
{
    double luongMin = ds->luongThang;
    for(int i = 1; i < n; i++)
    {
        if((ds + i)->luongThang < luongMin)
        {
            luongMin = (ds + i)->luongThang;
        }
    }

    for(int i = 0; i < n; i++)
    {
        if((ds + i)->luongThang == luongMin)
        {
            xuat(*(ds + i));
        }
    }
}

// Câu 8: các nhân viên có lương cơ bản cao nhất
void xuatLuongCBCaoNhat(NhanVien* ds, int n)
{
    double luongMax = ds->luongCoBan;
    for(int i = 1; i < n; i++)
    {
        if((ds + i)->luongCoBan > luongMax)
        {
            luongMax = (ds + i)->luongCoBan;
        }
    }

    for(int i = 0; i < n; i++)
    {
        if((ds + i)->luongCoBan == luongMax)
        {
            xuat(*(ds + i));
        }
    }
}

int main()
{
    NhanVien* ds = new NhanVien[100];
    int n = 0;

    if(ds == NULL)
    {
        cout << "Cap phat khong thanh cong" << endl;
        return 0;
    }

    cout << fixed << setprecision(0); // in tiền dạng 9729000 thay vì 9.729e+06

    khoiTao(ds, n);
    cout << "Cau 1-2. Danh sach nhan vien:" << endl;
    xuatMang(ds, n);

    capNhatLuong(ds, n);
    cout << "\nCau 3. Danh sach sau khi tinh luong:" << endl;
    xuatMang(ds, n);

    cout << "\nCau 4. Tong luong cong ty phai tra: " << tongLuong(ds, n) << endl;
    cout << "\nCau 5. Tong luong NV co luong CB < 5 trieu: " << tongLuongDuoi5Trieu(ds, n) << endl;

    string ma = "NV04";
    NhanVien* p = timTheoMa(ds, n, ma);
    cout << "\nCau 6. Tim nhan vien co ma " << ma << ": ";
    if(p != NULL)
    {
        cout << endl;
        xuat(*p);
    }
    else
    {
        cout << "Khong tim thay!" << endl;
    }

    cout << "\nCau 7. Nhan vien co luong hang thang thap nhat:" << endl;
    xuatLuongThapNhat(ds, n);

    cout << "\nCau 8. Nhan vien co luong co ban cao nhat:" << endl;
    xuatLuongCBCaoNhat(ds, n);

    delete[] ds;
    ds = NULL;
    return 0;
}
