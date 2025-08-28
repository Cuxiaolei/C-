#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char id[10];
    char name[50];
    float basicSalary;
    float positionSalary;
    float allowance;
    float medicalInsurance;
    float providentFund;
    float totalSalary;
} Employee;

void inputRecord(Employee* employee, int* count);
void displayRecord(const Employee* employee, int count);
void modifyRecord(Employee* employee, int count);
void searchRecord(Employee* employee, int count);
void deleteRecord(Employee* employee, int* count);
void statistics(Employee* employee, int count);
void saveData(Employee* employee, int count);

int main() {

    Employee* employee = NULL;

    FILE* file = fopen("employee_data.txt", "rb");
    if (file == NULL) {
        perror("�ļ���ʧ��");
    }
    employee = (Employee*)calloc(1, sizeof(Employee));
    int count = 0;
    while (fread(&employee[count], sizeof(Employee), 1, file))
    {
        count++;
        employee = (Employee*)realloc(employee, (count + 1) * sizeof(Employee));
    }
    fclose(file);



    int choice;
    do {
        printf("\n===== ְ�����ʹ���ϵͳ =====\n");
        printf("1. �����¼\n");
        printf("2. ��ʾ��¼\n");
        printf("3. �޸ļ�¼\n");
        printf("4. ���Ҽ�¼\n");
        printf("5. ɾ����¼\n");
        printf("6. ͳ��\n");
        printf("7. ��������\n");
        printf("0. �˳�\n");
        printf("������ѡ��");
        scanf("%d", &choice);

        switch (choice) {
        case 1:
            inputRecord(employee, &count);
            break;
        case 2:
            displayRecord(employee, count);
            break;
        case 3:
            modifyRecord(employee, count);
            break;
        case 4:
            searchRecord(employee, count);
            break;
        case 5:
            deleteRecord(employee, &count);
            break;
        case 6:
            statistics(employee, count);
            break;
        case 7:
            saveData(employee, count);
            break;
        case 0:
            printf("�˳�����\n");
            break;
        default:
            printf("��Ч��ѡ�����������롣\n");
        }
    } while (choice != 0);


    return 0;
}

void inputRecord(Employee* employee, int* count) {



    //if (employee == NULL) {
    printf("������ְ��ID�ţ�");
    employee = (Employee*)realloc(employee, (*count + 1) * sizeof(Employee));
    scanf("%9s", employee[*count].id);

    //// ��ȡ�Ѵ��ڵļ�¼
    //if (fread(&newEmployee, sizeof(Employee), 1, file) == 1) {
    //    printf("������ְ��������");
    //    scanf("%49s", newEmployee.name);

    //    printf("������������ʣ�");
    //    scanf("%f", &newEmployee.basicSalary);

    //    printf("������ְ���ʣ�");
    //    scanf("%f", &newEmployee.positionSalary);

    //    printf("�������λ������");
    //    scanf("%f", &newEmployee.allowance);

    //    printf("������ҽ�Ʊ��գ�");
    //    scanf("%f", &newEmployee.medicalInsurance);

    //    printf("�����빫����");
    //    scanf("%f", &newEmployee.providentFund);
    //}
    //else {
        // ���û���Ѵ��ڵļ�¼������������¼�¼

    printf("������ְ��������");
    scanf("%49s", employee[*count].name);
    printf("������������ʣ�");
    scanf("%f", &employee[*count].basicSalary);
    printf("������ְ���ʣ�");
    scanf("%f", &employee[*count].positionSalary);
    printf("�������λ������");
    scanf("%f", &employee[*count].allowance);
    printf("������ҽ�Ʊ��գ�");
    scanf("%f", &employee[*count].medicalInsurance);
    printf("�����빫����");
    scanf("%f", &employee[*count].providentFund);
    // }

    employee[*count].totalSalary = employee[*count].basicSalary + employee[*count].positionSalary +
        employee[*count].allowance - employee[*count].medicalInsurance - employee[*count].providentFund;
    (*count)++;
    //fseek(file, 0, SEEK_END);  // ���ļ�ָ���ƶ����ļ�ĩβ
    //fwrite(&newEmployee, sizeof(Employee), 1, file);

    printf("��¼���³ɹ���\n");
    //}

    /*else {
        fseek(file, -(int)sizeof(Employee), SEEK_CUR);
        fwrite(employee, sizeof(Employee), 1, file);
        printf("��¼���³ɹ���\n");
    }*/
}

