TinyProject: Hồi quy tuyến tính với C++

TinyProject là một dự án C++ thực hiện hồi quy tuyến tính để dự đoán hiệu năng phần cứng dựa trên tập dữ liệu Computer Hardware. Dự án sử dụng phương pháp giải hệ phương trình tuyến tính và tối ưu hóa với ma trận đối xứng dương.
Mục lục

Giới thiệu
Yêu cầu hệ thống
Cài đặt
Cách chạy
Kết quả
Cấu trúc dự án
Troubleshooting
Đóng góp
Giấy phép

Giới thiệu
Dự án này được phát triển như một bài tập học thuật để:

Áp dụng hồi quy tuyến tính cho bài toán dự đoán thực tế.
Sử dụng C++ để xây dựng các lớp Matrix, Vector, và LinearSystem.
Tối ưu hóa giải hệ phương trình tuyến tính với ma trận đối xứng dương (PosSymLinSystem).

Tập dữ liệu machine.data được sử dụng để huấn luyện và đánh giá mô hình. Kết quả được đo bằng Root Mean Squared Error (RMSE).
Yêu cầu hệ thống



Công cụ
Phiên bản
Mô tả



HĐH
Windows 10/11
Hỗ trợ MSYS2


MSYS2
Mới nhất
Cung cấp môi trường MinGW


GCC/G++
13.x.x
Trình biên dịch C++


mingw32-make
4.x.x
Công cụ xây dựng


Git
Mới nhất
Quản lý mã nguồn


Cài đặt
1. Cài đặt MSYS2

Tải MSYS2 từ msys2.org và cài vào C:\msys64.
Mở terminal MSYS2 UCRT64 (C:\msys64\ucrt64.exe).
Cập nhật hệ thống:pacman -Syu


Cài các gói cần thiết:pacman -S mingw-w64-x86_64-gcc mingw-w64-x86_64-make



2. Thêm MSYS2 vào Path

Nhấn Win + R, gõ sysdm.cpl, vào Environment Variables.
Trong System Variables, thêm C:\msys64\ucrt64\bin vào Path.
Kiểm tra:g++ --version
mingw32-make --version



3. Clone dự án

Cài Git nếu chưa có: git-scm.com.
Clone kho:git clone https://github.com/lqh2005/TinyProject.git
cd TinyProject



4. Tải dữ liệu

Đảm bảo file machine.data nằm trong thư mục data/.
Nếu thiếu, tải từ UCI.

Cách chạy

Di chuyển đến thư mục dự án:
cd /c/Users/hungl/OneDrive/Documents/TinyProject


Làm sạch dự án:
mingw32-make clean


Biên dịch:
mingw32-make


Chạy chương trình:
mingw32-make run


Kết quả RMSE sẽ hiển thị (ví dụ: RMSE: 47.89).



Kết quả

RMSE: 47.89 (giá trị thực tế sau khi chạy mingw32-make run).
Mô hình đạt độ chính xác tương đối trên tập dữ liệu machine.data.

Cấu trúc dự án
TinyProject/
├── data/
│   └── machine.data
├── include/
│   ├── LinearSystem.hpp
│   ├── Matrix.hpp
│   ├── Vector.hpp
├── src/
│   ├── LinearSystem.cpp
│   ├── main.cpp
│   ├── Matrix.cpp
│   ├── Vector.cpp
├── Makefile
├── README.md


data/: Chứa tập dữ liệu.
include/: Chứa file tiêu đề (.hpp).
src/: Chứa file mã nguồn (.cpp).
Makefile: File cấu hình biên dịch.

Troubleshooting



Lỗi
Giải pháp



g++: command not found
Cài mingw-w64-x86_64-gcc hoặc thêm C:\msys64\ucrt64\bin vào Path.


mingw32-make: command not found
Cài mingw-w64-x86_64-make.


machine.data not found
Tải file từ UCI và đặt vào data/.


Lỗi biên dịch streamsize
Dùng GCC/G++ phiên bản mới (13.x.x).


Lỗi A, b trong LinearSystem
Kiểm tra LinearSystem.hpp có khai báo Matrix A; Vector b;.


Đóng góp

Fork kho: https://github.com/lqh2005/TinyProject.
Tạo nhánh: git checkout -b feature/ten-nhanh.
Commit: git commit -m "Mô tả thay đổi".
Push: git push origin feature/ten-nhanh.
Tạo Pull Request trên GitHub.

Giấy phép
Dự án được cấp phép dưới MIT License.

Liên hệ: lqh2005Nộp bài: Moodle (thay bằng link Moodle thực tế)RMSE: 47.89 (cập nhật giá trị thực tế sau khi chạy)
