#include "Header/desain.h"
#include "Header/bus.h"
#include "Header/terminal.h"
#include "Header/admin.h"
#include "Header/queue.h"
#include <stdio.h>
#include <stdlib.h>

int main() {
    SplashScreenAdmin();

    Queue queueBus;
    CreateQueue(&queueBus);

    if (!LoginAdmin()) {
        printf("Akses ditolak. Keluar dari program...\n");
        return 0;
    }

    int pilihan;
    do {
        AdminMenu();
        scanf("%d", &pilihan); getchar();

        switch (pilihan) {
            case 1: { // Manajemen Bus
                int pilihMenuAdmin;
                do {
                    ManajemenBus();
                    printf("Masukkan pilihan Anda: ");
                    scanf("%d", &pilihMenuAdmin); getchar();

                    switch (pilihMenuAdmin) {
                        case 1: {
                            terminalTree T;
                            CreateTerminal(T);
                            int root = 0;
                            NodeBus *busBaru = inputDataBus(T, root);
                            if (busBaru != NULL) {
                                printf("Data bus berhasil ditambahkan.\n");
                                free(busBaru);
                            }
                            break;
                        }
                        case 2: {
                            char idBus[10];
                            printf("Masukkan ID Bus yang ingin dihapus: ");
                            scanf("%s", idBus);
                            deleteBus(idBus);
                            break;
                        }
                        case 3:
                            printAllBus();
                            break;
                        case 4:
                            printf("Keluar dari menu manajemen bus...\n");
                            break;
                        default:
                            printf("Pilihan tidak valid.\n");
                    }
                    printf("\n");
                } while (pilihMenuAdmin != 4);
                break;
            }
            case 2: { // Antri & Release Bus
                int subpil;
                do {
                    printf("\n=== ANTRI & RELEASE BUS ===\n");
                    printf("1. Lihat Bus Dalam Antrian\n");
                    printf("2. Antri Bus ke Terminal\n");
                    printf("3. Release Bus dari Terminal\n");
                    printf("4. Kembali\n");
                    printf("Pilih: ");
                    scanf("%d", &subpil); getchar();

                    switch (subpil) {
                        case 1:
                            LihatBusDiSetiapTerminal(&queueBus);
                            break;
                        case 2:
                            AntriBus(&queueBus);
                            break;
                        case 3:
                            ReleaseBusDariTerminal(&queueBus);
                            break;
                        case 4:
                            printf("Kembali ke menu utama.\n");
                            break;
                        default:
                            printf("Pilihan tidak valid.\n");
                    }
                } while (subpil != 4);
                break;
            }
            case 3: // Jalur Terminal
                {
                    terminalTree T;
                    CreateTerminal(T);
                    tampilkanTerminal(T);
                }
                break;
            case 4: // Riwayat Transaksi Tiket
                RiwayatTransaksi();
                break;
            case 5:
                printf("Keluar dari menu admin...\n");
                break;
            default:
                printf("Pilihan tidak valid.\n");
        }
    } while (pilihan != 5);

    return 0;
}
