#include <iostream>

using namespace std;

// Fungsi manual untuk menyalin string (pengganti strcpy)
void salinKata(char* tujuan, const char* asal) {
    int i = 0;
    while (asal[i] != '\0') {
        tujuan[i] = asal[i];
        i++;
    }
    tujuan[i] = '\0';
}

// Fungsi manual untuk membandingkan string (pengganti strcmp)
bool cekSama(const char* kata1, const char* kata2) {
    int i = 0;
    while (kata1[i] != '\0' && kata2[i] != '\0') {
        if (kata1[i] != kata2[i]) {
            return false;
        }
        i++;
    }
    return kata1[i] == kata2[i];
}

struct Node {
    char jabatan[50];
    Node* left;
    Node* right;
};

Node* buatNode(const char* nama) {
    Node* baru = new Node;
    salinKata(baru->jabatan, nama);
    baru->left = NULL;
    baru->right = NULL;
    return baru;
}

Node* cariNode(Node* root, const char* target) {
    if (root == NULL) return NULL;
    if (cekSama(root->jabatan, target)) return root;

    Node* cariKiri = cariNode(root->left, target);
    if (cariKiri != NULL) return cariKiri;

    return cariNode(root->right, target);
}

bool tambahBawahan(Node* root, const char* atasan, const char* bawahan) {
    Node* nodeAtasan = cariNode(root, atasan);
    if (nodeAtasan == NULL) {
        cout << "Atasan tidak ditemukan\n";
        return false;
    }

    if (cariNode(root, bawahan) != NULL) {
        cout << "Jabatan sudah ada\n";
        return false;
    }

    Node* nodeBaru = buatNode(bawahan);

    if (nodeAtasan->left == NULL) {
        nodeAtasan->left = nodeBaru;
    } else {
        Node* temp = nodeAtasan->left;
        while (temp->right != NULL) {
            temp = temp->right;
        }
        temp->right = nodeBaru;
    }

    cout << "Berhasil ditambah\n";
    return true;
}

void tampil(Node* root, int level = 0) {
    if (root == NULL) return;

    for (int i = 0; i < level; i++) cout << "  ";
    
    if (level == 0) cout << "- " << root->jabatan << " (Puncak)\n";
    else cout << "- " << root->jabatan << "\n";

    tampil(root->left, level + 1);
    tampil(root->right, level);
}

Node* hapus(Node* root, const char* target, bool& terhapus, bool isRoot) {
    if (root == NULL) return NULL;

    if (cekSama(root->jabatan, target)) {
        if (isRoot) {
            cout << "Puncak tidak bisa dihapus\n";
            return root;
        }
        if (root->left != NULL) {
            cout << "Gagal: Jabatan masih punya bawahan\n";
            return root;
        }

        Node* temp = root->right;
        delete root;
        terhapus = true;
        return temp;
    }

    root->left = hapus(root->left, target, terhapus, false);
    root->right = hapus(root->right, target, terhapus, false);
    return root;
}

void hapusDaun(Node* root, const char* target) {
    if (cariNode(root, target) == NULL) {
        cout << "Jabatan tidak ditemukan\n";
        return;
    }
    bool status = false;
    hapus(root, target, status, true);
    if (status) cout << "Berhasil dihapus\n";
}

void bersihkan(Node* root) {
    if (root == NULL) return;
    bersihkan(root->left);
    bersihkan(root->right);
    delete root;
}

int main() {
    Node* root = buatNode("Direktur");
    int pil;
    char atasan[50], bawahan[50], target[50];

    do {
        cout << "\nMenu Struktur Organisasi\n";
        cout << "1. Tambah Bawahan\n";
        cout << "2. Tampil Struktur\n";
        cout << "3. Cari Jabatan\n";
        cout << "4. Hapus Daun\n";
        cout << "5. Keluar\n";
        cout << "Pilih: ";
        cin >> pil;
        cin.ignore();

        if (pil == 1) {
            cout << "Atasan: ";
            cin.getline(atasan, 50);
            cout << "Bawahan baru: ";
            cin.getline(bawahan, 50);
            tambahBawahan(root, atasan, bawahan);
        } else if (pil == 2) {
            tampil(root);
        } else if (pil == 3) {
            cout << "Cari: ";
            cin.getline(target, 50);
            if (cariNode(root, target)) cout << "Ditemukan\n";
            else cout << "Tidak ditemukan\n";
        } else if (pil == 4) {
            cout << "Hapus: ";
            cin.getline(target, 50);
            hapusDaun(root, target);
        }
    } while (pil != 5);

    bersihkan(root);
    return 0;
}
