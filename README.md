# Detective Conan: Fallen Angel Highway

Bài tập C++ phân tích cuộc truy đuổi và xác định nghi phạm chính, sử dụng mảng một chiều, vòng lặp và hàm.

## Chức năng

1. Tìm đoạn đường có điểm rủi ro cao nhất.
2. Ước tính tốc độ Quái Xế Đen.
3. Tính và phân loại điểm nghi ngờ của từng nghi phạm.
4. Chọn nghi phạm chính theo điểm, bằng chứng, camera và thứ tự xuất hiện.
5. Đưa ra kết luận điều tra.

## Cấu trúc

- `src/main.cpp`: chương trình tham khảo đầy đủ.
- `tests/sample.in`: dữ liệu mẫu trong đề.
- `tests/sample.out`: kết quả mẫu trong đề.

## Biên dịch và chạy

Chạy trong PowerShell tại thư mục gốc của dự án, với `g++` đã được cài đặt:

```powershell
g++ -std=c++17 -Wall -Wextra src/main.cpp -o main.exe
Get-Content tests/sample.in | .\main.exe
```

Đối chiếu kết quả với `tests/sample.out`. Muốn tự nhập dữ liệu, chạy `./main.exe`.

## Đầu vào

- Số đoạn đường `M` (1–5), sau đó `M` dòng: `segmentSpeed speedLimit danger`.
- Số nghi phạm `N` (1–5), sau đó `N` dòng: `speed alibi cameraMatch vehicleMatch evidence`.

## Lưu ý định dạng

Chương trình tính phân loại và điểm rủi ro từng đoạn nhưng chỉ in đoạn nguy hiểm nhất, theo output mẫu. Dòng `The Black Rider has been identified.` chỉ được in khi kết luận là `CASE SOLVED`; đề không cung cấp câu bổ sung tương ứng cho hai kết luận khác.