void displayRecord(const Employee* employee, int count) {
    if (count == 0)
    {
        printf("��û��ְԱ��Ϣ\n");
        return;
    }
    for (int i = 0; i < count; i++)
    {
        printf("ID��    ����        ��������    ְ����    ����        ҽ�Ʊ���    ������      �ܹ���    \n");
        printf("%-8s%-12s%-12.2f%-12.2f%-12.2f%-12.2f%-12.2f%-12.2f\n",
            employee[i].id, employee[i].name, employee[i].basicSalary, employee[i].positionSalary,
            employee[i].allowance, employee[i].medicalInsurance, employee[i].providentFund, employee[i].totalSalary);
    }

}

void modifyRecord(Employee* employee, int count) {
    /*if (file == NULL) {
        perror("�ļ�ָ��Ϊ��");
        exit(EXIT_FAILURE);
    }*/

    char modifyId[10];
    printf("������Ҫ�޸ļ�¼��ְ��ID�ţ�");
    scanf("%s", modifyId);

    //Employee temp;
    //long position = -1;  // ��¼ƥ���¼��λ��

    //rewind(file);
    int i;
    //while (fread(&temp, sizeof(Employee), 1, file) == 1) {
    for (i = 0; i < count; i++)
    {
        if (strcmp(employee[i].id, modifyId) == 0) {
            /*position = ftell(file) - sizeof(Employee); */ // ��¼ƥ���¼��λ��
            break;
        }
    }
    // }
     //if (position != -1) {
     //    fseek(file, position, SEEK_SET);  // ���ļ�ָ���ƶ���ƥ���¼��λ��

         // ��ʾ�޸�ǰ�ļ�¼
    printf("�޸�ǰ�ļ�¼��\n");
    printf("ID��    ����        ��������    ְ����    ����        ҽ�Ʊ���    ������      �ܹ���    \n");
    printf("%-8s%-12s%-12.2f%-12.2f%-12.2f%-12.2f%-12.2f%-12.2f\n",
        employee[i].id, employee[i].name, employee[i].basicSalary, employee[i].positionSalary,
        employee[i].allowance, employee[i].medicalInsurance, employee[i].providentFund, employee[i].totalSalary);

    // �û�������µ�����
    printf("������ְ��������");
    scanf("%s", employee[i].name);

    printf("������������ʣ�");
    scanf("%f", &employee[i].basicSalary);

    printf("������ְ���ʣ�");
    scanf("%f", &employee[i].positionSalary);

    printf("�������λ������");
    scanf("%f", &employee[i].allowance);

    printf("������ҽ�Ʊ��գ�");
    scanf("%f", &employee[i].medicalInsurance);

    printf("�����빫����");
    scanf("%f", &employee[i].providentFund);

    employee[i].totalSalary = employee[i].basicSalary + employee[i].positionSalary +
        employee[i].allowance - employee[i].medicalInsurance - employee[i].providentFund;

    // ��ʾ�޸ĺ�ļ�¼
    printf("�޸ĺ�ļ�¼��\n");
    printf("ID��    ����        ��������    ְ����    ����        ҽ�Ʊ���    ������      �ܹ���    \n");
    printf("%-8s%-12s%-12.2f%-12.2f%-12.2f%-12.2f%-12.2f%-12.2f\n",
        employee[i].id, employee[i].name, employee[i].basicSalary, employee[i].positionSalary,
        employee[i].allowance, employee[i].medicalInsurance, employee[i].providentFund, employee[i].totalSalary);

    //fseek(file, position, SEEK_SET);  // ���ļ�ָ���ٴ��ƶ���ƥ���¼��λ��
    //fwrite(&temp, sizeof(Employee), 1, file);  // д����º�ļ�¼

    printf("��¼���³ɹ���\n");
    // }
     /*else {
         printf("δ�ҵ�ƥ��ļ�¼��\n");
     }*/
}

void searchRecord(Employee* employee, int count) {
    /* if (file == NULL) {
         perror("�ļ�ָ��Ϊ��");
         exit(EXIT_FAILURE);
     }*/

     //if (searchName == NULL) {
    printf("������Ҫ���ҵ�ְ��������");
    char tempName[50];
    if (scanf("%49s", tempName) != 1) {
        perror("������Ч");
        exit(EXIT_FAILURE);
    }
    //searchName = tempName;
//  }

 //Employee temp;
    int found = 0;

    // rewind(file);
    int i;
    printf("ƥ��ļ�¼��\n");
    //while (fread(&temp, sizeof(Employee), 1, file) == 1) {
    for (i = 0; i < count; i++)
    {
        if (strcmp(employee[i].name, tempName) == 0) {
            printf("ID��    ����        ��������    ְ����    ����        ҽ�Ʊ���    ������      �ܹ���    \n");
            printf("%-8s%-12s%-12.2f%-12.2f%-12.2f%-12.2f%-12.2f%-12.2f\n",
                employee[i].id, employee[i].name, employee[i].basicSalary, employee[i].positionSalary,
                employee[i].allowance, employee[i].medicalInsurance, employee[i].providentFund, employee[i].totalSalary);
            found = 1;
        }
    }
    //}

    if (found == 0) {
        printf("δ�ҵ�ƥ��ļ�¼��\n");
    }
}

