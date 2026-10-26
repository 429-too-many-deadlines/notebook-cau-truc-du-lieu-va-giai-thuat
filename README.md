# Notebook Cấu trúc dữ liệu và Giải thuật (IT003)

Sổ tay cá nhân cho môn **Cấu trúc dữ liệu và Giải thuật (IT003)**. Repo gồm slide bài giảng gốc, bản bài giảng gõ lại bằng LaTeX (Beamer) và lời giải bài tập bằng C++, chia theo chương.

## Cấu trúc thư mục

```
.
├── BaiGiang/
│   └── IT003_FULL.pdf            # Slide bài giảng gốc của môn học
└── Hoc/
    └── BaiGiang.tex/
        └── Chuong1/              # Con trỏ - Cấp phát động - Ứng dụng
            ├── ch1_contro.tex    # Nội dung slide chương 1 (LaTeX Beamer)
            ├── main_bai1.pdf     # Bản PDF đã biên dịch
            └── BaiTap/
                ├── Bai1.cpp
                ├── Bai2.cpp
                └── Bai3.cpp
```

## Nội dung

### Chương 1: Con trỏ, cấp phát động và ứng dụng

Lý thuyết ([ch1_contro.tex](Hoc/BaiGiang.tex/Chuong1/ch1_contro.tex)):

1. Biến và vùng nhớ RAM
2. Toán tử `&` và `*`
3. Khái niệm con trỏ
4. Cú pháp khai báo
5. Con trỏ có giá trị NULL
6. Cấp phát bộ nhớ
7. Con trỏ và hàm
8. Con trỏ và chuỗi
9. Con trỏ trong mảng 1 chiều
10. Con trỏ và cấu trúc
11. Bài tập

Bài tập ([BaiTap/](Hoc/BaiGiang.tex/Chuong1/BaiTap/)):

| File | Chủ đề | Các câu |
|------|--------|---------|
| [Bai1.cpp](Hoc/BaiGiang.tex/Chuong1/BaiTap/Bai1.cpp) | Dùng con trỏ với mảng 1 chiều số thực | Sinh mảng ngẫu nhiên, xuất, tính tổng/tích, đếm, tìm min, đảo mảng, lọc số âm, lọc theo đoạn `[x, y]` (câu 1–11) |
| [Bai2.cpp](Hoc/BaiGiang.tex/Chuong1/BaiTap/Bai2.cpp) | Cấp phát động cho mảng 1 chiều | Kiểm tra toàn dương, đối xứng, chứa số nguyên tố/chính phương; tìm kiếm; lọc số nguyên tố, chính phương, âm, dương; đảo mảng tại chỗ (câu 1–3, 6–13; đề bài không có câu 4, 5) |
| [Bai3.cpp](Hoc/BaiGiang.tex/Chuong1/BaiTap/Bai3.cpp) | Cấp phát động mảng cấu trúc: quản lý lương nhân viên | Tạo dữ liệu, xuất danh sách, tính lương, tổng lương, tìm theo mã, tìm lương thấp nhất/lương cơ bản cao nhất (câu 1–8) |

## Chạy bài tập

Cần trình biên dịch C++ hỗ trợ C++11 trở lên (ví dụ `g++`):

```bash
cd Hoc/BaiGiang.tex/Chuong1/BaiTap
g++ -std=c++17 -Wall Bai1.cpp -o bai1
./bai1
```

Thay `Bai1` bằng `Bai2` hoặc `Bai3` cho các bài còn lại.

## Ghi chú về phần LaTeX

`ch1_contro.tex` chỉ chứa phần thân slide. Nó dùng các macro riêng (`\LectureTitle`, môi trường `blk`, `slidepic`, style `lstlisting` tên `gray`, ...) được định nghĩa trong một file chính kèm preamble. File chính đó hiện chưa có trong repo, nên muốn biên dịch lại phải bổ sung nó. Còn để đọc thì mở thẳng [main_bai1.pdf](Hoc/BaiGiang.tex/Chuong1/main_bai1.pdf).
