# Sistem Struktur Organisasi (First-Child Next-Sibling Tree)

Repositori ini berisi implementasi program **Sistem Struktur Organisasi** menggunakan struktur data *Tree* (Pohon) dalam bahasa C++. Program ini ditulis secara murni *dari nol* (from scratch), hanya menggunakan *library* dasar `<iostream>` tanpa bantuan *library* tambahan seperti `<string>` atau `<vector>`.

## 📌 Deskripsi Logika (First-Child Next-Sibling)

Secara konseptual, sebuah struktur organisasi adalah **N-ary Tree** (sebuah pohon di mana satu *node* atasan bisa memiliki banyak bawahan tanpa batas). Namun, dalam program ini, *N-ary Tree* tersebut direpresentasikan menggunakan struktur **Binary Tree** dengan teknik klasik yang sangat efisien secara memori, yaitu **First-Child Next-Sibling (FCNS)** atau **Left-Child Right-Sibling**.

Dalam logika ini, setiap *node* (jabatan) hanya memiliki dua *pointer*:
* `left` (**First Child**): Menunjuk ke bawahan langsung yang pertama.
* `right` (**Next Sibling**): Menunjuk ke rekan sejawat (saudara) atau bawahan lain yang berada di bawah atasan yang sama.

Keuntungan dari pendekatan ini adalah kita bisa membuat struktur organisasi dengan **jumlah bawahan tak terbatas** pada setiap atasan, tanpa harus memesan ukuran *array* yang tetap di awal. Selain itu, manipulasi *string* (pencarian dan penyalinan teks) dilakukan secara manual menggunakan manipulasi *array of char* (`char[]`).

---

## 🚀 Fitur Utama

1.  **Tambah Bawahan**: Menambahkan jabatan baru di bawah jabatan atasan yang sudah ada.
2.  **Tampil Struktur**: Menampilkan hierarki organisasi secara visual menggunakan indentasi (mirip *Preorder Traversal*).
3.  **Cari Jabatan**: Mengecek apakah sebuah jabatan eksis di dalam struktur.
4.  **Hapus Daun**: Menghapus jabatan yang berada di ujung struktur (tidak memiliki bawahan). Node *root* (puncak) dan node yang memiliki bawahan tidak bisa dihapus untuk menjaga integritas struktur.

---

## 💻 Contoh Output Program

Berikut adalah simulasi jalannya program yang dibagi berdasarkan beberapa skenario penggunaan:

### Skenario 1: Menambahkan Struktur Jabatan
Pengguna menambahkan "Manajer IT" dan "Manajer HRD" di bawah "Direktur", lalu menambahkan "Staff Programmer" di bawah "Manajer IT".

```text
Menu Struktur Organisasi
...
Pilih: 1
Atasan: Direktur
Bawahan baru: Manajer IT
Berhasil ditambah

Pilih: 1
Atasan: Direktur
Bawahan baru: Manajer HRD
Berhasil ditambah

Pilih: 1
Atasan: Manajer IT
Bawahan baru: Staff Programmer
Berhasil ditambah

```

### Skenario 2: Menampilkan Hierarki Organisasi

Melihat representasi visual dari struktur data yang sudah dibangun menggunakan fitur nomor 2.

```text
Pilih: 2

- Direktur (Puncak)
  - Manajer IT
    - Staff Programmer
  - Manajer HRD

```

### Skenario 3: Mencari Jabatan Spesifik

Memeriksa apakah sebuah jabatan ada di dalam struktur *tree*.

```text
Pilih: 3
Cari: Staff Programmer
Ditemukan

```

### Skenario 4: Menghapus Jabatan Daun (Leaf Node)

Menghapus node yang tidak memiliki bawahan (misalnya "Manajer HRD"). Kemudian menampilkan kembali struktur untuk memastikan node telah terhapus.

```text
Pilih: 4
Hapus: Manajer HRD
Berhasil dihapus

Pilih: 2

- Direktur (Puncak)
  - Manajer IT
    - Staff Programmer
```