void deleteRecord(Employee* employee, int* count) {
    /*if (file == NULL) {
        perror("�ļ�ָ��Ϊ��");
        exit(EXIT_FAILURE);
    }*/

    //if (deleteId == NULL) {
    if (*count == 0)
    {
        printf("û��ְԱ��Ϣ");
        return;
    }
    printf("������Ҫɾ����¼��ְ��ID�ţ�");
    char tempId[10];
    if (scanf("%9s", tempId) != 1) {
        perror("������Ч");
        exit(EXIT_FAILURE);
    }
    // }

     /*Employee temp;
     FILE* tempFile;*/
     //long int position;  // �����ļ�ָ��λ��
     /*if (tmpfile_s(&tempFile) != 0) {
         perror("�޷�������ʱ�ļ�");
         exit(EXIT_FAILURE);
     }*/

     // �����ļ�ָ��λ��
     //position = ftell(file);

     //rewind(file);
    int i;
    // while (fread(&temp, sizeof(Employee), 1, file) == 1) {
    for (i = 0; i < *count; i++)
    {
        if (strcmp(employee[i].id, tempId) == 0) {
            break;
        }
    }
    for (int t = i; t < *count - 1; t++)
    {
        employee[t].allowance = employee[t + 1].allowance;
        employee[t].basicSalary = employee[t + 1].basicSalary;
        strcpy(employee[t].id, employee[t + 1].id);
        employee[t].medicalInsurance = employee[t + 1].medicalInsurance;
        strcpy(employee[t].name, employee[t + 1].name);
        employee[t].positionSalary = employee[t + 1].positionSalary;
        employee[t].providentFund = employee[t + 1].providentFund;
        employee[t].totalSalary = employee[t + 1].totalSalary;
    }
    (*count)--;
    // } 

     //fclose(file);
     //if (fopen_s(&file, "employee_data.txt", "wb") != 0) {
     //    perror("�ļ���ʧ��");
     //    exit(EXIT_FAILURE);
    // }

     // �ָ��ļ�ָ��λ��
    // fseek(file, position, SEEK_SET);

    // rewind(tempFile);
    // while (fread(&temp, sizeof(Employee), 1, tempFile) == 1) {
    //     fwrite(&temp, sizeof(Employee), 1, file);
    // }

    // fclose(tempFile);
    printf("��¼ɾ���ɹ���\n");
}

