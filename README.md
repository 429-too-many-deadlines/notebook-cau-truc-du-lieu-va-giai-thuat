# Notebook Cấu Trúc Dữ Liệu và Giải Thuật (IT003)

Kho lưu trữ tài liệu học tập, bài giảng biên soạn bằng LaTeX và mã nguồn C++ thực hành cho học phần **Cấu trúc dữ liệu và Giải thuật (`IT003`)**.

## Cấu trúc thư mục

```text
notebook-cau-truc-du-lieu-va-giai-thuat/
├── BaiGiang/
│   └── IT003_FULL.pdf              # Tài liệu / slide bài giảng tổng hợp của học phần (114 trang)
├── BaiGiang.tex/
│   ├── Pointer/                    # Chuyên đề: Con trỏ - Cấp phát động - Ứng dụng
│   │   ├── Pointer.tex
│   │   ├── Pointer.pdf
│   │   ├── main.tex
│   │   └── main.pdf
│   └── List/                       # Chuyên đề: Danh sách liên kết đơn
│       ├── List.tex
│       ├── List.pdf
│       ├── main.tex
│       └── main.pdf
├── Code/
│   └── Buoi3/
│       ├── BaiTap/
│       │   └── Demo01.cpp          # Cài đặt minh họa danh sách liên kết đơn
│       └── TrenLop/                # Thư mục lưu code thực hành trên lớp buổi 3
├── .gitignore
└── README.md
```

## Nội dung hiện có

### 1. Bài giảng tham khảo (`BaiGiang/`)
- [`BaiGiang/IT003_FULL.pdf`](BaiGiang/IT003_FULL.pdf): Bộ tài liệu tổng hợp toàn học phần IT003.

### 2. Chuyên đề biên soạn bằng LaTeX (`BaiGiang.tex/`)
Các chuyên đề được trình bày kèm sơ đồ minh họa (TikZ), mã nguồn C++ (`listings`) và bài tập áp dụng:

| Chuyên đề | Mã nguồn LaTeX | File PDF | Nội dung chính |
| :--- | :--- | :--- | :--- |
| **Con trỏ -- Cấp phát động -- Ứng dụng** | [`Pointer.tex`](BaiGiang.tex/Pointer/Pointer.tex) | [`Pointer.pdf`](BaiGiang.tex/Pointer/Pointer.pdf) | Vùng nhớ RAM, toán tử `&` và `*`, khai báo & con trỏ `NULL`, `sizeof`, cấp phát động (`new`/`delete`) & lỗi Dangling Pointer, con trỏ với hàm, mảng một chiều, `struct` & cấu trúc tự tham chiếu, bài tập ứng dụng. |
| **Danh sách liên kết đơn** | [`List.tex`](BaiGiang.tex/List/List.tex) | [`List.pdf`](BaiGiang.tex/List/List.pdf) | Ý tưởng chuyển từ mảng sang danh sách liên kết đơn, kiến trúc `Node`/`List`, quy trình xây dựng 4 bước, các thao tác (`addHead`, `addTail`, `printList`, `printWh`, tìm kiếm, đếm, min/max, tính tổng, `removeHead`, `removeTail`), bài tập quản lý số nguyên & sinh viên. |

> **Lưu ý:** Trong mỗi thư mục chuyên đề có thêm file `main.tex` (chỉ gọi `\input{...}`) và `main.pdf` để tiện biên dịch theo cấu trúc project LaTeX.

### 3. Mã nguồn thực hành C++ (`Code/`)
- [`Code/Buoi3/BaiTap/Demo01.cpp`](Code/Buoi3/BaiTap/Demo01.cpp): Minh họa khởi tạo `Node`, `List` và các thao tác cơ bản (`initNode`, `initList`, `addHead`, `addTail`, `printList`).
- `Code/Buoi3/TrenLop/`: Thư mục dành cho mã nguồn thực hành trên lớp buổi 3.

## Hướng dẫn biên dịch

### Biên dịch tài liệu LaTeX (`.tex` → `.pdf`)
Yêu cầu cài đặt TeX Live với `pdflatex` (hoặc `latexmk`) cùng các gói tiếng Việt và đồ họa (`babel` với tùy chọn `vietnamese`, `mathptmx`, `tikz`, `listings`, `booktabs`, `tabularx`, `titlesec`, `enumitem`, ...).

Ví dụ biên dịch chuyên đề **Danh sách liên kết đơn**:

```bash
cd BaiGiang.tex/List
pdflatex List.tex
# Hoặc sử dụng latexmk:
latexmk -pdf List.tex
```

Thực hiện tương tự trong `BaiGiang.tex/Pointer/` với `Pointer.tex` (hoặc `main.tex`).

### Biên dịch mã nguồn C++
Do mã nguồn sử dụng thư viện chuẩn và cú pháp C++ (`<iostream>`, `new`, `nullptr`, tham chiếu `&`), hãy biên dịch bằng `g++` (hoặc trình biên dịch C++ tương đương):

```bash
g++ -std=c++11 -Wall Code/Buoi3/BaiTap/Demo01.cpp -o Code/Buoi3/BaiTap/Demo01
./Code/Buoi3/BaiTap/Demo01
```

## Quy ước Git (`.gitignore`)

File [`.gitignore`](.gitignore) đã được cấu hình sẵn để giữ repository gọn nhẹ:
- **Bỏ qua** các file thực thi không có phần mở rộng sinh ra khi biên dịch C/C++ trên Linux bên trong `Code/` (các file có đuôi như `.cpp`, `.c`, `.h`, `.hpp`, ... và `Makefile` vẫn được giữ lại).
- **Bỏ qua** các file trung gian/tạm khi biên dịch LaTeX (`*.aux`, `*.log`, `*.fls`, `*.fdb_latexmk`, `*.synctex.gz`, ...).
- **Bỏ qua** cấu hình IDE (`.vscode/`) và file tạm của hệ điều hành.
- **Luôn giữ lại** toàn bộ file nguồn `*.tex` và kết quả biên dịch `*.pdf`.