void statistics(Employee* employee, int count) {
    /*if (file == NULL) {
        perror("�ļ�ָ��Ϊ��");
        exit(EXIT_FAILURE);
    }*/

    //Employee temp;
    int numRecords = 0;
    float totalBasicSalary = 0.0;
    float totalPositionSalary = 0.0;
    float totalAllowance = 0.0;
    float totalMedicalInsurance = 0.0;
    float totalProvidentFund = 0.0;
    float totalTotalSalary = 0.0;

    float minSalaryRange = 1000.0;  // ��͹��ʷ�Χ
    float maxSalaryRange = 2000.0;  // ��߹��ʷ�Χ
    int countAbove3000 = 0;
    int countBetween2000And3000 = 0;
    int countBetween1000And2000 = 0;

    //rewind(file);

    //while (fread(&temp, sizeof(Employee), 1, file) == 1) {
    for (int i = 0; i < count; i++)
    {
        numRecords++;
        totalBasicSalary += employee[i].basicSalary;
        totalPositionSalary += employee[i].positionSalary;
        totalAllowance += employee[i].allowance;
        totalMedicalInsurance += employee[i].medicalInsurance;
        totalProvidentFund += employee[i].providentFund;
        totalTotalSalary += employee[i].totalSalary;

        // ͳ�ƹ��ʷ�Χ
        float totalSalaryRange = employee[i].basicSalary + employee[i].positionSalary + employee[i].allowance;
        if (totalSalaryRange > 3000) {
            countAbove3000++;
        }
        else if (totalSalaryRange >= 2000) {
            countBetween2000And3000++;
        }
        else if (totalSalaryRange >= 1000) {
            countBetween1000And2000++;
        }
    }
    // }

     // (A) ��������ƽ�����ʼ��ܹ���
    float avgBasicSalary = totalBasicSalary / numRecords;
    float avgPositionSalary = totalPositionSalary / numRecords;
    float avgAllowance = totalAllowance / numRecords;
    float avgMedicalInsurance = totalMedicalInsurance / numRecords;
    float avgProvidentFund = totalProvidentFund / numRecords;
    float avgTotalSalary = totalTotalSalary / numRecords;

    printf("�ܼ�¼����%d\n", numRecords);
    printf("�����ƽ��ֵ��\n");
    printf("�������ʣ�%f\n", avgBasicSalary);
    printf("ְ���ʣ�%f\n", avgPositionSalary);
    printf("������%f\n", avgAllowance);
    printf("ҽ�Ʊ��գ�%f\n", avgMedicalInsurance);
    printf("������%f\n", avgProvidentFund);
    printf("�ܹ��ʣ�%f\n", avgTotalSalary);

    // (B) ͳ�Ʒ���ָ�������Ĺ��ʷ�Χ�ڵ�ְ��������ռ��ְ�������İٷֱ�
    int totalCount = countAbove3000 + countBetween2000And3000 + countBetween1000And2000;
    float percentAbove3000 = (float)countAbove3000 / numRecords * 100;
    float percentBetween2000And3000 = (float)countBetween2000And3000 / numRecords * 100;
    float percentBetween1000And2000 = (float)countBetween1000And2000 / numRecords * 100;

    printf("\n���ʷ�Χͳ�ƣ�\n");
    printf("3000Ԫ���ϵ�������%d��ռ�������� %.2f\n", countAbove3000, percentAbove3000);
    printf("3000Ԫ��2000Ԫ��������%d��ռ�������� %.2f\n", countBetween2000And3000, percentBetween2000And3000);
    printf("2000Ԫ��1000Ԫ��������%d��ռ�������� %.2f\n", countBetween1000And2000, percentBetween1000And2000);

    // (C) ���ַ������ʽ��ӡȫ��ְ��������Ϣ��ƽ������
    printf("\nȫ��ְ��������Ϣ��\n");
    /*printf("%-10s%-10s%-15s%-15s%-10s%-15s%-10s%-15s\n",
        "ID��", "����", "��������", "ְ����", "����", "ҽ�Ʊ���", "������", "�ܹ���");*/

        //rewind(file);
        //while (fread(&temp, sizeof(Employee), 1, file) == 1) {
    displayRecord(employee, count);
    // }

    printf("\nƽ�����ʣ�\n");
    printf("�������ʣ�%f\n", avgBasicSalary);
    printf("ְ���ʣ�%f\n", avgPositionSalary);
    printf("������%f\n", avgAllowance);
    printf("ҽ�Ʊ��գ�%f\n", avgMedicalInsurance);
    printf("������%f\n", avgProvidentFund);
    printf("�ܹ��ʣ�%f\n", avgTotalSalary);
}

void saveData(Employee* employee, int count) {
    /*if (file == NULL) {
        perror("�ļ�ָ��Ϊ��");
        exit(EXIT_FAILURE);
    }*/

    //rewind(file);

    FILE* pwrite = fopen("employee_data.txt", "wb");
    if (pwrite == NULL)
    {
        perror("saveData");
        return;
    }
    //Employee temp;

    // ��ȡ��һ����¼
    //if (fread(&temp, sizeof(Employee), 1, file) != 1) {
        //printf("û�м�¼�ɱ��档\n");
       // return;
   // }

    // �����һ����¼ȫ��0����ʾû����Ч��¼��ֱ�ӷ���
    /*if (temp.basicSalary == 0 && temp.positionSalary == 0 && temp.allowance == 0 &&
        temp.medicalInsurance == 0 && temp.providentFund == 0 && temp.totalSalary == 0) {
        printf("û�м�¼�ɱ��档\n");
        return;
    }*/

    // �����ͷ��Ϣ
    //printf("%-10s%-10s%-15s%-15s%-10s%-15s%-10s%-15s\n",
    //    "ID��", "����", "��������", "ְ����", "����", "ҽ�Ʊ���", "������", "�ܹ���");

    //// ���ļ�ָ�������ƶ����ļ���ͷ
    //rewind(file);

    //// �����¼
    //do {
    //    displayRecord(&temp);
    //} while (fread(&temp, sizeof(Employee), 1, file) == 1);


    for (int i = 0; i < count; i++)
    {
        fwrite(&employee[i], sizeof(Employee), 1, pwrite);
    }


    fclose(pwrite);
    pwrite = NULL;

    printf("���ݱ���ɹ���\n");
}